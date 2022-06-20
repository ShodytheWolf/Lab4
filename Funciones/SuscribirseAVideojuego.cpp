#include <iostream>
#include <stdio.h>
#include "../IControlador/IControlador.h"
#include "../Fabrica/Fabrica.h"

using namespace std;

void suscribirseAVideojuego(){  //caso de uso 5

Fabrica fab;
IControlador* controlador = fab.getInterface();

int opcion = 0;

//enumPago metodoDePago; 
//enumSuscripcion tipoSuscripcion;
//string nombreVideojuego;
bool estaSuscrito = false;
char confirmar;
string tipoSus;
do{
    cout << "|===========================|" << endl;
    cout << " Suscribirse a un videojuego." << endl;
    cout << "|===========================|" << endl;

    cout << "1- Listar Videojuegos suscriptos y no suscriptos." << endl;
    cout << "2- Ingrese nombre del videojuego." << endl;
    cout << "3- NuevaSuscripcion." << endl;
    cout << "4- Salir." << endl;
    cin >> opcion;
    system("clear");

    try{
        switch(opcion){
            case 1:
                cout << "entraste a listarVideojuegosDieferenciada" << endl;
                //listarVideojuegosDiferenciada();
                break;

            case 2:
                cout << "ingresarVideojuego" << endl;
                //ingresarVideojuego(nombreVideojuego);
                break;

            case 3:
                cout << "entraste a suscribirte  a un videojuego" << endl;
                if (estaSuscrito == false){ //si no tiene una suscripcion 
                    cout << "¿Desea confirmar?" << endl;
                    cout << "Presione (s/S) para confirmar o cualquier tecla para cancelar" << endl;
                    cin >> confirmar;
                    if (confirmar == 's' || confirmar == 'S'){
                    cout << "te suscribiste exitosamente" << endl;
                    //nuevaSuscripcion();
                    //return;
                    }
                    else { //cancelar
                        cout << "decidiste canclelar volviendo al menu...." << endl;
                        return;
                        //menuJugador();
                    } 
                }
                else { //tiene una suscripcion temporal 
                    if(estaSuscrito == true && tipoSus != "vitalicia"){
                        cout << "¿Desea dar de baja la suscripcion activa y crear una nueva?" << endl;
                        cout << "Presione (s/S) para confirmar o cualquier tecla para cancelar" << endl;
                        cin >> confirmar;
                        if (confirmar == 's' || confirmar == 'S'){
                            cout << "diste de baja una suscripcion" << endl;
                            //dardeBaja();
                            cout << "Ingrese datos de la nueva suscripcion." << endl;                          
                            //nuevaSuscripcion();
                        }
                        else{
                            cout << "decidiste no dar de baja la suscripcion" << endl;
                            return;
                        }
                    }
                }
                break;

            case 4:
                cout << "decidiste salir" << endl;
                return;
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

}while(opcion >= 1 || opcion <= 4);
}