#ifndef FABRICA_H
#define FABRICA_H
#include "../IControlador/IControlador.h"

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