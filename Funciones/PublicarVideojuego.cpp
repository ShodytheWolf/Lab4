#include <iostream>
#include <stdio.h>
#include "../IControlador/IControlador.h"
#include "../Fabrica/Fabrica.h"


using namespace std;

void publicarVideojuego(){

Fabrica fab;
IControlador* controlador = fab.getInterface();

dtCategoria** generos;
dtCategoria** plataformas;
dtCategoria** otros;



int opcion = 0;
char confirmar;
do{
    cout << "|=======================|" << endl;
    cout << " Publicar un videojuego." << endl;
    cout << "|=======================|" << endl;

    cout << "1- Listar plataforma." << endl;
    cout << "2- Listar género." << endl;
    cout << "3- Listar otro." << endl;
    cout << "4- Publicar videojuego." << endl;
    cout << "5- Menu principal." << endl;
    cin >> opcion;
    system("clear");

    try{
        switch(opcion){

            case 1:
                cout << "Entraste a listar y seleccionar genero" << endl;
                cout << "Ingrese el genero a seleccionar: " << endl;

                dtCategoria** generos = controlador->listarGenero(); //violacion de segmento (core)
                //
                //listarGenero();
                //mostrar
                //seleccion
                break;

            case 2:
                cout << "Entraste a listar y seleccionar plataforma" << endl;
                dtCategoria** plataformas = controlador->listarPlataforma();
                //listarplataforma();
                //mostrar
                //seleccion
                break;

            case 3:
                //listar
                //mostrar
                //selecc
                cout << "Entraste a listar Otros" << endl;
                dtCategoria** otros = controlador->listarOtro();

                cout << "¿Desea seleccionar otros?" << endl;
                cout << "Presione (s/S) para confirmar o cualquier tecla para cancelar" << endl;
                cin >> confirmar;
                if (confirmar == 's' || confirmar == 'S'){
                cout << "seleccionaste otros" << endl;
                } 
                else {
                    //menuDesarrollador();
                }
                break;

            case 4:
                cout << "Confirme si desea publicar un videojuego:" << endl;
                cout << "Presione (s/S) para confirmar o cualquier tecla para cancelar" << endl;
                cin >> confirmar;
                if (confirmar == 's' || confirmar == 'S'){
                cout << "Publicaste un videojuego" << endl;
                //controlador->publicarVideojuego(); como hacer la seleccion para pasar datos
                } 
                else {
                    cout << "cancelaste" << endl;
                }
                break;

            case 5:
                cout << "Entraste a menuprincipal" << endl;
                //menuPrincipal;
            break;

            default: 
            cout << "Opción incorrecta. Presione ENTER tecla para continuar nuevamente." << endl;
            getchar();
            getchar();
            system("clear");
            break;
        }
    }

    catch(invalid_argument& error){
    cout << error.what();
    }

} while(opcion >= 1 || opcion <= 5);
}