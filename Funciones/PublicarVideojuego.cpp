#include <iostream>
#include <stdio.h>
#include "../IControlador/IControlador.h"
#include "../Fabrica/Fabrica.h"


using namespace std;

bool verificarEnLista(string** , string);

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
                cout << "Entraste a listar y seleccionar genero" << endl;
                cout << "Ingrese el genero a seleccionar: " << endl;

                dtCategoria** listGeneros = controlador->listarGenero(); //violacion de segmento (core)
                //
                //listarGenero();
                //mostrar
                //seleccion

                cout << "Entraste a listar y seleccionar plataforma" << endl;
                dtCategoria** listPlataformas = controlador->listarPlataforma();
                //listarplataforma();
                //mostrar
                //seleccion

                //listar
                //mostrar
                //selecc
                cout << "Entraste a listar Otros" << endl;
                dtCategoria** listOtros = controlador->listarOtro();

                cout << "¿Desea seleccionar otros?" << endl;
                cout << "Presione (s/S) para confirmar o cualquier tecla para cancelar" << endl;
                cin >> confirmar;
                if (confirmar == 's' || confirmar == 'S'){
                cout << "seleccionaste otros" << endl;
                } 
                else {
                    //menuDesarrollador();
                }

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

                cout << "Entraste a menuprincipal" << endl;
                //menuPrincipal;

            cout << "Opción incorrecta. Presione ENTER tecla para continuar nuevamente." << endl;
            getchar();
            getchar();
            system("clear");
        }

        catch(invalid_argument& error){
        cout << error.what();
        }
    } while(opcion >= 1 || opcion <= 5);
}