#include "EnVivo.h"

EnVivo::EnVivo()
{

}

EnVivo::~EnVivo()
{

}

void EnVivo::eliminarComentarios(){
    for(IIterator* it = this->comentarios->getIterator(); it->hasCurrent(); it->next()){
        Comentario* com = (Comentario*) it->getCurrent();
        comentarios->remove(com);
        delete com;
    }
}
