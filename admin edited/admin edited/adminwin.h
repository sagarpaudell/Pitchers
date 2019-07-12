#ifndef ADMINWIN_H
#define ADMINWIN_H

#include <QMainWindow>
#include<QtSql>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QSqlQuery>
#include<QFileDialog>
#include<QPixmap>
#include<QTextEdit>
#include<QTableView>
#include<QTableWidget>

namespace Ui {
class AdminWin;
}

class AdminWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWin(QWidget *parent = nullptr);
    ~AdminWin();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_add_clicked();

    void on_browse_clicked();

    void on_clear_clicked();

    void on_show_clicked();

private:
    Ui::AdminWin *ui;
    QSqlDatabase database;
};

#endif // ADMINWIN_H
