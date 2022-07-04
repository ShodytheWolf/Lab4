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
#include "../Suscripcion/Anual.h"//agregar al make
#include "../Suscripcion/Mensual.h"//agregar al make
#include "../Suscripcion/Trimestral.h"//agregar al make
#include "../Suscripcion/Vitalicia.h"//agregar al make
#include "../Datatypes/dtSuscripcion.h"
#include "../Datatypes/dtVideoJuego.h"
#include "../Estadistica/Estadistica.h"
#include "../Desarrollador/Desarrollador.h"

using namespace std;

#pragma once

class Videojuego : public ICollectible
{
public:
    Videojuego(const char*, string,Desarrollador*, dtSuscripcion*);
    ~Videojuego();

    String* getNombreJuego();
    void setNombreJuego(const char* nombreJuego);

    string getDescripcionJuego();
    void setDescripcionJuego(string descripcionJuego);

    Desarrollador* getDesarrollador();
    void setDesarrollador(Desarrollador* desarrollador);

    Anual* getSuscripcionAnual();
    Mensual* getSuscripcionMensual();
    Trimestral* getSuscripcionTrimestral();
    Vitalicia* getSuscripcionVitalicia();

    void aniadirCategoria(Categoria* cat);
    void addDtJuego(dtVideoJuego datosJuego); //armar datos
    dtEstadistica* getEstadisticas(const char*);
    string** getNombreCategorias();

protected:
    String* nombreJuego; // atributo que sera la key
    string descripcionJuego; 
    Desarrollador* desarrollador;
    IDictionary* categorias = new OrderedDictionary();
    Anual* suscripcionAnual;
    Mensual* suscripcionMensual;
    Trimestral* suscripcionTrimestral;
    Vitalicia* suscripcionVitalicia;
    IDictionary* estadisticas = new OrderedDictionary();
};

#endif