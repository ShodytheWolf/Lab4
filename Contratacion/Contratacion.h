#ifndef CONTRATACION_H
#define CONTRATACION_H

#include "../Enumeration/enumPago.h"
#include "../Videojuego/Videojuego.h"
#include "../Enumeration/enumSuscripcion.h"
#include <ctime>

#pragma once

class Contratacion : public ICollectible
{
    public:
        Contratacion(Videojuego*,enumSuscripcion, enumPago, time_t);
        ~Contratacion();
        enumPago getMetodoDePago();
        void setMetodoDePago(enumPago metodoDePago);
        time_t getFechaDeSuscripcion();
        void setFechaDeSuscripcion(time_t fechaDeSuscripcion);
        enumSuscripcion getTipoSuscripto();

    private:
        Suscripcion* suscripcion;
        enumPago metodoDePago;
        time_t fechaDeSuscripcion;
};

#endif