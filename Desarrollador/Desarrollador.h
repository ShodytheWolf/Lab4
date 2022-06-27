#ifndef DESARROLLADOR_H
#define DESARROLLADOR_H
#include "../Usuario/Usuario.h"

#pragma once

class Desarrollador : public Usuario
{
public:
    Desarrollador(string, string, char*);
    ~Desarrollador();
    String* getNombreEmpresa();
    void setNombreEmpresa(char* nombreEmpresa);

    //Operaciones del padre:
    string getContrasenia();
    void setContrasenia(string);
    string getEmail();
    void setEmail(string);

private:
    String* nombreEmpresa; //IKEY
};

#endif