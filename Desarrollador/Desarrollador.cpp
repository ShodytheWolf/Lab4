#include "Desarrollador.h"

Desarrollador::Desarrollador(string email, string contrasenia, char* nombreEmpresa)
{
	this->email = email;
	this->contrasenia = contrasenia;
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