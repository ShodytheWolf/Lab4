#include "dtSuscripcion.h"

dtSuscripcion::dtSuscripcion()
{

}

dtSuscripcion::dtSuscripcion(float costoMen, float costoTri, float costoAn, float costoVit){

    this->costoAnual = costoAn;
    this->costoMensual = costoMen;
    this->costoTrimestral = costoTri;
    this->costoVitalicia = costoVit;
}

dtSuscripcion::~dtSuscripcion()
{

}

float dtSuscripcion::getCostoMensual(){
    return this->costoMensual;
};

float dtSuscripcion::getCostoTrimestral(){
    return this->costoTrimestral;
};

float dtSuscripcion::getCostoAnual(){
    return this->costoAnual;
};

float dtSuscripcion::getCostoVitalicia(){
    return this->costoVitalicia;
};