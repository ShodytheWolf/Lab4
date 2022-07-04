#include "Jugador.h"
#include "string.h"

Jugador::Jugador(string correo, string contrasenia, const char* nick, string descripcionJugador)
{
    this->email = correo;
    this->contrasenia = contrasenia;
    setNickname(nick) ;
    setDescripcionJugador(descripcionJugador);
}

Jugador::~Jugador()
{

}


//Operaciones del padre:
string Jugador::getContrasenia(){
    return this->contrasenia;
}
void Jugador::setContrasenia(string pass){
    this->contrasenia = pass;
}
string Jugador::getEmail(){
    return this->email;
}
void Jugador::setEmail(string correo){
    this->email = correo;
}

//Setters y getter:
String* Jugador::getNickname() {
    return nickname;
}

void Jugador::setNickname(const char* nick) 
{
    this->nickname = new String(nick) ;
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

string** Jugador::listarJuegosSuscripto(){
    IIterator* it = registros->getIterator();
    
    string** listaADevolver = new string*[this->registros->getSize()];
    int i = 0;
    while(it->hasCurrent()){
        Registro* reg = dynamic_cast<Registro*>(it->getCurrent());
        listaADevolver[i] = new string(reg->getVideojuego()->getNombreJuego()->getValue());
        it->next();
    }
    delete it;
    return listaADevolver;
} 

dtPartidaIndividual** Jugador::listarPartidasFinalizadas(){
    IIterator* it = partidasInactivas->getIterator();
    dtPartidaIndividual** listaADevolver = new dtPartidaIndividual*[this->partidasInactivas->getSize()];//la lista devuelta es mas grande de lo que necesita tho

    int i = 0;
    while(it->hasCurrent()){

        if(dynamic_cast<dtPartidaIndividual*>(it->getCurrent())){//me aseguro que sea una partida individual lo que estoy consiguiendo
            dtPartidaIndividual* partidaIndi = dynamic_cast<dtPartidaIndividual*>(it->getCurrent());//casteo
            listaADevolver[i] = partidaIndi;//la guardo
            i++;
        };
        it->next();
    }
    delete it;
    return listaADevolver;
}

void Jugador::partidaAContinuar(dtPartidaIndividual* datosPartida){}

String* Jugador::getNick(string nombreJuego){

    bool taSuscritoSi = false;
    String* s1 = new String(nombreJuego.data());

    IIterator* it = registros->getIterator();

    while(it->hasCurrent()){
        Registro* reg = dynamic_cast<Registro*>(it->getCurrent());
        String* s2 = reg->getVideojuego()->getNombreJuego();

        if(s1 == s2){
            taSuscritoSi = reg->estaSuscrito();
            if(taSuscritoSi){
                return s2;
            }
        }
        it->next();
    }
    delete it;
    return NULL;
}

Multijugador* Jugador::iniciarMultijugador(dtPartidaMultijugador* datosPartida,Videojuego* vj, int idPartida,time_t horaActual){

    if(datosPartida->getEnVivo()){

        EnVivo* partiAAnadiar = new EnVivo(idPartida,horaActual,0,vj);

        Integer* k = new Integer(idPartida);
        partidasActivas->add(k,partiAAnadiar);

        return partiAAnadiar;

    }else{

        Multijugador* partiAAnadiar = new Multijugador(idPartida,horaActual,0,vj);

        Integer* k = new Integer(idPartida);
        partidasActivas->add(k,partiAAnadiar);

        return partiAAnadiar;
    }
    
}

void Jugador::iniciarIndividual(dtPartidaIndividual* datosPartida,Videojuego* vj,int idPartida,time_t horaActual){

     if(datosPartida->getContinuacion()){
         //hay que hacer
         OrderedKey* kAnt = new Integer(datosPartida->getIdPartidaAnterior());//conseguimos la key

         Individual* partiContinuada = (Individual*)partidasInactivas->find(kAnt);//conseguimos la partida ya inactiva a continuar

         double horadiferida = difftime(datosPartida->getFecha(),horaActual);
         OrderedKey* k = new Integer(idPartida);
       
         Individual* partiAAnadiar = new Individual(idPartida,horaActual,horadiferida,vj,partiContinuada);

         this->partidasActivas->add(k,partiAAnadiar);
     }else{

         Individual* partiAAnadiar = new Individual(idPartida,horaActual,0,vj,NULL);

         OrderedKey* k2 = new Integer(idPartida);

         this->partidasActivas->add(k2,partiAAnadiar);
     }
     return;
}
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


void Jugador::eliminarContRegisJuego(Videojuego* vj){
    IIterator* it;
    for(it = this->registros->getIterator(); it->hasCurrent(); it->next()){
        Registro* r = (Registro*) it->getCurrent();
        if(r->confrmarJuego(vj)){
            registros->remove(r);
            delete r;
            for(it = this->partidasInactivas->getIterator(); it->hasCurrent(); it->next()){
                Partida* paIna = (Partida*) it->getCurrent();
                if(paIna->comprobarJuego(vj)){
                    partidasInactivas->remove(paIna->getId());
                    delete paIna;
                }
            }
        }
        delete it;
        return;
    }
}

void Jugador::unirseAPartida(Multijugador* multi){
    this->partidasUnido->add(multi);
}

