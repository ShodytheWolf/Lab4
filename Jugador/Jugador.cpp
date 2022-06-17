#include "Jugador.h"

Jugador::Jugador(char* nick, char* descripcionJugador)
{
    setNickname(nick);
    setDescripcionJugador(descripcionJugador);
}

Jugador::~Jugador()
{

}

String Jugador::getNickname() {
    return this->nickname;
}

void Jugador::setNickname(char* nick) 
{
    this->nickname = String(nick);
}

string Jugador::getDescripcionJugador() {
    return this->descripcionJugador;
}

void Jugador::setDescripcionJugador(char* descripcionJugador) {
    this->descripcionJugador = descripcionJugador;
}