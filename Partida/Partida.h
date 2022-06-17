#ifndef PARTIDA_H
#define PARTIDA_H
#include "ctime"
#include "../Datatypes/dtPartida.h"
#include "../colecciones-genericas/interfaces/ICollectible.h"
#include "../colecciones-genericas/String.h"
#include "../colecciones-genericas/Integer.h"


#pragma once

class Partida : public ICollectible
{
public:
    Partida();
    Partida(int id, time_t fechaInicio, float duracion);
    ~Partida();
    Integer getId();
    void setId(int id);
    time_t getFechaInicio();
    void setFechaInicio(time_t fechaInicio);
    float getDuracion();
    void setDuracion(float duracion);
    dtPartida getDtPartida();
    void calcularDuracion();
    bool verificarJuego(String nombreJuego);
    void eliminarComentarios();

private:
    Integer id; //key
    time_t fechaInicio;
    float duracion;
};

#endif