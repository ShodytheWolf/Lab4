#ifndef CATEGORIA_H
#define CATEGORIA_H
#include <iostream>
#include "../colecciones-genericas/String.h"
#include "../colecciones-genericas/interfaces/ICollectible.h"
#include "../Datatypes/dtCategoria.h"
#include "../Enumeration/enumCategoria.h"

using namespace std;

#pragma once

class Categoria : public ICollectible
{
public:
    Categoria(char* nombreCategoria, string descripcionCategoria, enumCategoria tipoCategoria);
    ~Categoria();
    String getNombreCategoria();
    void setNombreCategoria(char* nombreCategoria);
    string getDescripcionCategoria();
    void setDescripcionCategoria(string descripcionCategoria);
    enumCategoria getTipoCategoria();
    void setTipoCategoria(enumCategoria tipoCategoria);
    dtCategoria getDtGenero();
    dtCategoria getDtPlataforma();
    dtCategoria getDtOtro();

private:
    String nombreCategoria;
    string descripcionCategoria;
    enumCategoria tipoCategoria;
};

#endif