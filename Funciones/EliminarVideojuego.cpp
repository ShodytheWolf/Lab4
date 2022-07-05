#include <iostream>
#include <stdlib.h>
#include "../IControlador/IControlador.h"
#include "../Fabrica/Fabrica.h"

using namespace std;

bool verificarEnLista(string**, string);

void eliminarVideojuego(){
    Fabrica f;
    IControlador* sistema = f.getInterface();
    string juego;
    char op;
    bool loop;
    try{
        string** listVJ = sistema->listarVideojuegosPublicados();
        cout << "Por favor elija un videojuego ingresando su nombre: " <<endl;
        int i = 0;
        while(listVJ[i]){
            cout <<"-"<< *listVJ[i] <<endl;
            i++; 
        }
        getline(cin.ignore(),juego,'\n');
        while(!verificarEnLista(listVJ, juego)){
            cout << "El juego no existe. Por favor intentelo de nuevo" <<endl;
            getline(cin,juego,'\n');
            cout << endl;
        }
        cout << "Se eliminara el Videojuego: " << juego <<"\nDesea confirmar? S/N\n" <<endl;
        do{
            cin >> op;
            switch (op)
            {
            case 's':
            case 'S':
                sistema->confirmoEliminacion(juego.data());
                cout << "Se elimino correctamente " << juego <<"\n\nPresione <enter> para continuar" << endl;
                getchar();
                getchar();
                loop = false;
                break;
            case 'n':
            case 'N':
                cout << "Cancelando eliminacion...\n\nPresione <enter> para continuar" <<endl;
                getchar();
                getchar();
                loop = false;
                break;

            default:
                cout << "Opcion incorrecta. Intente nuevamente" <<endl;
                loop = true; 
                break;
            }
        }while(loop);
    }catch(invalid_argument &e){
        cout << e.what() << " Presione <enter> para continuar"<<endl;
        getchar();
        getchar();
    }
    system("clear");
}