#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <gameboard.hh>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QLabel>


/* COMP.CS.110
 * Projecti 'Peli nimeltä 2048'
 * Opiskelija: Eetu Luoma
 * Email: eetu.luoma@tuni.fi
 * Opiskelijanumero: K444309
 *
 * Täällä paljon oleellista asiaa. Katso tämän headerin,
 * tämän headerin cpp tiedoston kommentointeja sekä cpp tiedoston
 * docstringiä, sekä dokumentointia.
 *
 *
 *
 */



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(GameBoard gameboard, QWidget *parent = nullptr);
    ~MainWindow();



private slots:

    // When the user gives the seed and indirectly the goal value,
    // those numbers are saved to private variables
    void on_seedSpinBox_valueChanged();
    void on_exponentSpinBox_valueChanged();

    // starts the game.
    void on_startPushButton_clicked();

    // The side of the board is set into a variable,
    // so the upper limit of goal can be calculated
    // before starting the game.
    void on_boardsideSpinBox_valueChanged();


    // bunch of slots for the push buttons,
    // functionality commented to .cpp
    void on_resetButton_clicked();

    void on_upPushButton_clicked();

    void on_leftPushButton_clicked();

    void on_downPushButton_clicked();

    void on_rightPushButton_clicked();

private:
    Ui::MainWindow *ui;

    // initializes the QGraphicsScene scene
    void init_scene();

    // updates the scene to the current state of board
    void update_scene();

    // resets the scene, emptying the tile labels
    void reset_scene();

    // sets various gui elements to disabled state
    void settings_disabled();

    // sets various gui elements to enabled state
    void settings_enabled();

    // sets movement to disabled state
    void movement_disabled();

    //sets movement to enabled state
    void movement_enabled();

    // fills the board (only for the first time)
    void fill_board();

    // Makes the move the user input happen,
    // checks for win or loss
    void move_and_check(Coords dir);

    // method to indirectly set gameboard size
    void set_gameboard_size();

    // calculates max exponent for 2, to get a goal number
    int calculate_max_exp(int boardside);

    // the goal number is calculated in a private method
    void calculate_goal();

    // for 2048
    const int DEFAULT_EXPONENT_ = 11;

    // side of a square object on the board.
    // chosen so it can fit a large number
    const int SQUARE_SIDE_ = 100;

    // Store all, im scared
    std::vector< std::vector<QLabel* > > boxlabels_;
    std::vector< std::vector<QGraphicsRectItem* > > rects_;
    std::vector< std::vector<QGraphicsProxyWidget* > > widgets_;

    // view for the game hex
    QGraphicsScene* scene_;


    // private variables for the seed and goal
    int userseed_ = 0;
    int userexponent_;

    // private variable for the side of the gameboard
    // as entered by the user.
    // int side_of_gameboard_;
    GameBoard gameboard_;

    // the goal number which is calculated in calculate_goal
    long int goalnumber_;

    // bool to see if a board has been already filled
    bool first_board_ = true;



};
#endif // MAINWINDOW_HH
