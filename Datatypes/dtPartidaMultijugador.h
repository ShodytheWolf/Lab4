#ifndef DTPARTIDAMULTIJUGADOR_H
#define DTPARTIDAMULTIJUGADOR_H
#include "dtPartida.h"

#pragma once

class dtPartidaMultijugador : public dtPartida
{
public:
    dtPartidaMultijugador();
    ~dtPartidaMultijugador();

private:
    bool enVivo;
    char* nickHost;
    char* jugadoresUnidos[10]; //manejarlo con STL????
};

#endif