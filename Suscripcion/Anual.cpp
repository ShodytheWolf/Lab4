#include "Anual.h"
Anual::Anual(){}

Anual::Anual(float costoA)
{
	this->costoAnual = costoA;
	
}

Anual::~Anual()
{

}

enumSuscripcion Anual::getTipo(){
	return this->tipo;
}

float Anual::getCostoAnual() {
	return this->costoAnual;
}
void Anual::setCostoAnual(float costoAnual) {
	this->costoAnual = costoAnual;
}

