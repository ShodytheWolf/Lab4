#include "Controlador.h"
#include <iostream>
#include <stdlib.h>
#include "../breakpoint.cpp"

Controlador *Controlador::instance = nullptr;

Controlador::~Controlador()
{
}

Controlador::Controlador()
{
}

Controlador *Controlador::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Controlador();
    }
    return instance;
}

/**
 * @brief Devuelve una lista con el nick de todos los jugadores del sistema
 *
 */
string **Controlador::jugadores()
{
    string **jugadores = new string *[this->usuarios->getSize() + 1];
    if (!this->usuarios->isEmpty())
    {
        int i = 0;
        for (IIterator *it = this->usuarios->getIterator(); it->hasCurrent(); it->next())
        {
            Usuario *u = (Usuario *)it->getCurrent();
            if (dynamic_cast<Jugador *>(u))
            {
                Jugador *j = (Jugador *)u;
                jugadores[i] = new string(j->getNickname()->getValue());
                i++;
            }
        }
    }
    return jugadores;
}

void Controlador::ingresarEmpresa(const char *nombreEmpresa)
{
    this->nombreEmpresa = nombreEmpresa;
}

/**
 * Instancia un nuevo Desarrollador y lo agrega a la lista de usuarios
 */
void Controlador::confirmarNuevoDesarrollador()
{
    Desarrollador *d = new Desarrollador(this->emailUser, this->passUser, this->nombreEmpresa);
    usuarios->add(d->getNombreEmpresa(), d);
}

bool Controlador::ingresarNickname(const char *nickname)
{
    this->nickJugador = nickname;
}

void Controlador::ingresarDescripcion(string descripcion)
{
    this->descripcionJuegador = descripcion;
}

/**
 * Instancia un nuevo Jugador y lo agrega a la lista de usuarios
 */
void Controlador::confirmarNuevoJugador()
{
    Jugador *j = new Jugador(this->emailUser, this->passUser, this->nickJugador, this->descripcionJuegador);
    usuarios->add(j->getNickname(), j);
}

/**
 * @brief El sistema recuerda email y pass y si es necesario verifica si existem
 *
 * @param verificacion  Recibe true si se necesita verificacion y false si no necesita
 * @return true si existe
 * @return false si no existe
 */
bool Controlador::ingresoData(string email, string contrasenia, bool verificacion)
{
    this->emailUser = email;
    this->passUser = contrasenia;
    if (verificacion)
    {
        if (this->usuarios->isEmpty())
            throw invalid_argument("No hay usuarios en el sistema.");
        IIterator *it;
        for (it = usuarios->getIterator(); it->hasCurrent(); it->next())
        {
            Usuario *u = dynamic_cast<Usuario *>(it->getCurrent());
            // cout << "Email: " <<u->getEmail() << "Contra: " <<u->getContrasenia() <<endl;
            if (u->getEmail() == email && u->getContrasenia() == contrasenia)
            {
                delete it;
                return true;
            }
        }
        delete it;
        return false;
    }
}

char Controlador::confirmarSesion()
{
    for (IIterator *it = usuarios->getIterator(); it->hasCurrent(); it->next())
    {
        Usuario *u = (Usuario *)it->getCurrent();
        if (u->getEmail() == this->emailUser && u->getContrasenia() == this->passUser)
        {
            cout << "entre al if" << endl;
            this->loggedUser = u;
            if (dynamic_cast<Jugador *>(u))
                return 'j';
            else
                return 'd';
        }
    }
}

dtCategoria **Controlador::listarGenero()
{

    if (categorias->isEmpty())
    {
        throw invalid_argument("No hay categorias en el sistema.");
    }
    dtCategoria **generos = new dtCategoria *[categorias->getSize() + 1];
    int c = 0;
    for (IIterator *it = categorias->getIterator(); it->hasCurrent(); it->next())
    {
        Categoria *catG = (Categoria *)it->getCurrent();
        if (catG->getTipoCategoria() == Genero)
        {
            generos[c] = catG->getDtGenero();
            c++;
        }
    }
    return generos;
}

dtCategoria **Controlador::listarPlataforma()
{

    dtCategoria **plataformas = new dtCategoria *[categorias->getSize() + 1];
    int c = 0;
    for (IIterator *it = categorias->getIterator(); it->hasCurrent(); it->next())
    {
        Categoria *catP = (Categoria *)it->getCurrent();
        if (catP->getTipoCategoria() == Plataforma)
        {
            plataformas[c] = catP->getDtPlataforma();
            c++;
        }
    }
    return plataformas;
}

dtCategoria **Controlador::listarOtro()
{

    dtCategoria **otros = new dtCategoria *[categorias->getSize() + 1];
    int c = 0;
    for (IIterator *it = categorias->getIterator(); it->hasCurrent(); it->next())
    {
        Categoria *catO = (Categoria *)it->getCurrent();
        if (catO->getTipoCategoria() == Otro)
        {
            otros[c] = catO->getDtOtro();
            c++;
        }
    }
    return otros;
}

void Controlador::publicarVideojuego(dtVideoJuego *datosJuegos, dtCategoria **generos, dtCategoria **plataformas, dtCategoria **otros)
{

    Desarrollador *dev = (Desarrollador *)loggedUser; //traigo al desarrollador
    int i = 0;
    int c = 0;
    String *str;
    // constructor del vj
    Videojuego *vj = new Videojuego(datosJuegos->getNombreVideojuego().data(), datosJuegos->getDescripcionJuego(), dev, datosJuegos->getCostos());//creo el jueguito
    IIterator *it;//creo iterador
    for (it = categorias->getIterator(); it->hasCurrent(); it->next()){ //itero en categorias
        Categoria *cat = (Categoria *)it->getCurrent();//obtengo la categoria
        cout << "iteracion " << c << endl;
        //string* str = new string(cat->getNombreCategoria()->getValue());
        switch (cat->getTipoCategoria()){ //para cada tipo de categoria un caso
        case Genero:
            i = 0;
            while (generos[i]){
                str = new String(generos[i]->getNombre().data());//cambiazo de tipo
                if (cat->getNombreCategoria()->compare(str) == EQUAL){
                    cout << generos[i] << endl;
                    vj->aniadirCategoria(cat); //Tic
                }
                i++;
            }
            break;
        case Plataforma:
            i = 0;
            while (plataformas[i]){     
                str = new String(plataformas[i]->getNombre().data());//cambiazo de tipo
                if (cat->getNombreCategoria()->compare(str) == EQUAL){
                    vj->aniadirCategoria(cat);
                }
                i++;
            }
            break;
        case Otro:
            i = 0;
            while (otros[i]){          
                str = new String(otros[i]->getNombre().data());//cambiazo de tipo
                if (cat->getNombreCategoria()->compare(str) == EQUAL){
                
                    vj->aniadirCategoria(cat);
                }
                i++;
            }
            break;
        }
        c++;
    }
    videojuegos->add(vj->getNombreJuego(), vj); // añado juego
}

dtVideoJuego **Controlador::listarVideojuegosDiferenciada()
{
}
void Controlador::ingresarVideojuego(char *nombreVideojuego)
{
}
bool Controlador::estaSuscripto(char *nombreVideojuego)
{
}
void Controlador::nuevaSuscripcion(enumPago metodoDePago, enumSuscripcion tipoSuscripcion)
{
}
void Controlador::darDeBajaSuscripcion()
{
}

string **Controlador::listarVideojuegosSuscripto()
{

    if (dynamic_cast<Jugador *>(this->loggedUser))
    {
        Jugador *jug = dynamic_cast<Jugador *>(this->loggedUser);

        string **lista = jug->listarJuegosSuscripto();
        return lista;
    }
    else
    {
        throw invalid_argument("Usuario loggeado no es jugador!");
    }
}
dtPartidaIndividual **Controlador::listoPartidasInactivas()
{

    Jugador *jug = dynamic_cast<Jugador *>(this->loggedUser);

    dtPartidaIndividual **listaPartidas = jug->listarPartidasFinalizadas();
    return listaPartidas;
}
void Controlador::confirmarIndividual(dtPartidaIndividual *datosPartida)
{

    // PREGUNTAR AL BRAIAN ESO DE PASAR DE string A char*

    Jugador *jug = dynamic_cast<Jugador *>(this->loggedUser);

    OrderedKey *k = new String(datosPartida->getNombreVideojuego());

    this->ultimaIdPartida = +1;
    jug->iniciarIndividual(datosPartida, (Videojuego *)videojuegos->find(k), this->ultimaIdPartida, this->horaActual); // casteo paaaaaaaaaaaaa
}

string **Controlador::listarNicks(string nombreVideojuego)
{

    IIterator *it = usuarios->getIterator();
    string **listaADevolver = new string *[usuarios->getSize()];

    int c = 0;
    while (it->hasCurrent())
    {

        if (dynamic_cast<Jugador *>(it->getCurrent()))
        {

            Jugador *jug = dynamic_cast<Jugador *>(it->getCurrent());
            String *str = jug->getNick(nombreVideojuego);

            if (str)
            {
                listaADevolver[c] = new string(str->getValue()); // robadísimo del braian xDDDD
                c++;
            }
        }
        it->next();
    }
    return listaADevolver;
}

void Controlador::confirmarMultijugador(dtPartidaMultijugador *datosPartida)
{
    Jugador *jug = dynamic_cast<Jugador *>(this->loggedUser);

    OrderedKey *k = new String(datosPartida->getNombreVideojuego());

    this->ultimaIdPartida = +1;
    Multijugador *multi = jug->iniciarMultijugador(datosPartida, (Videojuego *)videojuegos->find(k), this->ultimaIdPartida, this->horaActual); // casteo paaaaaaaaaaaaa

    int i = 0;
    while (datosPartida->getjugadoresUnidos()[i] != NULL)
    {
        String *str = new String(datosPartida->getjugadoresUnidos()[i]->data());

        Jugador *user = dynamic_cast<Jugador *>(this->usuarios->find(str));
        user->unirseAPartida(multi);
        i++;
    }
}

dtPartida **Controlador::listoPartidasActivas()
{
}

void Controlador::seleccionarPartida(int idPartida)
{
}

string **Controlador::listarTodosVJ()
{
}

dtVideoJuego *Controlador::seleccionarVideojuego(char *nombreVideojuego)
{
}

string **Controlador::listarVideojuegosPublicados()
{
    if (this->videojuegos->isEmpty())
        throw invalid_argument("No hay videojuegos en el sistema");
    int tam = this->videojuegos->getSize();
    string **listVJ = new string *[tam + 1];
    Desarrollador *d = (Desarrollador *)this->loggedUser;
    IIterator *it;
    int i = 0;
    for (it = videojuegos->getIterator(); it->hasCurrent(); it->next())
    {
        Videojuego *vj = dynamic_cast<Videojuego *>(it->getCurrent());
        // if(vj->getDesarrollador()->getNombreEmpresa() == d->getNombreEmpresa()) ESTO ESTA MAL
        // if(vj->getDesarrollador()->getNombreEmpresa().getValue() == d->getNombreEmpresa().getValue) ESTO ESTA BIEN PERO ESTA MAL !!!!
        // if(vj->getDesarrollador()->getNombreEmpresa().compare(d->getNombreEmpresa()) ESTO SIN KEY PUNTERO TAMBIEN ESTRA MAL
        if (vj->getDesarrollador()->getNombreEmpresa()->compare(d->getNombreEmpresa()) == EQUAL)
        { // ESTA ES LA MANERA :D nombreEmpresa es un String*
            listVJ[i] = new string(vj->getNombreJuego()->getValue());
            i++;
        }
    }
    if (listVJ[0] == NULL)
        throw invalid_argument("No hay ningun juego publicado por el Desarrollador");
    for (it = usuarios->getIterator(); it->hasCurrent(); it->next())
    {
        Usuario *u = dynamic_cast<Usuario *>(it->getCurrent());
        if (dynamic_cast<Jugador *>(u))
        {
            Jugador *j = dynamic_cast<Jugador *>(u);
            listVJ = j->comprobarPartidas(listVJ, tam);
        }
        if (listVJ[0] == NULL)
            throw invalid_argument("No hay ningun videojuego sin partida activa");
    }
    delete it;
    return listVJ;
}

void Controlador::confirmoEliminacion(char *nombreVideojuego)
{
    Videojuego *vj = dynamic_cast<Videojuego *>(videojuegos->find(new String(nombreVideojuego)));
    for (IIterator *it = this->usuarios->getIterator(); it->hasCurrent(); it->next())
    {
        Usuario *u = (Usuario *)it->getCurrent();
        if (dynamic_cast<Jugador *>(u))
        {
            Jugador *j = (Jugador *)u;
            j->eliminarContRegisJuego(vj);
        }
    }
    delete vj;
}

/**
 * @brief Crea una nueva categoria y la agrega al diccionario de categorias
 *
 * @param nom nobmre de la categoria
 * @param desc descripcion de la categoria
 * @param tipo tipo de categoria {Genero, Plataforma, Otro}
 */
void Controlador::nuevaCategoria(const char *nom, string desc, enumCategoria tipo)
{
    Categoria *c = new Categoria(nom, desc, tipo);
    categorias->add(new String(nom), c);
}
