#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H
#include "../colecciones-genericas/interfaces/ICollectible.h"

#pragma once

class Videojuego
{
public:
    Videojuego();
    ~Videojuego();



    char* getNombreJuego();
    void setNombreJuego(char* jueguito);
    char* getDescripcion();
    void setDescripcion(char* desc);
private:
    char* nombreJuego;
    char* descripcionJuego;
    ICollectible* categorias;
};

#endif