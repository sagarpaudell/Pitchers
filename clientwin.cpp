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

//    close();
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
            QSignalMapper* m_sigmapper1 = new QSignalMapper(this);
            connect(moviename_button, SIGNAL(clicked()), m_sigmapper1, SLOT(map()));
            m_sigmapper1->setMapping(moviename_button,movienameString);
            connect(m_sigmapper1, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

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
            QSignalMapper* m_sigmapper2 = new QSignalMapper(this);
            connect(button, SIGNAL(clicked()), m_sigmapper2, SLOT(map()));
            m_sigmapper2->setMapping(button,movienameString);
            connect(m_sigmapper2, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
            QSignalMapper* m_sigmapper3 = new QSignalMapper(this);
            connect(moviename_button, SIGNAL(clicked()), m_sigmapper3, SLOT(map()));
            m_sigmapper3->setMapping(moviename_button,movienameString);
            connect(m_sigmapper3, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

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
            QSignalMapper* m_sigmapper4 = new QSignalMapper(this);
            connect(button, SIGNAL(clicked()), m_sigmapper4, SLOT(map()));
            m_sigmapper4->setMapping(button,movienameString);
            connect(m_sigmapper4, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
            QSignalMapper* m_sigmapper5 = new QSignalMapper(this);
            connect(moviename_button, SIGNAL(clicked()), m_sigmapper5, SLOT(map()));
            m_sigmapper5->setMapping(moviename_button,movienameString);
            connect(m_sigmapper5, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

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
            QSignalMapper* m_sigmapper6 = new QSignalMapper(this);
            connect(button, SIGNAL(clicked()), m_sigmapper6, SLOT(map()));
            m_sigmapper6->setMapping(button,movienameString);
            connect(m_sigmapper6, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
            QSignalMapper* m_sigmapper7 = new QSignalMapper(this);
            connect(moviename_button, SIGNAL(clicked()), m_sigmapper7, SLOT(map()));
            m_sigmapper7->setMapping(moviename_button,movienameString);
            connect(m_sigmapper7, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

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
            QSignalMapper* m_sigmapper8 = new QSignalMapper(this);
            connect(button, SIGNAL(clicked()), m_sigmapper8, SLOT(map()));
            m_sigmapper8->setMapping(button,movienameString);
            connect(m_sigmapper8, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
            QSignalMapper* m_sigmapper9 = new QSignalMapper(this);
            connect(moviename_button, SIGNAL(clicked()), m_sigmapper9, SLOT(map()));
            m_sigmapper9->setMapping(moviename_button,movienameString);
            connect(m_sigmapper9, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

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

    QString nationality = data[5].toLower();
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
                QSignalMapper* m_sigmapper12 = new QSignalMapper(this);
                connect(button, SIGNAL(clicked()), m_sigmapper12, SLOT(map()));
                m_sigmapper12->setMapping(button,movienameString);
                connect(m_sigmapper12, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                 QSignalMapper* m_sigmapper12a = new QSignalMapper(this);
                connect(moviename_button, SIGNAL(clicked()), m_sigmapper12a, SLOT(map()));
                m_sigmapper12a->setMapping(moviename_button,movienameString);
                connect(m_sigmapper12a, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
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
                        QSignalMapper* m_sigmapper13 = new QSignalMapper(this);
                        connect(button, SIGNAL(clicked()), m_sigmapper13, SLOT(map()));
                        m_sigmapper13->setMapping(button,movienameString);
                        connect(m_sigmapper13, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                        QSignalMapper* m_sigmapper14 = new QSignalMapper(this);
                        connect(moviename_button, SIGNAL(clicked()), m_sigmapper14, SLOT(map()));
                        m_sigmapper14->setMapping(moviename_button,movienameString);
                        connect(m_sigmapper14, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

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
                QSignalMapper* m_sigmapper15 = new QSignalMapper(this);
                connect(button, SIGNAL(clicked()), m_sigmapper15, SLOT(map()));
                m_sigmapper15->setMapping(button,movienameString);
                connect(m_sigmapper15, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                QSignalMapper* m_sigmapper16 = new QSignalMapper(this);
                connect(moviename_button, SIGNAL(clicked()), m_sigmapper16, SLOT(map()));
                m_sigmapper16->setMapping(moviename_button,movienameString);
                connect(m_sigmapper16, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

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
                            QSignalMapper* m_sigmapper17= new QSignalMapper(this);
                            connect(button, SIGNAL(clicked()), m_sigmapper17, SLOT(map()));
                            m_sigmapper17->setMapping(button,movienameString);
                            connect(m_sigmapper17, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                            QSignalMapper* m_sigmapper18 = new QSignalMapper(this);
                            connect(moviename_button, SIGNAL(clicked()), m_sigmapper18, SLOT(map()));
                            m_sigmapper18->setMapping(moviename_button,movienameString);
                            connect(m_sigmapper18, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

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
                    QSignalMapper* m_sigmapper19 = new QSignalMapper(this);
                    connect(button, SIGNAL(clicked()), m_sigmapper19, SLOT(map()));
                    m_sigmapper19->setMapping(button,movienameString);
                    connect(m_sigmapper19, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                    QSignalMapper* m_sigmapper20 = new QSignalMapper(this);
                    connect(moviename_button, SIGNAL(clicked()), m_sigmapper20, SLOT(map()));
                    m_sigmapper20->setMapping(moviename_button,movienameString);
                    connect(m_sigmapper20, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

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
                        QSignalMapper* m_sigmapper21 = new QSignalMapper(this);
                        connect(button, SIGNAL(clicked()), m_sigmapper21, SLOT(map()));
                        m_sigmapper21->setMapping(button,movienameString);
                        connect(m_sigmapper21, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                        QSignalMapper* m_sigmapper22 = new QSignalMapper(this);
                        connect(moviename_button, SIGNAL(clicked()), m_sigmapper22, SLOT(map()));
                        m_sigmapper22->setMapping(moviename_button,movienameString);
                        connect(m_sigmapper22, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

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
                QSignalMapper* m_sigmapper23 = new QSignalMapper(this);
                connect(button, SIGNAL(clicked()), m_sigmapper23, SLOT(map()));
                m_sigmapper23->setMapping(button,movienameString);
                connect(m_sigmapper23, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                QSignalMapper* m_sigmapper24 = new QSignalMapper(this);
                connect(moviename_button, SIGNAL(clicked()), m_sigmapper24, SLOT(map()));
                m_sigmapper24->setMapping(moviename_button,movienameString);
                connect(m_sigmapper24, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
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
                        QSignalMapper* m_sigmapper25 = new QSignalMapper(this);
                        connect(button, SIGNAL(clicked()), m_sigmapper25, SLOT(map()));
                        m_sigmapper25->setMapping(button,movienameString);
                        connect(m_sigmapper25, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                        QSignalMapper* m_sigmapper26 = new QSignalMapper(this);
                        connect(moviename_button, SIGNAL(clicked()), m_sigmapper26, SLOT(map()));
                        m_sigmapper26->setMapping(moviename_button,movienameString);
                        connect(m_sigmapper26, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

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
                QSignalMapper* m_sigmapper27 = new QSignalMapper(this);
                connect(button, SIGNAL(clicked()), m_sigmapper27, SLOT(map()));
                m_sigmapper27->setMapping(button,movienameString);
                connect(m_sigmapper27, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                QSignalMapper* m_sigmapper28 = new QSignalMapper(this);
                connect(moviename_button, SIGNAL(clicked()), m_sigmapper28, SLOT(map()));
                m_sigmapper28->setMapping(moviename_button,movienameString);
                connect(m_sigmapper28, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

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
                QSignalMapper* m_sigmapper29 = new QSignalMapper(this);
                connect(button, SIGNAL(clicked()), m_sigmapper29, SLOT(map()));
                m_sigmapper29->setMapping(button,movienameString);
                connect(m_sigmapper29, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                QSignalMapper* m_sigmapper30 = new QSignalMapper(this);
                connect(moviename_button, SIGNAL(clicked()), m_sigmapper30, SLOT(map()));
                m_sigmapper30->setMapping(moviename_button,movienameString);
                connect(m_sigmapper30, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

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
                    QSignalMapper* m_sigmapper31 = new QSignalMapper(this);
                    connect(button, SIGNAL(clicked()), m_sigmapper31, SLOT(map()));
                    m_sigmapper31->setMapping(button,movienameString);
                    connect(m_sigmapper31, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                    QSignalMapper* m_sigmapper32 = new QSignalMapper(this);
                    connect(moviename_button, SIGNAL(clicked()), m_sigmapper32, SLOT(map()));
                    m_sigmapper32->setMapping(moviename_button,movienameString);
                    connect(m_sigmapper32, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

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
                        QSignalMapper* m_sigmapper33 = new QSignalMapper(this);
                        connect(button, SIGNAL(clicked()), m_sigmapper33, SLOT(map()));
                        m_sigmapper33->setMapping(button,movienameString);
                        connect(m_sigmapper33, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                        QSignalMapper* m_sigmapper34 = new QSignalMapper(this);
                        connect(moviename_button, SIGNAL(clicked()), m_sigmapper34, SLOT(map()));
                        m_sigmapper34->setMapping(moviename_button,movienameString);
                        connect(m_sigmapper34, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

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
                            QSignalMapper* m_sigmapper35 = new QSignalMapper(this);
                            connect(button, SIGNAL(clicked()), m_sigmapper35, SLOT(map()));
                            m_sigmapper35->setMapping(button,movienameString);
                            connect(m_sigmapper35, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                            QSignalMapper* m_sigmapper36 = new QSignalMapper(this);
                            connect(moviename_button, SIGNAL(clicked()), m_sigmapper36, SLOT(map()));
                            m_sigmapper36->setMapping(moviename_button,movienameString);
                            connect(m_sigmapper36, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
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
                                    QSignalMapper* m_sigmapper37 = new QSignalMapper(this);
                                    connect(button, SIGNAL(clicked()), m_sigmapper37, SLOT(map()));
                                    m_sigmapper37->setMapping(button,movienameString);
                                    connect(m_sigmapper37, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                                    QSignalMapper* m_sigmapper38 = new QSignalMapper(this);
                                    connect(moviename_button, SIGNAL(clicked()), m_sigmapper38, SLOT(map()));
                                    m_sigmapper38->setMapping(moviename_button,movienameString);
                                    connect(m_sigmapper38, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

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
                            QSignalMapper* m_sigmapper39 = new QSignalMapper(this);
                            connect(button, SIGNAL(clicked()), m_sigmapper39, SLOT(map()));
                            m_sigmapper39->setMapping(button,movienameString);
                            connect(m_sigmapper39, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                            QSignalMapper* m_sigmapper40 = new QSignalMapper(this);
                            connect(moviename_button, SIGNAL(clicked()), m_sigmapper40, SLOT(map()));
                            m_sigmapper40->setMapping(moviename_button,movienameString);
                            connect(m_sigmapper40, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

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
                            QSignalMapper* m_sigmapper41 = new QSignalMapper(this);
                            connect(button, SIGNAL(clicked()), m_sigmapper41, SLOT(map()));
                            m_sigmapper41->setMapping(button,movienameString);
                            connect(m_sigmapper41, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                            QSignalMapper* m_sigmapper42 = new QSignalMapper(this);
                            connect(moviename_button, SIGNAL(clicked()), m_sigmapper42, SLOT(map()));
                            m_sigmapper42->setMapping(moviename_button,movienameString);
                            connect(m_sigmapper42, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

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
                                QSignalMapper* m_sigmapper43 = new QSignalMapper(this);
                                connect(button, SIGNAL(clicked()), m_sigmapper43, SLOT(map()));
                                m_sigmapper43->setMapping(button,movienameString);
                                connect(m_sigmapper43, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                                QSignalMapper* m_sigmapper44 = new QSignalMapper(this);
                                connect(moviename_button, SIGNAL(clicked()), m_sigmapper44, SLOT(map()));
                                m_sigmapper44->setMapping(moviename_button,movienameString);
                                connect(m_sigmapper44, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

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
                                    QSignalMapper* m_sigmapper45 = new QSignalMapper(this);
                                    connect(button, SIGNAL(clicked()), m_sigmapper45, SLOT(map()));
                                    m_sigmapper45->setMapping(button,movienameString);
                                    connect(m_sigmapper45, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));
                                    QSignalMapper* m_sigmapper46 = new QSignalMapper(this);
                                    connect(moviename_button, SIGNAL(clicked()), m_sigmapper46, SLOT(map()));
                                    m_sigmapper46->setMapping(moviename_button,movienameString);
                                    connect(m_sigmapper46, SIGNAL(mapped(QString)),this, SLOT(display_movie_details(const QString)));

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



//void ClientWin::on_trailer_button_clicked(QString tlink)
//{
//     QDesktopServices::openUrl(QUrl(tlink));
//}

//void ClientWin::on_movie_button_clicked()
//{
//    qDebug()<<"grrdtgvxdfgvdx";
////    QString tempm= ui->movietitle->text();
////    qDebug()<<tempm;
////    DbManager d("moviedataset");
////    QSqlQuery query;
////    query.prepare (QString( "SELECT * FROM imdb WHERE UPPER(REPLACE(title, ' ', '')) = UPPER(REPLACE(:moviename, ' ', '')) union (SELECT * FROM nepali WHERE UPPER(REPLACE(title, ' ', '')) = UPPER(REPLACE(:moviename, ' ', '')))union(SELECT * FROM hindi WHERE UPPER(REPLACE(title, ' ', '')) = UPPER(REPLACE(:moviename, ' ', '')))union (SELECT * FROM kids WHERE UPPER(REPLACE(title, ' ', '')) = UPPER(REPLACE(:moviename, ' ', '')))union (SELECT * FROM southindian WHERE UPPER(REPLACE(title, ' ', '')) = UPPER(REPLACE(:moviename, ' ', '')))union (SELECT * FROM crime WHERE UPPER(REPLACE(title, ' ', '')) = UPPER(REPLACE(:moviename, ' ', '')))union (SELECT * FROM drama WHERE UPPER(REPLACE(title, ' ', '')) = UPPER(REPLACE(:moviename, ' ', '')))union (SELECT * FROM romance WHERE UPPER(REPLACE(title, ' ', '')) = UPPER(REPLACE(:moviename, ' ', '')))union (SELECT * FROM action WHERE UPPER(REPLACE(title, ' ', '')) = UPPER(REPLACE(:moviename, ' ', '')))union (SELECT * FROM history WHERE UPPER(REPLACE(title, ' ', '')) = UPPER(REPLACE(:moviename, ' ', '')))union (SELECT * FROM documentary WHERE UPPER(REPLACE(title, ' ', '')) = UPPER(REPLACE(:moviename, ' ', '')))"));
////    query.bindValue(":moviename",tempm);
////    if(query.exec()){
////        while (query.next()) {
////            QString mlink=query.value(10).toString();
////              qDebug()<<mlink;
////        }
////    }



////    QDesktopServices::openUrl(QUrl(mlink));
//}

void ClientWin::on_backButton_clicked()
{
    this->close();
    QWidget *parent = this->parentWidget();
    parent->show();
}
void ClientWin::display_movie_details(const QString temp){
     ui->stackedWidget->setCurrentIndex(7);
    DbManager db1("moviedataset");
      QSqlQuery query;
      query.prepare (QString( "SELECT * FROM imdb WHERE UPPER(REPLACE(title, ' ', '')) = UPPER(REPLACE(:moviename, ' ', '')) union (SELECT * FROM nepali WHERE UPPER(REPLACE(title, ' ', '')) = UPPER(REPLACE(:moviename, ' ', '')))union(SELECT * FROM hindi WHERE UPPER(REPLACE(title, ' ', '')) = UPPER(REPLACE(:moviename, ' ', '')))union (SELECT * FROM kids WHERE UPPER(REPLACE(title, ' ', '')) = UPPER(REPLACE(:moviename, ' ', '')))union (SELECT * FROM southindian WHERE UPPER(REPLACE(title, ' ', '')) = UPPER(REPLACE(:moviename, ' ', '')))union (SELECT * FROM crime WHERE UPPER(REPLACE(title, ' ', '')) = UPPER(REPLACE(:moviename, ' ', '')))union (SELECT * FROM drama WHERE UPPER(REPLACE(title, ' ', '')) = UPPER(REPLACE(:moviename, ' ', '')))union (SELECT * FROM romance WHERE UPPER(REPLACE(title, ' ', '')) = UPPER(REPLACE(:moviename, ' ', '')))union (SELECT * FROM action WHERE UPPER(REPLACE(title, ' ', '')) = UPPER(REPLACE(:moviename, ' ', '')))union (SELECT * FROM history WHERE UPPER(REPLACE(title, ' ', '')) = UPPER(REPLACE(:moviename, ' ', '')))union (SELECT * FROM documentary WHERE UPPER(REPLACE(title, ' ', '')) = UPPER(REPLACE(:moviename, ' ', '')))"));
      query.bindValue ( ":moviename",temp );
      QString tlink;
      QString mlink;

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
                         tlink=query.value(9).toString();
                         mlink=query.value(10).toString();
                     }
                    qDebug()<<tlink;

       }
      QSignalMapper* m_sigmapperq = new QSignalMapper(this);
     connect(ui->trailer_button, SIGNAL(clicked()), m_sigmapperq, SLOT(map()));
     m_sigmapperq->setMapping(ui->trailer_button,tlink);
     connect(m_sigmapperq, SIGNAL(mapped(QString)),this, SLOT(trailer(const QString)));
      QSignalMapper* m_sigmapperr = new QSignalMapper(this);
     connect(ui->movie_button, SIGNAL(clicked()), m_sigmapperr, SLOT(map()));
     m_sigmapperr->setMapping(ui->movie_button,mlink);
     connect(m_sigmapperr, SIGNAL(mapped(QString)),this, SLOT(movie(const QString)));




}
void ClientWin::on_commandLinkButton_clicked()
{

    QString search_movie = ui->search->text();
    display_movie_details(search_movie);

}
void ClientWin::trailer(QString tlink)
{

  QDesktopServices::openUrl(QUrl(tlink));


}
void ClientWin::movie(QString mlink)
{
     QDesktopServices::openUrl(QUrl(mlink));
}
