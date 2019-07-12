#include "adminwin.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AdminWin w;
    w.show();

    return a.exec();
}
