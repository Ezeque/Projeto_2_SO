#ifndef AREACRITICA_H
#define AREACRITICA_H
#include <array>


class AreaCritica
{
public:
    AreaCritica(std::array<int,2> pos1, std::array<int,2> pos2);
    std::array<int,2> pos1;
    std::array<int,2> pos2;

private:
    bool ocupado;
    bool isLivre();
    void ocupar();
    void liberar();
};

#endif // AREACRITICA_H
