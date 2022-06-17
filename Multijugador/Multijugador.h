#ifndef MULTIJUGADOR_H
#define MULTIJUGADOR_H
#include "../Partida/Partida.h"
#include <ctime>
#pragma once

class Multijugador : public Partida
{
    public:
        Multijugador();
        ~Multijugador();
        time_t registrarHoraRetiro();
    private:
         time_t** horaRetiro;
};

#endif