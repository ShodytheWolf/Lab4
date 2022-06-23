#include "Jugador.h"
#include "string.h"

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

/**
 * @brief Operacion que comprueba si tiene partidas activas para Videojuegos 
 * concretos
 * 
 * @param nombreJuegos Lista de juegos concretos 
 * @return string** Lista con la misma cantidad o menos de la que recibio 
 */
string** Jugador::comprobarPartidas(string** nombreJuegos, int t){
    int i = 0;
    while(nombreJuegos[i]){
        for(IIterator* it = this->partidasActivas->getIterator(); it->hasCurrent(); it->next()){
            Partida* pA = (Partida*) it->getCurrent();
            if(pA->verificarJuego(nombreJuegos[i]->data())){
                nombreJuegos[i] = NULL;
                break;
            }
        }
        i++;
    }
    string** juegosComp = new string*[t+1];
    int c = 0;
    for(int i=0; i<t; i++){
        if(nombreJuegos[i]){
            juegosComp[c] = nombreJuegos[i];
            c++;
        }
    }
    return juegosComp;
}


void Jugador::eliminarContRegisJuego(Videojuego* vj){}
