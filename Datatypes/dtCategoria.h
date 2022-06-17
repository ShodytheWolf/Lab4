#ifndef DTCATEGORIA_H
#define DTCATEGORIA_H


#pragma once

class dtCategoria
{
public:
    dtCategoria();
    ~dtCategoria();

    string getNombre();
    string getDescripcion();
    
private:
    string nombre;
    string descripcion;

};

#endif