#include "dtPartidaIndividual.h"

dtPartidaIndividual::dtPartidaIndividual()
{

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