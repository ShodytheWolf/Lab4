#ifndef MENSUAL_H
#define MENSUAL_H
#include "Suscripcion.h"
#pragma once

class Mensual : public Suscripcion
{
    public:
        Mensual();
        ~Mensual();
        float getCostoMensual();
        void setCostoMensual(float costoMensual);
    private:
        float costoMensual;


};

#endif