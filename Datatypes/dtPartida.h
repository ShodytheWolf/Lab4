#ifndef DTPARTIDA_H
#define DTPARTIDA_H
//#include"time.h"

#pragma once

class dtPartida
{
public:
    dtPartida();
    ~dtPartida();

    char* getNombreVideojuego();

private:
    int idPartida;
   // datetime FechaInicio; ver como era lo de las fechas
   char* nombreVideojuego;
};

#endif