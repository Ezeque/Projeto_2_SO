#include "trem.h"
#include <QtCore>

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        switch(ID){
        case 1:     //Trem 1
            if (y == 300 && x >140)
                x-=10;
            else if (x == 140 && y > 160)
                y-=10;
            else if (x < 370 && y == 160)
                x+=10;
            else
                y+=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;

        case 2: //Trem 2
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
        msleep(velocidade);
    }
}




