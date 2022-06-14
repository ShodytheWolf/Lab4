#ifndef REGISTRO_H
#define REGISTRO_H

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
private:
    float cantHoras;
    int puntajeJuego; 
};

#endif
