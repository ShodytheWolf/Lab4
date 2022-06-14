#ifndef CONTRATACION_H
#define CONTRATACION_H

#include "../Enumeration/enumPago.h"
#include <ctime>

#pragma once

class Contratacion
{
    public:
        Contratacion();
        ~Contratacion();
        enumPago getMetodoDePago();
        void setMetodoDePago(enumPago metodoDePago);
        time_t getFechaDeSuscripcion();
        void setFechaDeSuscripcion(time_t fechaDeSuscripcion);
    private:
        enumPago metodoDePago;
        time_t fechaDeSuscripcion;
};

#endif