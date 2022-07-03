#include <iostream>
#include <vector>
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
void cargarVideojuegos(Fabrica);

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
                cargarOtros(f);
                break;
            case '4':
                cargarVideojuegos(f);
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
    //                                      D1                      D2              D3              D4
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
    //                            C4         C5                C6          C9        C10 
    string nombres[GENEROS] = {"Deporte", "Supervivencia", "Estrategia", "Accion", "Aventura"};
    for(int i = 0; i<GENEROS; i++){
        sistema->nuevaCategoria(nombres[i].data(),"",Genero);
    }
}

void cargarPltaformas(Fabrica f){
    IControlador* sistema = f.getInterface();
    //                              C1     C2      C3       C11       C12      C13
    string nombres[PLATAFORMAS] = {"PC","PS4","Xbox One", "Switch", "Xbox X", "PS5"};
    for(int i = 0; i<PLATAFORMAS; i++){
        sistema->nuevaCategoria(nombres[i].data(),"", Plataforma);
    }
}

void cargarOtros(Fabrica f){
    IControlador* sistema = f.getInterface();
    //                       C7    C8
    string otros[OTRAS] = {"Teen","E"};
    string descripciones[OTRAS] = 
    {"Su contenido está dirigido a jóvenes de 13 años en adelante",
    "Su contenido está dirigido para todo público"};
    for(int i = 0; i<OTRAS; i++){
        sistema->nuevaCategoria(otros[i].data(), descripciones[i], Otro);
    }
}

void cargarVideojuegos(Fabrica f){ //para arreglar
    IControlador* sistema = f.getInterface();
    //"Kingdom Rush", "Fortnite", "Minecraft", "FIFA"
    dtSuscripcion* costosKR = new dtSuscripcion(1,2,7,14);
    dtSuscripcion* costosFortnite = new dtSuscripcion(3,8,30,60);
    dtSuscripcion* costosMinecraft = new dtSuscripcion(2,5,20,40);
    dtSuscripcion* costosFIFA = new dtSuscripcion(3,8,28,50);
    dtCategoria* c1 = new dtCategoria("PC", NULL, Plataforma);
    dtCategoria* c2 = new dtCategoria("PS4", NULL, Plataforma);
    dtCategoria* c3 = new dtCategoria("Xbox One", NULL, Plataforma);
    dtCategoria* c4 = new dtCategoria("Deporte",NULL,Genero);
    dtCategoria* c5 = new dtCategoria("Supervivencia",NULL,Genero);
    dtCategoria* c6 = new dtCategoria("Estrategia",NULL,Genero);
    dtCategoria* c7 = new dtCategoria("Teen",NULL,Otro);
    dtCategoria* c8 = new dtCategoria("E",NULL,Otro);

    //Incersion del Kingdom Rush
    dtCategoria** plataformasKR = new dtCategoria*[3];
    plataformasKR[0] = c1; plataformasKR[1] = c2;
    dtCategoria** generosKR = new dtCategoria*[2];
    generosKR[0] = c6;
    dtCategoria** otrosKR = new dtCategoria*[2];
    otrosKR[0] = c8;
    dtVideoJuego* datosKR = new dtVideoJuego("Kingdom Rush", "", "", costosKR, false, 0, 0);
    sistema->publicarVideojuego(datosKR, generosKR, plataformasKR, otrosKR);

    //Incersion del Fortnite
    dtCategoria** plataformasFortnite = new dtCategoria*[4];
    plataformasFortnite[0] = c1; plataformasFortnite[1] = c2; plataformasFortnite[2] = c3;
    dtCategoria** generosFortnite = new dtCategoria*[2];
    generosFortnite[0] = c5;
    dtCategoria** otrosFortnite = new dtCategoria*[2];
    otrosFortnite[0] = c7;
    dtVideoJuego* datosFortnite = new dtVideoJuego("Fortnite", "", "", costosFortnite, false, 0, 0);
    sistema->publicarVideojuego(datosFortnite, generosFortnite, plataformasFortnite, otrosFortnite);

    //Incersion del Minecraft
    dtCategoria** plataformasMinecraft = new dtCategoria*[2];
    plataformasMinecraft[0] = c1; 
    dtCategoria** generosMinecraft = new dtCategoria*[2];
    generosMinecraft[0] = c5;
    dtCategoria** otrosMinecraft = new dtCategoria*[2];
    otrosMinecraft[0] = c8;
    dtVideoJuego* datosMinecraft = new dtVideoJuego("Minecraft", "", "", costosMinecraft, false, 0, 0);
    sistema->publicarVideojuego(datosMinecraft, generosMinecraft, plataformasMinecraft, otrosMinecraft);

    //Incersion del FIFA
    dtCategoria** plataformasFIFA = new dtCategoria*[4];
    plataformasFIFA[0] = c1; plataformasFIFA[1] = c2; plataformasFIFA[2] = c3;
    dtCategoria** generosFIFA = new dtCategoria*[2];
    generosFIFA[0] = c4;
    dtCategoria** otrosFIFA = new dtCategoria*[2];
    otrosFIFA[0] = c8;
    dtVideoJuego* datosFIFA = new dtVideoJuego("FIFA", "", "", costosFIFA, false, 0, 0);
    sistema->publicarVideojuego(datosFIFA, generosFIFA, plataformasFIFA, otrosFIFA);

}  
/**
 * C1: PC
 * C2: PS4
 * C3: Xbox One
 * C4: Deporte
 * C5: Supervivencia
 * C6: Estrategia
 * C7: Teen
 * C8: E
 * 
 */
/**
 *
 *  
    V1 D1 KingdomRush $1 | $2 | $7 | $14 C1, C2, C6, C8
    V2 D2 Fortnite $3 | $8 | $30 | $60 C1, C2, C3, C5, C7
    V3 D3 Minecraft $2 | $5 | $20 | $40 C1, C5, C8
    V4 D4 FIFA 21 $3 | $8 | $28 | $50 C1, C2, C3, C4, C8
 * 
 */