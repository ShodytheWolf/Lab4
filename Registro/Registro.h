#ifndef REGISTRO_H
#define REGISTRO_H
#include "../Datatypes/dtVideoJuego.h"
#include "../Enumeration/enumPago.h"
#include "../Enumeration/enumSuscripcion.h"
#include "../Contratacion/Contratacion.h"
#include "../colecciones-genericas/interfaces/ICollectible.h"
#include "../colecciones-genericas/interfaces/ICollection.h"
#include "../colecciones-genericas/collections/List.h"

#pragma once


class Registro : public ICollectible
{
public:
    Registro();
    Registro(float cantHoras,int puntajeJuego );
    ~Registro();

    dtVideoJuego getDtJuego();
    dtVideoJuego** getDtVideoJuego();
    void activarSuscripcion(enumSuscripcion tipoSuscripcion, enumPago metodoDePago);
    void cancelSuscripcion();
    bool estaSuscrito();
    void eliminoContratacion();
    float getCantHoras();
    void setCantHoras(float cantHoras);
    int getPuntajeJuego();
    void setPuntajeJuego(int puntajeJuego);
private:
    float cantHoras;
    int puntajeJuego;  
    Videojuego* juego;
    ICollection* contratacionesInactivas = new List();
    Contratacion* contratacionActiva;
};

#endif
