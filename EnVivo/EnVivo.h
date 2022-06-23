#ifndef ENVIVO_H
#define ENVIVO_H
#include "../Multijugador/Multijugador.h"
#include "../colecciones-genericas/interfaces/ICollection.h"
#include "../colecciones-genericas/collections/List.h"
#include "../Comentario/Comentario.h"

#pragma once

class EnVivo : public Multijugador
{
public:
    EnVivo();
    ~EnVivo();
    void eliminarComentarios();
private:
    ICollection* comentarios = new List();
};

#endif