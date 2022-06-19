#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H
#include <iostream>
#include "../colecciones-genericas/String.h"
#include "../colecciones-genericas/interfaces/ICollection.h"
#include "../colecciones-genericas/collections/List.h"
#include "../colecciones-genericas/interfaces/IDictionary.h"
#include "../colecciones-genericas/collections/OrderedDictionary.h"
#include "../Categoria/Categoria.h"
#include "../Suscripcion/Suscripcion.h"
#include "../Datatypes/dtSuscripcion.h"
#include "../Datatypes/dtVideoJuego.h"
#include "../Estadistica/Estadistica.h"
#include "../Desarrollador/Desarrollador.h"

using namespace std;

#pragma once

class Videojuego : public ICollectible
{
public:
    Videojuego(char*, string);
    ~Videojuego();

    String getNombreJuego();
    void setNombreJuego(char* nombreJuego);

    string getDescripcionJuego();
    void setDescripcionJuego(string descripcionJuego);
    void aniadirCategoria(Categoria cat);
    void crearSuscripciones(dtSuscripcion costos);
    void addDtJuego(dtVideoJuego datosJuego);
    dtEstadistica** getEstadisticas();

private:
    String nombreJuego; // atributo que sera la key
    string descripcionJuego; 
    Desarrollador* desarrollador;
    ICollection* categorias = new List();
    ICollection* suscripciones = new List();
    IDictionary* estadisticas = new OrderedDictionary();
};

#endif