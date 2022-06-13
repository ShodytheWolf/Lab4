#ifndef DESARROLLADOR_H
#define DESARROLLADOR_H
#include "../Usuario/Usuario.h"

#pragma once

class Desarrollador : public Usuario
{
public:
    Desarrollador(char*);
    ~Desarrollador();
    char* getNombreEmpresa();
    void setNombreEmpresa(char* nombreEmpresa);

private:
    char* nombreEmpresa;
};

#endif