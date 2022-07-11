#include "Mensual.h"
#include <iostream>

using namespace std;

Mensual::Mensual(){}

Mensual::Mensual(float costoM)
{
	this->costoMensual = costoM;
}

Mensual::~Mensual()
{

}

enumSuscripcion Mensual::getTipo(){
	return this->tipo;
}

float Mensual::getCostoMensual() {
	return this->costoMensual;
}
void Mensual::setCostoMensual(float costoMensual) {
	this->costoMensual = costoMensual;
}
