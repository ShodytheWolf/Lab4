#include "dtSuscripcion.h"
#include <iostream>

using namespace std;

dtSuscripcion::dtSuscripcion()
{

}

dtSuscripcion::dtSuscripcion(float costoMen, float costoTri, float costoAn, float costoVit, enumSuscripcion tipoSus){

    this->costoAnual = costoAn;
    this->costoMensual = costoMen;
    this->costoTrimestral = costoTri;
    this->costoVitalicia = costoVit;
    this->tipo = tipoSus;
}

dtSuscripcion::~dtSuscripcion()
{

}

enumSuscripcion dtSuscripcion::getTipo() {
	return this->tipo;
}

float dtSuscripcion::getCostoMensual(){
    return this->costoMensual;
}

float dtSuscripcion::getCostoTrimestral(){
    return this->costoTrimestral;
}

float dtSuscripcion::getCostoAnual(){
    return this->costoAnual;
}

float dtSuscripcion::getCostoVitalicia(){
    return this->costoVitalicia;
}