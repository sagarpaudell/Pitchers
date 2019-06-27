#ifndef ADMINWIN_H
#define ADMINWIN_H

#include <QMainWindow>

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

private:
    Ui::AdminWin *ui;
};

#endif // ADMINWIN_H
