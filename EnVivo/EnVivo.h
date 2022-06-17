#ifndef ENVIVO_H
#define ENVIVO_H
#include "../Multijugador/Multijugador.h"
#include "../colecciones-genericas/interfaces/ICollection.h"
#include "../colecciones-genericas/collections/List.h"

#pragma once

class EnVivo : public Multijugador
{
public:
    EnVivo();
    ~EnVivo();

private:
    ICollection* comentarios = new List();
};

#endif