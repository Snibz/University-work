#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include "gameboard.hh"
#include <QGraphicsScene>
#include <QColor>
#include <QPainter>
#include <QBrush>
#include <QGraphicsProxyWidget>
#include <QBoxLayout>


// for calculating goal
#include <cmath>
#include <iostream>

/* COMP.CS.110
 * Projecti 'Peli nimeltä 2048'
 * Opiskelija: Eetu Luoma
 * Email: eetu.luoma@tuni.fi
 * Opiskelijanumero: K444309
 *
 * Kuvaus projektista:
 *  Projektiin on annettu valmiina pohjakoodina koodi pelille '2048'.
 *  Projektin tarkoitus on tehdä graafinen käyttöliittymä pelille.
 *
 *  Ohjelma on siis peli '2048', jota pelataan graafisen käyttöliittymän kautta.
 *  Ohjelman peli vastaa tavanomaista 2048:a aika lailla tarkasti.
 *  Pelistä tarkemmin dokumentaatiossa.
 *
 *  Projektissa täytyy käyttää annettua koodipohjaa, mutta koska
 *  tehtävänannossa ei eksplisiittisesti sanottu ettei sitä saa muokata,
 *  on koodipohjaa muokattu pääasiassa ruudukon kokoon liittyen.
 *  Mikäli koodipohjaa ei olisi saanut muokata, se olisi pitänyt erikseen mainita.
 *
 * Ohjelman toiminnallisuus on rankasti kommentoituna ohjelmakoodissa sekä tiedostossa
 * 'instructions.txt'.
 *
 * Tämä tiedosto, eli mainwindow.cpp on yhtä aikaa pelimoottori ja gui-moottori.
 * Varsinaiset pelioperaatiot tapahtuvat tiedostoissa gameboard.cpp ja numbertile.cpp
 *
 * täsmällisempi toiminnallisuus sekä kommentoinneissa että dokumentaatiossa.
 *
 * Muistinhallinnasta:
 * Vain scene täytyy manuaalisesti deletoida. Deletointi tapahtuu
 * boardsideSpinBoxin slotissa.
 * Itse ajamani valgrind ei näytä muita kuin external erroreja.
 *
 *
 * Lisäominaisuudet:
 *
 *  -laudan koon muuttaminen guissa
 *  -ikkunan värin muuttuminen ja palautuminen
 *  -maalina vain kakkosen potenssit
 *
 *  (-lopetusnappula)
 *
 *
 * Muuta:
 *  Eräs mielenkiintoinen huomio: tehtävänannossa ei missään vaadita,
 *  että peli lisää uuden numeron aina kun pelaaja tekee siirron.
 *  Todellisuudessa tämä täytyy toteuttaa jotta voitto olisi mahdollista,
 *  mutta sitäkään ei tehtävänannossa määrätä, että pelin pitää pystyä voittamaan
 *
 *  Olen toteuttanut numeron lisäämisen, vaikka sitä ei tehtävänannossa vaadittu.
 *  Olisiko se nyt sitten siis lisäominaisuus?
 *
 */

MainWindow::MainWindow(GameBoard gameboard, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      gameboard_(gameboard)
{



    ui->setupUi(this);
    // Button to quit program is implemented solely by the qt designer

    // initializes scene, so that when the ranges and defaults are set below,
    // valgrind memory issues dont happen
    init_scene();

    // set ranges for seed and goal exponent spin boxes
    // Seed has an arbitrary range,
    // The maximum value of the goal number is 2^(n*n), where n is the side of the of the board
    // but as a long int, it seems to overflow with an exponent of 63 or higher.
    // As such, the largest possible goal is either 2^(n*n) or 2⁶², whichever is smaller
    ui->seedSpinBox->setRange(-99999999, 99999999);
    int largestexponent = calculate_max_exp(gameboard_.side_of_board_);
    ui->exponentSpinBox->setRange(2, largestexponent);

    // range for board size. We will set sensical, yet arbitrary limits of 2 and 7.
    ui->boardsideSpinBox->setRange(2, 7);


    // set defaults
    ui->seedSpinBox->setValue(0);
    ui->exponentSpinBox->setValue(DEFAULT_EXPONENT_);
    ui->boardsideSpinBox->setValue(SIZE);

    // set window default color
    ui->centralwidget->setStyleSheet("background-color: white");

    // set victory- and defeat labels disabled
    ui->victoryLabel->setVisible(false);
    ui->defeatLabel->setVisible(false);

    // set movement disabled until game starts
    movement_disabled();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init_scene()
{
    // Make the scene of the gameboard and all it requires.
    // This must be called whenever the board size changes as well.

    // Scene is dynamically allocated, so it needs to be manually deleted.
    // init_scene is only called when the spin box for board side is changed in value
    // Thus, we'll make that slot delete current scene_
    scene_ = new QGraphicsScene(this);

    // data structure in which pointers to the box objects' labels are stored
    std::vector< std::vector< QLabel* > > labels;

    std::vector< std::vector<QGraphicsRectItem* > > rects;
    std::vector< std::vector<QGraphicsProxyWidget* > > widgets;

    // Set the visual board so that some borders are visible.
    // Board set to the 'middle' of the window, so that it expands outwards
    // and doesn't interfere with other gui elements
    ui->graphicsView->setGeometry(250, 120, (gameboard_.side_of_board_ * SQUARE_SIDE_) + 3,
                                  (gameboard_.side_of_board_ * SQUARE_SIDE_) + 3);
    ui->graphicsView->setScene(scene_);

    scene_->setSceneRect(0, 0, (gameboard_.side_of_board_ * SQUARE_SIDE_) - 1,
                         (gameboard_.side_of_board_ * SQUARE_SIDE_) - 1);

    QBrush yellowBrush(Qt::yellow);
    QPen blackPen(Qt::black);
    blackPen.setWidth(1);

    // Set colors for victory and defeat messages
    ui->victoryLabel->setStyleSheet("background-color : white");
    ui->defeatLabel->setStyleSheet("background-color : white");

    // Setup the actual board: rectangles, widgets with labels.
    for (int y = 0; y < gameboard_.side_of_board_ * SQUARE_SIDE_; )
    {
        std::vector< QLabel* > labelrow;
        std::vector< QGraphicsRectItem* > rectrow;
        std::vector< QGraphicsProxyWidget* > widgetrow;
        for (int x = 0; x < gameboard_.side_of_board_ * SQUARE_SIDE_; )
        {
            QGraphicsRectItem* rect = scene_->addRect(x, y, SQUARE_SIDE_,
                                                      SQUARE_SIDE_, blackPen, yellowBrush);

            // if parent set in these parentheses, cannot embed label to widget
            // But no valgrind error this way, so I guess deleting scene_ takes
            // care of these as well.
            QLabel* label = new QLabel();

            label->setStyleSheet("background-color : yellow;");
            label->setFixedWidth(SQUARE_SIDE_ - 4);
            label->setAlignment(Qt::AlignCenter);

            // I think deleting scene_ deletes the rects, so these as well
            QGraphicsProxyWidget* widget = new QGraphicsProxyWidget(rect);

            widget->setWidget(label);

            // this way the position is not irritating to a relatively normal human
            widget->setPos(x + 3, y + (SQUARE_SIDE_ / 2 - 10));

            labelrow.push_back(label);
            rectrow.push_back(rect);
            widgetrow.push_back(widget);

            x = x + SQUARE_SIDE_;
        }

        labels.push_back(labelrow);

        // not sure if these are needed, but im too afraid to remove them
        rects.push_back(rectrow);
        widgets.push_back(widgetrow);

        y = y + SQUARE_SIDE_;
    }

    boxlabels_ = labels;
    rects_ = rects;
    widgets_ = widgets;


}

void MainWindow::update_scene()
{
    // This function makes it so that each square object on the board
    // has the corresponding value of the number tile it represents.
    // So essentially, it updates the scene of the board on the gui.
    // In effect, the text of the labels is changed.
    // This is called when a changed that must be seen is made.

    int last_row_of_column_index = gameboard_.side_of_board_ - 1;
    for (int rowindex = 0; rowindex <= last_row_of_column_index; ++rowindex)
    {

        for (int columnindex = 0; columnindex <= last_row_of_column_index; ++columnindex)
        {
            // get the tile's value
            std::pair<int, int> coordpair(rowindex, columnindex);
            NumberTile* tile = gameboard_.get_item(coordpair);
            int tilevalue = tile->get_value();

            // turn tile's value into qstring, update label text
            // unless value is 0.
            // if 0, set to empty
            QLabel* label = boxlabels_.at(rowindex).at(columnindex);

            if (tilevalue > 0) {
                std::string valuestring = std::to_string(tilevalue);

                QString newlabeltext = QString::fromStdString(valuestring);
                label->setText(newlabeltext);
            }
            else
            {
                label->setText("");
            }
        }
    // this is done to update scene during runtime?
    QCoreApplication::processEvents();
    }

}

void MainWindow::reset_scene()
{
    // We want to empty all the labels on the scene, but not delete and remake NumberTiles.

    int last_row_of_column_index = gameboard_.side_of_board_ - 1;

    for (int rowindex = 0; rowindex <= last_row_of_column_index; ++rowindex)
    {

        //std::cout << "rowindex " << rowindex << std::endl;

        for (int columnindex = 0; columnindex <= last_row_of_column_index; ++columnindex)
        {

            //std::cout << "columnindex " << columnindex << std::endl;

            QLabel* label = boxlabels_.at(rowindex).at(columnindex);
            label->setText("");

        }
    }

}

void MainWindow::settings_disabled()
{
    ui->startPushButton->setEnabled(false);
    ui->boardsideSpinBox->setEnabled(false);
    ui->exponentSpinBox->setEnabled(false);
    ui->seedSpinBox->setEnabled(false);
}

void MainWindow::settings_enabled()
{
    ui->startPushButton->setEnabled(true);
    ui->boardsideSpinBox->setEnabled(true);
    ui->exponentSpinBox->setEnabled(true);
    ui->seedSpinBox->setEnabled(true);
}

void MainWindow::movement_disabled()
{
    ui->upPushButton->setEnabled(false);
    ui->downPushButton->setEnabled(false);
    ui->leftPushButton->setEnabled(false);
    ui->rightPushButton->setEnabled(false);
}

void MainWindow::movement_enabled()
{
    ui->upPushButton->setEnabled(true);
    ui->downPushButton->setEnabled(true);
    ui->leftPushButton->setEnabled(true);
    ui->rightPushButton->setEnabled(true);
}



void MainWindow::fill_board()
{
    // We fill the board so playing can start.
    // This is called only if it's the first game start for this instance of current
    // board size setting. Else, gameboard_.fill_existing is used

    gameboard_.fill(userseed_);

}

void MainWindow::move_and_check(Coords dir)
{
    // The user has chosen their move. Move is made,
    // game status is checked. Relevant things are shown to user.
    bool victorystatus = gameboard_.move(dir, goalnumber_);
    update_scene();

    if (victorystatus)
    {
        // game was won
        ui->victoryLabel->setVisible(true);
        ui->centralwidget->setStyleSheet("background-color: green");
        movement_disabled();
        return;
    }
    else if (gameboard_.is_full())
    {
        // game was lost, board full and not won
        ui->defeatLabel->setVisible(true);
        ui->centralwidget->setStyleSheet("background-color: red");
        movement_disabled();
        return;
    }

    gameboard_.new_value(false);
    update_scene();

}

int MainWindow::calculate_max_exp(int board_size)
{
    // Max exponent is either 62 or boardsize², whichever is smaller.
    // This way game is in theory winnable, and no integer overflow
    int calcexp = std::pow(board_size, 2);
    int maxexp_before_overflow = 62;
    if (calcexp > 62) {
        return maxexp_before_overflow;
    } else {
        return calcexp;
    }
}

void MainWindow::calculate_goal()
{
    // The user enters the exponent of 2 which corresponds to the
    // wanted goal number. This method calculates that goal number.

    goalnumber_ = std::pow(2, userexponent_);
}


void MainWindow::on_seedSpinBox_valueChanged()
{
    // user changed seed
    userseed_ = ui->seedSpinBox->value();

}


void MainWindow::on_exponentSpinBox_valueChanged()
{
    // Not only is the goal calculated, but also
    // displayed to the user in a label.
    // No math required.
    userexponent_ = ui->exponentSpinBox->value();
    calculate_goal();

    std::string goalstring = std::to_string(goalnumber_);
    QString goalqstring = QString::fromStdString(goalstring);
    ui->goalLabel->setText(goalqstring);
}


void MainWindow::set_gameboard_size()
{
    // Sets the gameboard size as the number that the user
    // has chosen in the relevant spinbox.
    // gameboard_.side_of_board_ has been made integral
    // for the given base code, so it is heavily used.

    int side = ui->boardsideSpinBox->value();
    gameboard_.side_of_board_ = side;

    // Since size has changed, goal limit will too.
    int largestexponent = calculate_max_exp(gameboard_.side_of_board_);
    ui->exponentSpinBox->setRange(2, largestexponent);
    ui->exponentSpinBox->setValue(DEFAULT_EXPONENT_);

}


void MainWindow::on_startPushButton_clicked()
{
    // This will set the size of the gameboard,
    // and effectively start the game.
    // Depending on whether the board has already been
    // initialized in this size, a different method is used,
    // so that when user resets, NumberTile -instances are not remade.

    if (first_board_)
    {
        fill_board();
        first_board_ = false;

    }
    else
    {
        gameboard_.fill_existing();
    }

    update_scene();

    // limit user from doing bad things
    settings_disabled();
    movement_enabled();
}


void MainWindow::on_boardsideSpinBox_valueChanged()
{
    // So that the goal's limits can be correctly calculated,
    // the board's side must be set immediately after editing
    // init_empty clears the board's datastructure and fills it with
    // nullptrs.
    // Since board size was changed, tiles must be redone.

    // delete dynamically allocated scene, since this method makes a new one
    delete scene_;

    set_gameboard_size();
    gameboard_.init_empty();
    first_board_ = true;
    init_scene();

}


void MainWindow::on_resetButton_clicked()
{
    // We reset the game. The NumberTiles remain as is,
    // we only change the objects on the gui.
    // NumberTiles changed on next game start, unless board size is changed.
    reset_scene();

    // Limiting user for the good of all
    settings_enabled();
    movement_disabled();

    // hide game state labels again and reset color, in case
    // user ended previous round by win or loss
    ui->victoryLabel->setVisible(false);
    ui->defeatLabel->setVisible(false);
    ui->centralwidget->setStyleSheet("background-color: white");
}


void MainWindow::on_upPushButton_clicked()
{
    move_and_check(UP);
}


void MainWindow::on_leftPushButton_clicked()
{
    move_and_check(LEFT);
}


void MainWindow::on_downPushButton_clicked()
{
    move_and_check(DOWN);
}


void MainWindow::on_rightPushButton_clicked()
{
    move_and_check(RIGHT);
}

