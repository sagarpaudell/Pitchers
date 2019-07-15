#ifndef CLIENTWIN_H
#define CLIENTWIN_H

#include <QMainWindow>
#include <QStackedWidget>
#include "movie_details.h"
#include  <QCompleter>

namespace Ui {
class ClientWin;
}

class ClientWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClientWin(QWidget *parent = nullptr,QString uname="");

    ~ClientWin();

private slots:
    void display_movie_details(const QString temp);
    void setrecommendedMovies(const QString uname);
    void setmostratedMovies();
    void setdramaMovies();
    void setcrimeMovies();
    void setromanceMovies();
    void setdocumentaryMovies();

    void on_home_clicked();

    void on_mostrated_clicked();

    void on_drama_clicked();

    void on_crime_clicked();

    void on_romance_clicked();

    void on_documentary_clicked();

    void on_commandLinkButton_clicked();

private:
    Ui::ClientWin *ui;
    Movie_Details *movie_details;
    QCompleter *moviename_completer;
    QString uname;
};
class user{
    public:

};

#endif // CLIENTWIN_H
