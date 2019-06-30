#include "movie_details.h"
#include "ui_movie_details.h"
#include "mainwindow.h"

Movie_Details::Movie_Details(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Movie_Details)
{
    ui->setupUi(this);
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("movies");
    if(db.open()){

        //creating database queries
      QSqlQuery query;
      query.prepare(QString("SELECT * FROM romance WHERE moviename = :movietitle"));
      query.bindValue(":moviename","Casablanca");

      if(!query.exec()){

                 QMessageBox::information(this,"Failed","query failed to execute");

            }
            else {  qDebug() << query.value(3);
                     while (query.next()) {
                         ui->synopsis->setText(query.value(3).toString());

                     }
            }
    }
}

Movie_Details::~Movie_Details()
{
    delete ui;
}
