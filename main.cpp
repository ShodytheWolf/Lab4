#include <stdlib.h>
#include <iostream>
#include "IControlador/IControlador.h"
#include "Fabrica/Fabrica.h"
#include "Funciones/Menus.h"

using namespace std;

void menuDesarrollador();
void menuJugador();
void esperarEnter();
void bp();

int main(){
    char tipoUsuario = ' ';
    char op = ' ';
    cout << "Bienvenido a la plataforma de videojuegos Estim" <<endl; 
    do{
        cout << "Por favor ingrese una op numerica:\n"
        <<"1.Alta usuario\n"
        <<"2.Iniciar Sesion\n"
        <<"3.Cargar datos de pruebas (solo admins)\n" 
        <<"4.Salir"
        <<endl;
        cin >>op;
        system("clear");
        switch (op)
        {
        case '1':
            altaUsuario();
            break;
        case '2':
            iniciarSesion(tipoUsuario);
            bp();
            switch (tipoUsuario)
            {
            case 'j':
                menuJugador();
                esperarEnter();
                break;
            case 'd':
                menuDesarrollador();
                esperarEnter();
                break;
            }
            break;
        case '3':
            cargarDatos();
            break;
        case '4':
            cout << "Hasta luego, vuelva pronto :)" <<endl;
            break;
        
        default:
            cout << "op icorrecta por favor intente de nuevo" <<endl;
            break;
        }
    }while(op != '4');
    return 0;
}


void menuDesarrollador(){
    char op = ' ';
    char exit = ' ';
    do{
        cout
        << "=============\n" 
        << "Menú Desarrolador.\n" 
        << "=============\n" 
        <<"1. Publicar videojuego\n"
        <<"2. Eliminar videojuego\n"
        <<"3. Ver información de videojuego\n"
        <<"4. Modificar fecha del sistema\n"
        <<"5. Salir\n"
        <<"Ingrese una opción numerica:\n"
        <<endl;
        cin >> op;
        system("clear");
        switch(op){
            case '1':
                publicarVideojuego();
                break;
            case '2':
                eliminarVideojuego();
                break;
            case '3':
                verInformacionVideojuego();
                break;
            case '4':
                cout << "Esta funcion se ha deshabilitado en esta version\nPresione <enter> para continuar"<<endl;
                getchar();
                break;
            case '5':
                cout << "Volvera al menu principal y debera iniciar sesion nuevamente. Seguro que desea hacerlo ? S/N" << endl;
                cin >> exit;
                system("clear");
                break;
            default:
                cout << "opcion incorrecta. Por favor intente nuevamente" <<endl;
                break;
        }
    }while(exit != 's' || exit != 'S');
}

void menuJugador(){

    char op = ' ';
    char exit = ' ';
    cout << "=============" << endl;
    cout << "Menú jugador." << endl;
    cout << "=============" << endl;
    cout << "1- Suscribirse a un videojuego." << endl;
    cout << "2- Iniciar partida." << endl;
    cout << "3- Finalizar partida." << endl;
    cout << "4- Ver información de videojuego." << endl;
    cout << "5- Modificar fecha del sistema." << endl;
    cout << "6- Salir." << endl;
    cin >> op;
    system("clear");
    do{
        switch(op){
            case '1':
                suscribirseAVideojuego();
                break;
            case '2':
                iniciarPartida();
                break;
            case '3':
                finalizarPartida();
                break;
            case '4':
                verInformacionVideojuego();
                break;
            case '5':
                cout << "Esta funcion se ha deshabilitado en esta version\nPresione <enter> para continuar"<<endl;
                break;
            case '6':
                cout << "Volvera al menu principal y debera iniciar seion nuevamente.\nSeguro que desea continuar? S/N" << endl;
                cin >> exit;
                system("clear");
                break;
            default: 
            cout << "Opción incorrecta. Intente de nuevo" << endl;
            break;
        }
    }while( exit != 's' || exit != 'S');
}

void esperarEnter(){
    cout << "Presione <enter> para continuar" <<endl;
    getchar();
    getchar();
    system("clear");
}

//Operacion para meter breakpoints cuando sea necesario (no quedara en la version final del programa)
void bp()
{
    cout <<"BP" <<endl;
    getchar();
}

