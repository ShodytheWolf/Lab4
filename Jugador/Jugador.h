#ifndef JUGADOR_H
#define JUGADOR_H
#include "../Usuario/Usuario.h"
#include "../Videojuego/Videojuego.h"
#include "../Datatypes/dtPartidaIndividual.h"
#include "../Datatypes/dtPartidaMultijugador.h"
#include "../Enumeration/enumSuscripcion.h"
#include "../Enumeration/enumPago.h"
#include "../colecciones-genericas/interfaces/ICollection.h"
#include "../Individual/Individual.h"
#include "../Multijugador/Multijugador.h"
#include "../Registro/Registro.h"
#include "../EnVivo/EnVivo.h"

#pragma once

class Jugador : public Usuario
{
public:
    Jugador(string email, string contrasenia, char* nickname, string descripcionJugador);
    ~Jugador();

    //Operaciones del padre:
    string getContrasenia();
    void setContrasenia(string);
    string getEmail();
    void setEmail(string);

    //Setters y getters:
    String* getNickname(); 
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
    void iniciarMultijugador(dtPartidaMultijugador* datosPartida, Videojuego* vj);
    void iniciarIndividual(dtPartidaIndividual* datosPartida, Videojuego* vj);
    dtPartidaIndividual** listarPartidasIndividuales();
    dtPartidaMultijugador** partidaAFinalizar();
    void partidaAFinalizar(int idPartida);
    string** comprobarPartidas(string** nombreJuegos, int t);
    void eliminarContRegisJuego(Videojuego* vj);

private:
    String* nickname;
    string descripcionJugador;
    IDictionary* partidasInactivas = new OrderedDictionary();
    IDictionary* partidasActivas = new OrderedDictionary();
    ICollection* partidasUnido = new List(); 
    ICollection* registros = new List();

};

#endif
