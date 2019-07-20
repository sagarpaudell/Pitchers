#include "loginwin.h"
#include "ui_loginwin.h"
#include "mainwindow.h"
#include "movie_manager.h"
#include<QMovie>

extern QString ID;
loginwin::loginwin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::loginwin)
{
    ui->setupUi(this);
    connect(ui->password, SIGNAL(returnPressed()),ui->loginButton,SIGNAL(clicked()));
    QMovie *movie = new QMovie(":/img/welcome.gif");
    ui->welcomelabel->setMovie(movie);
    ui->welcomelabel->setScaledContents( true );

    ui->welcomelabel->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

    movie->start();
}

loginwin::~loginwin()
{
    delete ui;
}

void loginwin::on_loginButton_clicked()
{
    QString ID = ui->username->text();
    QString Pass = ui->password->text();
    if(ID=="RECOMOVIES" && Pass == "RECOMOVIES" ){
           close();
           adminwin = new AdminWin(this);
           adminwin->show();}
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("registration");
    if(db.open()){

        //creating database queries
      QSqlQuery query;
      query.prepare(QString("SELECT * FROM user WHERE username = :username AND pass = :password"));
      query.bindValue(":username",ID);
      query.bindValue(":password",Pass);
            if(!query.exec()){

                 QMessageBox::information(this,"Failed","query failed to execute");

            }
            else {
                     while (query.next()) {
                         QString usernamefromDB = query.value(1).toString();
                         QString passwordfromDB = query.value(6).toString();
                             if(usernamefromDB == ID && passwordfromDB == Pass){


                                 QMessageBox::information(this,"Success","Login success");
                                 close();
                                 clientwin = new ClientWin(this,ID);
                                 clientwin->show();
                              }
                     }

             }
    db.close();
    }
    else {
             QMessageBox::information(this,"db connection","login insertion failed");
    }


//    if(ID=="RECOMOVIES" && Pass == "RECOMOVIES" ){
//        close();
//        adminwin = new AdminWin(this);
//        adminwin->show();}
//    else if(ID=="user" && Pass == "user" ){
//                close();
//                clientwin = new ClientWin(this);
//                clientwin->show();
//}
}




void loginwin::on_signupButton_clicked()
{
//    QSignalMapper* m_sigmapper = new QSignalMapper(this);
//    connect(button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
//    m_sigmapper->setMapping(button,movienameString);
//    connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
    this->close();
    QWidget *parent = this->parentWidget();
    parent->show();






}
