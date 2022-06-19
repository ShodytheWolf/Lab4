#ifndef CONTRATACION_H
#define CONTRATACION_H

#include "../Enumeration/enumPago.h"
#include "../Videojuego/Videojuego.h"
#include "../Enumeration/enumSuscripcion.h"
#include <ctime>

#pragma once

class Contratacion
{
    public:
        Contratacion(enumSuscripcion, enumPago, Videojuego*);
        ~Contratacion();
        enumPago getMetodoDePago();
        void setMetodoDePago(enumPago metodoDePago);
        time_t getFechaDeSuscripcion();
        void setFechaDeSuscripcion(time_t fechaDeSuscripcion);
    private:
        Suscripcion* suscripcion;
        enumPago metodoDePago;
        time_t fechaDeSuscripcion;
};

#endif