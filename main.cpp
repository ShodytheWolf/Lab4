#include <stdlib.h>
#include <iostream>
#include "IControlador/IControlador.h"
#include "Fabrica/Fabrica.h"
#include "Menus/Menus.h"


using namespace std;

void menuDesarrollador();
void menuJugador();

int main(){
    Fabrica* fabrica = new Fabrica();
    IControlador* sistema = fabrica->getInterface();
    //menuDesarrollador();
    menuJugador();

    return 0;
}

// void menuDesarrollador(){
//     int opcion;
//     cout << "Bienvenido al menu de Jugador\n" 
//     "Por favor ingrese una opcion:\n" << endl;
//     do{
//         cout << 
//         "1. Agregar categoría\n"
//         "2. Publicar videojuego\n"
//         "3. Eliminar videojuego\n"
//         "4. Seleccionar estadísticas\n"
//         "5. Consultar estadísticas\n"
//         "6. Ver información de videojuego\n"
//         "7. Modificar fecha del sistema\n"
//         "8. Salir"
//         <<endl;
//         cin >> opcion;
//         if( opcion < 1 || opcion>8 )
//             cout << "Opcion incorrecta\n";
//     }while(opcion < 1 || opcion > 8);
// }

void menuJugador(){

    int opcion = 0;

    cout << "=============" << endl;
    cout << "Menú jugador." << endl;
    cout << "=============" << endl;
    
    cout << "1- Suscribirse a un videojuego." << endl;
    cout << "2- Asignar puntaje a videojuego." << endl;
    cout << "3- Iniciar partida." << endl;
    cout << "4- Abandonar partida multijugador." << endl;
    cout << "5- Finalizar partida." << endl;
    cout << "6- Ver información de videojuego." << endl;
    cout << "7- Modificar fecha del sistema." << endl;
    cout << "8- Salir." << endl;
    cin >> opcion;
    system("clear");
        
   if (opcion >= 1 || opcion<= 8){
        try{
            switch(opcion){
                case 1:
                    cout << "Entraste a suscribirse a videojuego" << endl;
                    //menuSuscribirse();
                    suscribirseAVideojuego();
					break;
                case 2:
                    cout << "Entraste a asignar puntaje a videojogo" << endl;
                    //asignarpuntajeAvideojuego();
                    asignarPuntajeAVideojuego();
					break;
                case 3:
                    cout << "Entraste a iniciar partida" << endl;
                    //iniciarPartida();
					break;
                case 4:
                    cout << "Entraste a abandonar partida moltijogador" << endl;
                    //AbandonarPartidaMultijugador();
					break;
                case 5:
                    cout << "Entraste a finalizar partida" << endl;
                    //FinalizarPartida();
					break;
                case 6:
                    cout << "Entraste a ver informacion de videojogo" << endl;
                    //verInformaciondeVideojuego();
					break;
                case 7:
                    cout << "Entraste a modificar fecha sistema" << endl;
                    //ModificarFechadelSistema();
					break;
                case 8:
                    cout << "entraste a menu principal" << endl;
                    //menuprincipal();
                default: 
                cout << "Opción incorrecta pibe." << endl;
				break;
            }
        }
        catch(invalid_argument& error){
        cout << error.what();
        }
   }
}


// void menuPrincipal(){
//     int opt;
// 	do{
//         cout<<"Bienvenido a Steam barato!"<<endl;
// 	    cout<<"Seleccione una opcion a continuacion:"<<endl;
// 	    cout<<"-------------------------------------"<<endl<<endl;
// 	    cout<<"1)Alta de Usuario"<<endl;
// 	    cout<<"2)Iniciar Sesion"<<endl;
// 	    cout<<"3)Cargar datos de prueba"<<endl;
// 	    cout<<"4)Salir"<<endl;
// 		cin>>opt;

// 	switch(opt){
//             case 1:
// 				//acá se llama a AltaUsuario
// 			break;

// 			case 2:
// 				//acá se inicia sesion
// 				//se mostrará 2 menus, el de desarrollador o el de jogador, dependiendo quién inicié sesión jaja xd
// 			break;

// 			case 3:
// 				//se cargaran datos de prueba
// 			break;

// 			case 4:
// 				return;
// 			break;

// 			default:
// 			cout<<"opcion invalida"<<endl;
// 		}
// 	}while(opt != 4);
// }

