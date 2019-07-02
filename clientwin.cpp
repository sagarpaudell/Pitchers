#include "clientwin.h"
#include "ui_clientwin.h"
#include "mainwindow.h"
#include  "loginwin.h"
#include "mainwindow.h"
#include "movie_manager.h"
#include <QDebug>
#include <QHBoxLayout>
#include <QVariant>
#include <QSignalMapper>
#include  <QLabel>

ClientWin::ClientWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientWin)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);
    setmostratedMovies();
    setdramaMovies();
    setcrimeMovies();
    setromanceMovies();
    setdocumentaryMovies();
    DbManager db("movies");
    QStringList competionlist;
    competionlist = db.getmoviesforsearch();
    moviename_completer = new QCompleter(competionlist,this);
    moviename_completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->search->setCompleter(moviename_completer);
    connect(ui->search, SIGNAL(returnPressed()),ui->commandLinkButton,SIGNAL(clicked()));
}

ClientWin::~ClientWin()
{
    delete ui;
}

//void ClientWin::on_pushButton_clicked()
//{

//    hide();
//    /*loginwin *loginWin;
//    loginWin = new loginwin(this);
//    loginWin->setFixedSize(763,424);
//    loginWin->show();*/
//    MainWindow *mainwindow;
//    mainwindow = new MainWindow(this);
//    mainwindow->setFixedSize(763,424);
//    mainwindow->show();

//}






void ClientWin::on_home_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void ClientWin::on_mostrated_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void ClientWin::on_drama_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
void ClientWin :: setmostratedMovies() {
    DbManager db("movies");


    QList<QList<QVariant>>data = db.getAllmostrated();
    qDebug()<<"Lenght: "<<data.length();
    QGridLayout *layout = new QGridLayout;

    int index = 0;
    for (int i = 0; i < 5; ++i) {
        for (int k = 0; k < 2; ++k){
            QPushButton *button = new QPushButton();
            button->setFixedSize(131,181);
            QList<QVariant> temp1 = data[index];
            QVariant moviename = temp1[0];
            QString movienameString = moviename.toString();
            QSignalMapper* m_sigmapper = new QSignalMapper(this);
            connect(button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
            m_sigmapper->setMapping(button,movienameString);
            connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

            QVariant info = temp1[0];
            QVariant image = temp1[6];

            QString infoString = info.toString();

            QVBoxLayout* vbox = new QVBoxLayout();


            button->setStyleSheet("border: 1px solid black; border-radius: 8px;  background: rgb(170, 0, 0); color: white;");
            button->setText(infoString);
            button->setFixedSize(131,25);
            QPixmap outPixmap = QPixmap(); // Create QPixmap, which will be placed in
            outPixmap = image.value<QPixmap>();
            QLabel* imageLabel = new QLabel();
            imageLabel->setPixmap(outPixmap.scaled(131,181));
//                /* Taking the image data from the table as QByteArray and put them in QPixmap
//                 * */
//                outPixmap.loadFromData( data[8.8].toByteArray());
//                button->setPixmap(outPixmap.scaled(131,181));
            vbox->addWidget(imageLabel);
            vbox->addWidget(button);
            layout->addLayout(vbox,k,i);
            ui->mostrated_page_1->setLayout(layout);
            index++;
        }
    }

}
void ClientWin :: setcrimeMovies() {
    DbManager db("movies");


    QList<QList<QVariant>>data = db.getAllcrime();
    qDebug()<<"Lenght: "<<data.length();
    QGridLayout *layout = new QGridLayout;

    int index = 0;
    for (int i = 0; i < 5; ++i) {
        for (int k = 0; k < 2; ++k){
            QPushButton *button = new QPushButton();
            button->setFixedSize(131,181);
            QList<QVariant> temp1 = data[index];
            QVariant moviename = temp1[0];
            QString movienameString = moviename.toString();
            QSignalMapper* m_sigmapper = new QSignalMapper(this);
            connect(button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
            m_sigmapper->setMapping(button,movienameString);
            connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

            QVariant info = temp1[0];
            //QVariant image = temp1[6];

            QString infoString = info.toString();

            QVBoxLayout* vbox = new QVBoxLayout();


            button->setStyleSheet("border: 1px solid black; border-radius: 8px;  background: rgb(170, 0, 0); color: white;");
            button->setText(infoString);
            button->setFixedSize(131,25);

            QPixmap back(":/img/comingsoon.png"); // Create QPixmap, which will be placed in
            //outPixmap = image.value<QPixmap>();
            QLabel* imageLabel = new QLabel();
            //imageLabel->setText("Image Coming Soon");
            imageLabel->setPixmap(back.scaled(131,181));
//                /* Taking the image data from the table as QByteArray and put them in QPixmap
//                 * */
//                outPixmap.loadFromData( data[8.8].toByteArray());
//                button->setPixmap(outPixmap.scaled(131,181));
            vbox->addWidget(imageLabel);
            vbox->addWidget(button);
            layout->addLayout(vbox,k,i);
            ui->crime_page_3->setLayout(layout);
            index++;
        }
    }

}
void ClientWin :: setdramaMovies() {
    DbManager db("movies");


    QList<QList<QVariant>>data = db.getAlldrama();
    qDebug()<<"Lenght: "<<data.length();
    QGridLayout *layout = new QGridLayout;

    int index = 0;
    for (int i = 0; i < 5; ++i) {
        for (int k = 0; k < 2; ++k){
            QPushButton *button = new QPushButton();
            button->setFixedSize(131,181);
            QList<QVariant> temp1 = data[index];
            QVariant moviename = temp1[0];
            QString movienameString = moviename.toString();
            QSignalMapper* m_sigmapper = new QSignalMapper(this);
            connect(button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
            m_sigmapper->setMapping(button,movienameString);
            connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

            QVariant info = temp1[0];
            //QVariant image = temp1[6];

            QString infoString = info.toString();

            QVBoxLayout* vbox = new QVBoxLayout();


            button->setStyleSheet("border: 1px solid black; border-radius: 8px;  background: rgb(170, 0, 0); color: white;");
            button->setText(infoString);
            button->setFixedSize(131,25);

            //QPixmap outPixmap = QPixmap(); // Create QPixmap, which will be placed in
            //outPixmap = image.value<QPixmap>();
            QPixmap back(":/img/comingsoon.png"); // Create QPixmap, which will be placed in
            //outPixmap = image.value<QPixmap>();
            QLabel* imageLabel = new QLabel();
            //imageLabel->setText("Image Coming Soon");
            imageLabel->setPixmap(back.scaled(131,181));
//                /* Taking the image data from the table as QByteArray and put them in QPixmap
//                 * */
//                outPixmap.loadFromData( data[8.8].toByteArray());
//                button->setPixmap(outPixmap.scaled(131,181));
            vbox->addWidget(imageLabel);
            vbox->addWidget(button);
            layout->addLayout(vbox,k,i);
            ui->drama_page_2->setLayout(layout);
            index++;
        }
    }

}
void ClientWin :: setromanceMovies() {
    DbManager db("movies");


    QList<QList<QVariant>>data = db.getAllromance();
    qDebug()<<"Lenght: "<<data.length();
    QGridLayout *layout = new QGridLayout;

    int index = 0;
    for (int i = 0; i < 5; ++i) {
        for (int k = 0; k < 2; ++k){
            QPushButton *button = new QPushButton();
            button->setFixedSize(131,181);
            QList<QVariant> temp1 = data[index];
            QVariant moviename = temp1[0];
            QString movienameString = moviename.toString();
            QSignalMapper* m_sigmapper = new QSignalMapper(this);
            connect(button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
            m_sigmapper->setMapping(button,movienameString);
            connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

            QVariant info = temp1[0];
            //QVariant image = temp1[6];

            QString infoString = info.toString();

            QVBoxLayout* vbox = new QVBoxLayout();


            button->setStyleSheet("border: 1px solid black; border-radius: 8px;  background: rgb(170, 0, 0); color: white;");
            button->setText(infoString);
            button->setFixedSize(131,25);

            //QPixmap outPixmap = QPixmap(); // Create QPixmap, which will be placed in
            //outPixmap = image.value<QPixmap>();

            QPixmap back(":/img/comingsoon.png"); // Create QPixmap, which will be placed in
            //outPixmap = image.value<QPixmap>();
            QLabel* imageLabel = new QLabel();
            //imageLabel->setText("Image Coming Soon");
            imageLabel->setPixmap(back.scaled(131,181));
//                /* Taking the image data from the table as QByteArray and put them in QPixmap
//                 * */
//                outPixmap.loadFromData( data[8.8].toByteArray());
//                button->setPixmap(outPixmap.scaled(131,181));
            vbox->addWidget(imageLabel);
            //imageLabel->setPixmap(outPixmap.scaled(131,181));
//                /* Taking the image data from the table as QByteArray and put them in QPixmap
//                 * */
//                outPixmap.loadFromData( data[8.8].toByteArray());
//                button->setPixmap(outPixmap.scaled(131,181));
            //vbox->addWidget(imageLabel);
            vbox->addWidget(button);
            layout->addLayout(vbox,k,i);
            ui->romance_page_4->setLayout(layout);
            index++;
        }
    }

}
void ClientWin :: setdocumentaryMovies() {
    DbManager db("movies");


    QList<QList<QVariant>>data = db.getAlldocumentary();
    qDebug()<<"Lenght: "<<data.length();
    QGridLayout *layout = new QGridLayout;

    int index = 0;
    for (int i = 0; i < 5; ++i) {
        for (int k = 0; k < 2; ++k){
            QPushButton *button = new QPushButton();
            button->setFixedSize(131,181);
            QList<QVariant> temp1 = data[index];
            QVariant moviename = temp1[0];
            QString movienameString = moviename.toString();
            QSignalMapper* m_sigmapper = new QSignalMapper(this);
            connect(button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
            m_sigmapper->setMapping(button,movienameString);
            connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

            QVariant info = temp1[0];
            //QVariant image = temp1[6];

            QString infoString = info.toString();

            QVBoxLayout* vbox = new QVBoxLayout();


            button->setStyleSheet("border: 1px solid black; border-radius: 8px;  background: rgb(170, 0, 0); color: white;");
            button->setText(infoString);
            button->setFixedSize(131,25);

            //QPixmap outPixmap = QPixmap(); // Create QPixmap, which will be placed in
            //outPixmap = image.value<QPixmap>();

            QPixmap back(":/img/comingsoon.png"); // Create QPixmap, which will be placed in
            //outPixmap = image.value<QPixmap>();
            QLabel* imageLabel = new QLabel();
            //imageLabel->setText("Image Coming Soon");
            imageLabel->setPixmap(back.scaled(131,181));
//                /* Taking the image data from the table as QByteArray and put them in QPixmap
//                 * */
//                outPixmap.loadFromData( data[8.8].toByteArray());
//                button->setPixmap(outPixmap.scaled(131,181));
            vbox->addWidget(imageLabel);
            //imageLabel->setPixmap(outPixmap.scaled(131,181));
//                /* Taking the image data from the table as QByteArray and put them in QPixmap
//                 * */
//                outPixmap.loadFromData( data[8.8].toByteArray());
//                button->setPixmap(outPixmap.scaled(131,181));
            //vbox->addWidget(imageLabel);
            vbox->addWidget(button);
            layout->addLayout(vbox,k,i);
            ui->documentary_page_5->setLayout(layout);
            index++;
        }
    }

}
void ClientWin::on_crime_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void ClientWin::on_romance_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}


void ClientWin::on_documentary_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}
void ClientWin::display_movie_details(const QString temp){
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("movies");
    if(db.open()){

        //creating database queries
      QSqlQuery query;
      query.prepare ( "SELECT * FROM imdb WHERE UPPER(REPLACE(title, ' ', '')) = UPPER(REPLACE(:moviename, ' ', ''))");
      query.bindValue ( ":moviename",temp );

      //query.prepare(QString("SELECT * FROM drama WHERE  UPPER(REPLACE(moviename, ' ', '')) = UPPER(REPLACE(:moviename, ' ', '')) union (SELECT * FROM horror WHERE UPPER(REPLACE(moviename, ' ', '')) = UPPER(REPLACE(:moviename, ' ', ''))) union (SELECT * FROM romance WHERE UPPER(REPLACE(moviename, ' ', '')) = UPPER(REPLACE(:moviename, ' ', ''))) union (SELECT * FROM crime WHERE UPPER(REPLACE(moviename, ' ', '')) = UPPER(REPLACE(:moviename, ' ', ''))) "));
//      query.bindValue(":moviename",search_movie);


      if(query.exec()){
              qDebug() <<query.value(0)<<query.value(1)<<query.value(3)<<query.value(4)<<query.value(5)<<query.value(6);
                     while (query.next()) {
                         ui->movietitle->setText(query.value(1).toString());
                         ui->year->setText(query.value(2).toString());
                         ui->IMDb->setText(query.value(4).toString());
                         ui->director->setText(query.value(3).toString());
                         ui->cast->setText(query.value(5).toString());
                         ui->synopsis->setText(query.value(6).toString());
                         ui->genre->setText(query.value(7).toString());

                         QPixmap outPixmap = QPixmap(); // Create QPixmap, which will be placed in picLabel
                             /* Taking the image data from the table as QByteArray and put them in QPixmap
                              * */
                             outPixmap.loadFromData( query.value(8).toByteArray());
                             ui->movie_poster->setPixmap(outPixmap.scaled(131,181));






                     }
       }
      else{
//          QSqlQuery query1;
//          query1.prepare(QString("SELECT * FROM horror WHERE moviename = :moviename"));
//          query1.bindValue(":moviename",search_movie);
//          if(query1.exec()){
//                  qDebug() <<query1.value(0)<<query1.value(1)<<query1.value(3)<<query1.value(4)<<query1.value(5)<<query1.value(6);
//                         while (query1.next()) {
//                             ui->movietitle->setText(query1.value(0).toString());
//                             ui->year->setText(query1.value(1).toString());
//                             ui->IMDb->setText(query1.value(3).toString());
//                             ui->director->setText(query1.value(2).toString());
//                             ui->cast->setText(query1.value(4).toString());
//                             ui->synopsis->setText(query1.value(5).toString());
//                             //ui->IMDb->setText(query.value(3).toString());
//                         }
         qDebug() << query.lastError().text();
      }
     db.close();
    }
    ui->stackedWidget->setCurrentIndex(7);

}
void ClientWin::on_commandLinkButton_clicked()
{

    QString search_movie = ui->search->text();
    display_movie_details(search_movie);
}
