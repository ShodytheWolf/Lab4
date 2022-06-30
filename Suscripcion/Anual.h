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
        void setCostoAnual(float costoAnual);
    private:
        float costoAnual;
};

#endif