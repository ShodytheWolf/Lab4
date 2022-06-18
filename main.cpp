#include <stdlib.h>
#include <iostream>
#include "IControlador/IControlador.h"
#include "Fabrica/Fabrica.h"
#include "Controlador/Controlador.h"

using namespace std;

Controlador *u = Controlador::getInstance();

void AltaUsuario() {
    cout << "Alta Usuarios" << endl;
    cout << "==============" << endl;
    string email, contrasenia, nombreEmpresa;
    char option;
    cout << "Dar de alta como desarrollador o jugador? (d=desarrollador o j=jugador)"<< endl;
    cin>>option;

    if(option == 'd' or option == 'D'){
    cout << "Ingrese email" << endl;
    cin>>email;
    cout << "Ingrese contrasenia" << endl;
    cin>>contrasenia;
    cout << "Ingrese nombre empresa" << endl;
    cin>>nombreEmpresa;
    u->confirmarNuevoDesarrollador(email, contrasenia, nombreEmpresa);
    } else { //por implementar aun
        if(option == 'j' or option == 'J'){
       	cout << "Ingrese nickname" << endl;
        cin>>nombreEmpresa;
	cout << "Ingrese descripcion" << endl;
        cin>>descripcion;
        u->confirmarNuevoJugador();
        }
    }
}

void menuDesarrollador();
// void menuJugador();
// void menuPublicarVideojuego();
// void menuSuscribirse();
// void menuAsignarPuntaje();

int main(){
    Fabrica* fabrica = new Fabrica();
    IControlador* sistema = fabrica->getInterface();
    menuDesarrollador();
    return 0;
}

void menuDesarrollador(){
    int opcion;
    cout << "Bienvenido al menu de Jugador\n" 
    "Por favor ingrese una opcion:\n" << endl;
    do{
        cout << 
        "1. Agregar categoría\n"
        "2. Publicar videojuego\n"
        "3. Eliminar videojuego\n"
        "4. Seleccionar estadísticas\n"
        "5. Consultar estadísticas\n"
        "6. Ver información de videojuego\n"
        "7. Modificar fecha del sistema\n"
        "8. Salir"
        <<endl;
        cin >> opcion;
        if( opcion < 1 || opcion>8 )
            cout << "Opcion incorrecta\n";
    }while(opcion < 1 || opcion > 8);
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
//     cout << "Presione ENTER para continuar..." << endl;
//     getchar();
//     getchar();
//     system("clear");
        
//    while (opcion <= 1 || opcion>= 8){
//         try{
        
//             switch(opcion){

//                 case 1:
//                     //suscribirseAvideojuego();
// 					break;
//                 case 2:
//                     //asignarpuntajeAvideojuego();
// 					break;
//                 case 3:
//                     //iniciarPartida();
// 					break;
//                 case 4:
//                     //AbandonarPartidaMultijugador();
// 					break;
//                 case 5:
//                     //FinalizarPartida();
// 					break;
//                 case 6:
//                     //verInformaciondeVideojuego();
// 					break;
//                 case 7:
//                     //ModificarFechadelSistema();
// 					break;
//                 case 8:
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

// void menuPublicarVideojuego(){
// 	int opcion = 0;

// 	//dtVideojuego datosjuegos;
// 	//set<dtcategoria> categorias;
//     //char confirmacion;

//     cout << "|======================|" << endl;
//     cout << " Publicar un videojuego." << endl;
//     cout << "|======================|" << endl;
    
//     cout << "1- Listar generos." << endl;
//     cout << "2- Listar plataformas." << endl;
//     cout << "3- Listar Otros." << endl;
//     cout << "4- PublicarVideojuego." << endl;
//     cout << "5- Salir." << endl;
//     cin >> opcion;
//     cout << "Presione ENTER para continuar..." << endl;
//     getchar();
//     getchar();
//     system("clear");

	      
//    while (opcion <= 1 || opcion>= 5){
//         try{
//             switch(opcion){
//                 case 1:
//                     //listarGenero()<dtCategoria>;
// 					//seleccion
// 					break;
//                 case 2:
//                     //listarPlataforma()<dtCategoria>
// 					//seleccion
// 					break;
//                 case 3:
//                     //listarOtro()<dtCategoria>
// 					//cout << "¿Desea seleccionar otra categoría?" << endl;
//                     //cout << "Presione (s/S) para confirmar, o cualquier tecla para cancelar" << endl;
//                     //if (confirmacion == 's' || confirmacion == 'S'){
//                     //selecciono juego.
//                     //}
// 					break;
//                 case 4:
// 					//se insertan datos del jueguito
//                     //publicarVideojuego(dtVideojuego datosjuego, set<categorias> categorias);
//                     //cout << "¿Desea confirmar la publicación del videojuego?" << endl;
//                     //cout << "Presione (s/S) para confirmar, o cualquier tecla para cancelar" << endl;
//                     //if (confirmacion == 's' || confirmacion == 'S'){
//                     //videoJuego * jogo = new videoJuego(dtVideojuego, categorias);
//                     //}
// 					//else {
//                     //cout << "Ha cancelado la publicacion volviendo al menu de desarrollador" << endl;
//                     //menuDesarrollador(); 
//                     //}
// 					break;
//                 case 5:
//                     //menuDesarrollador();
// 				break;
//                 default: 
//                 cout << "Opción incorrecta guanaco." << endl;
// 				break;
//             }
//         }
//         catch(invalid_argument& error){
//         cout << error.what();
//         }
    
//    }

// }

// void menuSuscribirse(){
// 	int opcion = 0;

// 	enumPago metodoDePago; 
//     enumSuscripcion tipoSuscripcion;


//     cout << "|===========================|" << endl;
//     cout << " Suscribirse a un videojuego." << endl;
//     cout << "|===========================|" << endl;
    
//     cout << "1- ListarVideojuegos." << endl;
//     cout << "2- IngresarVideojuego." << endl;
//     cout << "3- NuevaSuscripcion." << endl;
//     cout << "4- Dar de Baja." << endl;
//     cout << "5- Salir." << endl;
//     cin >> opcion;
//     cout << "Presione ENTER para continuar..." << endl;
//     getchar();
//     getchar();
//     system("clear");

	      
//    while (opcion <= 1 || opcion>= 5){
//         try{
//             switch(opcion){
//                 case 1:
//                     //listarVideojuegosActivos();
//                     //listarVideojuegosInActivos();
// 					break;
//                 case 2:
// 					//char* nombreVideojuego;
//                     //cout << "Ingrese nombre del videojuego: ";
//                     //cin >> nombreVideojuego;
//                     //ingresoVideojuego(nombreVideojuego)
// 					break;
//                 case 3:
//                     //cout << "Ingrese tipo de suscripcion: (1-Mensual, 2-Trimestral, 3- Anual, 4- Vitalicia) ";
//                     //cin >> opcionSus;
//                     //cout << "Ingrese metodoDePago (1-Paypal o 2-Tarjeta): ";
//                     //cin >> opcionPago;
//                     //nuevaSuscripcion(metodoDePago,tipoSuscripcion);
//                     //suscripcion * sus = new suscripcion(metodoDePago, tipoSuscripcion);
// 					break;
//                 case 4:
// 					//darDebaja();
// 					break;
//                 case 5:
//                     //menuJugador();
// 				break;
//                 default: 
//                 cout << "Opción incorrecta platita" << endl;
// 				break;
//             }
//         }
//         catch(invalid_argument& error){
//         cout << error.what();
//         }
    
//    }

// }

// void menuAsignarPuntaje(){
// 	int opcion = 0;

//     cout << "|===============================|" << endl;
//     cout << " Asignar puntaje a un videjuego." << endl;
//     cout << "|===============================|" << endl;
    
//     cout << "1- ListarVideojuegos." << endl;
//     cout << "2- Asignar puntaje." << endl;
//     cout << "3- Salir." << endl;
//     cin >> opcion;
//     cout << "Presione ENTER para continuar..." << endl;
//     getchar();
//     getchar();
//     system("clear");

	      
//    while (opcion <= 1 || opcion>= 3){
//         try{
//             switch(opcion){
//                 case 1:
//                     //listarVideojuegos();
// 					break;
//                 case 2:
// 					//char* nombreVideojuego;
// 					//int puntuacion;
//                     //cout << "Ingrese nombre del videojuego: " << endl;
//                     //cin >> nombreVideojuego;
//                     //cout << "Ingrese puntuación del videojuego: " << endl;
//                     //cin >> puntuacion;
// 					//asignarPuntaje(nombreVideojuego, puntuacion);
// 					break;
//                 case 3:
//                     //menuJugador();
// 				break;
//                 default: 
//                 cout << "Opción incorrecta  mastercard." << endl;
// 				break;
//             }
//         }
//         catch(invalid_argument& error){
//         cout << error.what();
//         }
    
//    }

// }

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

// void menuIniciarPartida(){
//     int optInicarPartida;
//     do{
// 		cout<<"Bienvenido a Iniciar Partida!"<<endl;
// 	    cout<<"Seleccione una opcion a continuacion:"<<endl;
// 	    cout<<"-------------------------------------"<<endl<<endl;
// 	    cout<<"1)Listar Videojuegos Suscriptos"<<endl;
// 	    cout<<"2)Salir"<<endl;
// 		cin>>optInicarPartida;

// 		switch (optInicarPartida)
// 		{
// 		case 1:
// 			int juegoAIniciar;
// 			int multiOIndividual;
// 			//juegosSuscriptos = listarVideojuegosSuscripto(); devuelve los juegos que el jugador está suscripto en una lista de strings.
// 			//entiendo que acá iteramos juegosSuscriptos para mostrarlos todos, basandonos en un orden númerico para luego saber cual es
// 			cout<<"Seleccione la ID del juego que desea iniciar su partida"<<endl;
// 			cin>>juegoAIniciar;
// 			//iteramos para conseguir el string del juego específico a inicializar partida, nombreJuego
// 			cout<<"Epicardo, sera una multijugador o individual my brudda?"<<endl;
// 			cout<<"1)Individual"<<endl;
// 			cout<<"2)Multijogador"<<endl;
// 			cin>>multiOIndividual;

// 			switch (multiOIndividual)
// 			{
// 			case 1://Individual
// 				bool esContinuacion;
// 				cout<<"Epicardo, sera una continuacion de una anterior?"<<endl;
// 				cout<<"0)NO Continuacion"<<endl;
// 				cout<<"1)Continuacion"<<endl;
// 				cin>>esContinuacion;

// 				if(esContinuacion){ //habra que controlar que haya al menos una partida para cada caso????
// 					int IdPartidaAContinuar;
// 					//partidasSeleccionadas = listoPartidasInactivas(); siendo partidasSeleccionadas una lista en orden cronologico de dtPartidaIndividual de las partidas inactivas del usuario.
// 					cout<<"Seleccione porfa el ID de la partida a continuar"<<endl;
// 					cin>>IdPartidaAContinuar;
// 					//formamos dtPartidaIndividual datosPartida con la info que ya hemos conseguido.
// 				}else{
// 					//aca entiendo formaremos un dtPartidaIndividual datosPartida con toda la info que hemos recolectado hasta ahora.
// 				}
// 				//confirmarIndividual(datosPartida);
// 				cout<<"Partida Iniciada con exito!"<<endl;
// 				return;
// 				break;
			
// 			case 2://Multijugador
// 				bool esVivo;
// 				cout<<"Epicardo, sera una partida transmitida en vivo?"<<endl;
// 				cout<<"0)NO en vivo"<<endl;
// 				cout<<"1)en vivo"<<endl;
// 				cin>>esVivo;

// 				//jugadoresUnidosString listarNicks(nombreJuego); mostramos todos los nicks de los jugadores que tienen una sus activa para el juego que le pasamos por parametro (el que se consigió iterando hace un rato)
// 				//formamos dtPartidaMultijugador datosPartidaMulti con la info gathereada.
// 				//confirmarMultijugador(datosPartidaMulti);
// 				cout<<"Partida Iniciada con exito!"<<endl;
// 				break;
// 			default:
// 				cout<<"opciOwOn invalida"<<endl;
// 			}
// 		break;
		
// 		case 2:
// 			return;
// 		break;
		
// 		default:
// 		cout<<"opciOwOn invalida"<<endl;
// 			break;
// 		}
//     }while(optInicarPartida != 2);

// }

// void menuAbandonarPartidaMultijugador(){
//     int optAbandonarPartida;
//     do{
//         cout<<"Bienvenido a Abandonar Partida Multijogador!"<<endl;
// 	    cout<<"Seleccione una opcion a continuacion:"<<endl;
// 	    cout<<"-------------------------------------"<<endl<<endl;
// 	    cout<<"1)Listar Videojuegos Suscriptos"<<endl;
// 	    cout<<"2)Salir"<<endl;
// 		cin>>optAbandonarPartida;

//         switch (optAbandonarPartida)
//         {
//         case 1:
//             int idPartidaMulti;
//             //SET<dtPartidaMultijugador> = listoPartidaMultijugador(); conseguimos todas las partidas multis que el jugador se ha unido, pero no finalizado.
//             //entiendo que luego iteramos para mostrar esas partidas, incluyiendo el id, fecha y hora de comienzo, nombre del videojogo y es en vivo.
//             cout<<"Ingrese el ID de la partida que desea abandonar"<<endl;
//             cin>>idPartidaMulti;
//             //confirmoAbandono(idPartidaMulti); listo el pollo!
//             cout<<"Se abandono la partida con exito"<<endl;
//         break;
        
//         case 2:
//             return;
//         break;


//         default:
//             cout<<"opciOwOn invalida"<<endl;
//         break;
//         }

//     }while(optAbandonarPartida != 2);
// }
