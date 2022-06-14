#ifndef ESTADISTICA_H
#define ESTADISTICA_H
#include "../colecciones-genericas/interfaces/ICollectible.h"
#include "../Datatypes/dtEstadistica.h"

#pragma once

class Estadistica : public ICollectible
{
public:
    Estadistica();
    ~Estadistica();

    char* getNombre();
    char* getDescripcion();
    void setNombre(char* nuevoNombre);
    void setDescripcion(char* nuevaDesc);
    dtEstadistica * getDtEstadistica();
private:
    char* nombre;
    char* descripcion;
    float dato;
    float promedioPuntaje;
};

#endif