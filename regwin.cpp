#include "regwin.h"
#include "ui_regwin.h"
#include "mainwindow.h"
#include  "loginwin.h"
#include  "adminwin.h"
#include  "clientwin.h"
#include  "movie_manager.h"
#include <QMessageBox>

regwin::regwin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::regwin)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

}

regwin::~regwin()
{
    delete ui;
}
void regwin::on_signin_clicked()
{
    close();
    loginWin = new loginwin(this);
    loginWin->show();
  //  ui->stackedWidget->setCurrentIndex(1);
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
    QString agevalue = ui->agebox->currentText();
    int age =agevalue.toInt();

    if(isEmpty(F_name)){QMessageBox::warning(this,"Sign Up Error!","User name empty!");}
            else if(isEmpty(L_name)){QMessageBox::information(this,"Sign Up Error!","User name empty!");}
            else if(isEmpty(Email)){QMessageBox::information(this,"Sign Up Error!","Email name empty!");}
            else if(isEmpty(Password)){QMessageBox::information(this,"Sign Up Error!","Password name empty!");}
            else if(isEmpty(Re_Password)){QMessageBox::information(this,"Sign Up Error!","Re-enter password!");}
            else if(Password!=Re_Password){QMessageBox::warning(this,"Sign Up Error!","Passowrds do not match!");}
    else{

        DbManager db("registration");
        if(db.doesuserExits(username)){
               QMessageBox::information(this,"Oops!","The Username is taken!");
        }
        else {
            QSqlQuery query;
            query.prepare("INSERT INTO user(username,firstname,lastname,sex,email,pass,repass,nationality,age)"
                         " VALUES(:username,:Fv_name,:L_name,:sex,:Email,:Password,:Re_Password,:Nationality,:Age)");
            query.bindValue(":username",username);
            query.bindValue(":Fv_name",F_name);
            query.bindValue(":L_name",L_name);
            query.bindValue(":sex",sex);
            query.bindValue(":Email",Email);
            query.bindValue(":Password",Password);
            query.bindValue(":Re_Password",Re_Password);
            query.bindValue(":Nationality",nationality);
            query.bindValue(":Age",age);
            if(query.exec()){
                QMessageBox::information(this,"Congratulations","Registration Successful");
            }
            else {
                 QMessageBox::information(this,"oops!","values insertion failed");
            }
            this->close();
            QWidget *parent = this->parentWidget();
            parent->show();
      }
   }

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
        close();
        adminwin = new AdminWin(this);
        adminwin->show();}
    else if(ID=="user" && Pass == "user" ){
                close();
                clientwin = new ClientWin(this);
                clientwin->show();
}
}


void regwin::on_backButton_clicked()
{
    close();
    mainWindow = new MainWindow(this);
    mainWindow->setFixedSize(763,424);
    mainWindow->show();
}


