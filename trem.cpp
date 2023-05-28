#include "trem.h"
#include <QtCore>
#include <QMutex>
#include <iostream>
#include <string>
#include "mainwindow.h"

std::array<QMutex,7> Trem::mutex;

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    this->velocidade = 100;
}

void Trem::setVelocidade(int velocidade){ //Setter de velocidade
    this->velocidade = velocidade;
}

int Trem::isArea0(){
    if((x == 480&& y == 40) || (x == 520 && y == 160)){
        MainWindow::localTrens[0] = ID;
        return 1;
    }
    else if((x == 480&& y == 160) || (x == 520 && y == 40)){
        MainWindow::localTrens[0] = 0;
        return -1;
    }
    return 0;
}

int Trem::isArea1(){
    if((x == 210 && y == 160) || (x == 390 && y == 160)){ //Verifica se a posição do trem corresponde à "entrada" da área crítica
        MainWindow::localTrens[ID] = 1;
        return 1;
    }
    else if((x == 230 && y == 140) || (x == 370 && y == 180)){ //Verifica se a posição do trem corresponde à "saída" da área crítica
        MainWindow::localTrens[ID] = 0;
        return -1;
    }
    return 0;
}

int Trem::isArea2(){
    if((x == 500 && y == 140) || (x == 370 && y == 180)){
        MainWindow::localTrens[ID] = 2;
        return 1;
    }
    else if((x == 520 && y == 160) || (x == 350 && y == 160)){
        MainWindow::localTrens[ID] = 0;
        return -1;
    }
    return 0;
}

int Trem::isArea3(){
    if((x == 480 && y == 160) || (x == 670 && y == 160)){
        MainWindow::localTrens[ID] = 3;
        return 1;
    }
    else if((x == 500&& y == 140) || (x == 650 && y == 180)){
        MainWindow::localTrens[ID] = 0;
        return -1;
    }
    return 0;
}

int Trem::isArea4(){
    if((x == 650 && y == 180) || (x == 770 && y == 140)){
        MainWindow::localTrens[ID] = 4;
        return 1;
    }
    else if((x == 630&& y == 160) || (x == 790 && y == 160)){
        MainWindow::localTrens[ID] = 0;
        return -1;
    }
    return 0;
}

int Trem::isArea5(){
    if((x == 390 && y == 300) || (x == 350 && y == 160)){
        MainWindow::localTrens[ID] = 5;
        return 1;
    }
    else if((x == 390 && y == 160) || (x == 350 && y == 300)){
        MainWindow::localTrens[ID] = 0;
        return -1;
    }
    return 0;
}

int Trem::isArea6(){
    if((x == 630 && y == 160) || (x == 670 && y == 300)){
        MainWindow::localTrens[ID] = 6;
        return 1;
    }
    else if((x == 630 && y == 300) || (x == 670 && y == 160)){
        MainWindow::localTrens[ID] = 0;
        return -1;
    }
    return 0;
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){

        if(this->velocidade == 0){
            continue;
        }

        switch(ID){
            case 1: //Trem 1

                if (isArea1() == 1){
                    mutex[1].lock();
                    mutex[5].lock();
                    }
                if (isArea5() == -1)
                    mutex[5].unlock();
                if (isArea1() == -1)
                    mutex[1].unlock();

                if (y == 300 && x >140)
                    x-=10;
                else if (x == 140 && y > 160)
                    y-=10;
                else if (x < 370 && y == 160){
                    x+=10;
                }
                else
                    y+=10;
                emit updateGUI(ID, x,y);    //Emite um sinal
                break;

            case 2: //Trem 2
                if (isArea0() == 1){
                    mutex[0].lock();
                    mutex[2].lock();
                    mutex[1].lock();
                    }
                if (isArea0() == -1)
                    mutex[0].unlock();
                if (isArea1() == -1)
                    mutex[1].unlock();
                if (isArea2() == -1)
                    mutex[2].unlock();

                if (y == 160 && x >230)
                    x-=10;
                else if (x == 230 && y > 40)
                    y-=10;
                else if (x < 500 && y == 40)
                    x+=10;
                else
                    y+=10;
                emit updateGUI(ID, x,y);    //Emite um sinal
                break;

            case 3: //Trem 3
                if (isArea4() == 1){
                    mutex[4].lock();
                    mutex[3].lock();
                    mutex[0].lock();
                    }
                if (isArea3() == -1)
                    mutex[3].unlock();
                if (isArea4() == -1)
                    mutex[4].unlock();
                if (isArea0() == -1)
                    mutex[0].unlock();

                if (y == 160 && x >500)
                    x-=10;
                else if (x == 500 && y > 40)
                    y-=10;
                else if (x < 770 && y == 40)
                    x+=10;
                else
                    y+=10;
                emit updateGUI(ID, x,y);    //Emite um sinal
                break;

            case 4: //Trem 4
                if (isArea6() == 1){
                    mutex[6].lock();
                    mutex[4].lock();
                    }
                if (isArea4() == -1)
                    mutex[4].unlock();
                if (isArea6() == -1)
                    mutex[6].unlock();
                if (y == 300 && x >650)
                    x-=10;
                else if (x == 650 && y > 160)
                    y-=10;
                else if (x < 880 && y == 160)
                    x+=10;
                else
                    y+=10;
                emit updateGUI(ID, x,y);    //Emite um sinal
                break;

            case 5: //Trem 5
                if (isArea5() == 1){
                    mutex[5].lock();
                    mutex[2].lock();
                    mutex[3].lock();
                    mutex[6].lock();
                    }
                    if (isArea2() == -1)
                        mutex[2].unlock();
                    if (isArea3() == -1)
                        mutex[3].unlock();
                    if (isArea5() == -1)
                        mutex[5].unlock();
                    if (isArea6() == -1)
                        mutex[6].unlock();
                if (y == 300 && x >370)
                    x-=10;
                else if (x == 370 && y > 160)
                    y-=10;
                else if (x < 650 && y == 160)
                    x+=10;
                else
                    y+=10;
                emit updateGUI(ID, x,y);    //Emite um sinal
                break;

            default:
                break;
        }
        msleep(230 - velocidade); // Espera 230 - "velocidade" ms.
    }

}




