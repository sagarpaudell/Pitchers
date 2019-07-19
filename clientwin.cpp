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
#include <QDesktopServices>
#include <QUrl>

ClientWin::ClientWin(QWidget *parent,QString uname) :
    QMainWindow(parent),
    ui(new Ui::ClientWin)
{
    ui->setupUi(this);
    this->uname = uname;
    this->setWindowTitle("WELCOME " +uname+"");
    ui->stackedWidget->setCurrentIndex(0);
    qDebug()<<uname;
    setmostratedMovies();
    setdramaMovies();
    setcrimeMovies();
    setromanceMovies();
    setdocumentaryMovies();
    setrecommendedMovies(uname);
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
    DbManager db("moviedataset");

    QList<QList<QVariant>>data = db.getAllmostrated();
    qDebug()<<"Lenght: "<<data.length();
    QGridLayout *layout = new QGridLayout;

    int index = data.length()-  1;
    for (int i = 0; i < 5; ++i) {
        for (int k = 0; k < 4; ++k){


            QList<QVariant> temp1 = data[index];
            QVBoxLayout* vbox = new QVBoxLayout();
            QPushButton* moviename_button = new QPushButton();
            QLabel* blank = new QLabel();
            QPushButton* button = new QPushButton();

            QVariant movietitle = temp1[0];
            QString movienameString = movietitle.toString();
            moviename_button->setText(movienameString);
            blank->setText("");
            button->setFixedSize(135,185);
            moviename_button->setStyleSheet("border: none ;  background: black; color: white; font-size:14px; text-decoration: underline;");
            button->setStyleSheet("border-radius:0px; background:white ;");

            moviename_button->setFixedSize(131,25);
            QVariant image = temp1[6];
            QPixmap outPixmap = QPixmap(); // Create QPixmap, which will be placed in
            outPixmap = image.value<QPixmap>();
            QPixmap pixmap(outPixmap);
            QIcon ButtonIcon(pixmap);
            const QSize BUTTON_SIZE = QSize(131, 181);
            button->setIcon(ButtonIcon);
            button->setIconSize((BUTTON_SIZE));
            QSignalMapper* m_sigmapper = new QSignalMapper(this);
            connect(button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
            m_sigmapper->setMapping(button,movienameString);
            connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
            connect(moviename_button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
            m_sigmapper->setMapping(moviename_button,movienameString);
            connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

            vbox->addWidget(button);
            vbox->addWidget(moviename_button);
            vbox->addWidget(blank);
            layout->addLayout(vbox,k,i);
            ui->mostrated_Scroll->setLayout(layout);
            index--;


}
    }


}
void ClientWin :: setcrimeMovies() {
    DbManager db("moviedataset");


    QList<QList<QVariant>>data = db.getAllcrime();
    qDebug()<<"Lenght: "<<data.length();
    QGridLayout *layout = new QGridLayout;

    int index = data.length()-  1;
    for (int i = 0; i < 5; ++i) {
        for (int k = 0; k < 2; ++k){


            QList<QVariant> temp1 = data[index];
            QVBoxLayout* vbox = new QVBoxLayout();
            QPushButton* moviename_button = new QPushButton();
            QLabel* blank = new QLabel();
            QPushButton* button = new QPushButton();

            QVariant movietitle = temp1[0];
            QString movienameString = movietitle.toString();
            moviename_button->setText(movienameString);
            blank->setText("");
            button->setFixedSize(135,185);
            moviename_button->setStyleSheet("border: none ;  background: black; color: white; font-size:14px; text-decoration: underline;");
            button->setStyleSheet("border-radius:0px; background:white ;");

            moviename_button->setFixedSize(131,25);
            QVariant image = temp1[6];
            QPixmap outPixmap = QPixmap(); // Create QPixmap, which will be placed in
            outPixmap = image.value<QPixmap>();
            QPixmap pixmap(outPixmap);
            QIcon ButtonIcon(pixmap);
            const QSize BUTTON_SIZE = QSize(131, 181);
            button->setIcon(ButtonIcon);
            button->setIconSize((BUTTON_SIZE));
            QSignalMapper* m_sigmapper = new QSignalMapper(this);
            connect(button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
            m_sigmapper->setMapping(button,movienameString);
            connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
            connect(moviename_button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
            m_sigmapper->setMapping(moviename_button,movienameString);
            connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

            vbox->addWidget(button);
            vbox->addWidget(moviename_button);
            vbox->addWidget(blank);
            layout->addLayout(vbox,k,i);
            ui->crime_page_3->setLayout(layout);
            index--;
}

}

}
void ClientWin :: setdramaMovies() {
    DbManager db("moviedataset");

    QList<QList<QVariant>>data = db.getAlldrama();
    qDebug()<<"Lenght: "<<data.length();
    QGridLayout *layout = new QGridLayout;

    int index = data.length()-  1;
    for (int i = 0; i < 5; ++i) {
        for (int k = 0; k < 2; ++k){


            QList<QVariant> temp1 = data[index];
            QVBoxLayout* vbox = new QVBoxLayout();
            //QGridLayout* gbox = new QGridLayout()
            QPushButton* moviename_button = new QPushButton();
            QLabel* blank = new QLabel();
            QPushButton* button = new QPushButton();

           // QList<QString> itemname;
            // Note: 0->itemName 1->itemCost
            QVariant movietitle = temp1[0];
            QString movienameString = movietitle.toString();
            moviename_button->setText(movienameString);
            blank->setText("");
            button->setFixedSize(135,185);
            moviename_button->setStyleSheet("border: none ;  background: black; color: white; font-size:14px; text-decoration: underline;");
            button->setStyleSheet("border-radius:0px; background:white ;");

            moviename_button->setFixedSize(131,25);
            QVariant image = temp1[6];
            QPixmap outPixmap = QPixmap(); // Create QPixmap, which will be placed in
            outPixmap = image.value<QPixmap>();
            QPixmap pixmap(outPixmap);
            QIcon ButtonIcon(pixmap);
            const QSize BUTTON_SIZE = QSize(131, 181);
            button->setIcon(ButtonIcon);
            button->setIconSize((BUTTON_SIZE));
            //addButton->setFixedSize(pixmap.rect().size());
           // QString imgAd = itemData[1];
            //button->setStyleSheet("width:131px;height:181px;color: rgb(255, 255, 255);");
            QSignalMapper* m_sigmapper = new QSignalMapper(this);
            connect(button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
            m_sigmapper->setMapping(button,movienameString);
            connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
            connect(moviename_button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
            m_sigmapper->setMapping(moviename_button,movienameString);
            connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

            vbox->addWidget(button);
            vbox->addWidget(moviename_button);
            vbox->addWidget(blank);
            layout->addLayout(vbox,k,i);
            ui->drama_Scroll->setLayout(layout);
            index--;
}

}

}
void ClientWin :: setromanceMovies() {
    DbManager db("moviedataset");


    QList<QList<QVariant>>data = db.getAllromance();
    qDebug()<<"Lenght: "<<data.length();
    QGridLayout *layout = new QGridLayout;

    int index = data.length()-  1;
    for (int i = 0; i < 5; ++i) {
        for (int k = 0; k < 2; ++k){


            QList<QVariant> temp1 = data[index];
            QVBoxLayout* vbox = new QVBoxLayout();
            QPushButton* moviename_button = new QPushButton();
            QLabel* blank = new QLabel();
            QPushButton* button = new QPushButton();

            QVariant movietitle = temp1[0];
            QString movienameString = movietitle.toString();
            moviename_button->setText(movienameString);
            blank->setText("");
            button->setFixedSize(135,185);
            moviename_button->setStyleSheet("border: none ;  background: black; color: white; font-size:14px; text-decoration: underline;");
            button->setStyleSheet("border-radius:0px; background:white ;");

            moviename_button->setFixedSize(131,25);
            QVariant image = temp1[6];
            QPixmap outPixmap = QPixmap(); // Create QPixmap, which will be placed in
            outPixmap = image.value<QPixmap>();
            QPixmap pixmap(outPixmap);
            QIcon ButtonIcon(pixmap);
            const QSize BUTTON_SIZE = QSize(131, 181);
            button->setIcon(ButtonIcon);
            button->setIconSize((BUTTON_SIZE));
            QSignalMapper* m_sigmapper = new QSignalMapper(this);
            connect(button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
            m_sigmapper->setMapping(button,movienameString);
            connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
            connect(moviename_button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
            m_sigmapper->setMapping(moviename_button,movienameString);
            connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

            vbox->addWidget(button);
            vbox->addWidget(moviename_button);
            vbox->addWidget(blank);
            layout->addLayout(vbox,k,i);
            ui->romance_page_4->setLayout(layout);
            index--;
}

}
}
void ClientWin :: setdocumentaryMovies() {
    DbManager db("moviedataset");


    QList<QList<QVariant>>data = db.getAlldocumentary();
    qDebug()<<"Lenght: "<<data.length();
    QGridLayout *layout = new QGridLayout;

    int index = data.length()-  1;
    for (int i = 0; i < 5; ++i) {
        for (int k = 0; k < 2; ++k){


            QList<QVariant> temp1 = data[index];
            QVBoxLayout* vbox = new QVBoxLayout();
            QPushButton* moviename_button = new QPushButton();
            QLabel* blank = new QLabel();
            QPushButton* button = new QPushButton();

            QVariant movietitle = temp1[0];
            QString movienameString = movietitle.toString();
            moviename_button->setText(movienameString);
            blank->setText("");
            button->setFixedSize(135,185);
            moviename_button->setStyleSheet("border: none ;  background: black; color: white; font-size:14px; text-decoration: underline;");
            button->setStyleSheet("border-radius:0px; background:white ;");

            moviename_button->setFixedSize(131,25);
            QVariant image = temp1[6];
            QPixmap outPixmap = QPixmap(); // Create QPixmap, which will be placed in
            outPixmap = image.value<QPixmap>();
            QPixmap pixmap(outPixmap);
            QIcon ButtonIcon(pixmap);
            const QSize BUTTON_SIZE = QSize(131, 181);
            button->setIcon(ButtonIcon);
            button->setIconSize((BUTTON_SIZE));
            QSignalMapper* m_sigmapper = new QSignalMapper(this);
            connect(button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
            m_sigmapper->setMapping(button,movienameString);
            connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
            connect(moviename_button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
            m_sigmapper->setMapping(moviename_button,movienameString);
            connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

            vbox->addWidget(button);
            vbox->addWidget(moviename_button);
            vbox->addWidget(blank);
            layout->addLayout(vbox,k,i);
            ui->documentary_page_5->setLayout(layout);
            index--;
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
     ui->stackedWidget->setCurrentIndex(7);
//    QSqlDatabase db;
//    db = QSqlDatabase::addDatabase("QMYSQL");
//    db.setHostName("127.0.0.1");
//    db.setUserName("root");
//    db.setPassword("");
//    db.setDatabaseName("moviedataset");
//    if(db.open()){
    DbManager db1("moviedataset");
        //creating database queries
      QSqlQuery query;
      query.prepare (QString( "SELECT * FROM imdb WHERE UPPER(REPLACE(title, ' ', '')) = UPPER(REPLACE(:moviename, ' ', '')) union (SELECT * FROM nepali WHERE UPPER(REPLACE(title, ' ', '')) = UPPER(REPLACE(:moviename, ' ', '')))union(SELECT * FROM hindi WHERE UPPER(REPLACE(title, ' ', '')) = UPPER(REPLACE(:moviename, ' ', '')))union (SELECT * FROM kids WHERE UPPER(REPLACE(title, ' ', '')) = UPPER(REPLACE(:moviename, ' ', '')))union (SELECT * FROM southindian WHERE UPPER(REPLACE(title, ' ', '')) = UPPER(REPLACE(:moviename, ' ', '')))"));
      query.bindValue ( ":moviename",temp );

      //query.prepare(QString("SELECT * FROM drama WHERE  UPPER(REPLACE(moviename, ' ', '')) = UPPER(REPLACE(:moviename, ' ', '')) union (SELECT * FROM horror WHERE UPPER(REPLACE(moviename, ' ', '')) = UPPER(REPLACE(:moviename, ' ', ''))) union (SELECT * FROM romance WHERE UPPER(REPLACE(moviename, ' ', '')) = UPPER(REPLACE(:moviename, ' ', ''))) union (SELECT * FROM crime WHERE UPPER(REPLACE(moviename, ' ', '')) = UPPER(REPLACE(:moviename, ' ', ''))) "));
//      query.bindValue(":moviename",search_movie);


      if(query.exec()){
              //qDebug() <<query.value(0)<<query.value(1)<<query.value(3)<<query.value(4)<<query.value(5)<<query.value(6);
                    while (query.next()) {
                         ui->movietitle->setText(query.value(1).toString());
                         ui->year->setText(query.value(2).toString());
                         ui->director->setText(query.value(3).toString());
                         ui->IMDb->setText(query.value(4).toString());
                         ui->cast->setText(query.value(5).toString());
                         ui->synopsis->setText(query.value(6).toString());
                         ui->genre->setText(query.value(7).toString());


                         QPixmap outPixmap = QPixmap(); // Create QPixmap, which will be placed in picLabel
                             /* Taking the image data from the table as QByteArray and put them in QPixmap
                              * */
                             outPixmap.loadFromData( query.value(8).toByteArray());
                             ui->movie_poster->setPixmap(outPixmap.scaled(131,181));
                             QString tlink=query.value(9).toString();
                              QString mlink=query.value(10).toString();
                                 qDebug()<<tlink;
                         // on_trailer_button_clicked(tlink);
                              QSignalMapper* m_sigmapper = new QSignalMapper(this);
                             connect(ui->trailer_button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
                             m_sigmapper->setMapping(ui->trailer_button,tlink);
                             connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(trailer(const QString)));
                              QSignalMapper* m_sigmapper1 = new QSignalMapper(this);
                             connect(ui->movie_button, SIGNAL(clicked()), m_sigmapper1, SLOT(map()));
                             m_sigmapper1->setMapping(ui->movie_button,mlink);
                             connect(m_sigmapper1, SIGNAL(mapped(QString)),this, SLOT(movie(const QString)));



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
         //qDebug() << query.lastError().text();
      }




}
void ClientWin::on_commandLinkButton_clicked()
{

    QString search_movie = ui->search->text();
    display_movie_details(search_movie);
}
void ClientWin::trailer(QString tlink)
{
  qDebug()<<"QStr";   QDesktopServices::openUrl(QUrl(tlink));
}
void ClientWin::movie(QString mlink)
{
     QDesktopServices::openUrl(QUrl(mlink));
}

//void ClientWin :: setrecommendedMovies(QString( temp)){



//    DbManager db("moviedataset");
//    QString nationality;
//    nationality=ui->search->text();
//    if(nationality=="nepali"){
//    QList<QList<QVariant>>data = db.getAllnepali();
//    qDebug()<<"Lenght: "<<data.length();
//    QGridLayout *layout = new QGridLayout;

//    int index = data.length()-  1;
//    for (int i = 0; i < 5; ++i) {
//        for (int k = 0; k < 1; ++k){


//            QList<QVariant> temp1 = data[index];
//            QVBoxLayout* vbox = new QVBoxLayout();
//            //QGridLayout* gbox = new QGridLayout()
//            QPushButton* moviename_button = new QPushButton();
//            QLabel* blank = new QLabel();
//            QPushButton* button = new QPushButton();

//           // QList<QString> itemname;
//            // Note: 0->itemName 1->itemCost
//            QVariant movietitle = temp1[0];
//            QString movienameString = movietitle.toString();
//            moviename_button->setText(movienameString);
//            blank->setText("");
//            button->setFixedSize(135,185);
//            moviename_button->setStyleSheet("border: none ;  background: black; color: white; font-size:14px; text-decoration: underline;");
//            button->setStyleSheet("border-radius:0px; background:white ;");

//            moviename_button->setFixedSize(131,25);
//            QVariant image = temp1[6];
//            QPixmap outPixmap = QPixmap(); // Create QPixmap, which will be placed in
//            outPixmap = image.value<QPixmap>();
//            QPixmap pixmap(outPixmap);
//            QIcon ButtonIcon(pixmap);
//            const QSize BUTTON_SIZE = QSize(131, 181);
//            button->setIcon(ButtonIcon);
//            button->setIconSize((BUTTON_SIZE));
//            //addButton->setFixedSize(pixmap.rect().size());
//           // QString imgAd = itemData[1];
//            //button->setStyleSheet("width:131px;height:181px;color: rgb(255, 255, 255);");
//            QSignalMapper* m_sigmapper = new QSignalMapper(this);
//            connect(button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
//            m_sigmapper->setMapping(button,movienameString);
//            connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
//            connect(moviename_button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
//            m_sigmapper->setMapping(moviename_button,movienameString);
//            connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

//            vbox->addWidget(button);
//            vbox->addWidget(moviename_button);
//            vbox->addWidget(blank);
//            layout->addLayout(vbox,k,i);
//            ui->recommended_for_you->setLayout(layout);
//            index--;


//}
//    }


//    }
//    else if(nationality=="indian") {
//         QList<QList<QVariant>>data = db.getAllhindi();

//         qDebug()<<"Lenght: "<<data.length();
//         QGridLayout *layout = new QGridLayout;

//         int index = data.length()-  1;
//         for (int i = 0; i < 5; ++i) {
//             for (int k = 0; k < 2; ++k){


//                 QList<QVariant> temp1 = data[index];
//                 QVBoxLayout* vbox = new QVBoxLayout();
//                 //QGridLayout* gbox = new QGridLayout()
//                 QPushButton* moviename_button = new QPushButton();
//                 QLabel* blank = new QLabel();
//                 QPushButton* button = new QPushButton();

//                // QList<QString> itemname;
//                 // Note: 0->itemName 1->itemCost
//                 QVariant movietitle = temp1[0];
//                 QString movienameString = movietitle.toString();
//                 moviename_button->setText(movienameString);
//                 blank->setText("");
//                 button->setFixedSize(135,185);
//                 moviename_button->setStyleSheet("border: none ;  background: black; color: white; font-size:14px; text-decoration: underline;");
//                 button->setStyleSheet("border-radius:0px; background:white ;");

//                 moviename_button->setFixedSize(131,25);
//                 QVariant image = temp1[6];
//                 QPixmap outPixmap = QPixmap(); // Create QPixmap, which will be placed in
//                 outPixmap = image.value<QPixmap>();
//                 QPixmap pixmap(outPixmap);
//                 QIcon ButtonIcon(pixmap);
//                 const QSize BUTTON_SIZE = QSize(131, 181);
//                 button->setIcon(ButtonIcon);
//                 button->setIconSize((BUTTON_SIZE));
//                 //addButton->setFixedSize(pixmap.rect().size());
//                // QString imgAd = itemData[1];
//                 //button->setStyleSheet("width:131px;height:181px;color: rgb(255, 255, 255);");
//                 QSignalMapper* m_sigmapper = new QSignalMapper(this);
//                 connect(button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
//                 m_sigmapper->setMapping(button,movienameString);
//                 connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
//                 connect(moviename_button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
//                 m_sigmapper->setMapping(moviename_button,movienameString);
//                 connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

//                 vbox->addWidget(button);
//                 vbox->addWidget(moviename_button);
//                 vbox->addWidget(blank);
//                 layout->addLayout(vbox,k,i);
//                 ui->recommended_for_you->setLayout(layout);
//                 index--;


//     }



//    }
//    }
//else{
//    QList<QList<QVariant>>data = db.getAllmostrated();
//    qDebug()<<"Lenght: "<<data.length();
//    QGridLayout *layout = new QGridLayout;

//    int index = data.length()-  1;
//    for (int i = 0; i < 5; ++i) {
//        for (int k = 0; k < 2; ++k){


//            QList<QVariant> temp1 = data[index];
//            QVBoxLayout* vbox = new QVBoxLayout();
//            //QGridLayout* gbox = new QGridLayout()
//            QPushButton* moviename_button = new QPushButton();
//            QLabel* blank = new QLabel();
//            QPushButton* button = new QPushButton();

//           // QList<QString> itemname;
//            // Note: 0->itemName 1->itemCost
//            QVariant movietitle = temp1[0];
//            QString movienameString = movietitle.toString();
//            moviename_button->setText(movienameString);
//            blank->setText("");
//            button->setFixedSize(135,185);
//            moviename_button->setStyleSheet("border: none ;  background: black; color: white; font-size:14px; text-decoration: underline;");
//            button->setStyleSheet("border-radius:0px; background:white ;");

//            moviename_button->setFixedSize(131,25);
//            QVariant image = temp1[6];
//            QPixmap outPixmap = QPixmap(); // Create QPixmap, which will be placed in
//            outPixmap = image.value<QPixmap>();
//            QPixmap pixmap(outPixmap);
//            QIcon ButtonIcon(pixmap);
//            const QSize BUTTON_SIZE = QSize(131, 181);
//            button->setIcon(ButtonIcon);
//            button->setIconSize((BUTTON_SIZE));
//            //addButton->setFixedSize(pixmap.rect().size());
//           // QString imgAd = itemData[1];
//            //button->setStyleSheet("width:131px;height:181px;color: rgb(255, 255, 255);");
//            QSignalMapper* m_sigmapper = new QSignalMapper(this);
//            connect(button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
//            m_sigmapper->setMapping(button,movienameString);
//            connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
//            connect(moviename_button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
//            m_sigmapper->setMapping(moviename_button,movienameString);
//            connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

//            vbox->addWidget(button);
//            vbox->addWidget(moviename_button);
//            vbox->addWidget(blank);
//            layout->addLayout(vbox,k,i);
//            ui->recommended_for_you->setLayout(layout);
//            index--;


//}
//    }
//}
//}
//void ClientWin :: setrecommendedMovies(QString temp){
//    DbManager db("moviedataset");
//   //    QString nationality;
//   //    nationality=ui->search->text();
//   //    if(nationality=="nepali"){
//      QList<QList<QVariant>>data = db.getAllnepali();
//       qDebug()<<"Lenght: "<<data.length();
//       QGridLayout *layout = new QGridLayout;

//       int index = data.length()-  1;
//       for (int i = 0; i < 5; ++i) {
//           for (int k = 0; k < 2; ++k){


//               QList<QVariant> temp1 = data[index];
//               QVBoxLayout* vbox = new QVBoxLayout();
//   //            //QGridLayout* gbox = new QGridLayout()
//               QPushButton* moviename_button = new QPushButton();
//               QLabel* blank = new QLabel();
//               QPushButton* button = new QPushButton();

//              // QList<QString> itemname;
//               // Note: 0->itemName 1->itemCost
//               QVariant movietitle = temp1[0];
//               QString movienameString = movietitle.toString();
//               moviename_button->setText(movienameString);
//               blank->setText("");
//               button->setFixedSize(135,185);
//               moviename_button->setStyleSheet("border: none ;  background: black; color: white; font-size:14px; text-decoration: underline;");
//               button->setStyleSheet("border-radius:0px; background:white ;");

//               moviename_button->setFixedSize(131,25);
//               QVariant image = temp1[6];
//               QPixmap outPixmap = QPixmap(); // Create QPixmap, which will be placed in
//               outPixmap = image.value<QPixmap>();
//               QPixmap pixmap(outPixmap);
//               QIcon ButtonIcon(pixmap);
//               const QSize BUTTON_SIZE = QSize(131, 181);
//               button->setIcon(ButtonIcon);
//               button->setIconSize((BUTTON_SIZE));
//   //            //addButton->setFixedSize(pixmap.rect().size());
//   //           // QString imgAd = itemData[1];
//   //            //button->setStyleSheet("width:131px;height:181px;color: rgb(255, 255, 255);");
//   //            QSignalMapper* m_sigmapper = new QSignalMapper(this);
//   //            connect(button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
//   //            m_sigmapper->setMapping(button,movienameString);
//   //            connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
//   //            connect(moviename_button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
//   //            m_sigmapper->setMapping(moviename_button,movienameString);
//   //            connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

//               vbox->addWidget(button);
//               vbox->addWidget(moviename_button);
//               vbox->addWidget(blank);
//               layout->addLayout(vbox,k,i);
//               ui->parentScroll->setLayout(layout);
//               index--;


//   }
//  }


//   //    }
//}
void ClientWin::setrecommendedMovies(const QString uname){

    DbManager db("registration");

    QList<QString>data = db.getUserInfo(uname);

    QString nationality = data[5];
//    QString uFname = data[1];
//    QString uLname = data[2];
//    QString uAddr = data[3];
      int age = data[6].toInt();



//    QSqlQuery query("SELECT * FROM user WHERE username = (:uname)");
//    query.bindValue(":uname",uname);
//    int nationalityIndex = query.record().indexOf("nationality");
//    QString nationality = query.value(nationalityIndex).toString();
    qDebug()<<nationality;
    DbManager db1("moviedataset");
//    QString nationality = "nepali";
    if(nationality=="nepali"){//checknationality
        QList<QList<QVariant>>data = db1.getAllnepali();
        qDebug()<<"Lenght: "<<data.length();
        QGridLayout *layout = new QGridLayout;

        int index = data.length()-  1;
        for (int i = 0; i < 5; ++i) {
            for (int k = 0; k < 1; ++k){


                QList<QVariant> temp1 = data[index];
                QVBoxLayout* vbox = new QVBoxLayout();
                QPushButton* moviename_button = new QPushButton();
                QLabel* blank = new QLabel();
                QPushButton* button = new QPushButton();
                QLabel* textt = new QLabel();
                QVariant movietitle = temp1[0];
                if(index==data.length()-1){
                    textt->setText("Recommended for");
                    textt->setStyleSheet("border: none ;  background: black; color: white; font-size:18px;");
                }
                else if(index==data.length()-2){
                    textt->setText(" you!");
                    textt->setStyleSheet("border: none ;  background: black; color: white; font-size:18px;");
                }
                else textt->setText("");
                QString movienameString = movietitle.toString();
                moviename_button->setText(movienameString);
                blank->setText("");
                button->setFixedSize(135,185);
                moviename_button->setStyleSheet("border: none ;  background: black; color: white; font-size:14px; text-decoration: underline;");
                button->setStyleSheet("border-radius:0px; background:white ;");

                moviename_button->setFixedSize(131,25);
                QVariant image = temp1[6];
                QPixmap outPixmap = QPixmap(); // Create QPixmap, which will be placed in
                outPixmap = image.value<QPixmap>();
                QPixmap pixmap(outPixmap);
                QIcon ButtonIcon(pixmap);
                const QSize BUTTON_SIZE = QSize(131, 181);
                button->setIcon(ButtonIcon);
                button->setIconSize((BUTTON_SIZE));
                QSignalMapper* m_sigmapper = new QSignalMapper(this);
                connect(button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
                m_sigmapper->setMapping(button,movienameString);
                connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                 QSignalMapper* m_sigmapper1 = new QSignalMapper(this);
                connect(moviename_button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
                m_sigmapper1->setMapping(moviename_button,movienameString);
                connect(m_sigmapper1, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                vbox->addWidget(textt);
                vbox->addWidget(button);
                vbox->addWidget(moviename_button);
                vbox->addWidget(blank);
                layout->addLayout(vbox,k,i);
                ui->parentScroll->setLayout(layout);
                index--;
    }//forloopclosed

    }//forloopclosed
        qDebug()<<age;

        if(age>45){//checkage

            data = db1.getAllhistory();
            int index1 = data.length()-1;
                for (int i = 0; i < 5; ++i) {
                    for (int k = 0; k < 1; ++k){


                        QList<QVariant> temp = data[index1];
                        QVBoxLayout* vbox = new QVBoxLayout();
                        QPushButton* moviename_button = new QPushButton();
                        QLabel* blank = new QLabel();
                        QPushButton* button = new QPushButton();
                        QLabel* textt = new QLabel();
                        QVariant movietitle = temp[0];
                        QString movienameString = movietitle.toString();
                        moviename_button->setText(movienameString);
                        blank->setText("");
                        button->setFixedSize(135,185);
                        moviename_button->setStyleSheet("border: none ;  background: black; color: white; font-size:14px; text-decoration: underline;");
                        button->setStyleSheet("border-radius:0px; background:white ;");
                        if(index1==data.length()-1){
                            textt->setText("Picks for");
                            textt->setStyleSheet("border: none ;  background: black; color: white; font-size:18px;");
                        }
                        else if(index1==data.length()-2){
                            textt->setText(" you! ");
                            textt->setStyleSheet("border: none ;  background: black; color: white; font-size:18px; ");
                        }
                        else textt->setText("");
                        moviename_button->setFixedSize(131,25);
                        QVariant image = temp[6];
                        QPixmap outPixmap = QPixmap(); // Create QPixmap, which will be placed in
                        outPixmap = image.value<QPixmap>();
                        QPixmap pixmap(outPixmap);
                        QIcon ButtonIcon(pixmap);
                        const QSize BUTTON_SIZE = QSize(131, 181);
                        button->setIcon(ButtonIcon);
                        button->setIconSize((BUTTON_SIZE));
                        QSignalMapper* m_sigmapper = new QSignalMapper(this);
                        connect(button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
                        m_sigmapper->setMapping(button,movienameString);
                        connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                        QSignalMapper* m_sigmapper1 = new QSignalMapper(this);
                        connect(moviename_button, SIGNAL(clicked()), m_sigmapper1, SLOT(map()));
                        m_sigmapper1->setMapping(moviename_button,movienameString);
                        connect(m_sigmapper1, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

                        vbox->addWidget(textt);
                        vbox->addWidget(button);
                        vbox->addWidget(moviename_button);
                        vbox->addWidget(blank);
                        layout->addLayout(vbox,k+1,i);
                        ui->parentScroll->setLayout(layout);
                        index1--;
            }//forloopclosed

            }//forloopclosed
        }//foragecheckclosed
        else if (age>=18&&age<=45) {//checkage


    data = db1.getAllaction();
    int index1 = data.length()-1;
        for (int i = 0; i < 5; ++i) {
            for (int k = 0; k < 1; ++k){


                QList<QVariant> temp = data[index1];
                QVBoxLayout* vbox = new QVBoxLayout();
                QPushButton* moviename_button = new QPushButton();
                QLabel* blank = new QLabel();
                QPushButton* button = new QPushButton();
                QLabel* textt = new QLabel();
                QVariant movietitle = temp[0];
                QString movienameString = movietitle.toString();
                moviename_button->setText(movienameString);
                blank->setText("");
                button->setFixedSize(135,185);
                moviename_button->setStyleSheet("border: none ;  background: black; color: white; font-size:14px; text-decoration: underline;");
                button->setStyleSheet("border-radius:0px; background:white ;");
                if(index1==data.length()-1){
                    textt->setText("Some Actions ");
                    textt->setStyleSheet("border: none ;  background: black; color: white; font-size:18px;");
                }
                else if(index1==data.length()-2){
                    textt->setText("picks for you! ");
                    textt->setStyleSheet("border: none ;  background: black; color: white; font-size:18px; ");
                }
                else textt->setText("");
                moviename_button->setFixedSize(131,25);
                QVariant image = temp[6];
                QPixmap outPixmap = QPixmap(); // Create QPixmap, which will be placed in
                outPixmap = image.value<QPixmap>();
                QPixmap pixmap(outPixmap);
                QIcon ButtonIcon(pixmap);
                const QSize BUTTON_SIZE = QSize(131, 181);
                button->setIcon(ButtonIcon);
                button->setIconSize((BUTTON_SIZE));
                QSignalMapper* m_sigmapper = new QSignalMapper(this);
                connect(button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
                m_sigmapper->setMapping(button,movienameString);
                connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                QSignalMapper* m_sigmapper1 = new QSignalMapper(this);
                connect(moviename_button, SIGNAL(clicked()), m_sigmapper1, SLOT(map()));
                m_sigmapper1->setMapping(moviename_button,movienameString);
                connect(m_sigmapper1, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

                vbox->addWidget(textt);
                vbox->addWidget(button);
                vbox->addWidget(moviename_button);
                vbox->addWidget(blank);
                layout->addLayout(vbox,k+1,i);
                ui->parentScroll->setLayout(layout);
                index1--;
    }//forloopclosed
   }//forloopclosed
       }//foragecheckclosed
            else{//elseforage
                data = db1.getAllanimated();
              int   index1 = data.length()-1;
                    for (int i = 0; i < 5; ++i) {
                        for (int k = 0; k < 1; ++k){


                            QList<QVariant> temp = data[index1];
                            QVBoxLayout* vbox = new QVBoxLayout();
                            QPushButton* moviename_button = new QPushButton();
                            QLabel* blank = new QLabel();
                            QPushButton* button = new QPushButton();
                            QLabel* textt = new QLabel();
                            QVariant movietitle = temp[0];
                            QString movienameString = movietitle.toString();
                            moviename_button->setText(movienameString);
                            blank->setText("");
                            button->setFixedSize(135,185);
                            moviename_button->setStyleSheet("border: none ;  background: black; color: white; font-size:14px; text-decoration: underline;");
                            button->setStyleSheet("border-radius:0px; background:white ;");
                            if(index1==data.length()-1){
                                textt->setText("Some animated  ");
                                textt->setStyleSheet("border: none ;  background: black; color: white; font-size:18px;");
                            }
                            else if(index1==data.length()-2){
                                textt->setText("picks for you! ");
                                textt->setStyleSheet("border: none ;  background: black; color: white; font-size:18px; ");
                            }
                            else textt->setText("");
                            moviename_button->setFixedSize(131,25);
                            QVariant image = temp[6];
                            QPixmap outPixmap = QPixmap(); // Create QPixmap, which will be placed in
                            outPixmap = image.value<QPixmap>();
                            QPixmap pixmap(outPixmap);
                            QIcon ButtonIcon(pixmap);
                            const QSize BUTTON_SIZE = QSize(131, 181);
                            button->setIcon(ButtonIcon);
                            button->setIconSize((BUTTON_SIZE));
                            QSignalMapper* m_sigmapper = new QSignalMapper(this);
                            connect(button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
                            m_sigmapper->setMapping(button,movienameString);
                            connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                            QSignalMapper* m_sigmapper1 = new QSignalMapper(this);
                            connect(moviename_button, SIGNAL(clicked()), m_sigmapper1, SLOT(map()));
                            m_sigmapper1->setMapping(moviename_button,movienameString);
                            connect(m_sigmapper1, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

                            vbox->addWidget(textt);
                            vbox->addWidget(button);
                            vbox->addWidget(moviename_button);
                            vbox->addWidget(blank);
                            layout->addLayout(vbox,k+1,i);
                            ui->parentScroll->setLayout(layout);
                            index1--;
                }//forloopclosed

                }//forloopclosed
            }//elseforageclosed

        data = db1.getAllsouthindian();
        int index1 = data.length()-1;
            for (int i = 0; i < 5; ++i) {
                for (int k = 0; k < 1; ++k){


                    QList<QVariant> temp = data[index1];
                    QVBoxLayout* vbox = new QVBoxLayout();
                    QPushButton* moviename_button = new QPushButton();
                    QLabel* blank = new QLabel();
                    QPushButton* button = new QPushButton();
                    QLabel* textt = new QLabel();
                    QVariant movietitle = temp[0];
                    QString movienameString = movietitle.toString();
                    moviename_button->setText(movienameString);
                    blank->setText("");
                    button->setFixedSize(135,185);
                    moviename_button->setStyleSheet("border: none ;  background: black; color: white; font-size:14px; text-decoration: underline;");
                    button->setStyleSheet("border-radius:0px; background:white ;");
                    if(index1==data.length()-1){
                        textt->setText("Some South ");
                        textt->setStyleSheet("border: none ;  background: black; color: white; font-size:18px;");
                    }
                    else if(index1==data.length()-2){
                        textt->setText("Indian for you! ");
                        textt->setStyleSheet("border: none ;  background: black; color: white; font-size:18px; ");
                    }
                    else textt->setText("");
                    moviename_button->setFixedSize(131,25);
                    QVariant image = temp[6];
                    QPixmap outPixmap = QPixmap(); // Create QPixmap, which will be placed in
                    outPixmap = image.value<QPixmap>();
                    QPixmap pixmap(outPixmap);
                    QIcon ButtonIcon(pixmap);
                    const QSize BUTTON_SIZE = QSize(131, 181);
                    button->setIcon(ButtonIcon);
                    button->setIconSize((BUTTON_SIZE));
                    QSignalMapper* m_sigmapper = new QSignalMapper(this);
                    connect(button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
                    m_sigmapper->setMapping(button,movienameString);
                    connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                    QSignalMapper* m_sigmapper1 = new QSignalMapper(this);
                    connect(moviename_button, SIGNAL(clicked()), m_sigmapper1, SLOT(map()));
                    m_sigmapper1->setMapping(moviename_button,movienameString);
                    connect(m_sigmapper1, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

                    vbox->addWidget(textt);
                    vbox->addWidget(button);
                    vbox->addWidget(moviename_button);
                    vbox->addWidget(blank);
                    layout->addLayout(vbox,k+2,i);
                    ui->parentScroll->setLayout(layout);
                    index1--;
        }//forloopclosed

        }//forloopclosed
            data = db1.getAllmostrated();
             index1 = data.length()-1;
                for (int i = 0; i < 5; ++i) {
                    for (int k = 0; k < 1; ++k){


                        QList<QVariant> temp = data[index1];
                        QVBoxLayout* vbox = new QVBoxLayout();
                        QPushButton* moviename_button = new QPushButton();
                        QLabel* blank = new QLabel();
                        QPushButton* button = new QPushButton();
                        QLabel* textt = new QLabel();
                        QVariant movietitle = temp[0];
                        QString movienameString = movietitle.toString();
                        moviename_button->setText(movienameString);
                        blank->setText("");
                        button->setFixedSize(135,185);
                        moviename_button->setStyleSheet("border: none ;  background: black; color: white; font-size:14px; text-decoration: underline;");
                        button->setStyleSheet("border-radius:0px; background:white ;");
                        if(index1==data.length()-1){
                            textt->setText("Most Popular ");
                            textt->setStyleSheet("border: none ;  background: black; color: white; font-size:18px;");
                        }

                        else textt->setText("");
                        moviename_button->setFixedSize(131,25);
                        QVariant image = temp[6];
                        QPixmap outPixmap = QPixmap(); // Create QPixmap, which will be placed in
                        outPixmap = image.value<QPixmap>();
                        QPixmap pixmap(outPixmap);
                        QIcon ButtonIcon(pixmap);
                        const QSize BUTTON_SIZE = QSize(131, 181);
                        button->setIcon(ButtonIcon);
                        button->setIconSize((BUTTON_SIZE));
                        QSignalMapper* m_sigmapper = new QSignalMapper(this);
                        connect(button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
                        m_sigmapper->setMapping(button,movienameString);
                        connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                        QSignalMapper* m_sigmapper1 = new QSignalMapper(this);
                        connect(moviename_button, SIGNAL(clicked()), m_sigmapper1, SLOT(map()));
                        m_sigmapper1->setMapping(moviename_button,movienameString);
                        connect(m_sigmapper1, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

                        vbox->addWidget(textt);
                        vbox->addWidget(button);
                        vbox->addWidget(moviename_button);
                        vbox->addWidget(blank);
                        layout->addLayout(vbox,k+3,i);
                        ui->parentScroll->setLayout(layout);
                        index1--;
            }//forloopclosed

            }//forloopclosed
   }//checknationalityclosed
    else if(nationality=="indian"){//nationalitycheck
        QList<QList<QVariant>>data = db1.getAllhindi();
        qDebug()<<"Lenght: "<<data.length();
        QGridLayout *layout = new QGridLayout;

        int index = data.length()-  1;
        for (int i = 0; i < 5; ++i) {
            for (int k = 0; k < 1; ++k){


                QList<QVariant> temp1 = data[index];
                QVBoxLayout* vbox = new QVBoxLayout();
                QPushButton* moviename_button = new QPushButton();
                QLabel* blank = new QLabel();
                QPushButton* button = new QPushButton();
                QLabel* textt = new QLabel();
                QVariant movietitle = temp1[0];
                if(index==data.length()-1){
                    textt->setText("Recommended for");
                    textt->setStyleSheet("border: none ;  background: black; color: white; font-size:18px;");
                }
                else if(index==data.length()-2){
                    textt->setText(" you!");
                    textt->setStyleSheet("border: none ;  background: black; color: white; font-size:18px;");
                }
                else textt->setText("");
                QString movienameString = movietitle.toString();
                moviename_button->setText(movienameString);
                blank->setText("");
                button->setFixedSize(135,185);
                moviename_button->setStyleSheet("border: none ;  background: black; color: white; font-size:14px; text-decoration: underline;");
                button->setStyleSheet("border-radius:0px; background:white ;");

                moviename_button->setFixedSize(131,25);
                QVariant image = temp1[6];
                QPixmap outPixmap = QPixmap(); // Create QPixmap, which will be placed in
                outPixmap = image.value<QPixmap>();
                QPixmap pixmap(outPixmap);
                QIcon ButtonIcon(pixmap);
                const QSize BUTTON_SIZE = QSize(131, 181);
                button->setIcon(ButtonIcon);
                button->setIconSize((BUTTON_SIZE));
                QSignalMapper* m_sigmapper = new QSignalMapper(this);
                connect(button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
                m_sigmapper->setMapping(button,movienameString);
                connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                QSignalMapper* m_sigmapper1 = new QSignalMapper(this);
                connect(moviename_button, SIGNAL(clicked()), m_sigmapper1, SLOT(map()));
                m_sigmapper1->setMapping(moviename_button,movienameString);
                connect(m_sigmapper1, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                vbox->addWidget(textt);
                vbox->addWidget(button);
                vbox->addWidget(moviename_button);
                vbox->addWidget(blank);
                layout->addLayout(vbox,k,i);
                ui->parentScroll->setLayout(layout);
                index--;
    }//forloopclosed

    }//forloopclosed
        if(age>=45){//checkage

            data = db1.getAllhistory();
            int index1 = data.length()-1;
                for (int i = 0; i < 5; ++i) {
                    for (int k = 0; k < 1; ++k){


                        QList<QVariant> temp = data[index1];
                        QVBoxLayout* vbox = new QVBoxLayout();
                        QPushButton* moviename_button = new QPushButton();
                        QLabel* blank = new QLabel();
                        QPushButton* button = new QPushButton();
                        QLabel* textt = new QLabel();
                        QVariant movietitle = temp[0];
                        QString movienameString = movietitle.toString();
                        moviename_button->setText(movienameString);
                        blank->setText("");
                        button->setFixedSize(135,185);
                        moviename_button->setStyleSheet("border: none ;  background: black; color: white; font-size:14px; text-decoration: underline;");
                        button->setStyleSheet("border-radius:0px; background:white ;");
                        if(index1==data.length()-1){
                            textt->setText("Picks for ");
                            textt->setStyleSheet("border: none ;  background: black; color: white; font-size:18px;");
                        }
                        else if(index1==data.length()-2){
                            textt->setText(" you! ");
                            textt->setStyleSheet("border: none ;  background: black; color: white; font-size:18px; ");
                        }
                        else textt->setText("");
                        moviename_button->setFixedSize(131,25);
                        QVariant image = temp[6];
                        QPixmap outPixmap = QPixmap(); // Create QPixmap, which will be placed in
                        outPixmap = image.value<QPixmap>();
                        QPixmap pixmap(outPixmap);
                        QIcon ButtonIcon(pixmap);
                        const QSize BUTTON_SIZE = QSize(131, 181);
                        button->setIcon(ButtonIcon);
                        button->setIconSize((BUTTON_SIZE));
                        QSignalMapper* m_sigmapper = new QSignalMapper(this);
                        connect(button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
                        m_sigmapper->setMapping(button,movienameString);
                        connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                        QSignalMapper* m_sigmapper1 = new QSignalMapper(this);
                        connect(moviename_button, SIGNAL(clicked()), m_sigmapper1, SLOT(map()));
                        m_sigmapper1->setMapping(moviename_button,movienameString);
                        connect(m_sigmapper1, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

                        vbox->addWidget(textt);
                        vbox->addWidget(button);
                        vbox->addWidget(moviename_button);
                        vbox->addWidget(blank);
                        layout->addLayout(vbox,k+1,i);
                        ui->parentScroll->setLayout(layout);
                        index1--;
            }//forloopclosed

            }//forloopclosed
        }//checkageclosed
        else if (age>=18) {//checkage


    data = db1.getAllaction();
    int index1 = data.length()-1;
        for (int i = 0; i < 5; ++i) {
            for (int k = 0; k < 1; ++k){


                QList<QVariant> temp = data[index1];
                QVBoxLayout* vbox = new QVBoxLayout();
                QPushButton* moviename_button = new QPushButton();
                QLabel* blank = new QLabel();
                QPushButton* button = new QPushButton();
                QLabel* textt = new QLabel();
                QVariant movietitle = temp[0];
                QString movienameString = movietitle.toString();
                moviename_button->setText(movienameString);
                blank->setText("");
                button->setFixedSize(135,185);
                moviename_button->setStyleSheet("border: none ;  background: black; color: white; font-size:14px; text-decoration: underline;");
                button->setStyleSheet("border-radius:0px; background:white ;");
                if(index1==data.length()-1){
                    textt->setText("Some Action ");
                    textt->setStyleSheet("border: none ;  background: black; color: white; font-size:18px;");
                }
                else if(index1==data.length()-2){
                    textt->setText("picks for you! ");
                    textt->setStyleSheet("border: none ;  background: black; color: white; font-size:18px; ");
                }
                else textt->setText("");
                moviename_button->setFixedSize(131,25);
                QVariant image = temp[6];
                QPixmap outPixmap = QPixmap(); // Create QPixmap, which will be placed in
                outPixmap = image.value<QPixmap>();
                QPixmap pixmap(outPixmap);
                QIcon ButtonIcon(pixmap);
                const QSize BUTTON_SIZE = QSize(131, 181);
                button->setIcon(ButtonIcon);
                button->setIconSize((BUTTON_SIZE));
                QSignalMapper* m_sigmapper = new QSignalMapper(this);
                connect(button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
                m_sigmapper->setMapping(button,movienameString);
                connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                QSignalMapper* m_sigmapper1 = new QSignalMapper(this);
                connect(moviename_button, SIGNAL(clicked()), m_sigmapper1, SLOT(map()));
                m_sigmapper1->setMapping(moviename_button,movienameString);
                connect(m_sigmapper1, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

                vbox->addWidget(textt);
                vbox->addWidget(button);
                vbox->addWidget(moviename_button);
                vbox->addWidget(blank);
                layout->addLayout(vbox,k+1,i);
                ui->parentScroll->setLayout(layout);
                index1--;
    }//forloopclosed
   }//forloopclosed
       }//agecheckclosed
     else//elseforage
   {
        data = db1.getAllanimated();
          int index1 = data.length()-1;
        for (int i = 0; i < 5; ++i) {
            for (int k = 0; k < 1; ++k){


                QList<QVariant> temp = data[index1];
                QVBoxLayout* vbox = new QVBoxLayout();
                QPushButton* moviename_button = new QPushButton();
                QLabel* blank = new QLabel();
                QPushButton* button = new QPushButton();
                QLabel* textt = new QLabel();
                QVariant movietitle = temp[0];
                QString movienameString = movietitle.toString();
                moviename_button->setText(movienameString);
                blank->setText("");
                button->setFixedSize(135,185);
                moviename_button->setStyleSheet("border: none ;  background: black; color: white; font-size:14px; text-decoration: underline;");
                button->setStyleSheet("border-radius:0px; background:white ;");
                if(index1==data.length()-1){
                    textt->setText("Animated Choice ");
                    textt->setStyleSheet("border: none ;  background: black; color: white; font-size:18px;");
                }
                else if(index1==data.length()-2){
                    textt->setText("picks for you! ");
                    textt->setStyleSheet("border: none ;  background: black; color: white; font-size:18px; ");
                }
                else textt->setText("");
                moviename_button->setFixedSize(131,25);
                QVariant image = temp[6];
                QPixmap outPixmap = QPixmap(); // Create QPixmap, which will be placed in
                outPixmap = image.value<QPixmap>();
                QPixmap pixmap(outPixmap);
                QIcon ButtonIcon(pixmap);
                const QSize BUTTON_SIZE = QSize(131, 181);
                button->setIcon(ButtonIcon);
                button->setIconSize((BUTTON_SIZE));
                QSignalMapper* m_sigmapper = new QSignalMapper(this);
                connect(button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
                m_sigmapper->setMapping(button,movienameString);
                connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                QSignalMapper* m_sigmapper1 = new QSignalMapper(this);
                connect(moviename_button, SIGNAL(clicked()), m_sigmapper1, SLOT(map()));
                m_sigmapper1->setMapping(moviename_button,movienameString);
                connect(m_sigmapper1, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

                vbox->addWidget(textt);
                vbox->addWidget(button);
                vbox->addWidget(moviename_button);
                vbox->addWidget(blank);
                layout->addLayout(vbox,k+1,i);
                ui->parentScroll->setLayout(layout);
                index1--;
    }//forloopclosed

    }//forloopclosed
    }//elseforageclosed
        data = db1.getAllsouthindian();
        int index1 = data.length()-1;
            for (int i = 0; i < 5; ++i) {
                for (int k = 0; k < 1; ++k){


                    QList<QVariant> temp = data[index1];
                    QVBoxLayout* vbox = new QVBoxLayout();
                    QPushButton* moviename_button = new QPushButton();
                    QLabel* blank = new QLabel();
                    QPushButton* button = new QPushButton();
                    QLabel* textt = new QLabel();
                    QVariant movietitle = temp[0];
                    QString movienameString = movietitle.toString();
                    moviename_button->setText(movienameString);
                    blank->setText("");
                    button->setFixedSize(135,185);
                    moviename_button->setStyleSheet("border: none ;  background: black; color: white; font-size:14px; text-decoration: underline;");
                    button->setStyleSheet("border-radius:0px; background:white ;");
                    if(index1==data.length()-1){
                        textt->setText("Some south Indian");
                        textt->setStyleSheet("border: none ;  background: black; color: white; font-size:18px;");
                    }
                    else textt->setText("");
                    moviename_button->setFixedSize(131,25);
                    QVariant image = temp[6];
                    QPixmap outPixmap = QPixmap(); // Create QPixmap, which will be placed in
                    outPixmap = image.value<QPixmap>();
                    QPixmap pixmap(outPixmap);
                    QIcon ButtonIcon(pixmap);
                    const QSize BUTTON_SIZE = QSize(131, 181);
                    button->setIcon(ButtonIcon);
                    button->setIconSize((BUTTON_SIZE));
                    QSignalMapper* m_sigmapper = new QSignalMapper(this);
                    connect(button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
                    m_sigmapper->setMapping(button,movienameString);
                    connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                    QSignalMapper* m_sigmapper1 = new QSignalMapper(this);
                    connect(moviename_button, SIGNAL(clicked()), m_sigmapper1, SLOT(map()));
                    m_sigmapper1->setMapping(moviename_button,movienameString);
                    connect(m_sigmapper1, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

                    vbox->addWidget(textt);
                    vbox->addWidget(button);
                    vbox->addWidget(moviename_button);
                    vbox->addWidget(blank);
                    layout->addLayout(vbox,k+2,i);
                    ui->parentScroll->setLayout(layout);
                    index1--;
        }//forloopclosed

        }//forloopclosed
            data = db1.getAllmostrated();
             index1 = data.length()-50;
                for (int i = 0; i < 5; ++i) {
                    for (int k = 0; k < 1; ++k){


                        QList<QVariant> temp = data[index1];
                        QVBoxLayout* vbox = new QVBoxLayout();
                        QPushButton* moviename_button = new QPushButton();
                        QLabel* blank = new QLabel();
                        QPushButton* button = new QPushButton();
                        QLabel* textt = new QLabel();
                        QVariant movietitle = temp[0];
                        QString movienameString = movietitle.toString();
                        moviename_button->setText(movienameString);
                        blank->setText("");
                        button->setFixedSize(135,185);
                        moviename_button->setStyleSheet("border: none ;  background: black; color: white; font-size:14px; text-decoration: underline;");
                        button->setStyleSheet("border-radius:0px; background:white ;");
                        if(index1==data.length()-50){
                            textt->setText("Most Popular ");
                            textt->setStyleSheet("border: none ;  background: black; color: white; font-size:18px;");
                        }

                        else textt->setText("");
                        moviename_button->setFixedSize(131,25);
                        QVariant image = temp[6];
                        QPixmap outPixmap = QPixmap(); // Create QPixmap, which will be placed in
                        outPixmap = image.value<QPixmap>();
                        QPixmap pixmap(outPixmap);
                        QIcon ButtonIcon(pixmap);
                        const QSize BUTTON_SIZE = QSize(131, 181);
                        button->setIcon(ButtonIcon);
                        button->setIconSize((BUTTON_SIZE));
                        QSignalMapper* m_sigmapper = new QSignalMapper(this);
                        connect(button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
                        m_sigmapper->setMapping(button,movienameString);
                        connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                        QSignalMapper* m_sigmapper1 = new QSignalMapper(this);
                        connect(moviename_button, SIGNAL(clicked()), m_sigmapper1, SLOT(map()));
                        m_sigmapper1->setMapping(moviename_button,movienameString);
                        connect(m_sigmapper1, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

                        vbox->addWidget(textt);
                        vbox->addWidget(button);
                        vbox->addWidget(moviename_button);
                        vbox->addWidget(blank);
                        layout->addLayout(vbox,k+3,i);
                        ui->parentScroll->setLayout(layout);
                        index1--;
            }//forloopclosed

            }//forloopclosed
          }//nationalitycheckclosed
    else {//elsefornationality
                    QList<QList<QVariant>>data = db1.getAllmostrated();
                    qDebug()<<"Lenght: "<<data.length();
                    QGridLayout *layout = new QGridLayout;

                    int index = data.length()-  1;
                    for (int i = 0; i < 5; ++i) {
                        for (int k = 0; k < 1; ++k){


                            QList<QVariant> temp1 = data[index];
                            QVBoxLayout* vbox = new QVBoxLayout();
                            QPushButton* moviename_button = new QPushButton();
                            QLabel* blank = new QLabel();
                            QPushButton* button = new QPushButton();
                            QLabel* textt = new QLabel();
                            QVariant movietitle = temp1[0];
                            if(index==data.length()-1){
                                textt->setText("Recommended just");
                                textt->setStyleSheet("border: none ;  background: black; color: white; font-size:18px;");
                            }
                            else if(index==data.length()-2){
                                textt->setText("For You!");
                                textt->setStyleSheet("border: none ;  background: black; color: white; font-size:18px;");
                            }
                            else textt->setText("");
                            QString movienameString = movietitle.toString();
                            moviename_button->setText(movienameString);
                            blank->setText("");
                            button->setFixedSize(135,185);
                            moviename_button->setStyleSheet("border: none ;  background: black; color: white; font-size:14px; text-decoration: underline;");
                            button->setStyleSheet("border-radius:0px; background:white ;");

                            moviename_button->setFixedSize(131,25);
                            QVariant image = temp1[6];
                            QPixmap outPixmap = QPixmap(); // Create QPixmap, which will be placed in
                            outPixmap = image.value<QPixmap>();
                            QPixmap pixmap(outPixmap);
                            QIcon ButtonIcon(pixmap);
                            const QSize BUTTON_SIZE = QSize(131, 181);
                            button->setIcon(ButtonIcon);
                            button->setIconSize((BUTTON_SIZE));
                            QSignalMapper* m_sigmapper = new QSignalMapper(this);
                            connect(button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
                            m_sigmapper->setMapping(button,movienameString);
                            connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                            QSignalMapper* m_sigmapper1 = new QSignalMapper(this);
                            connect(moviename_button, SIGNAL(clicked()), m_sigmapper1, SLOT(map()));
                            m_sigmapper1->setMapping(moviename_button,movienameString);
                            connect(m_sigmapper1, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                            vbox->addWidget(textt);
                            vbox->addWidget(button);
                            vbox->addWidget(moviename_button);
                            vbox->addWidget(blank);
                            layout->addLayout(vbox,k,i);
                            ui->parentScroll->setLayout(layout);
                            index--;
                }//forloopclosed

                }//forloopclosed
                    if(age>45){//checkage

                        data = db1.getAllhistory();
                        int index1 = data.length()-1;
                            for (int i = 0; i < 5; ++i) {
                                for (int k = 0; k < 1; ++k){


                                    QList<QVariant> temp = data[index1];
                                    QVBoxLayout* vbox = new QVBoxLayout();
                                    QPushButton* moviename_button = new QPushButton();
                                    QLabel* blank = new QLabel();
                                    QPushButton* button = new QPushButton();
                                    QLabel* textt = new QLabel();
                                    QVariant movietitle = temp[0];
                                    QString movienameString = movietitle.toString();
                                    moviename_button->setText(movienameString);
                                    blank->setText("");
                                    button->setFixedSize(135,185);
                                    moviename_button->setStyleSheet("border: none ;  background: black; color: white; font-size:14px; text-decoration: underline;");
                                    button->setStyleSheet("border-radius:0px; background:white ;");
                                    if(index1==data.length()-1){
                                        textt->setText("Picks for");
                                        textt->setStyleSheet("border: none ;  background: black; color: white; font-size:18px;");
                                    }
                                    else if(index1==data.length()-2){
                                        textt->setText(" you! ");
                                        textt->setStyleSheet("border: none ;  background: black; color: white; font-size:18px; ");
                                    }
                                    else textt->setText("");
                                    moviename_button->setFixedSize(131,25);
                                    QVariant image = temp[6];
                                    QPixmap outPixmap = QPixmap(); // Create QPixmap, which will be placed in
                                    outPixmap = image.value<QPixmap>();
                                    QPixmap pixmap(outPixmap);
                                    QIcon ButtonIcon(pixmap);
                                    const QSize BUTTON_SIZE = QSize(131, 181);
                                    button->setIcon(ButtonIcon);
                                    button->setIconSize((BUTTON_SIZE));
                                    QSignalMapper* m_sigmapper = new QSignalMapper(this);
                                    connect(button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
                                    m_sigmapper->setMapping(button,movienameString);
                                    connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                                    QSignalMapper* m_sigmapper1 = new QSignalMapper(this);
                                    connect(moviename_button, SIGNAL(clicked()), m_sigmapper1, SLOT(map()));
                                    m_sigmapper1->setMapping(moviename_button,movienameString);
                                    connect(m_sigmapper1, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

                                    vbox->addWidget(textt);
                                    vbox->addWidget(button);
                                    vbox->addWidget(moviename_button);
                                    vbox->addWidget(blank);
                                    layout->addLayout(vbox,k+1,i);
                                    ui->parentScroll->setLayout(layout);
                                    index1--;
                        }//forloopclosed

                        }//forloopclosed
                    }//checkageclosed
                    else if (age>=18&&age<=45) {//elseforcheckage


                data = db1.getAllaction();
                int index1 = data.length()-1;
                    for (int i = 0; i < 5; ++i) {
                        for (int k = 0; k < 1; ++k){


                            QList<QVariant> temp = data[index1];
                            QVBoxLayout* vbox = new QVBoxLayout();
                            QPushButton* moviename_button = new QPushButton();
                            QLabel* blank = new QLabel();
                            QPushButton* button = new QPushButton();
                            QLabel* textt = new QLabel();
                            QVariant movietitle = temp[0];
                            QString movienameString = movietitle.toString();
                            moviename_button->setText(movienameString);
                            blank->setText("");
                            button->setFixedSize(135,185);
                            moviename_button->setStyleSheet("border: none ;  background: black; color: white; font-size:14px; text-decoration: underline;");
                            button->setStyleSheet("border-radius:0px; background:white ;");
                            if(index1==data.length()-1){
                                textt->setText("Some Actions ");
                                textt->setStyleSheet("border: none ;  background: black; color: white; font-size:18px;");
                            }
                            else if(index1==data.length()-2){
                                textt->setText("picks for you! ");
                                textt->setStyleSheet("border: none ;  background: black; color: white; font-size:18px; ");
                            }
                            else textt->setText("");
                            moviename_button->setFixedSize(131,25);
                            QVariant image = temp[6];
                            QPixmap outPixmap = QPixmap(); // Create QPixmap, which will be placed in
                            outPixmap = image.value<QPixmap>();
                            QPixmap pixmap(outPixmap);
                            QIcon ButtonIcon(pixmap);
                            const QSize BUTTON_SIZE = QSize(131, 181);
                            button->setIcon(ButtonIcon);
                            button->setIconSize((BUTTON_SIZE));
                            QSignalMapper* m_sigmapper = new QSignalMapper(this);
                            connect(button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
                            m_sigmapper->setMapping(button,movienameString);
                            connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                            QSignalMapper* m_sigmapper1 = new QSignalMapper(this);
                            connect(moviename_button, SIGNAL(clicked()), m_sigmapper1, SLOT(map()));
                            m_sigmapper1->setMapping(moviename_button,movienameString);
                            connect(m_sigmapper1, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

                            vbox->addWidget(textt);
                            vbox->addWidget(button);
                            vbox->addWidget(moviename_button);
                            vbox->addWidget(blank);
                            layout->addLayout(vbox,k+1,i);
                            ui->parentScroll->setLayout(layout);
                            index1--;
                }//forloopclosed
               }//forloopclosed
                   }//agecheckedpclosed
                    else//elseforage
               {
                 data = db1.getAllanimated();
                int index1 = data.length()-1;
                    for (int i = 0; i < 5; ++i) {
                        for (int k = 0; k < 1; ++k){


                            QList<QVariant> temp = data[index1];
                            QVBoxLayout* vbox = new QVBoxLayout();
                            QPushButton* moviename_button = new QPushButton();
                            QLabel* blank = new QLabel();
                            QPushButton* button = new QPushButton();
                            QLabel* textt = new QLabel();
                            QVariant movietitle = temp[0];
                            QString movienameString = movietitle.toString();
                            moviename_button->setText(movienameString);
                            blank->setText("");
                            button->setFixedSize(135,185);
                            moviename_button->setStyleSheet("border: none ;  background: black; color: white; font-size:14px; text-decoration: underline;");
                            button->setStyleSheet("border-radius:0px; background:white ;");
                            if(index1==data.length()-1){
                                textt->setText("Let's animate ");
                                textt->setStyleSheet("border: none ;  background: black; color: white; font-size:18px;");
                            }
                            else if(index1==data.length()-2){
                                textt->setText(" Will you ?! ");
                                textt->setStyleSheet("border: none ;  background: black; color: white; font-size:18px; ");
                            }
                            else textt->setText("");
                            moviename_button->setFixedSize(131,25);
                            QVariant image = temp[6];
                            QPixmap outPixmap = QPixmap(); // Create QPixmap, which will be placed in
                            outPixmap = image.value<QPixmap>();
                            QPixmap pixmap(outPixmap);
                            QIcon ButtonIcon(pixmap);
                            const QSize BUTTON_SIZE = QSize(131, 181);
                            button->setIcon(ButtonIcon);
                            button->setIconSize((BUTTON_SIZE));
                            QSignalMapper* m_sigmapper = new QSignalMapper(this);
                            connect(button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
                            m_sigmapper->setMapping(button,movienameString);
                            connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                            QSignalMapper* m_sigmapper1 = new QSignalMapper(this);
                            connect(moviename_button, SIGNAL(clicked()), m_sigmapper1, SLOT(map()));
                            m_sigmapper1->setMapping(moviename_button,movienameString);
                            connect(m_sigmapper1, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

                            vbox->addWidget(textt);
                            vbox->addWidget(button);
                            vbox->addWidget(moviename_button);
                            vbox->addWidget(blank);
                            layout->addLayout(vbox,k+1,i);
                            ui->parentScroll->setLayout(layout);
                            index1--;
                }//forloopclosed

                }//forloopclosed
                }//elseageclosed
                    data = db1.getAllmostrated();
                    int index1 = data.length()-22;
                        for (int i = 0; i < 5; ++i) {
                            for (int k = 0; k < 1; ++k){


                                QList<QVariant> temp = data[index1];
                                QVBoxLayout* vbox = new QVBoxLayout();
                                QPushButton* moviename_button = new QPushButton();
                                QLabel* blank = new QLabel();
                                QPushButton* button = new QPushButton();
                                QLabel* textt = new QLabel();
                                QVariant movietitle = temp[0];
                                QString movienameString = movietitle.toString();
                                moviename_button->setText(movienameString);
                                blank->setText("");
                                button->setFixedSize(135,185);
                                moviename_button->setStyleSheet("border: none ;  background: black; color: white; font-size:14px; text-decoration: underline;");
                                button->setStyleSheet("border-radius:0px; background:white ;");
                                if(index1==data.length()-22){
                                    textt->setText("People's Choice ");
                                    textt->setStyleSheet("border: none ;  background: black; color: white; font-size:18px;");
                                }
                                else textt->setText("");
                                moviename_button->setFixedSize(131,25);
                                QVariant image = temp[6];
                                QPixmap outPixmap = QPixmap(); // Create QPixmap, which will be placed in
                                outPixmap = image.value<QPixmap>();
                                QPixmap pixmap(outPixmap);
                                QIcon ButtonIcon(pixmap);
                                const QSize BUTTON_SIZE = QSize(131, 181);
                                button->setIcon(ButtonIcon);
                                button->setIconSize((BUTTON_SIZE));
                                QSignalMapper* m_sigmapper = new QSignalMapper(this);
                                connect(button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
                                m_sigmapper->setMapping(button,movienameString);
                                connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                                QSignalMapper* m_sigmapper1 = new QSignalMapper(this);
                                connect(moviename_button, SIGNAL(clicked()), m_sigmapper1, SLOT(map()));
                                m_sigmapper1->setMapping(moviename_button,movienameString);
                                connect(m_sigmapper1, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

                                vbox->addWidget(textt);
                                vbox->addWidget(button);
                                vbox->addWidget(moviename_button);
                                vbox->addWidget(blank);
                                layout->addLayout(vbox,k+2,i);
                                ui->parentScroll->setLayout(layout);
                                index1--;
                    }//forloopclosed

                    }//forloopclosed
                        data = db1.getAllhindi();
                         index1 = data.length()-1;
                            for (int i = 0; i < 5; ++i) {
                                for (int k = 0; k < 1; ++k){


                                    QList<QVariant> temp = data[index1];
                                    QVBoxLayout* vbox = new QVBoxLayout();
                                    QPushButton* moviename_button = new QPushButton();
                                    QLabel* blank = new QLabel();
                                    QPushButton* button = new QPushButton();
                                    QLabel* textt = new QLabel();
                                    QVariant movietitle = temp[0];
                                    QString movienameString = movietitle.toString();
                                    moviename_button->setText(movienameString);
                                    blank->setText("");
                                    button->setFixedSize(135,185);
                                    moviename_button->setStyleSheet("border: none ;  background: black; color: white; font-size:14px; text-decoration: underline;");
                                    button->setStyleSheet("border-radius:0px; background:white ;");
                                    if(index1==data.length()-1){
                                        textt->setText("Bollywood");
                                        textt->setStyleSheet("border: none ;  background: black; color: white; font-size:18px;");
                                    }
                                    else if(index1==data.length()-2){
                                        textt->setText("Jollywood");
                                        textt->setStyleSheet("border: none ;  background: black; color: white; font-size:18px;");
                                    }

                                    else textt->setText("");
                                    moviename_button->setFixedSize(131,25);
                                    QVariant image = temp[6];
                                    QPixmap outPixmap = QPixmap(); // Create QPixmap, which will be placed in
                                    outPixmap = image.value<QPixmap>();
                                    QPixmap pixmap(outPixmap);
                                    QIcon ButtonIcon(pixmap);
                                    const QSize BUTTON_SIZE = QSize(131, 181);
                                    button->setIcon(ButtonIcon);
                                    button->setIconSize((BUTTON_SIZE));
                                    QSignalMapper* m_sigmapper = new QSignalMapper(this);
                                    connect(button, SIGNAL(clicked()), m_sigmapper, SLOT(map()));
                                    m_sigmapper->setMapping(button,movienameString);
                                    connect(m_sigmapper, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                                    QSignalMapper* m_sigmapper1 = new QSignalMapper(this);
                                    connect(moviename_button, SIGNAL(clicked()), m_sigmapper1, SLOT(map()));
                                    m_sigmapper1->setMapping(moviename_button,movienameString);
                                    connect(m_sigmapper1, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

                                    vbox->addWidget(textt);
                                    vbox->addWidget(button);
                                    vbox->addWidget(moviename_button);
                                    vbox->addWidget(blank);
                                    layout->addLayout(vbox,k+3,i);
                                    ui->parentScroll->setLayout(layout);
                                    index1--;
                        }//forloopclosed

                        }//forloopclosed
   }//elsefornationalityclosed
}//blockclosed



void ClientWin::on_trailer_button_clicked(QString tlink)
{
     QDesktopServices::openUrl(QUrl(tlink));
}

void ClientWin::on_movie_button_clicked(QString mlink)
{

}
