#include "clientwin.h"
#include "ui_clientwin.h"
#include "mainwindow.h"
#include  "loginwin.h"
ClientWin::ClientWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientWin)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

ClientWin::~ClientWin()
{
    delete ui;
}

//void ClientWin::on_pushButton_clicked()
//{

//    hide();
//    /*loginwin *loginWin;
//    loginWin = new loginwin(this);
//    loginWin->setFixedSize(763,424);
//    loginWin->show();*/
//    MainWindow *mainwindow;
//    mainwindow = new MainWindow(this);
//    mainwindow->setFixedSize(763,424);
//    mainwindow->show();

//}






void ClientWin::on_home_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void ClientWin::on_mostrated_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void ClientWin::on_action_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void ClientWin::on_adventure_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void ClientWin::on_crime_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void ClientWin::on_drama_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void ClientWin::on_romance_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}
void ClientWin::on_casblanca_clicked()
{
    hide();
    movie_details =new Movie_Details(this);
    movie_details->show();

}
