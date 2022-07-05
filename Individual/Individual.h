#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H
#include "../Partida/Partida.h"
#include "../Datatypes/dtPartidaIndividual.h" //CUIDADO

#pragma once

class Individual : public Partida
{
public:
    Individual();
    Individual(int id, time_t fechaInicio, double duracion, Videojuego* vj, Individual* partidaAContinuar);
    ~Individual();


    Individual* getPartidaContinuada();
    dtPartida* getDtPartida();
    dtPartida* getDtPartida(string papaOso);
    void setDuracion(double duracion);
    void setPartidaContinuada(Individual* partidaContinuada);

private:
    Individual* partidaContinuada;
};

#endif