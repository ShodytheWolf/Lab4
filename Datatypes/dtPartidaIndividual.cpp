#include "dtPartidaIndividual.h"

dtPartidaIndividual::dtPartidaIndividual()
{

}

dtPartidaIndividual::dtPartidaIndividual(int idPart,time_t fechaIni, char* nombrejuego, bool conti, int IdPartidaAnt, float dura){
    this->idPartida = idPart;
    this->fechaInicio = fechaIni;
    this->nombreVideojuego = nombrejuego;
    this->continuacion = conti;
    this->idPartidaAnterior = IdPartidaAnt;
    this->duracion = dura;
}


dtPartidaIndividual::~dtPartidaIndividual()
{

}

bool dtPartidaIndividual::getContinuacion(){
    return this->continuacion;
};

int dtPartidaIndividual::getIdPartidaAnterior(){
    return this->idPartidaAnterior;
};

float dtPartidaIndividual::getDuracion(){
    return this->duracion;
};