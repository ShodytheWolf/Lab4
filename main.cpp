#include <stdlib.h>
#include <iostream>
#include "IControlador/IControlador.h"
#include "Fabrica/Fabrica.h"
#include "Funciones/Menus.h"

using namespace std;

void menuDesarrollador();
//void menuJugador();
void esperarEnter();
void bp();

int main(){
    char tipoUsuario = ' ';
    char op = ' ';
    do{
        cout << "Bienvenido a la plataforma de videojuegos Estim\n" 
        << "Por favor ingrese una opcion numerica:\n"
        <<"1.Alta usuario\n"
        <<"2.Iniciar Sesion\n"
        <<"3.Cargar datos de pruebas (solo admins)\n" 
        <<"4.Salir"
        <<endl;
        cin >>op;
        switch (op)
        {
        case '1':
            altaUsuario();
            break;
        case '2':
            iniciarSesion(tipoUsuario);
            switch (tipoUsuario)
            {
            case 'j':
                cout << "Entraste al menu Jugador" <<endl; //menuJugador()
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
            cout << "Opcion icorrecta por favor intente de nuevo" <<endl;
            break;
        }
    }while(op != '4');
    return 0;
}

void esperarEnter(){
    cout << "Presione <enter> para continuar" <<endl;
    getchar();
}

void bp()
{
    cout <<"BP" <<endl;
    getchar();
}


void menuDesarrollador(){
    char op;
    cout << "Bienvenido al menu de Desarrollador\n" 
    "Por favor ingrese una opcion:\n" << endl;
    do{
        cout << 
        "1. Publicar videojuego\n"
        "2. Eliminar videojuego\n"
        "3. Ver información de videojuego\n"
        "4. Modificar fecha del sistema\n"
        "5. Salir"
        <<endl;
        cin >> op;
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
                system("clear");
                break;
            default:
                cout << "Opcion incorrecta. Por favor intente nuevamente" <<endl;
                break;
        }
    }while(op != '5');
}

// void menuJugador(){

//     int opcion = 0;

//     cout << "=============" << endl;
//     cout << "Menú jugador." << endl;
//     cout << "=============" << endl;
    
//     cout << "1- Suscribirse a un videojuego." << endl;
//     cout << "2- Asignar puntaje a videojuego." << endl;
//     cout << "3- Iniciar partida." << endl;
//     cout << "4- Abandonar partida multijugador." << endl;
//     cout << "5- Finalizar partida." << endl;
//     cout << "6- Ver información de videojuego." << endl;
//     cout << "7- Modificar fecha del sistema." << endl;
//     cout << "8- Salir." << endl;
//     cin >> opcion;
//     system("clear");
        
//    if (opcion >= 1 || opcion<= 8){
//         try{
//             switch(opcion){
//                 case 1:
//                     cout << "Entraste a suscribirse a videojuego" << endl;
//                     //menuSuscribirse();
//                     suscribirseAVideojuego();
// 					break;
//                 case 2:
//                     cout << "Entraste a asignar puntaje a videojogo" << endl;
//                     //asignarpuntajeAvideojuego();
//                     asignarPuntajeAVideojuego();
// 					break;
//                 case 3:
//                     cout << "Entraste a iniciar partida" << endl;
//                     //iniciarPartida();
// 					break;
//                 case 4:
//                     cout << "Entraste a abandonar partida moltijogador" << endl;
//                     //AbandonarPartidaMultijugador();
// 					break;
//                 case 5:
//                     cout << "Entraste a finalizar partida" << endl;
//                     //FinalizarPartida();
// 					break;
//                 case 6:
//                     cout << "Entraste a ver informacion de videojogo" << endl;
//                     //verInformaciondeVideojuego();
// 					break;
//                 case 7:
//                     cout << "Entraste a modificar fecha sistema" << endl;
//                     //ModificarFechadelSistema();
// 					break;
//                 case 8:
//                     cout << "entraste a menu principal" << endl;
//                     //menuprincipal();
//                 default: 
//                 cout << "Opción incorrecta pibe." << endl;
// 				break;
//             }
//         }
//         catch(invalid_argument& error){
//         cout << error.what();
//         }
//    }
// }


