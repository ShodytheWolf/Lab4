#include "Vitalicia.h"

Vitalicia::Vitalicia(){}

Vitalicia::Vitalicia(float costoV)
{
	this->costoVitalicia = costoV;
}

Vitalicia::~Vitalicia()
{

}

enumSuscripcion Vitalicia::getTipo(){
	return this->tipo;
}

float Vitalicia::getCostoVitalicia() {
	return this->costoVitalicia;
}
void Vitalicia::setCostoVitalicia(float costoVitalicia) {
	this->costoVitalicia = costoVitalicia;
}