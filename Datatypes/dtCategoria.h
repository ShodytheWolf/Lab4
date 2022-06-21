#ifndef DTCATEGORIA_H
#define DTCATEGORIA_H

using namespace std;
#include <iostream>
#include "../Enumeration/enumCategoria.h"

#pragma once

class dtCategoria
{
public:
    dtCategoria();
    ~dtCategoria();

    string getNombre();
    string getDescripcion();
    enumCategoria getTipo();

private:
    string nombre;
    string descripcion;
    enumCategoria tipo;

};

#endif