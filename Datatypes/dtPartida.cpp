#include "dtPartida.h"

dtPartida::dtPartida()
{

}

dtPartida::~dtPartida()
{

}

string dtPartida::getNombreVideojuego(){
    return this->nombreVideojuego;
};

int dtPartida::getIdPartida(){
    return this->idPartida;
}

time_t dtPartida::getFecha(){
    return this->fechaInicio;
}