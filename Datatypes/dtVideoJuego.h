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

private:
    string nombreJuego;
    string nombreDesarrollador;
    string descripcionJuego;
    dtSuscripcion costo;
    bool estaSuscripto;
    string** categorias;
};

#endif