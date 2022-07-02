#ifndef MULTIJUGADOR_H
#define MULTIJUGADOR_H
#include "../Partida/Partida.h"
#include <ctime>
#pragma once

class Multijugador : public Partida
{
    public:
        Multijugador();
        Multijugador(int id, time_t fechaInicio, double dura,Videojuego* vjuego);
        ~Multijugador();
        void setDuracion(double dura);
        time_t registrarHoraRetiro();
    private:
        time_t** horaRetiro;
};

#endif