#ifndef DTJUGADOR_H
#define DTJUGADOR_H
using namespace std;
#include <iostream>

#pragma once

class dtJugador
{
public:
    dtJugador();
    ~dtJugador();

    string getNombre();
    string getDescripcion();
    
private:
    string nombre;
    string descripcion;
};

#endif