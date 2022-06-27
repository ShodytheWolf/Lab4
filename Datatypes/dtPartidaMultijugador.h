#ifndef DTPARTIDAMULTIJUGADOR_H
#define DTPARTIDAMULTIJUGADOR_H
#include "dtPartida.h"

#pragma once

class dtPartidaMultijugador : public dtPartida
{
public:
    dtPartidaMultijugador();
    dtPartidaMultijugador(int idParti,time_t fechaIni, char* juego,bool deVivo,string papaOso,string** nicksJuego);
    ~dtPartidaMultijugador();
    
    bool getEnVivo();
    string getnickHost();
    string** getjugadoresUnidos();
private:
    bool enVivo;
    string nickHost;
    string** jugadoresUnidos;
};

#endif