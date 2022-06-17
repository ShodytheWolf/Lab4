#include "Partida.h"

Partida::Partida()
{

}

Partida::Partida(int id, time_t fechaInicio, float duracion){
    setId(id);
    this->fechaInicio = fechaInicio;
    this->duracion = duracion;
}

Partida::~Partida()
{

}

Integer Partida::getId() {
    return this->id;
}

void Partida::setId(int id) {
    this->id = Integer(id);
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

dtPartida Partida::getDtPartida(){}
void Partida::calcularDuracion(){}
bool Partida::verificarJuego(String nombreJuego){}
void Partida::eliminarComentarios(){}
