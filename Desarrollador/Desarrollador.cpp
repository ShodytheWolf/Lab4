#include "Desarrollador.h"

Desarrollador::Desarrollador(char* nombreEmpresa)
{
    setNombreEmpresa(nombreEmpresa);
}

Desarrollador::~Desarrollador()
{

}

String* Desarrollador::getNombreEmpresa() {
    	return this->nombreEmpresa;
}

void Desarrollador::setNombreEmpresa(char* nombreEmpresa) {
	this->nombreEmpresa = new String(nombreEmpresa);
}