#include "Multijugador.h"

Multijugador::Multijugador()
{

}

Multijugador::Multijugador(int id, time_t fechaIni, double dura,Videojuego* vjuego,string** jugadoresAUnirse)
{
    Integer* k = new Integer(id);
    this->id = k;
    this->fechaInicio = fechaIni;
    this->duracion = dura;
    this->vj = vjuego;
    this->jugadoresUnidos = jugadoresAUnirse;
}

Multijugador::~Multijugador()
{

}

void Multijugador::registrarHoraRetiro(time_t horaFinalizada){
    int c;
    while(this->jugadoresUnidos[c] != NULL){
        c++;
    }

    time_t** listaADevolver = new time_t*[c];

    for (int i = 0; i <= c; i++)
    {
        listaADevolver[i] = &horaFinalizada;
    }
    
   //ACA (O EN OTRO LADO) HAY QUE SACAR EL TAMAÑO DEL HORA REGISTRO DE MIERDA, Y DARLE EL VALOR QUE LE LLEGA POR PARAMETRO
}

void Multijugador::setDuracion(double dura){
    this->duracion = dura;
}

dtPartida* Multijugador::getDtPartida(string papaOso){
    //SEGUIR POR ACA DIVINA uwuwuwuwu
    dtPartidaMultijugador* parti = new dtPartidaMultijugador(this->id->getValue(),this->fechaInicio,string(this->vj->getNombreJuego()->getValue()),false,papaOso,this->jugadoresUnidos);
    return parti;
}

dtPartida* Multijugador::getDtPartida(){
    
}