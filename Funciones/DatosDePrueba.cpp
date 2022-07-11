#include <iostream>
#include <vector>
#include "../Fabrica/Fabrica.h"
#include "../IControlador/IControlador.h"
//#include "../breakpoint.cpp"

//Constantes:
#define DESARROLLADORES 4
#define JUGADORES 4
#define CATEGORIAS 13
#define VIDEOJUEGOS 4
#define GENEROS 5
#define PLATAFORMAS 6
#define OTRAS 2
#define SUSCRIPCIONES 6
#define PUNTAJES 4
#define INDIVIDUALES 3
#define MULTIJUGADOR 3

using namespace std;

void cargarDesarrolladores(Fabrica); //1
void cargarJugadores(Fabrica); //2
void cargarGeneros(Fabrica); //3
void cargarPltaformas(Fabrica); //3
void cargarOtros(Fabrica); //3
void cargarVideojuegos(Fabrica); //4
void cargarSuscripciones(Fabrica); //5
void cargarPuntajes(Fabrica); //6
void cargarIndividuales(Fabrica); //7
void cargarMultijugador(Fabrica); //8
void finDeFuncion();

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
                cargarSuscripciones(f);
                break;
            case '6':
                cargarPuntajes(f);
                break;
            case '7':
                cargarIndividuales(f);
                break;
            case '8':
                cargarMultijugador(f);
                break;
            case '0':
                system("clear");
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

    cout  << "Cargaste datos de desarrolladores" << endl;
    cout << "Presione ENTER para continuar..." << endl;
    getchar();
    getchar();
    system("clear");
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

    finDeFuncion();
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
    finDeFuncion(); 
}

void cargarVideojuegos(Fabrica f){ 
    IControlador* sistema = f.getInterface();
    //"Kingdom Rush", "Fortnite", "Minecraft", "FIFA"
    dtSuscripcion* costosKR = new dtSuscripcion(1,2,7,14, enumSuscripcion(NULL));
    dtSuscripcion* costosFortnite = new dtSuscripcion(3,8,30,60, enumSuscripcion(NULL));
    dtSuscripcion* costosMinecraft = new dtSuscripcion(2,5,20,40, enumSuscripcion(NULL));
    dtSuscripcion* costosFIFA = new dtSuscripcion(3,8,28,50, enumSuscripcion(NULL));
    dtCategoria* c1 = new dtCategoria("PC", "", Plataforma);
    dtCategoria* c2 = new dtCategoria("PS4", "", Plataforma);
    dtCategoria* c3 = new dtCategoria("Xbox One", "", Plataforma);
    dtCategoria* c4 = new dtCategoria("Deporte","",Genero);
    dtCategoria* c5 = new dtCategoria("Supervivencia","",Genero);
    dtCategoria* c6 = new dtCategoria("Estrategia","",Genero);
    dtCategoria* c7 = new dtCategoria("Teen","",Otro);
    dtCategoria* c8 = new dtCategoria("E","",Otro);

    //Incersion del Minecraft
    dtCategoria** plataformasMinecraft = new dtCategoria*[2];
    plataformasMinecraft[0] = c1; 
    dtCategoria** generosMinecraft = new dtCategoria*[2];
    generosMinecraft[0] = c5;
    dtCategoria** otrosMinecraft = new dtCategoria*[2];
    otrosMinecraft[0] = c8;
    sistema->ingresoData("mojang@mail.com", "123", false);
    sistema->confirmarSesion();
    dtVideoJuego* datosMinecraft = new dtVideoJuego("Minecraft", "", "", costosMinecraft, false, 0, 0);
    sistema->publicarVideojuego(datosMinecraft, generosMinecraft, plataformasMinecraft, otrosMinecraft);

    //Incersion del FIFA
    dtCategoria** plataformasFIFA = new dtCategoria*[4];
    plataformasFIFA[0] = c1; plataformasFIFA[1] = c2; plataformasFIFA[2] = c3;
    dtCategoria** generosFIFA = new dtCategoria*[2];
    generosFIFA[0] = c4;
    dtCategoria** otrosFIFA = new dtCategoria*[2];
    otrosFIFA[0] = c8;
    sistema->ingresoData("ea@mail.com", "123", false);
    sistema->confirmarSesion();
    dtVideoJuego* datosFIFA = new dtVideoJuego("FIFA", "", "", costosFIFA, false, 0, 0);
    sistema->publicarVideojuego(datosFIFA, generosFIFA, plataformasFIFA, otrosFIFA);


    //Incersion del KingdomRush
    dtCategoria** plataformasKR = new dtCategoria*[3];
    plataformasKR[0] = c1; plataformasKR[1] = c2;
    dtCategoria** generosKR = new dtCategoria*[2];
    generosKR[0] = c6;
    dtCategoria** otrosKR = new dtCategoria*[2];
    otrosKR[0] = c8;
    dtVideoJuego* datosKR = new dtVideoJuego("KingdomRush", "", "", costosKR, false, 0, 0);
    sistema->ingresoData("ironhide@mail.com", "123", false);
    sistema->confirmarSesion();
    sistema->publicarVideojuego(datosKR, generosKR, plataformasKR, otrosKR);

    //Incersion del Fortnite
    dtCategoria** plataformasFortnite = new dtCategoria*[4];
    plataformasFortnite[0] = c1; plataformasFortnite[1] = c2; plataformasFortnite[2] = c3;
    dtCategoria** generosFortnite = new dtCategoria*[2];
    generosFortnite[0] = c5;
    dtCategoria** otrosFortnite = new dtCategoria*[2];
    otrosFortnite[0] = c7;
    dtVideoJuego* datosFortnite = new dtVideoJuego("Fortnite", "", "", costosFortnite, false, 0, 0);
    sistema->ingresoData("epic@mail.com", "123", false);
    sistema->confirmarSesion();
    sistema->publicarVideojuego(datosFortnite, generosFortnite, plataformasFortnite, otrosFortnite);



    finDeFuncion();

}  

void cargarSuscripciones(Fabrica f){
    IControlador* sistema = f.getInterface();
    string mailJdrs[SUSCRIPCIONES] = {"gamer@mail.com", "gamer@mail.com", "ari@mail.com", "ari@mail.com", "ibai@mail.com", "ibai@mail.com"};
    string juegos[SUSCRIPCIONES] = {   "KingdomRush",     "Fortnite",       "Fortnite",      "Minecraft",   "Fortnite",       "Minecraft"};
    enumSuscripcion tipoSus[SUSCRIPCIONES] = {Trim, Trim, Men, An, Men, Vit};
    int anios[SUSCRIPCIONES] = {2021, 2021, 2021, 2021, 2021, 2020};
    int meses[SUSCRIPCIONES] = {06, 06, 06, 06, 06, 05};
    int dias[SUSCRIPCIONES] = {01, 02, 04, 11, 03, 21};
    int horas[SUSCRIPCIONES] = {9, 11, 9, 9, 07, 15};
    enumPago tipoPagos[SUSCRIPCIONES] = {Paypal, Tarjeta, Paypal, Tarjeta, Tarjeta, Tarjeta};
    for(int i = 0; i < SUSCRIPCIONES; i++){
        sistema->ingresoData(mailJdrs[i], "123", false);
        sistema->confirmarSesion();
        tm fecha;
        fecha.tm_year = anios[i];
        fecha.tm_year -= 1900;
        fecha.tm_mon = meses[i];
        fecha.tm_mday = dias[i];
        fecha.tm_hour = horas[i];
        sistema->setFechaSistema(&fecha);
        sistema->ingresarVideojuego(juegos[i].data());
        sistema->nuevaSuscripcion(tipoPagos[i], tipoSus[i]);

    }
    finDeFuncion();
}

void cargarPuntajes(Fabrica f){
    IControlador* sistema = f.getInterface();
    string emailJdrs[PUNTAJES] = {"gamer@mail.com","gamer@mail.com","ari@mail.com","ari@mail.com"};
    string juegos[PUNTAJES] = { "KingdomRush", "Fortnite", "Fortnite", "Minecraft"};
    int puntajes[PUNTAJES] = {4, 5, 5, 3};
    for(int i = 0; i < PUNTAJES; i++){
        sistema->ingresoData(emailJdrs[i], "123", false);
        sistema->confirmarSesion();
        sistema->asignarPuntaje(juegos[i].data(), puntajes[i]);
    }
    finDeFuncion();
}

void cargarIndividuales(Fabrica f){
    IControlador* sistema = f.getInterface();
    int id;
    tm fecha;
    fecha.tm_year = 2019;
    fecha.tm_mon = 8; 
    fecha.tm_mday = 5;
    fecha.tm_hour = 13;
    sistema->setFechaSistema(&fecha);
    dtPartidaIndividual* datosPI;
    string emailJdrs[INDIVIDUALES] = {"gamer@mail.com","gamer@mail.com","ari@mail.com"};
    string juegos[INDIVIDUALES] = { "KingdomRush", "KingdomRush", "Minecraft"};
    bool continuacion[INDIVIDUALES] = {false, true, false}; 
    int anios[INDIVIDUALES] = {2021, 2021 , 2021};
    int meses[INDIVIDUALES] = {5,5,5};
    int dias[INDIVIDUALES] = { 2, 3, 12};
    int horasIn[INDIVIDUALES] = {9, 15, 16}; //horas de inicio
    int horasFin[INDIVIDUALES-1] = {10, 16};
    for(int i = 0; i<INDIVIDUALES; i++){
        cout << i <<endl;
        sistema->ingresoData(emailJdrs[i], "123", false);
        sistema->confirmarSesion();
        fecha.tm_year = anios[i];
        fecha.tm_year -= 1900;
        fecha.tm_mon = 05; 
        fecha.tm_mday = dias[i];
        fecha.tm_hour = horasIn[i];
        sistema->setFechaSistema(&fecha);
        datosPI = new dtPartidaIndividual(0, juegos[i], continuacion[i], 1, 0,NULL);
        id = sistema->confirmarIndividual(datosPI);
        if(i < INDIVIDUALES-1){
            cout << "Fin" <<endl;
            fecha.tm_year = 2021;
            fecha.tm_year -= 1900;
            fecha.tm_mon = 05; 
            fecha.tm_mday = dias[i];
            fecha.tm_hour = horasFin[i];
            sistema->setFechaSistema(&fecha);
            sistema->seleccionarPartida(id);
        }
    }
    finDeFuncion();
}

void cargarMultijugador(Fabrica f){
    IControlador* sistema = f.getInterface();
    dtPartidaMultijugador* datosPM;
    int id;
    tm fecha;
    fecha.tm_year = 2019;
    fecha.tm_mon = 8; 
    fecha.tm_mday = 5;
    fecha.tm_hour = 13;
    sistema->setFechaSistema(&fecha);

    string emailJdrs[MULTIJUGADOR] = {"gamer@mail.com","gamer@mail.com","ari@mail.com"};
    string juegos[MULTIJUGADOR] = { "Fortnite", "Fortnite", "Minecraft"};
    string** unidosAB = new string*[3]; 
    string** unidosC = new string*[2];
    unidosAB[0] = new string("ari");
    unidosAB[1] = new string("ibai");
    unidosAB[2] = NULL;
    unidosC[0] = new string("ibai");
    unidosC[1] = NULL;
    bool enVivo[MULTIJUGADOR] = {true, true, false};
    int dias[MULTIJUGADOR] = { 05, 06, 12};
    int horasIn[MULTIJUGADOR] = {5, 5, 8}; //horas de inicio
    for(int i = 0; i<MULTIJUGADOR; i++){
        sistema->ingresoData(emailJdrs[i], "123", false);
        sistema->confirmarSesion();
        fecha.tm_year = 2021;
        fecha.tm_year -= 1900;
        fecha.tm_mon = 05; 
        fecha.tm_mday = dias[i];
        fecha.tm_hour = horasIn[i];
        sistema->setFechaSistema(&fecha);
        if(i < MULTIJUGADOR-1)
            datosPM = new dtPartidaMultijugador(0, 0, juegos[i], enVivo[i], "", unidosAB);
        else 
            datosPM = new dtPartidaMultijugador(0, 0, juegos[i], enVivo[i], "", unidosC);  

        id  = sistema->confirmarMultijugador(datosPM);
        if(i < MULTIJUGADOR-1){
            fecha.tm_year = 2021;
            fecha.tm_year -= 1900;
            fecha.tm_mon = 05; 
            fecha.tm_mday = dias[i];
            fecha.tm_hour = 7;
            sistema->setFechaSistema(&fecha);
            sistema->seleccionarPartida(id);
        }
    }
    finDeFuncion();
}

void finDeFuncion(){
    cout  << "Cargaste datos correctamente." << endl;
    cout << "Presione ENTER para continuar..." << endl;
    getchar();
    getchar();
    system("clear");
}