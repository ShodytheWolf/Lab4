#ifndef USUARIO_H
#define USUARIO_H

#pragma once

class Usuario
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