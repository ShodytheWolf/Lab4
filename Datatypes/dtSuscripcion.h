#ifndef DTSUSCRIPCION_H
#define DTSUSCRIPCION_H
#include "../Enumeration/enumSuscripcion.h"
#pragma once

class dtSuscripcion
{
public:
    dtSuscripcion();
    dtSuscripcion(float costoMensual, float costoTrimestral, float costoAnual, float costoVitalicia, enumSuscripcion* tipo);
    ~dtSuscripcion();

    float getCostoMensual();
    float getCostoTrimestral();
    float getCostoAnual();
    float getCostoVitalicia();
    enumSuscripcion* getTipo();
private:
    enumSuscripcion* tipo;
    float costoMensual;
    float costoTrimestral;
    float costoAnual;
    float costoVitalicia;
};

#endif