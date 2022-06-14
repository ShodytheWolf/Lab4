#include "Contratacion.h"

Contratacion::Contratacion()
{

}

Contratacion::~Contratacion()
{

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