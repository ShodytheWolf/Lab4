#ifndef DTVIDEOJUEGO_H
#define DTVIDEOJUEGO_H
#include "dtSuscripcion.h"
using namespace std;
#include <iostream>
#pragma once

class dtVideoJuego
{
public:
    dtVideoJuego();
    ~dtVideoJuego();

    string getNombreVideojuego();
    string getNombreDesarrollador();
    string getDescripcionJuego();
    dtSuscripcion getDtSuscripcion();
    bool getEstaSuscripto();

private:
    string nombreJuego;
    string nombreDesarrollador;
    string descripcionJuego;
    dtSuscripcion costo;
    bool estaSuscripto;
    dtCategoria** dtCategorias;
};

#endif