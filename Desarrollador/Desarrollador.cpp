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

//Operaciones del padre:

//Operaciones del padre:
string Desarrollador::getContrasenia(){
    return this->contrasenia;
}

void Desarrollador::setContrasenia(string pass){
    this->contrasenia = pass;
}

string Desarrollador::getEmail(){
    return this->email;
}

void Desarrollador::setEmail(string correo){
    this->email = correo;
}