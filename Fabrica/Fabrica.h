#ifndef FABRICA_H
#define FABRICA_H
#include "../IControlador/IControlador.h"
#include "../Controlador/Controlador.h"

#pragma once

class Fabrica
{
public:
    Fabrica();
    ~Fabrica();
    IControlador* getInterface();

private:

};

#endif