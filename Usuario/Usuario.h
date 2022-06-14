#ifndef USUARIO_H
#define USUARIO_H
#include "../colecciones-genericas/interfaces/ICollectible.h"

#pragma once

class Usuario : public ICollectible
{
public:
    Usuario();
    Usuario(char* email, char* contrasenia);
    ~Usuario();
    char* getContrasenia();
    void setContrasenia(char*);
    char* getEmail();
    void setEmail(char*);

private:
    char* email;
    char* contrasenia;
};

#endif