#include "Controlador.h"
#include <iostream>
#include <stdlib.h>

Controlador* Controlador::instance = nullptr;


Controlador::~Controlador(){

}

Controlador::Controlador(){

}

Controlador* Controlador::getInstance(){
    if( instance == nullptr ){
        instance = new Controlador();
    }
    return instance;
}

/**
 * @brief Devuelve una lista con el nick de todos los jugadores del sistema
 * 
 */
string** Controlador::jugadores(){
    string** jugadores = new string*[this->usuarios->getSize() + 1];
    if(!this->usuarios->isEmpty()){
        int i = 0;
        for(IIterator* it = this->usuarios->getIterator(); it->hasCurrent(); it->next()){
            Usuario* u = (Usuario*) it->getCurrent();
            if((Jugador*)u){
                Jugador* j = (Jugador*) u;
                jugadores[i] = new string(j->getNickname()->getValue()); 
                i++;
            }
        }
    }
    return jugadores;
}

void Controlador::ingresarEmpresa(char* nombreEmpresa){
    this->nombreEmpresa = nombreEmpresa;

}   

/**
 * Instancia un nuevo Desarrollador y lo agrega a la lista de usuarios
 */
void Controlador::confirmarNuevoDesarrollador(){
    Desarrollador* d = new Desarrollador(this->emailUser, this->passUser, this->nombreEmpresa);
    usuarios->add(d->getNombreEmpresa(), d);
}


bool Controlador::ingresarNickname(char* nickname){
    this->nickJugador = nickname;
}   


void Controlador::ingresarDescripcion(string descripcion){
    this->descripcionJuegador = descripcion;
}  

/**
 * Instancia un nuevo Jugador y lo agrega a la lista de usuarios
 */
void Controlador::confirmarNuevoJugador(){
    Jugador* j = new Jugador(this->emailUser, this->passUser, this->nickJugador, this->descripcionJuegador);
    usuarios->add(j->getNickname(), j);
}

/**
 * @brief El sistema recuerda email y pass y si es necesario verifica si existem
 * 
 * @param verificacion  Recibe true si se necesita verificacion y false si no necesita
 * @return true si existe
 * @return false si no existe
 */
bool Controlador::ingresoData(string email, string contrasenia, bool verificacion){
    this->emailUser = email;
    this->passUser = contrasenia;
    if(verificacion){
        if(this->usuarios->isEmpty())
            throw invalid_argument("No hay usuarios en el sistema");

        IIterator* it;
        for(it = usuarios->getIterator(); it->hasCurrent(); it->next()){
            Usuario* u = dynamic_cast<Usuario*>(it->getCurrent());
            if(u->getEmail() == email && u->getContrasenia() == contrasenia){
                delete it;
                return true;
            }
        }
        delete it;
        return false;
    }
}

void Controlador::confirmarSesion(){
    IIterator* it;
    for(it = usuarios->getIterator(); it->hasCurrent(); it->next()){
        Usuario* u = dynamic_cast<Usuario*>(it->getCurrent());
        if(u->getEmail() == this->emailUser && u->getContrasenia() == this->passUser){
            this->loggedUser = u;
            break;
        }
    }
    delete it;
}

dtCategoria** Controlador::listarGenero(){

}                                                   
dtCategoria** Controlador::listarPlataforma(){

}                                                
dtCategoria** Controlador::listarOtro(){

}                                                      
void Controlador::publicarVideojuego(dtVideoJuego datosJuegos,dtCategoria**                    
genero, dtCategoria** plataforma, dtCategoria** otros){

}                            
dtVideoJuego** Controlador::listarVideojuegosDiferenciada(){

}                                 
void Controlador::ingresarVideojuego(char* nombreVideojuego){

}
bool Controlador::estaSuscripto(char* nombreVideojuego){
    
}                                 
void Controlador::nuevaSuscripcion(enumPago metodoDePago, enumSuscripcion tipoSuscripcion){

}   
void Controlador::darDeBajaSuscripcion(){

}                                                   

string** Controlador::listarVideojuegosSuscripto(){
        
  if(dynamic_cast<Jugador*>(this->loggedUser)){

        Jugador* jug = dynamic_cast<Jugador*>(this->loggedUser);

        string** lista = jug->listarJuegosSuscripto();
        return lista;
    }else{
        throw invalid_argument("Usuario loggeado no es jugador!");
    }
    

}                                           
dtPartidaIndividual** Controlador::listoPartidasInactivas(){
    
    Jugador* jug = dynamic_cast<Jugador*>(this->loggedUser);

    dtPartidaIndividual** listaPartidas = jug->listarPartidasFinalizadas();
    return listaPartidas;

}                                 
void Controlador::confirmarIndividual(dtPartidaIndividual *datosPartida){

    //PREGUNTAR AL BRAIAN ESO DE PASAR DE string A char*

    Jugador* jug = dynamic_cast<Jugador*>(this->loggedUser);

    OrderedKey* k = new String(datosPartida->getNombreVideojuego());
    

    jug->iniciarIndividual(datosPartida,(Videojuego*)videojuegos->find(k));//casteo paaaaaaaaaaaaa

}   

string** Controlador::listarNicks(char* nombreVideojuego){

}                                        
void Controlador::confirmarMultijugador (dtPartidaMultijugador *datosPartida){

}                

dtPartida** Controlador::listoPartidasActivas(){

}                                              
void Controlador::seleccionarPartida(int idPartida){

}

string** Controlador::listarTodosVJ(){

}

dtVideoJuego* Controlador::seleccionarVideojuego(char* nombreVideojuego){

}                    
string** Controlador::listarVideojuegosPublicados(){
    if(this->videojuegos->isEmpty())
        throw invalid_argument("No hay videojuegos en el sistema");
    int tam = this->videojuegos->getSize();
    string** listVJ = new string*[tam + 1];
    Desarrollador* d = (Desarrollador*) this->loggedUser;
    IIterator* it;
    int i=0;
    for(it = videojuegos->getIterator(); it->hasCurrent(); it->next()){
        Videojuego* vj = dynamic_cast<Videojuego*>(it->getCurrent());
        //if(vj->getDesarrollador()->getNombreEmpresa() == d->getNombreEmpresa()) ESTO ESTA MAL
        //if(vj->getDesarrollador()->getNombreEmpresa().getValue() == d->getNombreEmpresa().getValue) ESTO ESTA BIEN PERO ESTA MAL !!!!
        //if(vj->getDesarrollador()->getNombreEmpresa().compare(d->getNombreEmpresa()) ESTO SIN KEY PUNTERO TAMBIEN ESTRA MAL
        if(vj->getDesarrollador()->getNombreEmpresa()->compare(d->getNombreEmpresa()) == EQUAL){ //ESTA ES LA MANERA :D nombreEmpresa es un String*
            listVJ[i] = new string(vj->getNombreJuego()->getValue());
            i++;
        }
    }
    if(listVJ[0] == NULL)
        throw invalid_argument("No hay ningun juego publicado por el Desarrollador");
    for(it = usuarios->getIterator(); it->hasCurrent(); it->next()){
        Usuario* u = dynamic_cast<Usuario*>(it->getCurrent());
        if(dynamic_cast<Jugador*>(u)){
            Jugador* j = dynamic_cast<Jugador*>(u);
            listVJ = j->comprobarPartidas(listVJ, tam);
        }
        if(listVJ[0] == NULL)
            throw invalid_argument("No hay ningun videojuego sin partida activa");
    }
    delete it;
    return listVJ;
}    


void Controlador::confirmoEliminacion (char* nombreVideojuego){
    Videojuego* vj = dynamic_cast<Videojuego*>(videojuegos->find(new String(nombreVideojuego)));
    for(IIterator* it = this->usuarios->getIterator(); it->hasCurrent(); it->next()){
        Usuario* u = (Usuario*) it->getCurrent();
        if((Jugador*)u){
            Jugador* j = (Jugador*)u;
            j->eliminarContRegisJuego(vj);
        }
    }
    delete vj;
}                               
