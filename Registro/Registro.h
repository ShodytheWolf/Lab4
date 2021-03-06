#ifndef REGISTRO_H
#define REGISTRO_H
#include "../Datatypes/dtVideoJuego.h"
#include "../Contratacion/Contratacion.h"
#include "../colecciones-genericas/interfaces/ICollectible.h"
#include "../colecciones-genericas/interfaces/ICollection.h"
#include "../colecciones-genericas/collections/List.h"

#pragma once


class Registro : public ICollectible
{
public:
    Registro();
    Registro(Videojuego*, enumSuscripcion, enumPago, time_t);
    ~Registro();

    dtVideoJuego* getDtJuego();
    void activarSuscripcion(Videojuego* obj, enumSuscripcion tipoSuscripcion, enumPago metodoDePago, time_t fechinha);
    void cancelSuscripcion();
    bool estaSuscrito();
    bool confirmarJuego(Videojuego*);
    void puntuar(int);


    float getCantHoras();
    void setCantHoras(float cantHoras);
    int getPuntajeJuego();
    void setPuntajeJuego(int puntajeJuego);


    Videojuego* getVideojuego();
private:
    float cantHoras;
    int puntajeJuego;
    Videojuego* juego;
    ICollection* contratacionesInactivas = new List();
    Contratacion* contratacionActiva;
};

#endif
