#include "Individual.h"

Individual::Individual()
{

}
Individual::Individual(int idNormal, time_t fechaIniciada,double dura, Videojuego* video, Individual* partidaAContinuar)
{
    Integer* k = new Integer(idNormal);
    this->id = k;
    this->fechaInicio = fechaIniciada;
    this->duracion = dura;
    this->vj = video;
    this->partidaContinuada = partidaAContinuar;
}

void Individual::setDuracion(double duracion){
    this->duracion = duracion;
}

Individual::~Individual()
{

}

Individual* Individual::getPartidaContinuada() {
    return this->partidaContinuada;
}

void Individual::setPartidaContinuada(Individual* partidaContinuada) {
    this->partidaContinuada = partidaContinuada;
}