#ifndef DTPARTIDAMULTIJUGADOR_H
#define DTPARTIDAMULTIJUGADOR_H
#include "dtPartida.h"

#pragma once

class dtPartidaMultijugador : public dtPartida
{
public:
    dtPartidaMultijugador();
    ~dtPartidaMultijugador();
    
    bool getEnVivo();
    string getnickHost();
private:
    bool enVivo;
    string nickHost;
    string** jugadoresUnidos;
};

#endif