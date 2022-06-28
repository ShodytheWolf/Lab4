#ifndef PARTIDA_H
#define PARTIDA_H
#include "ctime"
#include "../Videojuego/Videojuego.h"
#include "../Datatypes/dtPartida.h"
#include "../colecciones-genericas/interfaces/ICollectible.h"
#include "../colecciones-genericas/String.h"
#include "../colecciones-genericas/Integer.h"


#pragma once

class Partida : public ICollectible
{
public:
    Partida();
    Partida(int id, time_t fechaInicio, double duracion);
    ~Partida();
    Integer* getId();
    void setId(int id);
    time_t getFechaInicio();
    void setFechaInicio(time_t fechaInicio);
    float getDuracion();
    virtual void setDuracion(double duracion) = 0;
    dtPartida getDtPartida();
    void calcularDuracion();
    Videojuego* getVideojuego();

    bool comprobarJuego(Videojuego*);
    bool verificarJuego(const char* nombreJuego);
    void eliminarComentarios();

protected:
    Videojuego* vj;
    Integer* id; //key
    time_t fechaInicio;
    double duracion;
};

#endif