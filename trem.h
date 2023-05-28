#ifndef TREM_H
#define TREM_H

#include <QThread>
#include <QMutex>

/*
 * Classe Trem herda QThread
 * Classe Trem passa a ser uma thread.
 * A função START inicializa a thread. Após inicializada, a thread irá executar a função RUN.
 * Para parar a execução da função RUN da thread, basta executar a função TERMINATE.
 *
*/
class Trem: public QThread{
 Q_OBJECT
public:
    Trem(int,int,int);  //construtor
    void run();         //função a ser executada pela thread
    void setVelocidade(int velocidade);


//Cria um sinal
signals:
    void updateGUI(int,int,int);

private:
   int x;           //posição X do trem na tela
   int y;           //posição Y do trem na tela
   int ID;          //ID do trem
   int velocidade;  //Velocidade. É o tempo de dormir em milisegundos entre a mudança de posição do trem
   static std::array<QMutex, 7> mutex;    //Um mutex para cada região crítica
   static std::array<bool, 7> areasCriticas; //Guarda se as areas criticas estão ou não ocupadas.
   int isArea0();
   int isArea1();
   int isArea2();
   int isArea3();
   int isArea4();
   int isArea5();
   int isArea6();

   void verifica0();
   void verifica1();
   void verifica2();
   void verifica3();
   void verifica4();
   void verifica5();
   void verifica6();

};

#endif // TREM_H
