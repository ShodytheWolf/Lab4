#ifndef JUGADOR_H
#define JUGADOR_H
#include <ctime>
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
    Jugador(string correo, string contrasenia, const char* nickname, string descripcionJugador);
    ~Jugador();

    //Operaciones del padre:
    string getContrasenia();
    void setContrasenia(string);
    string getEmail();
    void setEmail(string);

    //Setters y getters:
    String* getNickname(); 
    void setNickname(const char* nick);
    string getDescripcionJugador();
    void setDescripcionJugador(string descripcionJugador);


    void pasoJuego(String nombreVideojuego);
    dtPartida** getDtPartidasActivas();
    dtVideoJuego** getDatosVj(); 
    void aniadirSuscripcion(Videojuego* objeto, enumSuscripcion tipoSuscipcion, enumPago metodoDePago, time_t fechaSus);
    string** listarJuegosSuscripto();
    bool verificoJuego(Videojuego* vj); 
    dtPartidaIndividual** listarPartidasFinalizadas();
    void partidaAContinuar(dtPartidaIndividual* datosPartida);
    String* getNick(Videojuego*);
    Multijugador* iniciarMultijugador(dtPartidaMultijugador* datosPartida, Videojuego* vj, int idUltimaPartida,time_t horaActual,string** jugadoresUnidos);
    void iniciarIndividual(dtPartidaIndividual* datosPartida, Videojuego* vj,int idUltimaPartida,time_t horaActual);
    dtPartidaIndividual** listarPartidasIndividuales();
    dtPartidaMultijugador** partidaAFinalizar();
    void partidaAFinalizar(int idPartida,time_t horaActual);
    string** comprobarPartidas(string** nombreJuegos, int t);
    void eliminarContRegisJuego(Videojuego* vj);
    void unirseAPartida(Multijugador* multi);
    void nuevoPuntaje(Videojuego*, int);
    void abandonarPartidaMultijugador(int idPartida,time_t horaActual);


private:
    String* nickname;
    string descripcionJugador;
    time_t fecha;
    IDictionary* partidasInactivas = new OrderedDictionary();
    IDictionary* partidasActivas = new OrderedDictionary();
    IDictionary* partidasUnido = new OrderedDictionary(); 
    ICollection* registros = new List();

};

#endif
