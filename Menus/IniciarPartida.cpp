#include "Menus.h"

 void menuIniciarPartida(){
     int optInicarPartida;
     do{
 		cout<<"Bienvenido a Iniciar Partida!"<<endl;
 	    cout<<"Seleccione una opcion a continuacion:"<<endl;
 	    cout<<"-------------------------------------"<<endl<<endl;
 	    cout<<"1)Listar Videojuegos Suscriptos"<<endl;
 	    cout<<"2)Salir"<<endl;
 		cin>>optInicarPartida;

 		switch (optInicarPartida)
 		{
 		case 1:
 			int juegoAIniciar;
 			int multiOIndividual;
 			//juegosSuscriptos = listarVideojuegosSuscripto(); devuelve los juegos que el jugador está suscripto en una lista de strings.
 			//entiendo que acá iteramos juegosSuscriptos para mostrarlos todos, basandonos en un orden númerico para luego saber cual es
 			cout<<"Seleccione la ID del juego que desea iniciar su partida"<<endl;
 			cin>>juegoAIniciar;
 			//iteramos para conseguir el string del juego específico a inicializar partida, nombreJuego
 			cout<<"Epicardo, sera una multijugador o individual my brudda?"<<endl;
 			cout<<"1)Individual"<<endl;
 			cout<<"2)Multijogador"<<endl;
 			cin>>multiOIndividual;

 			switch (multiOIndividual)
 			{
 			case 1://Individual
 				bool esContinuacion;
 				cout<<"Epicardo, sera una continuacion de una anterior?"<<endl;
 				cout<<"0)NO Continuacion"<<endl;
 				cout<<"1)Continuacion"<<endl;
 				cin>>esContinuacion;

 				if(esContinuacion){// habra que controlar que haya al menos una partida para cada caso????
 					int IdPartidaAContinuar;
 					//partidasSeleccionadas = listoPartidasInactivas(); siendo partidasSeleccionadas una lista en orden cronologico de dtPartidaIndividual de las partidas inactivas del usuario.
 					cout<<"Seleccione porfa el ID de la partida a continuar"<<endl;
 					cin>>IdPartidaAContinuar;
 					//formamos dtPartidaIndividual datosPartida con la info que ya hemos conseguido.
 				}else{
 					//aca entiendo formaremos un dtPartidaIndividual datosPartida con toda la info que hemos recolectado hasta ahora.
 				}
 				//confirmarIndividual(datosPartida);
 				cout<<"Partida Iniciada con exito!"<<endl;
 				return;
 				break;
			
 			case 2://Multijugador
 				bool esVivo;
 				cout<<"Epicardo, sera una partida transmitida en vivo?"<<endl;
 				cout<<"0)NO en vivo"<<endl;
 				cout<<"1)en vivo"<<endl;
 				cin>>esVivo;

 				//jugadoresUnidosString listarNicks(nombreJuego); mostramos todos los nicks de los jugadores que tienen una sus activa para el juego que le pasamos por parametro (el que se consigió iterando hace un rato)
 				//formamos dtPartidaMultijugador datosPartidaMulti con la info gathereada.
 				//confirmarMultijugador(datosPartidaMulti);
 				cout<<"Partida Iniciada con exito!"<<endl;
 				break;
 			default:
 				cout<<"opciOwOn invalida"<<endl;
 			}
 		break;
		
 		case 2:
 			return;
 		break;
		
 		default:
 		cout<<"opciOwOn invalida"<<endl;
 			break;
 		}
     }while(optInicarPartida != 2);

 }
