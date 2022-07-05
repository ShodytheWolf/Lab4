#include "EnVivo.h"

EnVivo::EnVivo()
{

}

EnVivo::~EnVivo()
{

}

EnVivo::EnVivo(int id, time_t fechaIni, double dura,Videojuego* vjuego, string** jugadoresAUnirse)
{
    Integer* k = new Integer(id);
    this->id = k;
    this->fechaInicio = fechaIni;
    this->duracion = dura;
    this->vj = vjuego;
    this->jugadoresUnidos = jugadoresAUnirse;
}

void EnVivo::eliminarComentarios(){
    for(IIterator* it = this->comentarios->getIterator(); it->hasCurrent(); it->next()){
        Comentario* com = (Comentario*) it->getCurrent();
        comentarios->remove(com);
        delete com;
    }
}

dtPartida* EnVivo::getDtPartida(string papaOso){
    dtPartidaMultijugador* parti = new dtPartidaMultijugador(this->id->getValue(),this->fechaInicio,string(this->vj->getNombreJuego()->getValue()),true,papaOso,this->jugadoresUnidos);
    return parti;
}
