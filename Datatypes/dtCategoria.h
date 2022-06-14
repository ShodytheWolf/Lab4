#ifndef DTCATEGORIA_H
#define DTCATEGORIA_H


#pragma once

class dtCategoria
{
public:
    dtCategoria();
    ~dtCategoria();

    char* getNombre();
    char* getDescripcion();
    
private:
    char* nombre;
    char* descripcion;

};

#endif