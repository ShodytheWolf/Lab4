#include "EnVivo.h"

EnVivo::EnVivo()
{

}

EnVivo::~EnVivo()
{

}

EnVivo::EnVivo(int id, time_t fechaIni, double dura,Videojuego* vjuego)
{
    Integer* k = new Integer(id);
    this->id = k;
    this->fechaInicio = fechaIni;
    this->duracion = dura;
    this->vj = vjuego;
}

void EnVivo::eliminarComentarios(){
    for(IIterator* it = this->comentarios->getIterator(); it->hasCurrent(); it->next()){
        Comentario* com = (Comentario*) it->getCurrent();
        comentarios->remove(com);
        delete com;
    }
}
