#include "Jugador.h"
#include "string.h"
//#include "../bp.cpp"

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
////////////////////////
bool Jugador::verificoJuego(Videojuego* vj){

    IIterator* it;
    for(it = registros->getIterator();it->hasCurrent();it->next()){
        Registro* r = (Registro*)it->getCurrent();
        if(r->confirmarJuego(vj)){
            return r->estaSuscrito();
        }
    }
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


void Jugador::pasoJuego(String nombreVideojuego){

    IIterator* it;
    for (it = registros->getIterator(); it->hasCurrent(); it->next()){ //itero en registros.
        Registro* r = (Registro*)it->getCurrent(); //obtengo registro
        if(r->getVideojuego()->getNombreJuego()->compare(&nombreVideojuego) == EQUAL){ //comparo si el juego del registro es igual al que le paso por paramtero.
            r->cancelSuscripcion();
        }
    }
}

//getDatos vj suscripto
dtVideoJuego** Jugador::getDatosVj(){  

    dtVideoJuego** listajuegos = new dtVideoJuego*[registros->getSize()+1];
    dtVideoJuego* datoVj; //guardamos datos del dtjuego
    IIterator* it;
    int c = 0;

    for (it = registros->getIterator(); it->hasCurrent(); it->next()){ //itero en registros.
    //     cout << c <<endl;
    //     bp();
        Registro* reg = (Registro*)it->getCurrent(); //obtengo registro
        datoVj = reg->getDtJuego(); //->getNombreVideojuego();llamo al get en registro
        if(datoVj != NULL){
           listajuegos[c] = datoVj; 
        }
        c++;
    }
    listajuegos[c] = NULL;
    return listajuegos;
}

void Jugador::aniadirSuscripcion(Videojuego* obj, enumSuscripcion tipoSuscipcion, enumPago metodoDePago, time_t susDate){

    IIterator* it;
    for(it= registros->getIterator(); it->hasCurrent(); it->next()){//itero en registros
        Registro* r = dynamic_cast<Registro*>(it->getCurrent()); //registro en el q toy parao
        if(r->confirmarJuego(obj)){//confirmo si existe objeto en registro
            r->activarSuscripcion(obj, tipoSuscipcion, metodoDePago, susDate); //llamo coso pum pere
            registros->add(r);
            delete it;
            return;   
        }
    } 
    Registro* r = new Registro(obj, tipoSuscipcion, metodoDePago, susDate);
    registros->add(r);
}

string** Jugador::listarJuegosSuscripto(){
    IIterator* it = registros->getIterator();
    
    string** listaADevolver = new string*[this->registros->getSize()+1];

    int registrocant = this->registros->getSize();
    //cout<<"la cantidad de registros que tengo es: "<<registrocant<<endl;
    if(!it->hasCurrent()){
        //cout<<"El jugador no tiene ningun juego suscripto :c"<<endl;
        return NULL;
    }

    int i = 0;
    while(it->hasCurrent()){
        Registro* reg = dynamic_cast<Registro*>(it->getCurrent());

        listaADevolver[i] = new string(reg->getVideojuego()->getNombreJuego()->getValue());
        i++;
        it->next();
    }
    listaADevolver[i] = NULL;
    delete it;
    return listaADevolver;
} 

dtPartidaIndividual** Jugador::listarPartidasFinalizadas(string juegoAIniciar){
    IIterator* it = partidasInactivas->getIterator();
    dtPartidaIndividual** listaADevolver = new dtPartidaIndividual*[this->partidasInactivas->getSize()+1];//la lista devuelta es mas grande de lo que necesita tho

    int cont = this->partidasInactivas->getSize();
    //cout<<"La cantidad de partidas inactivas es "<<cont<<endl;
    int i = 0;
    while(it->hasCurrent()){

        if(dynamic_cast<Individual*>(it->getCurrent())){//me aseguro que sea una partida individual lo que estoy consiguiendo
            
            Individual* partidaIndi = dynamic_cast<Individual*>(it->getCurrent());//casteo

            //aca controlar que siempre se guarden partidas de un juego X
            if(string(partidaIndi->getVideojuego()->getNombreJuego()->getValue()) == juegoAIniciar){

                dtPartidaIndividual* dtPartidaIndi = dynamic_cast<dtPartidaIndividual*>(partidaIndi->getDtPartida());

                listaADevolver[i] = dtPartidaIndi;//la guardo
                i++;
            }

        };
        it->next();
    }

    // if(i == 0){
    //     listaADevolver[0] = NULL;
    // }

    listaADevolver[i] = NULL;
    delete it;
    return listaADevolver;
}

//void Jugador::partidaAContinuar(dtPartidaIndividual* datosPartida){}

String* Jugador::getNick(Videojuego* vj){

    bool taSuscritoSi = false;

    IIterator* it = registros->getIterator();

    while(it->hasCurrent()){
        Registro* reg = dynamic_cast<Registro*>(it->getCurrent());

        if(reg->confirmarJuego(vj)){
            taSuscritoSi = reg->estaSuscrito();
            if(taSuscritoSi){
                return this->nickname;
            }
        }
        it->next();
    }
    delete it;
    return NULL;
}

Multijugador* Jugador::iniciarMultijugador(dtPartidaMultijugador* datosPartida,Videojuego* vj, int idPartida,time_t horaActual, string** jugadoresUnidos){

    if(datosPartida->getEnVivo()){

        EnVivo* partiAAnadiar = new EnVivo(idPartida,horaActual,0,vj,datosPartida->getjugadoresUnidos());


        Integer* k = new Integer(idPartida);
        partidasActivas->add(k,partiAAnadiar);

        return partiAAnadiar;

    }else{

        Multijugador* partiAAnadiar = new Multijugador(idPartida,horaActual,0,vj,datosPartida->getjugadoresUnidos());

        Integer* k = new Integer(idPartida);
        partidasActivas->add(k,partiAAnadiar);

        return partiAAnadiar;
    }
    
}

void Jugador::iniciarIndividual(dtPartidaIndividual* datosPartida,Videojuego* vj,int idPartida,time_t horaActual){

     if(datosPartida->getContinuacion()){
         //hay que hacer
        Integer* kAnt = new Integer(datosPartida->getIdPartidaAnterior());//conseguimos la key

        Individual* partiAnterior = (Individual*)partidasInactivas->find(kAnt);//conseguimos la partida ya inactiva a continuar



        //double horadiferida = difftime(partiContinuada->getFechaInicio(),horaActual);
        Integer* k = new Integer(idPartida);
        
       
        Individual* partiAAnadiar = new Individual(idPartida,horaActual,partiAnterior->getDuracion(),vj,partiAnterior);
         
        this->partidasActivas->add(k,partiAAnadiar);
     }else{

        Individual* partiAAnadiar = new Individual(idPartida,horaActual,0,vj,NULL);
        Integer* k2 = new Integer(idPartida);

        this->partidasActivas->add(k2,partiAAnadiar);
     }
     return;
}
// dtPartidaIndividual** Jugador::listarPartidasIndividuales(){}
// dtPartidaMultijugador** Jugador::partidaAFinalizar(){}

void Jugador::partidaAFinalizar(int idPartida, time_t horaActual){

    Integer* k = new Integer(idPartida);
    Partida* parti = dynamic_cast<Partida*>(this->partidasActivas->find(k));

    //time_t horaDiferida = difftime(horaActual, parti->getFechaInicio());
    parti->calcularDuracion(horaActual);
    //parti->setDuracion(horaDiferida);


    this->partidasInactivas->add(parti->getId(),parti);
    this->partidasActivas->remove(parti->getId());
}

/**
 * @brief Operacion que comprueba si tiene partidas activas para Videojuegos 
 * concretos
 * 
 * @param nombreJuegos Lista de juegos concretos 
 * @return string** Lista con la misma cantidad o menos de la que recibio 
 */
string** Jugador::comprobarPartidas(string** nombreJuegos, int t){
    
    // if(partidasActivas->isEmpty())
    //     return nombreJuegos;
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
    juegosComp[c] = NULL;
    return juegosComp;
}


void Jugador::eliminarContRegisJuego(Videojuego* vj){
    int contador = 0;
    IIterator* it;
    for(it = this->registros->getIterator(); it->hasCurrent(); it->next()){
        Registro* r = (Registro*) it->getCurrent();
        if(r->confirmarJuego(vj)){
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
    }
    for(IIterator* i = registros->getIterator(); i->hasCurrent(); i->next()){ 
        Registro* r = (Registro*) i->getCurrent();
    }
    delete it;
    return;
}

void Jugador::unirseAPartida(Multijugador* multi){

    this->partidasUnido->add(multi->getId(),multi);
}


dtPartida** Jugador::getDtPartidasActivas(){

    IIterator* it = this->partidasActivas->getIterator();
    dtPartida** listaADevolver = new dtPartida*[this->partidasActivas->getSize()+1];

    int c = 0;
    while(it->hasCurrent()){
        Partida* Parti = dynamic_cast<Partida*>(it->getCurrent());
        if(dynamic_cast<Individual*>(Parti)){

            Individual* pI = dynamic_cast<Individual*>(Parti);
            listaADevolver[c] = Parti->getDtPartida();
            c++;
        }else{
            if(dynamic_cast<EnVivo*>(it->getCurrent())){

                Parti = dynamic_cast<EnVivo*>(it->getCurrent());
                listaADevolver[c] = Parti->getDtPartida(string(this->nickname->getValue()));
                c++;
            }else{

                Parti = dynamic_cast<Multijugador*>(it->getCurrent());
                listaADevolver[c] = Parti->getDtPartida(string(this->nickname->getValue()));
                c++;
            }
        }
        it->next(); 
    }
    delete it;

    //if(c == 0){
       // listaADevolver[0] = NULL;
  //  }

    listaADevolver[c] = NULL;

    return listaADevolver;
}

void Jugador::nuevoPuntaje(Videojuego* vj, int p){
    for(IIterator* it = registros->getIterator(); it->hasCurrent(); it->next()){
        Registro* r = (Registro*) it->getCurrent();
        if(r->confirmarJuego(vj)){   
            r->puntuar(p);
            break;
        }
    }
}

void Jugador::abandonarPartidaMultijugador(int idpartida, time_t horaActual){

    Integer* k = new Integer(idpartida);

    Partida* parti = dynamic_cast<Partida*>(this->partidasUnido->find(k));
    if(parti == NULL){
        return;

    }else{
        if(dynamic_cast<EnVivo*>(parti)){
            EnVivo* partiEnVivo = dynamic_cast<EnVivo*>(parti);
            partiEnVivo->registrarHoraRetiro(horaActual);//ACA PASO LA HORA DEL SISTEMA

            this->partidasUnido->remove(partiEnVivo->getId());

            return;
        }else{
            Multijugador* partiMulti = dynamic_cast<Multijugador*>(parti);
            partiMulti->registrarHoraRetiro(horaActual);

            this->partidasUnido->remove(partiMulti->getId());
            return;
        }
    }
}
