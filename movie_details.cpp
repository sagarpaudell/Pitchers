#include "movie_details.h"
#include "ui_movie_details.h"
#include "mainwindow.h"

Movie_Details::Movie_Details(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Movie_Details)
{
    ui->setupUi(this);


}
Movie_Details::~Movie_Details()
{
    delete ui;
}
