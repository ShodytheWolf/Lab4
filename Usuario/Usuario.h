#ifndef USUARIO_H
#define USUARIO_H
#include "../colecciones-genericas/interfaces/ICollectible.h"

#pragma once

class Usuario : public ICollectible
{
public:
    Usuario();
    ~Usuario();
    virtual string getContrasenia() = 0;
    void setContrasenia(string);
    string getEmail();
    void setEmail(string);

private:
    string email;
    string contrasenia;
};

#endif