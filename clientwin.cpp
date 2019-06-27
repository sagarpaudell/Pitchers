#include "clientwin.h"
#include "ui_clientwin.h"
#include "mainwindow.h"
#include  "loginwin.h"
ClientWin::ClientWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientWin)
{
    ui->setupUi(this);
}

ClientWin::~ClientWin()
{
    delete ui;
}
void ClientWin::on_pushButton_clicked()
{

    hide();
    /*loginwin *loginWin;
    loginWin = new loginwin(this);
    loginWin->setFixedSize(763,424);
    loginWin->show();*/
    MainWindow *mainwindow;
    mainwindow = new MainWindow(this);
    mainwindow->setFixedSize(763,424);
    mainwindow->show();

}
