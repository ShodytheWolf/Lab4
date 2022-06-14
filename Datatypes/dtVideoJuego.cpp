#include "dtVideoJuego.h"

dtVideoJuego::dtVideoJuego()
{

}

dtVideoJuego::~dtVideoJuego()
{

}

char* dtVideoJuego::getNombreVideojuego(){
    return this->nombreJuego;
};

char* dtVideoJuego::getNombreDesarrollador(){
    return this->nombreDesarrollador;
};

char* dtVideoJuego::getDescripcionJuego(){
    return this->descripcionJuego;
};

bool dtVideoJuego::getEstaSuscripto(){
    return this->estaSuscripto;
};

dtSuscripcion dtVideoJuego::getDtSuscripcion(){
    return this->costo;
};