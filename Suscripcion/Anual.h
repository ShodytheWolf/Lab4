#ifndef ANUAL_H
#define ANUAL_H
#include "Suscripcion.h"
#pragma once

class Anual : public Suscripcion
{
    public:
        Anual();
        Anual(float);
        ~Anual();
        float getCostoAnual();
        enumSuscripcion getTipo();
        void setCostoAnual(float costoAnual);
    private:
        float costoAnual;
        enumSuscripcion tipo = An;
};

#endif