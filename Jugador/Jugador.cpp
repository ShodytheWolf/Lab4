#include "Jugador.h"

Jugador::Jugador(char* nick, string descripcionJugador)
{
    setNickname(nick) ;
    setDescripcionJugador(descripcionJugador) ;
}

Jugador::~Jugador()
{

}

String Jugador::getNickname() {
    return this->nickname;
}

void Jugador::setNickname(char* nick) 
{
    this->nickname = String(nick) ;
}

string Jugador::getDescripcionJugador() {
    return this->descripcionJugador;
}

void Jugador::setDescripcionJugador(string descripcionJugador) {
    this->descripcionJugador = descripcionJugador;
}

void Jugador::setDescripcionJugador(string descripcionJugador){}
void Jugador::pasoJuego(String nombreVideojuego){}
dtVideoJuego** Jugador::getDatosVj(){} 
void Jugador::aniadirSuscripcion(enumSuscripcion tipoSuscipcion, enumPago metodoDePago){}
string** Jugador::listarJuegosSuscripto(){} 
dtPartidaIndividual** Jugador::listarPartidasFinalizadas(){}
void Jugador::partidaAContinuar(dtPartidaIndividual* datosPartida){}
String Jugador::getNick(String nombreJuego){}
void Jugador::iniciarMultijugador(dtPartidaMultijugador* datosPartida){}
dtPartidaIndividual** Jugador::listarPartidasIndividuales(){}
dtPartidaMultijugador** Jugador::partidaAFinalizar(){}
void Jugador::partidaAFinalizar(int idPartida){}
void Jugador::comprobarPartidas(string nombreJuegos[]){}
void Jugador::eliminarContRegisJuego(Videojuego* vj){}
