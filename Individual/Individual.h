#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H
#include "../Partida/Partida.h"

#pragma once

class Individual : public Partida
{
public:
    Individual();
    Individual(int id, time_t fechaInicio, double duracion, Videojuego* vj, Individual* partidaAContinuar);
    ~Individual();


    Individual* getPartidaContinuada();
    void setDuracion(double duracion);
    void setPartidaContinuada(Individual* partidaContinuada);

private:
    Individual* partidaContinuada;
};

#endif