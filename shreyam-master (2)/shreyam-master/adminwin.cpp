#include "adminwin.h"
#include "ui_adminwin.h"

AdminWin::AdminWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminWin)
{
    ui->setupUi(this);
    QPixmap pix("/Users/Public/Pictures/Sample Pictures/");
    ui->piclabel->setPixmap(pix);
    ui->stackedWidget->setCurrentIndex(0);

}

AdminWin::~AdminWin()
{
    delete ui;
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

void AdminWin::on_add_clicked()
{
    //Connecting to Mysql Database
    database=QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("Localhost");
    database.setUserName("root");
    database.setPassword("");
    database.setDatabaseName("a");
    database.open();

    if(database.open())
    {

        //Retrieve Data from Input Fields
        QString title = ui->title->text();
        QString year = ui->year->text();
        QString director = ui->director->text();
        QString imdb = ui->imdb->text();
        QString genre = ui->genre->text();
        QString cast = ui->cast->toPlainText();
        QString synopsis = ui->synopsis->toPlainText();

        //Run our Query
        QSqlQuery qry;
        qry.prepare("INSERT INTO a(title,year,director,imdb,genre)""VALUES(:title,:year,:director,:imdb,:genre)");
        qry.bindValue(":title",title);
        qry.bindValue(":year",year);
        qry.bindValue(":director",director);
        qry.bindValue(":imdb",imdb);
        qry.bindValue(":genre",genre);
        qry.bindValue(":cast",cast);
        qry.bindValue(":synopsis",synopsis);

        if(qry.exec())
        {
            QMessageBox::information(this,"Inserted ","Data Inserted Successfully");
        }
        else
        {
            QMessageBox::information(this,"Not Inserted","Data Is Not Inserted");
        }
    }
    else
    {
       QMessageBox::information(this,"Not Connected","Database is not connected!");
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

    }
}

void AdminWin::on_clear_clicked()
{
    QPixmap pix("/Users/Public/Pictures/Sample Pictures/");
    ui->piclabel->setPixmap(pix);
}
