#ifndef SUSCRIPCION_H
#define SUSCRIPCION_H
#include "../colecciones-genericas/interfaces/ICollectible.h"

#pragma once

class Suscripcion : public ICollectible
{
    public:
        Suscripcion();
        ~Suscripcion();
        char* getDescripcion();
        void setDescripcion(char* descripcion);
    private:
        char* descripcion;



};

#endif