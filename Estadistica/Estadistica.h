#ifndef ESTADISTICA_H
#define ESTADISTICA_H
#include "../colecciones-genericas/interfaces/ICollectible.h"
#include "../Datatypes/dtEstadistica.h"
#include "../colecciones-genericas/String.h"

#pragma once

class Estadistica : public ICollectible
{
public:
    Estadistica(char*, string);
    ~Estadistica();

    String* getNombre();
    string getDescripcion();
    void setNombre(char* nuevoNombre);
    void setDescripcion(string nuevaDesc);
    float getDato();
    void setDato(float dato);
    void sumaHoras(float);
    dtEstadistica * getDtEstadistica();
    void calcularPromedio(int, int);

private:
    String* nombre;
    string descripcion;
    float dato;
};

#endif