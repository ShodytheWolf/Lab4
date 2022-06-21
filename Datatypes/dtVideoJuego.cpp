#include "dtVideoJuego.h"

dtVideoJuego::dtVideoJuego(string n, string nD, string d, dtSuscripcion* c, bool eS, string** cats, float pP, float hT)
{
    this->nombreJuego = n;
    this->nombreDesarrollador = nD;
    this->descripcionJuego = d;
    this->costo = c;
    this->estaSuscripto = eS;
    this->categorias = cats;
    this->puntajePromedio = pP;
    this->horasTotales = hT;
}

dtVideoJuego::dtVideoJuego(string n, string nD, string d, dtSuscripcion* c, bool eS, float pP, float hT)
{
    this->nombreJuego = n;
    this->nombreDesarrollador = nD;
    this->descripcionJuego = d;
    this->costo = c;
    this->estaSuscripto = eS;
    this->categorias = new string*();
    this->puntajePromedio = pP;
    this->horasTotales = hT;
}


dtVideoJuego::~dtVideoJuego()
{

}

string dtVideoJuego::getNombreVideojuego(){
    return this->nombreJuego;
}

string dtVideoJuego::getNombreDesarrollador(){
    return this->nombreDesarrollador;
}

string dtVideoJuego::getDescripcionJuego(){
    return this->descripcionJuego;
}

bool dtVideoJuego::getEstaSuscripto(){
    return this->estaSuscripto;
}

dtSuscripcion* dtVideoJuego::getCostos(){
    return this->costo;
}

string** dtVideoJuego::getCategorias() {
	return this->categorias;
}


float dtVideoJuego::getPuntajePromedio() {
    return this->puntajePromedio;
}


float dtVideoJuego::getHorasTotales() {
    return this->horasTotales;
}

