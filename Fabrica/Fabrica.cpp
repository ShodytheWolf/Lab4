#include "Fabrica.h"
#include "../Controlador/Controlador.h"

Fabrica::Fabrica()
{

}

Fabrica::~Fabrica()
{

}

IControlador* Fabrica::getInterface(){
    return Controlador::getInstance();
}