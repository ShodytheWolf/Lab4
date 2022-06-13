#ifndef DTPARTIDAINDIVIDUAL_H
#define DTPARTIDAINDIVIDUAL_H
#include "dtPartida.h"

#pragma once

class dtPartidaIndividual : public dtPartida
{
public:
    dtPartidaIndividual();
    ~dtPartidaIndividual();

private:
    bool continuacion;
    int idPartidaAnterior;
    float duracion;
};

#endif