#ifndef JUGADOR_H
#define JUGADOR_H
#include "../Usuario/Usuario.h"
#include "../Videojuego/Videojuego.h"
#include "../Datatypes/dtPartidaIndividual.h"
#include "../Datatypes/dtPartidaMultijugador.h"
#include "../Enumeration/enumSuscripcion.h"
#include "../Enumeration/enumPago.h"
#include "../colecciones-genericas/interfaces/ICollection.h"

#pragma once

class Jugador : public Usuario
{
public:
    Jugador(char* nickname, string descripcionJugador);
    ~Jugador();
    String getNickname(); 
    void setNickname(char* nick);
    string getDescripcionJugador();
    void setDescripcionJugador(string descripcionJugador);
    void pasoJuego(String nombreVideojuego);
    dtVideoJuego** getDatosVj(); 
    void aniadirSuscripcion(enumSuscripcion tipoSuscipcion, enumPago metodoDePago);
    string** listarJuegosSuscripto(); 
    dtPartidaIndividual** listarPartidasFinalizadas();
    void partidaAContinuar(dtPartidaIndividual* datosPartida);
    String getNick(String nombreJuego);
    void iniciarMultijugador(dtPartidaMultijugador* datosPartida);
    dtPartidaIndividual** listarPartidasIndividuales();
    dtPartidaMultijugador** partidaAFinalizar();
    void partidaAFinalizar(int idPartida);
    void comprobarPartidas(string nombreJuegos[]);
    void eliminarContRegisJuego(Videojuego* vj);

private:
    String nickname;
    string descripcionJugador;
    IDictionary* partidasInactivas = new OrderedDictionary();
    IDictionary* partidasActivas = new OrderedDictionary();
    ICollection* partidasUnido = new List(); 
    ICollection* registros = new List();
};

#endif
