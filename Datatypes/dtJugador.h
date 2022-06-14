#ifndef DTJUGADOR_H
#define DTJUGADOR_H

#pragma once

class dtJugador
{
public:
    dtJugador();
    ~dtJugador();

    char* getNombre();
    char* getDescripcion();
    
private:
    char* nombre;
    char* descripcion;
};

#endif