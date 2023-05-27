#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <array>
#include "trem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    static std::array<int, 6> localTrens;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    void updateInterface(int,int,int);

private:
    Ui::MainWindow *ui;

    //Cria os objetos TREM's
    Trem *trem1;
    Trem *trem2;
    Trem *trem3;
    Trem *trem4;
    Trem *trem5;
};

#endif // MAINWINDOW_H
