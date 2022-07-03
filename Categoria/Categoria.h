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
    Categoria(const char* nombreCategoria, string descripcionCategoria, enumCategoria tipoCategoria);
    ~Categoria();
    String* getNombreCategoria();
    void setNombreCategoria(const char* nombreCategoria);
    string getDescripcionCategoria();
    void setDescripcionCategoria(string descripcionCategoria);
    enumCategoria getTipoCategoria();
    void setTipoCategoria(enumCategoria tipoCategoria);
    dtCategoria* getDtGenero();
    dtCategoria* getDtPlataforma();
    dtCategoria* getDtOtro();

private:
    String* nombreCategoria; //key
    string descripcionCategoria;
    enumCategoria tipoCategoria;
};

#endif