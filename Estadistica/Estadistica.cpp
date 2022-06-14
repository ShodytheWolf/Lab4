#include "Estadistica.h"

Estadistica::Estadistica()
{

}

Estadistica::~Estadistica()
{

}

void Estadistica::setDescripcion(char* nuevaDesc){
    this->descripcion = nuevaDesc;
};

void Estadistica::setNombre(char* nuevoNombre){
    this->nombre = nuevoNombre;
};

char* Estadistica::getNombre(){
    return this->nombre;
};

char* Estadistica::getDescripcion(){
    return this->descripcion;
};

dtEstadistica * Estadistica::getDtEstadistica(){
    dtEstadistica * estadistica = new dtEstadistica(this->nombre,this->dato);
    return estadistica;
};