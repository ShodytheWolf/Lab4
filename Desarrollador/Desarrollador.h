#ifndef DESARROLLADOR_H
#define DESARROLLADOR_H
#include "../Usuario/Usuario.h"

#pragma once

class Desarrollador : public Usuario
{
public:
    Desarrollador(string, string,const char*);
    ~Desarrollador();
    String* getNombreEmpresa();
    void setNombreEmpresa(const char* nombreEmpresa);

    //Operaciones del padre:
    string getContrasenia();
    void setContrasenia(string);
    string getEmail();
    void setEmail(string);

private:
    String* nombreEmpresa; //IKEY
};

#endif