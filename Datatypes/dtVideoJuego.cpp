#include "dtVideoJuego.h"

dtVideoJuego::dtVideoJuego()
{

}

dtVideoJuego::~dtVideoJuego()
{

}

string dtVideoJuego::getNombreVideojuego(){
    return this->nombreJuego;
};

string dtVideoJuego::getNombreDesarrollador(){
    return this->nombreDesarrollador;
};

string dtVideoJuego::getDescripcionJuego(){
    return this->descripcionJuego;
};

bool dtVideoJuego::getEstaSuscripto(){
    return this->estaSuscripto;
};

dtSuscripcion dtVideoJuego::getDtSuscripcion(){
    return this->costo;
};

string** dtVideoJuego::getCategorias() {
	return this->categorias;
};