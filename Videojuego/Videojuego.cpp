#include "Videojuego.h"

Videojuego::Videojuego(const char* nombre, string descripcion, Desarrollador* dev, dtSuscripcion* susCostos)
{
    setNombreJuego(nombre); //creo la key
    this->descripcionJuego = descripcion;
    this->desarrollador = dev;
    this->suscripcionAnual = new Anual(susCostos->getCostoAnual());
    this->suscripcionMensual = new Mensual(susCostos->getCostoMensual());
    this->suscripcionTrimestral = new Trimestral(susCostos->getCostoTrimestral());
    this->suscripcionVitalicia = new Vitalicia(susCostos->getCostoVitalicia());
    
    Estadistica* statsHoras = new Estadistica("Total de Horas",
    "Esta estadistica muestra el total de horas de todos los jugadores");
    estadisticas->add(statsHoras->getNombre(), statsHoras);

    Estadistica* statsPuntaje = new Estadistica("Puntaje promedio",
    "Esta estadistica muestra el puntaje promedio otrogado por todos los jugadores al videojuego");
    estadisticas->add(statsPuntaje->getNombre(),statsPuntaje);
}

Videojuego::~Videojuego()
{
    IIterator* it;
    delete this->suscripcionAnual;
    delete this->suscripcionMensual;
    delete this->suscripcionTrimestral;
    delete this->suscripcionVitalicia;
 
    for(it = this->estadisticas->getIterator(); it->hasCurrent(); it->next()){
        Estadistica* e = (Estadistica*)it->getCurrent();
        delete e;
    }
    delete it;
}

String* Videojuego::getNombreJuego() {
    return this->nombreJuego;
}
void Videojuego::setNombreJuego(const char* nombreJuego) {
    this->nombreJuego = new String(nombreJuego);
}

Desarrollador* Videojuego::getDesarrollador() {
    return this->desarrollador;
}
void Videojuego::setDesarrollador(Desarrollador* desarrollador) {
    this->desarrollador = desarrollador;
}

string Videojuego::getDescripcionJuego() {
    return this->descripcionJuego;
}

void Videojuego::setDescripcionJuego(string descripcionJuego) {
    this->descripcionJuego = descripcionJuego;
}

void Videojuego::aniadirCategoria(Categoria* cat){ //tic
    categorias->add(cat->getNombreCategoria(), cat);
};

void Videojuego::addDtJuego(dtVideoJuego datosJuego){

    //KEKW
};

dtEstadistica** Videojuego::getEstadisticas(){

    //KEKWWWW
};