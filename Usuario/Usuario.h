#ifndef USUARIO_H
#define USUARIO_H
#include "../colecciones-genericas/interfaces/ICollectible.h"

#pragma once

class Usuario : public ICollectible, public OrderedDictionary
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
    List* jugador;
    List* desarrollador;
};

#endif
