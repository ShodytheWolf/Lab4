#include "Trimestral.h"

Trimestral::Trimestral(){}

Trimestral::Trimestral(float costoT)
{
	this->costoTrimestral = costoT;
}

Trimestral::~Trimestral()
{

}

 float Trimestral::getCostoTrimestral() {
 	return this->costoTrimestral;
 }
 void Trimestral::setCostoTrimestral(float costoTrimestral) {
 	this->costoTrimestral = costoTrimestral;
 }