#include "Multijugador.h"

Multijugador::Multijugador()
{

}

Multijugador::Multijugador(int id, time_t fechaIni, double dura,Videojuego* vjuego)
{
    Integer* k = new Integer(id);
    this->id = k;
    this->fechaInicio = fechaIni;
    this->duracion = dura;
    this->vj = vjuego;
}

Multijugador::~Multijugador()
{

}

time_t Multijugador::registrarHoraRetiro(){}
