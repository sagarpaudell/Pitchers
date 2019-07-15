#include "regwin.h"
#include "ui_regwin.h"
#include "mainwindow.h"
#include  "loginwin.h"
#include  "adminwin.h"
#include  "clientwin.h"
#include <QMessageBox>

regwin::regwin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::regwin)
{
    ui->setupUi(this);

}

regwin::~regwin()
{
    delete ui;
}

void regwin::on_signin_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
bool isEmpty(QString string){
    if(string == "" || string ==" "|| string =="  ")return true;
            else return false;
}
void regwin::on_joinButton_clicked()
{

    QString F_name = ui->firstname->text();
    QString L_name = ui->lastname->text();
    QString Email  = ui->email->text();
    QString Password = ui->pass->text();
    QString Re_Password = ui->repass->text();
    QString username = ui->user_name->text();
    QString nationality = ui->nationality->text();
    QString sex;
    if(ui->male->isCheckable()){
        sex="male";
    }
   if (ui->female->isCheckable()) {
        sex="female";

    }



    if(isEmpty(F_name)){QMessageBox::warning(this,"Sign Up Error!","User name empty!");}
            else if(isEmpty(L_name)){QMessageBox::information(this,"Sign Up Error!","User name empty!");}
            else if(isEmpty(Email)){QMessageBox::information(this,"Sign Up Error!","Email name empty!");}
            else if(isEmpty(Password)){QMessageBox::information(this,"Sign Up Error!","Password name empty!");}
            else if(isEmpty(Re_Password)){QMessageBox::information(this,"Sign Up Error!","Re-enter password!");}
            else if(Password!=Re_Password){QMessageBox::warning(this,"Sign Up Error!","Passowrds do not match!");}
    else{
        QMessageBox::information(this,"Dialog","WELCOME");


    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("registration");
    if(db.open()){
        //create queries here.
//        run input queries
        QSqlQuery query;
        query.prepare("INSERT INTO user(username,firstname,lastname,sex,email,pass,repass,nationality)"
                     " VALUES(:username,:Fv_name,:L_name,:sex,:Email,:Password,:Re_Password,:Nationality)");
        query.bindValue(":username",username);
        query.bindValue(":Fv_name",F_name);
        query.bindValue(":L_name",L_name);
        query.bindValue(":sex",sex);
        query.bindValue(":Email",Email);
        query.bindValue(":Password",Password);
        query.bindValue(":Re_Password",Re_Password);
        query.bindValue(":Nationality",nationality);
        if(query.exec()){
            QMessageBox::information(this,"db connection","values inserted");
        }
        else {
             QMessageBox::information(this,"db connection","values insertion failed");
        }
     QMessageBox::information(this,"db connection","db connected");
    }
    else{
        QMessageBox::information(this,"db connection","db not connected");
    }
    db.close();
  }
    hide();
    MainWindow *mainwindow;
    mainwindow = new MainWindow(this);
    mainwindow->setFixedSize(763,424);
    mainwindow->show();
}

void regwin::on_signupButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void regwin::on_loginButton_clicked()
{
    QString ID = ui->username->text();
    QString Pass = ui->password->text();
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
                                 hide();
                                 clientwin = new ClientWin(this);
                                 clientwin->show();
                              }
                     }

            }

    db.close();
    }
    else {
             QMessageBox::information(this,"db connection","login insertion failed");
    }


    if(ID=="RECOMOVIES" && Pass == "RECOMOVIES" ){
        hide();
        adminwin = new AdminWin(this);
        adminwin->show();}
    else if(ID=="user" && Pass == "user" ){
                hide();
                clientwin = new ClientWin(this);
                clientwin->show();
}
}


void regwin::on_backButton_clicked()
{
    hide();
    mainWindow = new MainWindow(this);
    mainWindow->setFixedSize(763,424);
    mainWindow->show();
}



void regwin::on_birthdate_userDateChanged(const QDate &date)
{

}
