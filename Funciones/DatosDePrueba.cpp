#include <iostream>
#include "../Fabrica/Fabrica.h"
#include "../IControlador/IControlador.h"

//Constantes:
#define DESARROLLADORES 4
#define JUGADORES 4
#define CATEGORIAS 13
#define VIDEOJUEGOS 4
#define GENEROS 5
#define PLATAFORMAS 6
#define OTRAS 2

using namespace std;

void cargarDesarrolladores(Fabrica);
void cargarJugadores(Fabrica);
void cargarGeneros(Fabrica);
void cargarPltaformas(Fabrica);
void cargarOtros(Fabrica);

void cargarDatos(){
    Fabrica f;
    char op = ' ';
    do{
        cout
        << "Este modulo carga datos ficticios al sistema para hacer testeos del mismo\n"
        << "Ingrese los datos que quiere cargar:\n"
        << "1.Desarrolladores\n"
        << "2.Jugadores\n"
        << "3.Categorias\n"
        << "4.Videojuegos\n"
        << "5.Suscripciones\n"
        << "6.Puntajes de videojuegos\n"
        << "7.Partidas Individuales\n"
        << "8.Partidas multijugador\n"
        << "9.Abandono de partidas\n"
        << "0.Cancelar"
        <<endl;
        cin >> op;
        switch(op){
            case '1':
                cargarDesarrolladores(f);
                break;
            case '2':
                cargarJugadores(f);
                break;
            case '3':
                cargarGeneros(f);
                cargarPltaformas(f);
                break;
            case '4':
                break;
            case '5':
                break;
            case '6':
                break;
            case '7':
                break;
            case '8':
                break;
            case '9':
                break;
            case '0':
                return;
            default:
                cout << "Opcion incorrecta" <<endl;
        }
    }while (true);    
}

void cargarDesarrolladores(Fabrica f){
    IControlador* sistema = f.getInterface();
    string correos[DESARROLLADORES] = {"ironhide@mail.com", "epic@mail.com", "mojang@mail.com", "ea@mail.com"};
    string empresas[DESARROLLADORES] = {"Ironhide Game Studio", "Epic Games", "Mojang Studios", "EA Sports"};
    for(int i =0; i<DESARROLLADORES; i++){
        sistema->ingresoData(correos[i], "123", false);
        sistema->ingresarEmpresa(empresas[i].data());
        sistema->confirmarNuevoDesarrollador();
    }
}

void cargarJugadores(Fabrica f){
    IControlador* sistema = f.getInterface();
    string correos[JUGADORES] = {"gamer@mail.com", "ari@mail.com", "ibai@mail.com", "camila@mail.com"};
    string nicknames[JUGADORES] = {"gamer", "ari", "ibai", "camila"};
    for(int i =0; i<JUGADORES; i++){
        sistema->ingresoData(correos[i], "123", false);
        sistema->ingresarNickname(nicknames[i].data());
        sistema->confirmarNuevoJugador();
    }
}

void cargarGeneros(Fabrica f){
    IControlador* sistema = f.getInterface();
    string nombres[GENEROS] = {"Deporte", "Supervivencia", "Estrategia", "Accion", "Aventura"};
    for(int i = 0; i<GENEROS; i++){
        sistema->nuevaCategoria(nombres[i].data(),"",Genero);
    }
}

void cargarPltaformas(Fabrica f){
    IControlador* sistema = f.getInterface();
    string nombres[PLATAFORMAS] = {"PC","PS4","Xbox One", "Switch", "Xbox X", "PS5"};
    for(int i = 0; i<PLATAFORMAS; i++){
        sistema->nuevaCategoria(nombres[i].data(),"", Plataforma);
    }
}

void cargarOtros(Fabrica f){
    IControlador* sistema = f.getInterface();
    string otros[OTRAS] = {"Teen","E"};
    string descripciones[OTRAS] = 
    {"Su contenido está dirigido a jóvenes de 13 años en adelante",
    "Su contenido está dirigido para todo público"};
    for(int i = 0; i<OTRAS; i++){
        sistema->nuevaCategoria(otros[i].data(), descripciones[i], Otro);
    }
}
