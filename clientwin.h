#ifndef CLIENTWIN_H
#define CLIENTWIN_H

#include <QMainWindow>
#include <QStackedWidget>
#include "movie_details.h"
namespace Ui {
class ClientWin;
}

class ClientWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClientWin(QWidget *parent = nullptr);
    ~ClientWin();

private slots:

    void on_home_clicked();

    void on_mostrated_clicked();

    void on_action_clicked();

    void on_adventure_clicked();

    void on_crime_clicked();

    void on_drama_clicked();

    void on_romance_clicked();

    void on_pushButton_40_clicked();

    void on_djangounchained_clicked();

    void on_casblanca_clicked();

private:
    Ui::ClientWin *ui;
    Movie_Details *movie_details;
};

#endif // CLIENTWIN_H
