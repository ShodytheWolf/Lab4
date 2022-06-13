#include "Desarrollador.h"

Desarrollador::Desarrollador(char* nombreEmpresa)
{
    this->nombreEmpresa = nombreEmpresa;
}

Desarrollador::~Desarrollador()
{

}

char* Desarrollador::getNombreEmpresa() {
    	return this->nombreEmpresa;
}

void Desarrollador::setNombreEmpresa(char* nombreEmpresa) {
	this->nombreEmpresa = nombreEmpresa;
}