#ifndef DTVIDEOJUEGO_H
#define DTVIDEOJUEGO_H
#include "dtSuscripcion.h"
using namespace std;
#include <iostream>
#pragma once
/**
 * Implementacion de dtVideojuego
 *
 */
class dtVideoJuego
{
public:
    /**
     * @brief Constructor de dtVideojuego con categorias
     */
    dtVideoJuego(string n, string nD, string d, dtSuscripcion* c, bool eS, string **categorias, float pP, float hT);

    /**
     * @brief Constructor de dtVideojuego sin categorias
     */
    dtVideoJuego(string n, string nD, string d, dtSuscripcion* c, bool eS, float pP, float hT);

    ~dtVideoJuego();

    string getNombreVideojuego();
    string getNombreDesarrollador();
    string getDescripcionJuego();
    bool getEstaSuscripto();
    dtSuscripcion* getCostos();
    string **getCategorias();
    float getPuntajePromedio();
    float getHorasTotales();

private:
    string nombreJuego;
    string nombreDesarrollador;
    string descripcionJuego;
    dtSuscripcion* costo;
    bool estaSuscripto;
    string **categorias;
    float puntajePromedio;
    float horasTotales;

};

#endif