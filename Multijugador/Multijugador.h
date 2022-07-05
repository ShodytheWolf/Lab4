#ifndef MULTIJUGADOR_H
#define MULTIJUGADOR_H
#include "../Partida/Partida.h"
#include "../Datatypes/dtPartidaMultijugador.h" //CUIDADO
#include <ctime>
#pragma once

class Multijugador : public Partida
{
    public:
        Multijugador();
        Multijugador(int id, time_t fechaInicio, double dura,Videojuego* vjuego,string** jugadoresUnidos);
        ~Multijugador();
        void setDuracion(double dura);
        dtPartida* getDtPartida(string papaOso);
        dtPartida* getDtPartida();
        void registrarHoraRetiro(time_t horaFinalizada);
    protected:
        time_t** horaRetiro;
        string** jugadoresUnidos;
};

#endif