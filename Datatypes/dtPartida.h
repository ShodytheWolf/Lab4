#ifndef DTPARTIDA_H
#define DTPARTIDA_H
#include "time.h"

using namespace std;
#include <iostream>

#pragma once

class dtPartida
{
public:
    dtPartida();
    ~dtPartida();

   virtual char* getNombreVideojuego();
   int getIdPartida();
   time_t getFecha();

protected:
    int idPartida;
    time_t fechaInicio = 0;
    char* nombreVideojuego;
};

#endif