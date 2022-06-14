#include "Videojuego.h"

Videojuego::Videojuego()
{

}

Videojuego::~Videojuego()
{

}

char* Videojuego::getNombreJuego(){
    return this->nombreJuego;
};

void Videojuego::setNombreJuego(char* juegito){
    this->nombreJuego = juegito; //fijarme si así puedo reemplazar un char*, o si tengo que reemplazarlo de a uno.
};

char* Videojuego::getDescripcion(){
    return this->descripcionJuego;
};

void Videojuego::setDescripcion(char* desc){
    this->descripcionJuego = desc;
};

void Videojuego::aniadirCategoria(Categoria cat){
    //KEKW
};

void Videojuego::crearSuscripciones(dtSuscripcion costos){
    //KEKW
};

void Videojuego::addDtJuego(dtVideoJuego datosJuego){
    //KEKW
};

List Videojuego::getEstadisticas(){
    //KEKWWWW
};