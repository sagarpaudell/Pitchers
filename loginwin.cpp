#include "loginwin.h"
#include "ui_loginwin.h"
#include "mainwindow.h"
#include "registerwin.h"
loginwin::loginwin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::loginwin)
{
    ui->setupUi(this);
}

loginwin::~loginwin()
{
    delete ui;
}

void loginwin::on_pushButton_clicked()
{
    QString ID = ui->id->text();
    QString Pass = ui->pass->text();
    if(ID=="RECOMOVIES" && Pass == "RECOMOVIES" ){
           hide();
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
      query.prepare(QString("SELECT * FROM user WHERE firstname = :username AND pass = :password"));
      query.bindValue(":username",ID);
      query.bindValue(":password",Pass);
            if(!query.exec()){

                 QMessageBox::information(this,"Failed","query failed to execute");

            }
            else {
                     while (query.next()) {
                         QString usernamefromDB = query.value(1).toString();
                         QString passwordfromDB = query.value(4).toString();
                             if(usernamefromDB == ID && passwordfromDB == Pass){
                                 QMessageBox::information(this,"Success","Login success");
                                 hide();
                                 clientwin = new ClientWin(this);
                                 clientwin->show();
                              }
                     }
             }

    }
    else {
             QMessageBox::information(this,"db connection","login insertion failed");
    }


//    if(ID=="RECOMOVIES" && Pass == "RECOMOVIES" ){
//        hide();
//        adminwin = new AdminWin(this);
//        adminwin->show();}
//    else if(ID=="user" && Pass == "user" ){
//                hide();
//                clientwin = new ClientWin(this);
//                clientwin->show();
//}
}
