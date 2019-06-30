#ifndef REGWIN_H
#define REGWIN_H

#include <QMainWindow>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
class MainWindow;
class loginwin;
class AdminWin;
class  ClientWin;
namespace Ui {
class regwin;
}

class regwin : public QMainWindow
{
    Q_OBJECT

public:
    explicit regwin(QWidget *parent = nullptr);
    ~regwin();

private slots:
    void on_signin_clicked();

    void on_joinButton_clicked();

    void on_signupButton_clicked();

    void on_loginButton_clicked();

    void on_backButton_clicked();

private:
    Ui::regwin *ui;
    loginwin *loginWin;
    ClientWin *clientwin;
    AdminWin *adminwin;
    MainWindow *mainWindow;
};

#endif // REGWIN_H
