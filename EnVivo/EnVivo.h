#ifndef ENVIVO_H
#define ENVIVO_H
#include "../Multijugador/Multijugador.h"
#include "../colecciones-genericas/interfaces/ICollection.h"

#pragma once

class EnVivo : public Multijugador
{
public:
    EnVivo();
    ~EnVivo();

private:
ICollection* comentarios;
};

#endif