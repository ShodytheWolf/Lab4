#include "Partida.h"

Partida::Partida()
{

}

Partida::Partida(int id, time_t fechaInicio, double duracion){
    setId(id);
    this->fechaInicio = fechaInicio;
    this->duracion = duracion;
}

Partida::~Partida()
{
    this->vj = NULL;
}

Integer* Partida::getId() {
    return this->id;
}

void Partida::setId(int id) {
    this->id = new Integer(id);
}

time_t Partida::getFechaInicio() {
    return this->fechaInicio;
}

void Partida::setFechaInicio(time_t fechaInicio) {
    this->fechaInicio = fechaInicio;
}

float Partida::getDuracion() {
    return this->duracion;
}

dtPartida Partida::getDtPartida(){}
void Partida::calcularDuracion(){}

/**
 * @brief Comprueba si la partida es del videojuego que recibe,
 * en dicho caso dvuelve true de lo contrario devuelve false
 */
bool Partida::comprobarJuego(Videojuego* vj){
    if(this->vj == vj){return true;}
    return false;
}

/**
 * @brief Devuelve true si la partida es del videojuego que recibe
 */
bool Partida::verificarJuego(const char* nombreJuego){
    if(this->vj->getNombreJuego()->compare(new String(nombreJuego)) == EQUAL)
        return true;
    return false;
}

Videojuego* Partida::getVideojuego(){
    return this->vj;
}

void Partida::eliminarComentarios(){}
