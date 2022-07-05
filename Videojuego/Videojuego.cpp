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
    
    Estadistica* statsHoras = new Estadistica("Horas",
    "Esta estadistica muestra el total de horas de todos los jugadores");
    estadisticas->add(statsHoras->getNombre(), statsHoras);

    Estadistica* statsPuntaje = new Estadistica("Puntaje",
    "Esta estadistica muestra el puntaje promedio otrogado por todos los jugadores al videojuego");
    estadisticas->add(statsPuntaje->getNombre(),statsPuntaje);
}

dtSuscripcion* Videojuego::getCostosVj(){

    dtSuscripcion* datosSus;
    datosSus = new dtSuscripcion(suscripcionMensual->getCostoMensual(),
    suscripcionTrimestral->getCostoTrimestral(), suscripcionAnual->getCostoAnual(),
    suscripcionVitalicia->getCostoVitalicia());

    return datosSus;
}


Videojuego::~Videojuego()
{
    IIterator* it;
    delete this->suscripcionAnual;
    delete this->suscripcionMensual;
    delete this->suscripcionTrimestral;
    delete this->suscripcionVitalicia;
    this->desarrollador = NULL;

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
}

Anual* Videojuego::getSuscripcionAnual() {
    return this->suscripcionAnual;
}

Mensual* Videojuego::getSuscripcionMensual() {
    return this->suscripcionMensual;
}

Trimestral* Videojuego::getSuscripcionTrimestral() {
    return this->suscripcionTrimestral;
}

Vitalicia* Videojuego::getSuscripcionVitalicia() {
    return this->suscripcionVitalicia;
}

int Videojuego::getCantPuntajes() {
    return this->cantPuntajes;
}

void Videojuego::setCantPuntajes(int cantPuntajes) {
    this->cantPuntajes = cantPuntajes;
}

string** Videojuego::getNombreCategorias(){
    string** nCats = new string*[categorias->getSize() + 1];
    int i = 0;
    for(IIterator* it = this->categorias->getIterator(); it->hasCurrent(); it->next()){
        Categoria* c = (Categoria*) it->getCurrent();
        nCats[i] = new string(c->getNombreCategoria()->getValue());
        i++;
    }
    return nCats;
}

void Videojuego::nuevoPuntaje(int p){
    this->puntajeTotal += p;
    Estadistica* e = (Estadistica*) estadisticas->find(new String("Puntaje"));
    e->calcularPromedio(this->puntajeTotal, this->cantPuntajes);
}

void Videojuego::addDtJuego(dtVideoJuego** datosJuego){

    int i = 0;

    while(datosJuego[i]){
        if(datosJuego[i]->getNombreVideojuego() == string(this->nombreJuego->getValue())){ // si nombre del dt es igual al nombre del videojuego que itero
            return;
        }
        i++;
    }
    dtVideoJuego* data = NULL;
    data = new dtVideoJuego(string(this->nombreJuego->getValue()),
	string(this->desarrollador->getNombreEmpresa()->getValue()),
	this->descripcionJuego, this->getCostosVj(), false, 0,0);
    
    datosJuego[i] = data;//añado a lista
    datosJuego[i+1] = NULL; // inicializo siguiente en null.
};

dtEstadistica* Videojuego::getEstadisticas(const char* nStat)
{
    Estadistica* e = (Estadistica*) estadisticas->find(new String(nStat));
    dtEstadistica* dtE = new dtEstadistica(string(e->getNombre()->getValue()), e->getDato());
    return dtE;
}

void Videojuego::setPuntajeTotal(int puntaje) {
    this->puntajeTotal += puntaje;
}
