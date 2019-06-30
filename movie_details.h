#ifndef MOVIE_DETAILS_H
#define MOVIE_DETAILS_H

#include <QMainWindow>


namespace Ui {
class Movie_Details;
}

class Movie_Details : public QMainWindow
{
    Q_OBJECT

public:
    explicit Movie_Details(QWidget *parent = nullptr);
    ~Movie_Details();

private:
    Ui::Movie_Details *ui;
};

#endif // MOVIE_DETAILS_H
