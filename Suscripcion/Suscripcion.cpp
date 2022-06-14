#include "Suscripcion.h"

Suscripcion::Suscripcion()
{

}

Suscripcion::~Suscripcion()
{

}

char* Suscripcion::getDescripcion() {
	return this->descripcion;
}
void Suscripcion::setDescripcion(char* descripcion) {
	this->descripcion = descripcion;
}