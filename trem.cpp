#include "trem.h"
#include <QtCore>
#include <QMutex>
#include <iostream>
#include <string>

std::array<bool, 7> Trem::areasCriticas{false, false, false, false, false, false, false}; // Definição do membro de dados estático
std::array<QMutex,7> Trem::mutex;

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
}

int Trem::isArea0(){
    if((x == 480&& y == 40) || (x == 520 && y == 40)){
        return 1;
    }
    else if((x == 480&& y == 160) || (x == 520 && y == 160)){
        return -1;
    }
    return 0;
}

void Trem::verifica0(){
    if (isArea0() == 1){
        mutex[0].lock();
        if(areasCriticas[0] == false){
            areasCriticas[0] = true;
        }
    }
    else if(isArea0() == -1 && areasCriticas[0] == true){// Verificando se a região crítica 1 está ocupado
        areasCriticas[0] = false;
        mutex[0].unlock();
    }
}

int Trem::isArea1(){
    if((x == 210 && y == 160) || (x == 390 && y == 160)){
        return 1;
    }
    else if((x == 230 && y == 140) || (x == 370 && y == 180)){
        return -1;
    }
    return 0;
}

void Trem::verifica1(){
    if (isArea1() == 1){
        mutex[1].lock();
        if(areasCriticas[1] == false){
            areasCriticas[1] = true;
        }
    }
    else if(isArea1() == -1 && areasCriticas[1] == true){// Verificando se a região crítica 1 está ocupado
        areasCriticas[1] = false;
        mutex[1].unlock();
    }
}

int Trem::isArea2(){
    if((x == 500 && y == 140) || (x == 370 && y == 180)){
        return 1;
    }
    else if((x == 520 && y == 160) || (x == 350 && y == 160)){
        return -1;
    }
    return 0;
}

void Trem::verifica2(){
    if (isArea2() == 1){
        mutex[2].lock();
        if(areasCriticas[2] == false){
            areasCriticas[2] = true;
        }
    }
    else if(isArea2() == -1 && areasCriticas[2] == true){// Verificando se a região crítica 1 está ocupado
        areasCriticas[2] = false;
        mutex[2].unlock();
    }
}

int Trem::isArea3(){
    if((x == 480 && y == 160) || (x == 670 && y == 160)){
        return 1;
    }
    else if((x == 500&& y == 140) || (x == 650 && y == 180)){
        return -1;
    }
    return 0;
}

void Trem::verifica3(){
    if (isArea3() == 1){
        mutex[3].lock();
        if(areasCriticas[3] == false){
            areasCriticas[3] = true;
        }
    }
    else if(isArea3() == -1 && areasCriticas[3] == true){// Verificando se a região crítica 1 está ocupado
        areasCriticas[3] = false;
        mutex[3].unlock();
    }
}

int Trem::isArea4(){
    if((x == 650 && y == 180) || (x == 770 && y == 140)){
        return 1;
    }
    else if((x == 630&& y == 160) || (x == 790 && y == 160)){
        return -1;
    }
    return 0;
}

void Trem::verifica4(){
    if (isArea4() == 1){
        mutex[4].lock();
        if(areasCriticas[4] == false){
            areasCriticas[4] = true;
        }
    }
    else if(isArea4() == -1 && areasCriticas[4] == true){// Verificando se a região crítica 1 está ocupado
        areasCriticas[4] = false;
        mutex[4].unlock();
        mutex[6].unlock();
    }
}

int Trem::isArea5(){
    if((x == 390 && y == 300) || (x == 350 && y == 160)){
        return 1;
    }
    else if((x == 390 && y == 160) || (x == 350 && y == 300)){
        return -1;
    }
    return 0;
}

void Trem::verifica5(){
    if (isArea5() == 1){
        mutex[5].lock();
        if(areasCriticas[5] == false){
            areasCriticas[5] = true;
        }
    }
    else if(isArea5() == -1 && areasCriticas[5] == true){// Verificando se a região crítica 1 está ocupado
        areasCriticas[5] = false;
        mutex[5].unlock();
    }
}

int Trem::isArea6(){
    if((x == 630 && y == 160) || (x == 670 && y == 300)){
        return 1;
    }
    else if((x == 630 && y == 300) || (x == 670 && y == 160)){
        return -1;
    }
    return 0;
}

void Trem::verifica6(){
    if (isArea6() == 1){
        mutex[6].lock();
        if(areasCriticas[4] == true){ //Trava a Área crítica 4 para impedir deadlock
            mutex[4].lock();
        }
        if(areasCriticas[6] == false){
            areasCriticas[6] = true;
        }
    }
    else if(isArea6() == -1 && areasCriticas[6] == true){// Verificando se a região crítica 1 está ocupado
        areasCriticas[6] = false;
        mutex[6].unlock();
    }
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        switch(ID){
        case 1:     //Trem 1
            //VERIFICANDO REGIÃO CRÍTICA 1
            verifica1();

            //VERIFICANDO REGIÃO CRÍTICA 5
            verifica5();

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
            //VERIFICANDO REGIÃO CRÍTICA 0
            verifica0();

            //VERIFICANDO REGIÃO CRÍTICA 1
            verifica1();

            //VERIFICANDO REGIÃO CRÍTICA 2
            verifica2();

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
            //VERIFICANDO REGIÃO CRÍTICA 0
            verifica0();

            //VERIFICANDO REGIÃO CRÍTICA 3
            verifica3();

            //VERIFICANDO REGIÃO CRÍTICA 4
            verifica4();

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
            //VERIFICANDO REGIÃO CRÍTICA 4
            verifica4();

            //VERIFICANDO REGIÃO CRÍTICA 6
            verifica6();
            else if(isArea6() == -1 && areasCriticas[6] == true){// Verificando se a região crítica 1 está ocupado
                areasCriticas[6] = false;
                mutex[6].unlock();
            }

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
            //VERIFICANDO REGIÃO CRÍTICA 2
            verifica2();

            //VERIFICANDO REGIÃO CRÍTICA 3
            verifica3();

            //VERIFICANDO REGIÃO CRÍTICA 5
            verifica5();

            //VERIFICANDO REGIÃO CRÍTICA 6
            verifica6();

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




