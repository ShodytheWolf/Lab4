#ifndef DTVIDEOJUEGO.H_H
#define DTVIDEOJUEGO.H_H
#include "dtSuscripcion.h"
#pragma once

class dtVideoJuego
{
public:
    dtVideoJuego();
    ~dtVideoJuego();

    char* getNombreVideojuego();
    char* getNombreDesarrollador();
    char* getDescripcionJuego();
    dtSuscripcion getDtSuscripcion();
    bool getEstaSuscripto();

private:
    char* nombreJuego;
    char* nombreDesarrollador;
    char* descripcionJuego;
    dtSuscripcion costo;
    bool estaSuscripto;
    dtCategoria** dtCategorias;
};

#endif