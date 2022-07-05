#include "Trimestral.h"

Trimestral::Trimestral(){}

Trimestral::Trimestral(float costoT)
{
	this->costoTrimestral = costoT;
}

Trimestral::~Trimestral()
{

}

enumSuscripcion Trimestral::getTipo(){
	return this->tipo;
}

 float Trimestral::getCostoTrimestral() {
 	return this->costoTrimestral;
 }
 void Trimestral::setCostoTrimestral(float costoTrimestral) {
 	this->costoTrimestral = costoTrimestral;
 }