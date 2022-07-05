#include "Registro.h"

Registro::Registro(){}
Registro::Registro(float cantHoras,int puntajeJuego){
    this->cantHoras = cantHoras;
    this->puntajeJuego = puntajeJuego;
}

/**
 * @brief eliminarContrataciones se paso a hacer en el destructor
 * de registro
 * 
 */
Registro::~Registro(){
	if(this->contratacionActiva)
		delete this->contratacionActiva;
	for(IIterator* it = this->contratacionesInactivas->getIterator(); it->hasCurrent(); it->getCurrent()){
		Contratacion* c = (Contratacion*) it->getCurrent();
		contratacionesInactivas->remove(c);
		delete c;
	}
}

dtVideoJuego* Registro::getDtJuego(){
	dtVideoJuego* dato;
	if(contratacionActiva){
		dato = new dtVideoJuego(string(this->juego->getNombreJuego()->getValue()),
		string(juego->getDesarrollador()->getNombreEmpresa()->getValue()),
		juego->getDescripcionJuego(), NULL, true, 0, 0); 
		return dato;
	}
	return NULL;

}

void Registro::activarSuscripcion(enumSuscripcion tipoSuscripcion,enumPago metodoDePago){

}
void Registro::cancelSuscripcion(){

}

bool Registro::estaSuscrito(){
    if(this->contratacionActiva = NULL){
		return true;
	}else{
		return false;
	}
}

float Registro::getCantHoras() {
	return this->cantHoras;
}
void Registro::setCantHoras(float cantHoras) {
	this->cantHoras = cantHoras;
}

int Registro::getPuntajeJuego() {
 	return this->puntajeJuego;
}

void Registro::setPuntajeJuego(int puntajeJuego) {
	this->puntajeJuego = puntajeJuego;
}

bool Registro::confirmarJuego(Videojuego* vj){
	if(this->juego == vj){return true;}
	return false;
}

Videojuego* Registro::getVideojuego(){
	return this->juego;
}

void Registro::puntuar(int p){
	this->puntajeJuego = p;
	juego->nuevoPuntaje(p);
}