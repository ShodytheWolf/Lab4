#include "Videojuego.h"

Videojuego::Videojuego(char* nombre, string descripcion)
{
    setNombreJuego(nombre); //creo la key
    this->descripcionJuego = descripcion;
}

Videojuego::~Videojuego()
{
    IIterator* it;
    for(it = this->suscripciones->getIterator(); it->hasCurrent(); it->next()){
        Suscripcion* s = (Suscripcion*)it->getCurrent();
        delete s;
    }
    for(it = this->estadisticas->getIterator(); it->hasCurrent(); it->next()){
        Estadistica* e = (Estadistica*)it->getCurrent();
        delete e;
    }
    delete it;
}

String* Videojuego::getNombreJuego() {
    return this->nombreJuego;
}
void Videojuego::setNombreJuego(char*nombreJuego) {
    this->nombreJuego = new String(nombreJuego);
}

Desarrollador* Videojuego::getDesarrollador() {
    return this->desarrollador;
}
void Videojuego::setDesarrollador(Desarrollador* desarrollador) {
    this->desarrollador = desarrollador;
}

string Videojuego::getDescripcionJuego() {
    return this->descripcionJuego;
}

void Videojuego::setDescripcionJuego(string descripcionJuego) {
    this->descripcionJuego = descripcionJuego;
}



void Videojuego::aniadirCategoria(Categoria cat){
    //KEKW
};

void Videojuego::crearSuscripciones(dtSuscripcion costos){
    //KEKW
};

void Videojuego::addDtJuego(dtVideoJuego datosJuego){
    //KEKW
};

dtEstadistica** Videojuego::getEstadisticas(){
    //KEKWWWW
};