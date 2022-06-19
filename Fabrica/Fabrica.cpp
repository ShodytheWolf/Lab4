#include "Fabrica.h"

Fabrica::Fabrica()
{

}

Fabrica::~Fabrica()
{

}

IControlador* Fabrica::getInterface(){
    return Controlador::getInstance();
}