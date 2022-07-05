#ifndef MENSUAL_H
#define MENSUAL_H
#include "Suscripcion.h"
#pragma once

class Mensual : public Suscripcion
{
    public:
        Mensual();
        Mensual(float);
        ~Mensual();
        float getCostoMensual();
        enumSuscripcion getTipo();
        void setCostoMensual(float costoMensual);
    private:
        float costoMensual;
        enumSuscripcion tipo = Men;


};

#endif