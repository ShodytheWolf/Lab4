#ifndef JUGADOR_H
#define JUGADOR_H
#include "../Usuario/Usuario.h"
#include "../Videojuego/Videojuego.h"
#include "../Datatypes/dtVideoJuego.h"
#include "../Datatypes/dtPartidaIndividual.h"
#include "../Datatypes/dtPartidaMultijugador.h"
#include "../Enumeration/enumSuscripcion.h"
#include "../Enumeration/enumPago.h"

#pragma once

class Jugador : public Usuario
{
public:
    Jugador(char* nickname, char* descripcionJugador);
    ~Jugador();
    char* getNickname(); 
    void setNickname(char* nickname);
    char* getDescripcionJugador();
    void setDescripcionJugador(char* descripcionJugador);
    void pasoJuego(char* nombreVideokuego);
    //set<dtVideoJuego> getDatosVj(); Ver con el Taque como menajar las colleciones de DT's
    void aniadirSuscripcion(enumSuscripcion tipoSuscipcion, enumPago metodoDePago);
    //set<char*> listarJuegosSuscripto(); 
    //set<dtPartidaIndividual> listarPartidasFinalizadas();
    void partidaAContinuar(dtPartidaIndividual datosPartida);
    char* getNick(char* nombreJuego);
    void iniciarMultijugador(dtPartidaMultijugador datosPartida);
    //set<dtPartidaIndividual> listarPartidasIndividuales();
    //set<dtPartidaMultijugador> partidaAFinalizar();
    void partidaAFinalizar(int idPartida);
    //void comprobarPartidas(set<string> nombreJuegos);
    void eliminarContRegisJuego(Videojuego vj);

private:
    char* nickname;
    char* descripcionJugador;
};

#endif