#include <iostream>
#include "Estadistica.h"
#include "../colecciones-genericas/String.h"
using namespace std;

Estadistica::Estadistica(char* nombre, string descripcion)
{
    this->nombre = String(nombre);
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
    this->nombre = String(nuevoNombre);
};

String Estadistica::getNombre(){
    return this->nombre;
};

string Estadistica::getDescripcion(){
    return this->descripcion;
};

dtEstadistica * Estadistica::getDtEstadistica(){

}


