#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("U:/test1/logoimg.PNG");
    ui->logo_pic->setPixmap(pix.scaled(150,150,Qt::KeepAspectRatio));

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
    hide();
    registerWin=new Registerwin(this);
    registerWin->show();
}

void MainWindow::on_pushButton_clicked()
{
    hide();
    loginWin = new loginwin(this);
    loginWin->setFixedSize(763,424);
    loginWin->show();
}
