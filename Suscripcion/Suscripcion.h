#ifndef SUSCRIPCION_H
#define SUSCRIPCION_H
#include "../colecciones-genericas/interfaces/ICollectible.h"
#include "../Enumeration/enumSuscripcion.h"
#pragma once

class Suscripcion : public ICollectible
{
    public:
        Suscripcion();
        ~Suscripcion();
        char* getDescripcion();
        virtual enumSuscripcion getTipo() = 0;
        void setDescripcion(char* descripcion);
    private:
        char* descripcion;



};

#endif