#include "dtPartidaMultijugador.h"

dtPartidaMultijugador::dtPartidaMultijugador()
{

}

dtPartidaMultijugador::dtPartidaMultijugador(int idParti,time_t fechaIni, string juego,bool deVivo,string papaOso,string** nicksJuego){
    this->idPartida = idParti;
    this->fechaInicio = fechaIni;
    this->nombreVideojuego = juego.data();
    this->enVivo = deVivo;
    this->nickHost = papaOso;
    this->jugadoresUnidos = nicksJuego;
}

    


dtPartidaMultijugador::~dtPartidaMultijugador()
{

}

bool dtPartidaMultijugador::getEnVivo(){
    return this->enVivo;
};

string dtPartidaMultijugador::getnickHost(){
    return this->nickHost;
};

string** dtPartidaMultijugador::getjugadoresUnidos(){
    return this->jugadoresUnidos;
}