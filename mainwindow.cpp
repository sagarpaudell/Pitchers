#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}
MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_3_clicked()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_2_clicked()
{
     close();
     regWin = new regwin(this);
     regWin->setFixedSize(763,424);
     regWin->show();



//    registerWin=new Registerwin(this);
//    registerWin->setFixedSize(763,424);
//    registerWin->show();
}

void MainWindow::on_pushButton_clicked()
{
    close();
    loginWin = new loginwin(this);
    loginWin->setFixedSize(763,424);
    loginWin->show();
}
