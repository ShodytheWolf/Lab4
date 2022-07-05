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
	cout << this->tipo << endl;
	getchar();
	getchar();
	return this->tipo;
}

float Mensual::getCostoMensual() {
	return this->costoMensual;
}
void Mensual::setCostoMensual(float costoMensual) {
	this->costoMensual = costoMensual;
}
