#ifndef REGISTRO_H
#define REGISTRO_H
#include "../Datatypes/dtVideoJuego.h"
#include "../Enumeration/enumPago.h"
#include "../Enumeration/enumSuscripcion.h"

#pragma once

class Registro
{
public:
    Registro();
    Registro(float cantHoras,int puntajeJuego );
    ~Registro();

    dtVideoJuego getDtJuego();
    //SET<dtVideoJuego> getDtVideoJuego();
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
    dtVideoJuego dtJuego;
};

#endif
