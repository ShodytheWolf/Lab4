#ifndef JUGADOR_H
#define JUGADOR_H
#include "../Usuario/Usuario.h"
#include "../Videojuego/Videojuego.h"
#include "../Datatypes/dtVideoJuego.h"
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
    //set<dtVideoJuego> getDatosVj(); Ver con el Taque como menajar las colleciones de DT's
    void aniadirSuscripcion(enumSuscripcion tipoSuscipcion, enumPago metodoDePago);
    //set<char*> listarJuegosSuscripto(); 
    //set<dtPartidaIndividual> listarPartidasFinalizadas();
    void partidaAContinuar(dtPartidaIndividual datosPartida);
    String getNick(String nombreJuego);
    void iniciarMultijugador(dtPartidaMultijugador datosPartida);
    //set<dtPartidaIndividual> listarPartidasIndividuales();
    //set<dtPartidaMultijugador> partidaAFinalizar();
    void partidaAFinalizar(int idPartida);
    //void comprobarPartidas(set<string> nombreJuegos);
    void eliminarContRegisJuego(Videojuego vj);

private:
    String nickname;//IKey String
    string descripcionJugador;
    IDictionary* partidasInactivas = new OrderedDictionary();
    IDictionary* partidasActivas = new OrderedDictionary();
    ICollection* partidasUnido = new List(); 
    ICollection* registros = new List();
};

#endif
