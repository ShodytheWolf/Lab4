#ifndef DTPARTIDAINDIVIDUAL_H
#define DTPARTIDAINDIVIDUAL_H
#include "dtPartida.h"

#pragma once

class dtPartidaIndividual : public dtPartida
{
public:
    dtPartidaIndividual();
    dtPartidaIndividual(int IdPartidaAContinuar, string nombrejuego, bool esContinuada);
    dtPartidaIndividual(int idPart,time_t fechaIni,string nombrejuego, bool conti, int IdPartidaAnt, float dura);
    dtPartidaIndividual(string nombrejuego, bool noEsContinuadaxD);
    ~dtPartidaIndividual();

    bool getContinuacion();
    int getIdPartidaAnterior();
    float getDuracion();
    
private:
    bool continuacion;
    int idPartidaAnterior;
    float duracion;
};

#endif