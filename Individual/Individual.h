#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H
#include "../Partida/Partida.h"

#pragma once

class Individual : public Partida
{
public:
    Individual();
    ~Individual();
    Individual* getPartidaContinuada();
    void setPartidaContinuada(Individual* partidaContinuada);

private:
    Individual* partidaContinuada;
};

#endif