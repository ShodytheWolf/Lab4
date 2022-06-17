#include "Usuario.h"
#include <iostream>

using namespace std;


Usuario::~Usuario()
{

}

string Usuario::getContrasenia()
{
    return this->contrasenia;
}

void Usuario::setContrasenia(string contrasenia)
{
    this->contrasenia = contrasenia;
}

string Usuario::getEmail()
{
    return this->email;
}

void Usuario::setEmail(string email)
{
    this->email = email;
}