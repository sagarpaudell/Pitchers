/********************************************************************************
** Form generated from reading UI file 'adminwin.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWIN_H
#define UI_ADMINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWin
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *addMovie;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *title_2;
    QLabel *year_2;
    QLabel *director_2;
    QLabel *imdb_2;
    QLabel *genre_2;
    QLineEdit *imdb;
    QLineEdit *director;
    QLineEdit *year;
    QLineEdit *title;
    QLineEdit *genre;
    QTextEdit *cast;
    QLabel *cast_2;
    QPushButton *add;
    QLabel *image_2;
    QLineEdit *image;
    QLabel *synopsis_2;
    QTextEdit *synopsis;
    QLabel *label;
    QLabel *piclabel;
    QPushButton *browse;
    QPushButton *clear;
    QWidget *removeMovie;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QLabel *title_3;
    QLineEdit *title_4;
    QPushButton *pushButton_6;
    QLabel *label_2;
    QWidget *usersList;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QLabel *label_3;
    QTableView *tableView;
    QPushButton *show;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QMainWindow *AdminWin)
    {
        if (AdminWin->objectName().isEmpty())
            AdminWin->setObjectName(QString::fromUtf8("AdminWin"));
        AdminWin->resize(1263, 692);
        AdminWin->setStyleSheet(QString::fromUtf8("\n"
"	background-image: url(:/adminbackground.jpg);\n"
"\n"
"\n"
"\n"
""));
        centralWidget = new QWidget(AdminWin);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8(""));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(-10, 0, 981, 681));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        addMovie = new QWidget();
        addMovie->setObjectName(QString::fromUtf8("addMovie"));
        scrollArea = new QScrollArea(addMovie);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(50, 90, 921, 571));
        scrollArea->setStyleSheet(QString::fromUtf8(""));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 919, 569));
        title_2 = new QLabel(scrollAreaWidgetContents);
        title_2->setObjectName(QString::fromUtf8("title_2"));
        title_2->setGeometry(QRect(160, 50, 111, 21));
        QFont font;
        font.setPointSize(12);
        title_2->setFont(font);
        title_2->setStyleSheet(QString::fromUtf8("color:white;\n"
""));
        year_2 = new QLabel(scrollAreaWidgetContents);
        year_2->setObjectName(QString::fromUtf8("year_2"));
        year_2->setGeometry(QRect(160, 90, 111, 21));
        year_2->setFont(font);
        year_2->setStyleSheet(QString::fromUtf8("color:white;\n"
""));
        director_2 = new QLabel(scrollAreaWidgetContents);
        director_2->setObjectName(QString::fromUtf8("director_2"));
        director_2->setGeometry(QRect(160, 130, 111, 21));
        director_2->setFont(font);
        director_2->setStyleSheet(QString::fromUtf8("color:white;\n"
""));
        imdb_2 = new QLabel(scrollAreaWidgetContents);
        imdb_2->setObjectName(QString::fromUtf8("imdb_2"));
        imdb_2->setGeometry(QRect(160, 170, 111, 21));
        imdb_2->setFont(font);
        imdb_2->setStyleSheet(QString::fromUtf8("color:white;\n"
""));
        genre_2 = new QLabel(scrollAreaWidgetContents);
        genre_2->setObjectName(QString::fromUtf8("genre_2"));
        genre_2->setGeometry(QRect(160, 210, 111, 21));
        genre_2->setFont(font);
        genre_2->setStyleSheet(QString::fromUtf8("color:white;\n"
""));
        imdb = new QLineEdit(scrollAreaWidgetContents);
        imdb->setObjectName(QString::fromUtf8("imdb"));
        imdb->setGeometry(QRect(320, 170, 271, 31));
        imdb->setStyleSheet(QString::fromUtf8("background:white;\n"
"color:black;\n"
"border-radius:10;"));
        director = new QLineEdit(scrollAreaWidgetContents);
        director->setObjectName(QString::fromUtf8("director"));
        director->setGeometry(QRect(320, 130, 271, 31));
        director->setStyleSheet(QString::fromUtf8("background:white;\n"
"color:black;\n"
"border-radius:10;"));
        year = new QLineEdit(scrollAreaWidgetContents);
        year->setObjectName(QString::fromUtf8("year"));
        year->setGeometry(QRect(320, 90, 271, 31));
        year->setStyleSheet(QString::fromUtf8("background:white;\n"
"color:black;\n"
"border-radius:10;"));
        title = new QLineEdit(scrollAreaWidgetContents);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(320, 50, 271, 31));
        title->setStyleSheet(QString::fromUtf8("background:white;\n"
"color:black;\n"
"border-radius:10;"));
        genre = new QLineEdit(scrollAreaWidgetContents);
        genre->setObjectName(QString::fromUtf8("genre"));
        genre->setGeometry(QRect(320, 210, 271, 31));
        genre->setStyleSheet(QString::fromUtf8("background:white;\n"
"color:black;\n"
"border-radius:10;"));
        cast = new QTextEdit(scrollAreaWidgetContents);
        cast->setObjectName(QString::fromUtf8("cast"));
        cast->setGeometry(QRect(320, 250, 271, 101));
        cast->setStyleSheet(QString::fromUtf8("background:white;\n"
"color:black;\n"
"border-radius:10;"));
        cast_2 = new QLabel(scrollAreaWidgetContents);
        cast_2->setObjectName(QString::fromUtf8("cast_2"));
        cast_2->setGeometry(QRect(160, 250, 111, 21));
        cast_2->setFont(font);
        cast_2->setStyleSheet(QString::fromUtf8("color:white;\n"
""));
        add = new QPushButton(scrollAreaWidgetContents);
        add->setObjectName(QString::fromUtf8("add"));
        add->setGeometry(QRect(380, 500, 141, 41));
        add->setFont(font);
        add->setStyleSheet(QString::fromUtf8("\n"
"	color: rgb(170, 0, 0);\n"
"padding-left:20px;\n"
"padding-right:20px;\n"
"border-radius:20px;\n"
"background:rgb(255, 0, 0);\n"
"color:rgb(255, 255, 255);\n"
""));
        image_2 = new QLabel(scrollAreaWidgetContents);
        image_2->setObjectName(QString::fromUtf8("image_2"));
        image_2->setGeometry(QRect(160, 470, 111, 21));
        image_2->setFont(font);
        image_2->setStyleSheet(QString::fromUtf8("color:white;\n"
""));
        image = new QLineEdit(scrollAreaWidgetContents);
        image->setObjectName(QString::fromUtf8("image"));
        image->setGeometry(QRect(320, 460, 271, 31));
        image->setStyleSheet(QString::fromUtf8("background:white;\n"
"color:black;\n"
"border-radius:10;"));
        synopsis_2 = new QLabel(scrollAreaWidgetContents);
        synopsis_2->setObjectName(QString::fromUtf8("synopsis_2"));
        synopsis_2->setGeometry(QRect(160, 360, 111, 21));
        synopsis_2->setFont(font);
        synopsis_2->setStyleSheet(QString::fromUtf8("color:white;\n"
""));
        synopsis = new QTextEdit(scrollAreaWidgetContents);
        synopsis->setObjectName(QString::fromUtf8("synopsis"));
        synopsis->setGeometry(QRect(320, 360, 271, 91));
        synopsis->setStyleSheet(QString::fromUtf8("background:white;\n"
"color:black;\n"
"border-radius:10;"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 20, 131, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MV Boli"));
        font1.setPointSize(14);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color:red;"));
        piclabel = new QLabel(scrollAreaWidgetContents);
        piclabel->setObjectName(QString::fromUtf8("piclabel"));
        piclabel->setGeometry(QRect(690, 50, 131, 181));
        piclabel->setMaximumSize(QSize(131, 181));
        piclabel->setSizeIncrement(QSize(131, 181));
        piclabel->setStyleSheet(QString::fromUtf8("color:white;"));
        piclabel->setFrameShape(QFrame::StyledPanel);
        piclabel->setLineWidth(18);
        browse = new QPushButton(scrollAreaWidgetContents);
        browse->setObjectName(QString::fromUtf8("browse"));
        browse->setGeometry(QRect(610, 460, 91, 31));
        browse->setFont(font);
        browse->setStyleSheet(QString::fromUtf8("\n"
"	color: rgb(170, 0, 0);\n"
"padding-left:20px;\n"
"padding-right:20px;\n"
"border-radius:10px;\n"
"background:rgb(255, 0, 0);\n"
"color:rgb(255, 255, 255);\n"
""));
        clear = new QPushButton(scrollAreaWidgetContents);
        clear->setObjectName(QString::fromUtf8("clear"));
        clear->setGeometry(QRect(720, 460, 161, 31));
        clear->setFont(font);
        clear->setStyleSheet(QString::fromUtf8("\n"
"	color: rgb(170, 0, 0);\n"
"padding-left:20px;\n"
"padding-right:20px;\n"
"border-radius:10px;\n"
"background:rgb(255, 0, 0);\n"
"color:rgb(255, 255, 255);\n"
""));
        scrollArea->setWidget(scrollAreaWidgetContents);
        stackedWidget->addWidget(addMovie);
        removeMovie = new QWidget();
        removeMovie->setObjectName(QString::fromUtf8("removeMovie"));
        scrollArea_2 = new QScrollArea(removeMovie);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(50, 90, 851, 551));
        scrollArea_2->setStyleSheet(QString::fromUtf8(""));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 849, 549));
        title_3 = new QLabel(scrollAreaWidgetContents_2);
        title_3->setObjectName(QString::fromUtf8("title_3"));
        title_3->setGeometry(QRect(180, 200, 111, 21));
        title_3->setFont(font);
        title_3->setStyleSheet(QString::fromUtf8("color:white;\n"
""));
        title_4 = new QLineEdit(scrollAreaWidgetContents_2);
        title_4->setObjectName(QString::fromUtf8("title_4"));
        title_4->setGeometry(QRect(340, 200, 271, 31));
        title_4->setStyleSheet(QString::fromUtf8("background:white;\n"
"color:black;\n"
"border-radius:10;"));
        pushButton_6 = new QPushButton(scrollAreaWidgetContents_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(400, 280, 141, 41));
        pushButton_6->setFont(font);
        pushButton_6->setStyleSheet(QString::fromUtf8("\n"
"	color: rgb(170, 0, 0);\n"
"padding-left:20px;\n"
"padding-right:20px;\n"
"border-radius:20px;\n"
"background:rgb(255, 0, 0);\n"
"color:rgb(255, 255, 255);\n"
""));
        label_2 = new QLabel(scrollAreaWidgetContents_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 20, 191, 16));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color:red;"));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        stackedWidget->addWidget(removeMovie);
        usersList = new QWidget();
        usersList->setObjectName(QString::fromUtf8("usersList"));
        scrollArea_3 = new QScrollArea(usersList);
        scrollArea_3->setObjectName(QString::fromUtf8("scrollArea_3"));
        scrollArea_3->setGeometry(QRect(60, 90, 851, 551));
        scrollArea_3->setAutoFillBackground(true);
        scrollArea_3->setStyleSheet(QString::fromUtf8(""));
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 849, 549));
        label_3 = new QLabel(scrollAreaWidgetContents_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 20, 191, 16));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color:red;"));
        tableView = new QTableView(scrollAreaWidgetContents_3);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(50, 60, 611, 391));
        show = new QPushButton(scrollAreaWidgetContents_3);
        show->setObjectName(QString::fromUtf8("show"));
        show->setGeometry(QRect(290, 490, 121, 41));
        show->setFont(font);
        show->setStyleSheet(QString::fromUtf8("\n"
"	color: rgb(170, 0, 0);\n"
"padding-left:20px;\n"
"padding-right:20px;\n"
"border-radius:20px;\n"
"background:rgb(255, 0, 0);\n"
"color:rgb(255, 255, 255);\n"
""));
        lineEdit = new QLineEdit(scrollAreaWidgetContents_3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(360, 20, 251, 31));
        lineEdit->setStyleSheet(QString::fromUtf8("background:white;\n"
"color:black;\n"
"border-radius:10;"));
        scrollArea_3->setWidget(scrollAreaWidgetContents_3);
        stackedWidget->addWidget(usersList);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 20, 121, 41));
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("\n"
"	color: rgb(170, 0, 0);\n"
"padding-left:20px;\n"
"padding-right:20px;\n"
"border-radius:20px;\n"
"background:rgb(255, 0, 0);\n"
"color:rgb(255, 255, 255);\n"
""));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(150, 20, 151, 41));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("\n"
"	color: rgb(170, 0, 0);\n"
"padding-left:20px;\n"
"padding-right:20px;\n"
"border-radius:20px;\n"
"background:rgb(255, 0, 0);\n"
"color:rgb(255, 255, 255);\n"
""));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(310, 20, 161, 41));
        pushButton_3->setFont(font);
        pushButton_3->setStyleSheet(QString::fromUtf8("\n"
"	color: rgb(170, 0, 0);\n"
"padding-left:20px;\n"
"padding-right:20px;\n"
"border-radius:20px;\n"
"background:rgb(255, 0, 0);\n"
"color:rgb(255, 255, 255);\n"
""));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(640, 20, 101, 41));
        pushButton_4->setFont(font);
        pushButton_4->setStyleSheet(QString::fromUtf8("\n"
"	color: rgb(170, 0, 0);\n"
"padding-left:20px;\n"
"padding-right:20px;\n"
"border-radius:20px;\n"
"background:rgb(255, 0, 0);\n"
"color:rgb(255, 255, 255);\n"
""));
        AdminWin->setCentralWidget(centralWidget);

        retranslateUi(AdminWin);

        QMetaObject::connectSlotsByName(AdminWin);
    } // setupUi

    void retranslateUi(QMainWindow *AdminWin)
    {
        AdminWin->setWindowTitle(QCoreApplication::translate("AdminWin", "AdminWin", nullptr));
        title_2->setText(QCoreApplication::translate("AdminWin", "Title", nullptr));
        year_2->setText(QCoreApplication::translate("AdminWin", "Year", nullptr));
        director_2->setText(QCoreApplication::translate("AdminWin", "Director", nullptr));
        imdb_2->setText(QCoreApplication::translate("AdminWin", "IMDb", nullptr));
        genre_2->setText(QCoreApplication::translate("AdminWin", "Genre", nullptr));
        cast_2->setText(QCoreApplication::translate("AdminWin", "Cast", nullptr));
        add->setText(QCoreApplication::translate("AdminWin", "Add Now", nullptr));
        image_2->setText(QCoreApplication::translate("AdminWin", "Image", nullptr));
        synopsis_2->setText(QCoreApplication::translate("AdminWin", "Synopsis", nullptr));
        label->setText(QCoreApplication::translate("AdminWin", "ADD MOVIES!", nullptr));
        piclabel->setText(QString());
        browse->setText(QCoreApplication::translate("AdminWin", "Browse", nullptr));
        clear->setText(QCoreApplication::translate("AdminWin", "Clear Selection", nullptr));
        title_3->setText(QCoreApplication::translate("AdminWin", "Title", nullptr));
        pushButton_6->setText(QCoreApplication::translate("AdminWin", "Remove Now", nullptr));
        label_2->setText(QCoreApplication::translate("AdminWin", "REMOVE MOVIE!", nullptr));
        label_3->setText(QCoreApplication::translate("AdminWin", "USER'S LIST:", nullptr));
        show->setText(QCoreApplication::translate("AdminWin", "Show Data", nullptr));
        pushButton->setText(QCoreApplication::translate("AdminWin", "Add Movies", nullptr));
        pushButton_2->setText(QCoreApplication::translate("AdminWin", "Remove Movies", nullptr));
        pushButton_3->setText(QCoreApplication::translate("AdminWin", "Registered Users", nullptr));
        pushButton_4->setText(QCoreApplication::translate("AdminWin", "Log Out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWin: public Ui_AdminWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWIN_H
