#ifndef VITALICIA_H
#define VITALICIA_H
#include "Suscripcion.h"
#pragma once

class Vitalicia : public Suscripcion
{
    public:
        Vitalicia();
        Vitalicia(float);
        ~Vitalicia();
        float getCostoVitalicia();
        void setCostoVitalicia(float costoVitalicia); 

    private:
        float costoVitalicia;

};

#endif