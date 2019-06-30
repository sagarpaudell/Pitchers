#ifndef LOGINWIN_H
#define LOGINWIN_H

#include <QMainWindow>

#include  "regwin.h"
#include  "adminwin.h"
#include  "clientwin.h"
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
namespace Ui {
class loginwin;
}

class loginwin : public QMainWindow
{
    Q_OBJECT

public:
    explicit loginwin(QWidget *parent = nullptr);
    ~loginwin();

private slots:

    void on_loginButton_clicked();

    void on_signupButton_clicked();

private:
    Ui::loginwin *ui;
    AdminWin *adminwin;
    ClientWin *clientwin;
    regwin *regWin;



};

#endif // LOGINWIN_H
