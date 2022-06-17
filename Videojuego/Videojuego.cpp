#include "Videojuego.h"

Videojuego::Videojuego(char* nombre, string descripcion)
{
    this->nombreJuego = String(nombre); //creo la key
    this->descripcionJuego = descripcion;
}

Videojuego::~Videojuego()
{

}

String Videojuego::getNombreJuego() {
    return this->nombreJuego;
}
void Videojuego::setNombreJuego(char*nombreJuego) {
    this->nombreJuego = String(nombreJuego);
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