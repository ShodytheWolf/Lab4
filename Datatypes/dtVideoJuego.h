#ifndef DTVIDEOJUEGO.H_H
#define DTVIDEOJUEGO.H_H
#include "dtSuscripcion.h"
#pragma once

class dtVideoJuego
{
public:
    dtVideoJuego();
    ~dtVideoJuego();

private:
    char* nombreJuego;
    char* nombreDesarrollador;
    char* descripcionJuego;
    dtSuscripcion costo;
    bool estaSuscrito;
    //set de Categorias, no sé si hacer con los ICollection.
};

#endif