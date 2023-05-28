#include "AreaCritica.h"

AreaCritica::AreaCritica(std::array<int,2> pos1, std::array<int,2> pos2)
{
    this->pos1 = pos1;
    this->pos2 = pos2;
    this->ocupado = false;
}
bool AreaCritica::isLivre(){
    if (this->ocupado == true){
        return false;
    }
    return true;
}
void AreaCritica::ocupar(){
    this->ocupado = true;
}
void AreaCritica::liberar(){
    this->ocupado = false;
}
