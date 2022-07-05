#ifndef TRIMESTRAL_H
#define TRIMESTRAL_H
#include "Suscripcion.h"
#pragma once

class Trimestral : public Suscripcion
{
    public:
        Trimestral();
        Trimestral(float);
        ~Trimestral();
        float getCostoTrimestral();
        enumSuscripcion getTipo();
        void setCostoTrimestral(float costoTrimestral);

    private:
        float costoTrimestral;
        enumSuscripcion tipo = Trim;


};

#endif