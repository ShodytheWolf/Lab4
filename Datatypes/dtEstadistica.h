#ifndef DTESTADISTICA_H
#define DTESTADISTICA_H

#pragma once

class dtEstadistica
{
public:
    dtEstadistica();
    ~dtEstadistica();
    dtEstadistica(char* nom, float datinho);

    char* getNombre();
    float getDato();

private:
    char* nombre;
    float dato;
};

#endif