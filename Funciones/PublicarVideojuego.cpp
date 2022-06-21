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
int costoAnual;
int costoMensual;
int costoTrimestral;
int costoVitalicia;


int opcion = 0;
char confirmar;
do{
    cout << "|=======================|" << endl;
    cout << " Publicar un videojuego." << endl;
    cout << "|=======================|" << endl;

    cout << "Costos por tipo de suscripción. \n" << endl;
    cout << "Costo de suscripción anual: " << endl;
    cin >> costoAnual;
    cout << "Ingrese costo de suscripción trimestral: " << endl;
    cin >> costoTrimestral;
    cout << "Ingrese costo de suscripción mensual" << endl;

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
                cout << "Lista de generos: " << endl;

                dtCategoria** generos = controlador->listarGenero();
                int i = 0;
                // while (generos[i]){

                //     cout << "-" << *generos[i] <<endl;
                //     i++; 

                // while(!verificarEnLista(generos, string(genero))){
                //     cout << "El juego no existe. Por favor intentelo de nuevo" <<endl;

                // }
                //}
                cout << "Ingrese el genero a seleccionar: " << endl;
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