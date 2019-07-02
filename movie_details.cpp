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
      query.prepare(QString("SELECT * FROM horror WHERE moviename = :movietitle"));
      query.bindValue(":moviename","Wilding");

      if(query.exec()){
              qDebug() <<query.value(2);
                     while (query.next()) {
                         ui->label->setText(query.value(2).toString());
                     }
       }
      else{
               qDebug() << query.lastError().text();
      }
     db.close();
    }
}
Movie_Details::~Movie_Details()
{
    delete ui;
}
