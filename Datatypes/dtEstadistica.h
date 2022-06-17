#ifndef DTESTADISTICA_H
#define DTESTADISTICA_H

using namespace std;
#include <iostream>

#pragma once

class dtEstadistica
{
public:
    dtEstadistica();
    ~dtEstadistica();
    dtEstadistica(string nom, float datinho);

    string getNombre();
    float getDato();

private:
    string nombre;
    float dato;
};

#endif