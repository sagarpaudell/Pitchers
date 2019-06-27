#ifndef REGISTERWIN_H
#define REGISTERWIN_H

#include <QMainWindow>

class MainWindow;

namespace Ui {
class Registerwin;
}

class Registerwin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Registerwin(QWidget *parent = nullptr);
    ~Registerwin();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Registerwin *ui;
    MainWindow *mainWindow;
};

#endif // REGISTERWIN_H
