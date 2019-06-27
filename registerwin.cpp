#include "registerwin.h"
#include "ui_registerwin.h"
#include "mainwindow.h"
#include <QMessageBox>

Registerwin::Registerwin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Registerwin)
{
    ui->setupUi(this);
}

Registerwin::~Registerwin()
{
    delete ui;
}

void Registerwin::on_pushButton_2_clicked()
{
    hide();
    mainWindow = new MainWindow(this);
    mainWindow->setFixedSize(763,424);
    mainWindow->show();
}
bool isEmpty(QString string){
    if(string == "" || string ==" "|| string =="  ")return true;
            else return false;
}
void Registerwin::on_pushButton_clicked()
{
    QString F_name = ui->FirstName->text();
    QString L_name = ui->lastname->text();
    QString Email  = ui->Email->text();
    QString Password = ui->password->text();
    QString Re_Password = ui->repassword->text();
    if(isEmpty(F_name)){QMessageBox::warning(this,"Sign Up Error!","User name empty!");}
            else if(isEmpty(L_name)){QMessageBox::information(this,"Sign Up Error!","User name empty!");}
            else if(isEmpty(Email)){QMessageBox::information(this,"Sign Up Error!","Email name empty!");}
            else if(isEmpty(Password)){QMessageBox::information(this,"Sign Up Error!","Password name empty!");}
            else if(isEmpty(Re_Password)){QMessageBox::information(this,"Sign Up Error!","Re-enter password!");}
            else if(Password!=Re_Password){QMessageBox::warning(this,"Sign Up Error!","Passowrds do not match!");}
            else QMessageBox::information(this,"Dialog","WELCOME");


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
        query.prepare("INSERT INTO user(firstname,lastname,email,pass,repass)"
                     " VALUES(:Fv_name,:L_name,:Email,:Password,:Re_Password)");
        query.bindValue(":Fv_name",F_name);
        query.bindValue(":L_name",L_name);
        query.bindValue(":Email",Email);
        query.bindValue(":Password",Password);
        query.bindValue(":Re_Password",Re_Password);
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

}
