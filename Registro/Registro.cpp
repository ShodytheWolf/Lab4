#include "Registro.h"

Registro::Registro(){}

/**
 * @brief Construct a new Registro:: Registro object
 * 
 * @param vj juego del registro
 * @param tS tipo de suscripcion
 * @param tP tipo de pago
 * @param fS fecha de suscripcion
 */
Registro::Registro(Videojuego* vj,enumSuscripcion tS, enumPago tP, time_t fS){
	this->juego = vj;
	Contratacion* cont = new Contratacion(vj, tS, tP, fS);
	this->contratacionActiva = cont;
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
	dtVideoJuego* data = NULL; 
	

	if (contratacionActiva){
		string nombreVJ = this->juego->getNombreJuego()->getValue();
		string nombreEmp = this->juego->getDesarrollador()->getNombreEmpresa()->getValue();
		string desc = juego->getDescripcionJuego();
		
		dtSuscripcion* dataCostos = new dtSuscripcion(this->juego->getSuscripcionMensual()->getCostoMensual(),
		this->juego->getSuscripcionTrimestral()->getCostoTrimestral(),
		this->juego->getSuscripcionAnual()->getCostoAnual(),
		this->juego->getSuscripcionVitalicia()->getCostoVitalicia(),
		this->contratacionActiva->getTipoSuscripto()); //costos de cada una y tipo de suscripcion contratada

		data = new dtVideoJuego(nombreVJ, nombreEmp, desc, dataCostos, true, 0, 0);
	}
	return data;
}

void Registro::activarSuscripcion(Videojuego* vj, enumSuscripcion tipoSuscripcion,enumPago metodoDePago, time_t dateSus){
	Contratacion* cont = new Contratacion(vj, tipoSuscripcion, metodoDePago, dateSus);
	this->contratacionActiva = cont;
}

void Registro::cancelSuscripcion(){
	contratacionesInactivas->add(contratacionActiva);
	contratacionActiva = NULL;
}

bool Registro::estaSuscrito(){
    if(this->contratacionActiva == NULL){
		return false;
	}else{
		return true;
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