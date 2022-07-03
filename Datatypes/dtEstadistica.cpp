#include "dtEstadistica.h"


dtEstadistica::dtEstadistica()
{

}

dtEstadistica::~dtEstadistica()
{

}

dtEstadistica::dtEstadistica(string name, float data){
    this->nombre = name;
    this->dato = data;

}

string dtEstadistica::getNombre(){
    return this->nombre;
};

float dtEstadistica::getDato(){
    return this->dato;
};