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
        void setCostoTrimestral(float costoTrimestral);

    private:
        float costoTrimestral;


};

#endif