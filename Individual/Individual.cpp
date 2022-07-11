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


dtPartida* Individual::getDtPartida(){
    
    if(this->partidaContinuada == NULL){
        string nVj = string(this->vj->getNombreJuego()->getValue());
        dtPartidaIndividual* parti = new dtPartidaIndividual(this->id->getValue(),nVj,false,0,duracion,fechaInicio);
        return parti;

    }else{
        dtPartidaIndividual* parti2 = new dtPartidaIndividual(this->id->getValue(),string(this->vj->getNombreJuego()->getValue()),true,this->partidaContinuada->id->getValue(),duracion,this->getFechaInicio());
        return parti2;
    }
    
}

dtPartida* Individual::getDtPartida(string papaOso){
    
}