#include "Vitalicia.h"

Vitalicia::Vitalicia(){}

Vitalicia::Vitalicia(float costoV)
{
	this->costoVitalicia = costoV;
}

Vitalicia::~Vitalicia()
{

}

float Vitalicia::getCostoVitalicia() {
	return this->costoVitalicia;
}
void Vitalicia::setCostoVitalicia(float costoVitalicia) {
	this->costoVitalicia = costoVitalicia;
}