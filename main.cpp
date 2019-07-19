#include <QApplication>
#include <QLabel>
#include <QTextEdit>
#include <QTextEdit>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("RECOMOVIES");
    //w.setFixedSize(763,424);
    w.show();

    return a.exec();


}
