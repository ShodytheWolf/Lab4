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

   string getNombreVideojuego();

private:
    int idPartida;
    //t_time FechaInicio;
    string nombreVideojuego;
};

#endif