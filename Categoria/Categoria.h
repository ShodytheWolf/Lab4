#ifndef CATEGORIA_H
#define CATEGORIA_H
#include "../colecciones-genericas/interfaces/ICollectible.h"
#include "../Datatypes/dtCategoria.h"
#include "../Enumeration/enumCategoria.h"

#pragma once

class Categoria : public ICollectible
{
public:
    Categoria(char* nombreCategoria, char* descripcionCategoria, enumCategoria tipoCategoria);
    ~Categoria();
    char* getNombreCategoria();
    void setNombreCategoria(char* nombreCategoria);
    char* getDescripcionCategoria();
    void setDescripcionCategoria(char* descripcionCategoria);
    enumCategoria getTipoCategoria();
    void setTipoCategoria(enumCategoria tipoCategoria);
    dtCategoria getDtGenero();
    dtCategoria getDtPlataforma();
    dtCategoria getDtOtro();

private:
    char* nombreCategoria;
    char* descripcionCategoria;
    enumCategoria tipoCategoria;
};

#endif