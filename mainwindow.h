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

private slots:
    void on_velocidadeT2_valueChanged(int value);

    void on_velocidadeT1_valueChanged(int value);

    void on_velocidadeT3_valueChanged(int value);

    void on_velocidadeT4_valueChanged(int value);

    void on_velocidadeT5_valueChanged(int value);

private:
    Ui::MainWindow *ui;

    //Cria os objetos TREM's
    Trem *trem1;
    Trem *trem2;
    Trem *trem3;
    Trem *trem4;
    Trem *trem5;

    //Cria áreas críticas
    std::array<int, 4> area1;
    std::array<int, 4> area2;
    std::array<int, 4> area3;
    std::array<int, 4> area4;
    std::array<int, 4> area5;
    std::array<int, 4> area6;
    std::array<int, 4> area7;
};

#endif // MAINWINDOW_H
