#ifndef DTSUSCRIPCION_H
#define DTSUSCRIPCION_H

#pragma once

class dtSuscripcion
{
public:
    dtSuscripcion();
    ~dtSuscripcion();

private:
    float costoMensual;
    float costoTrimestral;
    float costoAnual;
    float costoVitalicia;
};

#endif