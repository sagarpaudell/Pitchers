#ifndef LOGINWIN_H
#define LOGINWIN_H

#include <QMainWindow>
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
    void on_pushButton_clicked();

private:
    Ui::loginwin *ui;
    AdminWin *adminwin;
    ClientWin *clientwin;
};

#endif // LOGINWIN_H
