#include "mainwindow.hh"

#include <QApplication>

/* COMP.CS.110
 * Projecti 'Peli nimeltä 2048'
 * Opiskelija: Eetu Luoma
 * Email: eetu.luoma@tuni.fi
 * Opiskelijanumero: K444309
 *
 * Täällä luodaan pelilautaolio, ikkunaolio, aloitetaan ikkuna
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GameBoard gameboard;
    gameboard.init_empty();

    MainWindow window(gameboard);

    window.show();

    return a.exec();
}
