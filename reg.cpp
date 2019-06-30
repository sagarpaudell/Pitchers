#include "reg.h"
#include "ui_reg.h"
#include "mainwindow.h"

Reg::Reg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Reg)
{
    ui->setupUi(this);
}

Reg::~Reg()
{
    delete ui;
}
