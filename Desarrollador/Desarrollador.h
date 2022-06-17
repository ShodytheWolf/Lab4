#ifndef DESARROLLADOR_H
#define DESARROLLADOR_H
#include "../Usuario/Usuario.h"
#include "../colecciones-genericas/String.h"

#pragma once

class Desarrollador : public Usuario
{
public:
    Desarrollador(char*);
    ~Desarrollador();
    String getNombreEmpresa();
    void setNombreEmpresa(char* nombreEmpresa);

private:
    String nombreEmpresa; //IKEY
};

#endif