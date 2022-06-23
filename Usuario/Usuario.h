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
    virtual string getContrasenia();
    void setContrasenia(string);
    string getEmail();
    void setEmail(string);

protected:
    string email;
    string contrasenia;
};

#endif