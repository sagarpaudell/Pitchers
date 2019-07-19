#include "adminwin.h"
#include "ui_adminwin.h"
#include  "mainwindow.h"
AdminWin::AdminWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminWin)
{
    ui->setupUi(this);
}

AdminWin::~AdminWin()
{
    delete ui;
}

void AdminWin::on_pushButton_clicked()
{
    hide();
    MainWindow *mainwindow;
    mainwindow = new MainWindow(this);
    mainwindow->setFixedSize(763,424);
    mainwindow->show();
}
