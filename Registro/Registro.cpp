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

	dtVideoJuego** listSuscritos;
	dtVideoJuego** listNoSuscriptos;
	dtVideoJuego** listJuegosDiff; //suscriptos y no suscriptos

	//aca le paso si esta suscrito o no
	//dtVideojuego* addJS = new dtVideojuego(nombrejuego,dessarrollador, desc, sus, suscrito, puntaje, horas);

	/*if(estaSuscrito){
		añado juego a lista suscritos.
		 //listSuscritos[i] = addJS;

	}
	else {
		añado juego a lista no suscrito.
		 //listNoSuscritos[i] = addJS;
	}
	*/

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

bool Registro::confrmarJuego(Videojuego* vj){
	if(this->juego == vj){return true;}
	return false;
}

Videojuego* Registro::getVideojuego(){
	return this->juego;
}
