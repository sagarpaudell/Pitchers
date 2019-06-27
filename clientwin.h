#ifndef CLIENTWIN_H
#define CLIENTWIN_H

#include <QMainWindow>

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

    void on_pushButton_clicked();

private:
    Ui::ClientWin *ui;
};

#endif // CLIENTWIN_H
