#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include "../colecciones-genericas/interfaces/ICollectible.h"
#include "../colecciones-genericas/String.h"

using namespace std;

#pragma once

class Usuario : public ICollectible
{
public:
    Usuario();
    Usuario(string, string);
    ~Usuario();
    virtual string getContrasenia() =0;
    virtual void setContrasenia(string)=0;
    virtual string getEmail()=0;
    virtual void setEmail(string)=0;

protected:
    string email;
    string contrasenia;
};

#endif