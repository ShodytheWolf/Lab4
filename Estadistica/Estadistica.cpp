#include <iostream>
#include "Estadistica.h"

using namespace std;

Estadistica::Estadistica(char* nombre, string descripcion)
{
    this->dato = 0;
    this->nombre = new String(nombre);
    this->descripcion = descripcion;
}

Estadistica::~Estadistica()
{

}

float Estadistica::getDato() {
    return this->dato;
}
void Estadistica::setDato(float dato) {
    this->dato = dato;
}

void Estadistica::setDescripcion(string nuevaDesc){
    this->descripcion = nuevaDesc;
};

void Estadistica::setNombre(char* nuevoNombre){
    this->nombre = new String(nuevoNombre);
};

String* Estadistica::getNombre(){
    return this->nombre;
};

string Estadistica::getDescripcion(){
    return this->descripcion;
};

dtEstadistica * Estadistica::getDtEstadistica(){

}


