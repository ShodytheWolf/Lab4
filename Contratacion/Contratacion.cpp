#include "Contratacion.h"

Contratacion::Contratacion(Videojuego* vj ,enumSuscripcion tipoSuscripcio, enumPago tipoPago, time_t fechaCont)
{
	this->metodoDePago = tipoPago;
	this->fechaDeSuscripcion = fechaCont;
	
	switch(tipoSuscripcio){
		case Men:
			this->suscripcion = vj->getSuscripcionMensual();
			break;
		case Trim:
			this->suscripcion = vj->getSuscripcionTrimestral();
			break;
		case An:
			this->suscripcion = vj->getSuscripcionAnual();
			break;
		case Vit:
			this->suscripcion = vj->getSuscripcionVitalicia();
			break;
	}
	
}

Contratacion::~Contratacion()
{
	this->suscripcion = NULL;
}


enumPago Contratacion::getMetodoDePago() {
	return this->metodoDePago;
}

void Contratacion::setMetodoDePago(enumPago metodoDePago) {
	this->metodoDePago = metodoDePago;
}


time_t Contratacion::getFechaDeSuscripcion() {
	return this->fechaDeSuscripcion;
}
void Contratacion::setFechaDeSuscripcion(time_t fechaDeSuscripcion) {
	this->fechaDeSuscripcion = fechaDeSuscripcion;
}

enumSuscripcion* Contratacion::getTipoSuscripto(){
	enumSuscripcion tipo = this->suscripcion->getTipo();
	cout << &tipo << endl;
	getchar();
	getchar();
	return &tipo;
}
