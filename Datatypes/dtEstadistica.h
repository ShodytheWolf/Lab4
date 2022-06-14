#ifndef DTESTADISTICA_H
#define DTESTADISTICA_H

#pragma once

class dtEstadistica
{
public:
    dtEstadistica();
    ~dtEstadistica();

    char* getNombre();
    float getDato();

private:
    char* nombre;
    float dato;
};

#endif