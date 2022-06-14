#include "Fabrica.h"
#include "../Controlador/Controlador.cpp"

Fabrica::Fabrica()
{

}

Fabrica::~Fabrica()
{

}

IControlador* Fabrica::getInterface(){
    return Controlador::getInstance();
}