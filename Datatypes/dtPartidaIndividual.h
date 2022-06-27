#ifndef DTPARTIDAINDIVIDUAL_H
#define DTPARTIDAINDIVIDUAL_H
#include "dtPartida.h"

#pragma once

class dtPartidaIndividual : public dtPartida
{
public:
    dtPartidaIndividual();
    dtPartidaIndividual(int IdPartidaAContinuar, char* nombrejuego, bool esContinuada);
    dtPartidaIndividual(int idPart,time_t fechaIni, char* nombrejuego, bool conti, int IdPartidaAnt, float dura);
    dtPartidaIndividual(char* nombrejuego, bool noEsContinuadaxD);
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