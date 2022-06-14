#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H
#include "../colecciones-genericas/interfaces/ICollection.h"
#include "../colecciones-genericas/collections/List.h"
#include "../Categoria/Categoria.h"
#include "../Suscripcion/Suscripcion.h"
#include "../Datatypes/dtSuscripcion.h"
#include "../Datatypes/dtVideoJuego.h"
#include "../Estadistica/Estadistica.h"

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
    void aniadirCategoria(Categoria cat);
    void crearSuscripciones(dtSuscripcion costos);
    void addDtJuego(dtVideoJuego datosJuego);
    List getEstadisticas(); //le tengo que pasar por parametro un set de strings, nidea como hacerlo uwu

private:
    char* nombreJuego;
    char* descripcionJuego;
    ICollection* categorias;
    ICollection* suscripciones;
    ICollection* estadisticas;
};

#endif