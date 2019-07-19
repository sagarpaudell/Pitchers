#include "adminwin.h"
#include "ui_adminwin.h"
#include "mainwindow.h"
#include "movie_manager.h"
AdminWin::AdminWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminWin)
{
    ui->setupUi(this);
    QPixmap pix("/Users/Public/Pictures/Sample Pictures/");
    ui->piclabel->setPixmap(pix);
    ui->stackedWidget->setCurrentIndex(0);
    ui->piclabel->setVisible(false);
}

AdminWin::~AdminWin()
{
    delete ui;
}
bool AdminWin::isEmpty(const QString& str)const{
    if(str == "" || str == " ") return true;
    return false;
}
void AdminWin::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void AdminWin::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void AdminWin::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void AdminWin::on_pushButton_4_clicked()
{
    hide();
    //mainwindow = new mainwindow(this);
    //mainwindow->centralWidget()->show();
}

void AdminWin::on_add_clicked(const QString fileName)
{

      DbManager db("moviedataset");
//    //Connecting to Mysql Database
//    database=QSqlDatabase::addDatabase("QMYSQL");
//    database.setHostName("Localhost");
//    database.setUserName("root");
//    database.setPassword("");
//    database.setDatabaseName("");
//    database.open();

//    if(database.open())
//    {

        //Retrieve Data from Input Fields
        QString title = ui->title->text();
        QString year = ui->year->text();
        QString director = ui->director->text();
        QString imdb = ui->imdb->text();
        QString genre = ui->genre->text();
        QString cast = ui->cast->toPlainText();
        QString synopsis = ui->synopsis->toPlainText();
        bool check = db.doesmovieExits(title);
       if(!check){
        //Run our Query
        QSqlQuery qry("SELECT * FROM imdb");
        qry.prepare("INSERT INTO imdb(title,year,director,imdb,genre,cast,synopsis,image)""VALUES(:title,:year,:director,:imdb,:genre,:cast,:synopsis,:image)");
        qry.bindValue(":title",title);
        qry.bindValue(":year",year);
        qry.bindValue(":director",director);
        qry.bindValue(":imdb",imdb);
        qry.bindValue(":genre",genre);
        qry.bindValue(":cast",cast);
        qry.bindValue(":synopsis",synopsis);
        QByteArray byte;
        QFile file(fileName);
        if(file.open(QIODevice::ReadOnly))
        {
            byte = file.readAll();
            file.close();
        }
       else QMessageBox :: critical(this,"Error",fileName);
        qry.bindValue(":image",byte);
        if(qry.exec())
        {
             QMessageBox :: information(this,"Save","Data Inserted successfully", QMessageBox ::Ok);
        }
        else
        {
             QMessageBox :: critical(this,"Error","Couldn't insert data");
             qDebug()<<synopsis<<qry.lastError();
        }
       }
       else {
                QMessageBox :: warning(this,"Error","The Movie already Exists!");
       }

}

void AdminWin::on_browse_clicked()
{
    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
    dialog.setViewMode(QFileDialog::Detail);
    QString fileName = QFileDialog::getOpenFileName(this,
    tr("Open Images"), "/Users/Public/Pictures/Sample Pictures", tr("Image Files (*.png *.jpg *.bmp)"));
    if (!fileName.isEmpty())
    {
           QImage image(fileName);

           ui->piclabel->setPixmap(QPixmap::fromImage(image));
           ui->piclabel->setFixedSize(131,181);
           ui->piclabel->setVisible(true);

    }
           on_add_clicked(fileName);

}

void AdminWin::on_clear_clicked()
{
//    QPixmap pix("/Users/Public/Pictures/Sample Pictures/");
    ui->piclabel->clear();
    ui->title->clear();
    ui->year->text();
    ui->director->clear();
    ui->imdb->clear();
    ui->genre->clear();
    ui->cast->clear();
    ui->synopsis->clear();

}

void AdminWin::on_show_clicked()
{

//        QSqlQueryModel * modal = new QSqlQueryModel();
//       // QSqlQuery* qry = new QSqlQuery(conn.database);
//        //qry->prepare("select user from usertable  where NAME='" +ui->lineEdit->text()+ "'");
//        qry->exec();
//        modal->setQuery(*qry);
//       // ui->tableView->setModel(modal);
}

void AdminWin::on_addmovies_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void AdminWin::on_removemovies_button_clicked()
{
      ui->stackedWidget->setCurrentIndex(3);
}

void AdminWin::on_userlist_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    DbManager db("registration");
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery();
    qry->prepare("SELECT username ,firstname ,lastname,email ,pass ,sex ,nationality ,age  FROM user");
    qry->exec();
    modal->setQuery(*qry);

     ui->tableView->setModel(modal);
   //  ui->tableView->setColumnHidden(1,true);
    // ui->tableView->setColumnHidden(8,true);
}

void AdminWin::on_logout_button_clicked()
{
    this->close();
    QWidget *parent = this->parentWidget();
    parent->show();

//      this->close();
//      MainWindow *mainwindow1 = new MainWindow(this);
//      mainwindow1->show();
}

void AdminWin::on_removemovies_button_2_clicked()
{
    QString movieName = ui->rem_mov->text();
    if(isEmpty(movieName)){
        qDebug("the movie title is empty. provide the valid title");
    }else{
            DbManager db("moviedataset");
        if(!db.doesmovieExits(movieName)){
            //Item donot exist show message
            qDebug()<<"Given Item doesn't exist";\
              QMessageBox :: warning(this,"Invalid","The Movie doesnt exist. provide the valid username", QMessageBox ::Ok);
        }else{
            //remove the data
            db.removemovie(movieName);
            QMessageBox :: information(this,"Removed","+movieName+ Removed successfully", QMessageBox ::Ok);
//            this->close();
//            QWidget *parent = this->parentWidget();
//            parent->show();
        }

    }
}

void AdminWin::on_remove_user_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void AdminWin::on_removeuser_button_clicked()
{
    QString userName = ui->rem_user->text();
    if(isEmpty(userName)){
        qDebug("the username is empty. provide the valid username");\
        QMessageBox :: warning(this,"Invalid","The username is empty. provide the valid username", QMessageBox ::Ok);

    }else{
            DbManager db("registration");
        if(!db.doesuserExits(userName)){
            //User donot exist show message
            qDebug()<<"Given Username doesn't exist";
              QMessageBox :: warning(this,"Invalid","The username doesnot exist. provide the valid username", QMessageBox ::Ok);
        }else{
            //remove the data
            db.removemovie(userName);
            QMessageBox :: information(this,"Removed","+userName+ Removed successfully", QMessageBox ::Ok);
//            this->close();
//            QWidget *parent = this->parentWidget();
//            parent->show();
        }

    }
}
