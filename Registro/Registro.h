#ifndef REGISTRO_H
#define REGISTRO_H

#pragma once

class Registro
{
public:
    Registro();
    Registro(float cantHoras,enumPuntuacion puntajeJuego );
    ~Registro();

    dtVideoJuego getDtJuego();
    //set<dtVideoJuego> getDtVideoJuego();
    void activarSuscripcion(enumSuscripcion tipoSuscripcion, enumPago metodoDePago);
    void cancelSuscripcion();
    bool estaSuscrito();
    void eliminoContratacion();
private:
    float cantHoras;
    enumPuntuacion puntajeJuego; 
};

#endif
