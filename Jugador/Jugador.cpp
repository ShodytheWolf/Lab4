#include "Jugador.h"

Jugador::Jugador(char* nickname, char* descripcionJugador)
{
    this->nickname = nickname;
    this->descripcionJugador = descripcionJugador;
}

Jugador::~Jugador()
{

}

char* Jugador::getNickname() {
    return this->nickname;
}

void Jugador::setNickname(char* nickname) 
{
    this->nickname = nickname;
}

char* Jugador::getDescripcionJugador() {
    return this->descripcionJugador;
}

void Jugador::setDescripcionJugador(char* descripcionJugador) {
    this->descripcionJugador = descripcionJugador;
}