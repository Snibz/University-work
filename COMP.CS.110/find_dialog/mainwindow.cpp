#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    connect(ui->fileLineEdit, &QLineEdit::editingFinished,
            this, &MainWindow::on_fileLineEdit_editingFinished);

    connect(ui->keyLineEdit, &QLineEdit::editingFinished,
            this, &MainWindow::on_keyLineEdit_editingFinished);

    connect(ui->findPushButton, &QPushButton::clicked,
            this, &MainWindow::on_findPushButton_clicked);



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_fileLineEdit_editingFinished()
{
    QString text = ui->fileLineEdit->text();
    filename = text.toStdString();
}


void MainWindow::on_keyLineEdit_editingFinished()
{
    QString text = ui->keyLineEdit->text();
    keyword = text.toStdString();
}


void MainWindow::on_findPushButton_clicked()
{
    // "File not found", if file isn't found
    // "File found", if file found but key not given
    // "Word not found" if file found, key given but not in file
    // "Word found" if file found, key given in file

    // If matchbox ischecked is true, then the inputs are case sensitive

    find_word();
}

std::string MainWindow::to_lower(std::string word)
{
    // converts all chars in word to lower
    std::string lowerword;
    for ( auto character : word ) {
        lowerword.push_back(tolower(character));
    }

    return lowerword;
}


void MainWindow::find_word()
{
    if (ui->matchCheckBox->isChecked() == false) {
        // case doesn't matter. I assume we use lowercase
        filename = to_lower(filename);
        keyword = to_lower(keyword);
    }

    std::ifstream file(filename);
    if ( not file ) {
        // continue here. outputs for the text box, readin the file
        QString openerror = "File not found";
        ui->textBrowser->setPlainText(openerror);
    } else {
        // file was opened successfully

        if ( keyword.empty() ) {
            QString emptyerror = "File found";
            ui->textBrowser->setPlainText(emptyerror);
        } else {
            // file open, keyword was given.
            // Now to read file and look for keyword
            QString foundtext = "Word found";
            QString notfoundtext = "Word not found";

            std::size_t found = std::string::npos;
            std::string row;

            while ( getline(file, row) ) {
                found = row.find(keyword);
                if ( found != std::string::npos ) {
                    // keyword was found
                    ui->textBrowser->setPlainText(foundtext);
                    break;
                } else {
                    continue;
                }
            }

            if ( found == std::string::npos ) {
                ui->textBrowser->setPlainText(notfoundtext);
            }


        }

    }
    file.close();

}
