#include "Usuario.h"

Usuario::Usuario(char* email, char* contrasenia)
{
    this->contrasenia = contrasenia;
    this->email = email;
}

Usuario::~Usuario()
{

}

char* Usuario::getContrasenia()
{
    return this->contrasenia;
}

void Usuario::setContrasenia(char* contrasenia)
{
    this->contrasenia = contrasenia;
}

char* Usuario::getEmail()
{
    return this->email;
}

void Usuario::setEmail(char* email)
{
    this->email = email;
}