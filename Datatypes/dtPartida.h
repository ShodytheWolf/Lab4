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

   const char* getNombreVideojuego();
   virtual int getIdPartida();
   time_t getFecha();

protected:
    int idPartida;
    time_t fechaInicio = 0;
    const char* nombreVideojuego;
};

#endif