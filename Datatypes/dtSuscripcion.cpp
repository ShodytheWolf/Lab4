#include "dtSuscripcion.h"

dtSuscripcion::dtSuscripcion()
{

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