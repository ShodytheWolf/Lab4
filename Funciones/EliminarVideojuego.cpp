#include <iostream>
#include <stdlib.h>
#include "../IControlador/IControlador.h"
#include "../Fabrica/Fabrica.h"

using namespace std;

void eliminarVideojuego(){
    Fabrica f;
    IControlador* sistema = f.getInterface();
    char* juego;
    char op;
    bool verificacion;
    string** listVJ = sistema->listarVideojuegosPublicados();
    cout << "Por favor elija un videojuego ingresando su nombre: " <<endl;
    int i = 0;
    while(listVJ[i]){
        cout <<"-"<< *listVJ[i] <<endl;
        i++; 
    }
    cin >> juego;
    cout << "Se eliminar el Videojuego: " << juego <<"\nDesea confirmar? S/N\n" <<endl;
    do{
        cin >> op;
        switch (op)
        {
        case 's':
        case 'S':
            sistema->confirmoEliminacion(juego);
            verificacion = true;
            break;

        case 'n':
        case 'N':
            cout << "Cancelando eliminacion..." <<endl;
            delete juego;
            delete listVJ;
            return;

        default:
            cout << "Opcion incorrecta. Intente nuevamente" <<endl;
            verificacion = false; 
            break;
        }
    }while(!verificacion);

}