#ifndef DTSUSCRIPCION_H
#define DTSUSCRIPCION_H

#pragma once

class dtSuscripcion
{
public:
    dtSuscripcion();
    dtSuscripcion(float costoMensual, float costoTrimestral, float costoAnual, float costoVitalicia);
    ~dtSuscripcion();

    float getCostoMensual();
    float getCostoTrimestral();
    float getCostoAnual();
    float getCostoVitalicia();
private:
    float costoMensual;
    float costoTrimestral;
    float costoAnual;
    float costoVitalicia;
};

#endif