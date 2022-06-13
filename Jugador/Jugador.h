#ifndef JUGADOR_H
#define JUGADOR_H
#include "../Usuario/Usuario.h"

#pragma once

class Jugador : public Usuario
{
public:
    Jugador(char* nickname, char* descripcionJugador);
    ~Jugador();
    char* getNickname(); 
    void setNickname(char* nickname);

private:
    char* nickname;
    char* descripcionJugador;
};

#endif