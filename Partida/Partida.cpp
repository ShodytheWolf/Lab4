#include "Partida.h"

Partida::Partida()
{

}

Partida::Partida(int id, time_t fechaInicio, float duracion){
    this->id = id;
    this->fechaInicio = fechaInicio;
    this->duracion = duracion;
}

Partida::~Partida()
{

}

int Partida::getId() {
    return this->id;
}

void Partida::setId(int id) {
    this->id = id;
}

time_t Partida::getFechaInicio() {
    return this->fechaInicio;
}

void Partida::setFechaInicio(time_t fechaInicio) {
    this->fechaInicio = fechaInicio;
}

float Partida::getDuracion() {
    return this->duracion;
}

void Partida::setDuracion(float duracion) {
    this->duracion = duracion;
}