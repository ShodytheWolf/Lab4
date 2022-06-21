// #include "Menus.h"
// #include "../IControlador/IControlador.h"
// #include "../Fabrica/Fabrica.h"
// #include "VerificarEnLista.cpp"

// Fabrica* fabrica = new Fabrica();
// IControlador* sistema = fabrica->getInterface();

//  void menuIniciarPartida(){
//      int optInicarPartida;
//      do{
//  		cout<<"Bienvenido a Iniciar Partida!"<<endl;
//  	    cout<<"Seleccione una opcion a continuacion:"<<endl;
//  	    cout<<"-------------------------------------"<<endl<<endl;
//  	    cout<<"1)Listar Videojuegos Suscriptos"<<endl;
//  	    cout<<"2)Salir"<<endl;
//  		cin>>optInicarPartida;

//  		switch(optInicarPartida)
//  		{
//  		case 1:
//  			//string juegoAIniciar;
//  			int multiOIndividual;
//  			string** juegosSuscriptos = sistema->listarVideojuegosSuscripto();//entro, consigo la lista de juegos, e inicializo juegosSuscriptos.

// 			int i = 0;
// 			while (juegosSuscriptos[i] != NULL)
// 			{
// 				cout<<*juegosSuscriptos[i]<<endl;
// 			}

// 				/*
// 			do{
//  				cout<<"Seleccione el nombre del juego que desea iniciar partida"<<endl;
//  				cin>>juegoAIniciar;
// 				bool taBienEscrito = verificarEnLista(juegosSuscriptos, juegoAIniciar);
// 			}while(taBienEscrito != true);*/
			

// 			//string nombreJuego = *juegosSuscriptos[juegoAIniciar]; //nombre del juego a empezar.
// 			//para arreglar

//  			cout<<"Epicardo, sera una multijugador o individual my brudda?"<<endl;
//  			cout<<"1)Individual"<<endl;
//  			cout<<"2)Multijogador"<<endl;
//  			cin>>multiOIndividual;

//  			switch (multiOIndividual)
//  			{
//  			case 1:     //Individual
//  				bool esContinuacion;
//  				cout<<"Epicardo, sera una continuacion de una anterior?"<<endl;
//  				cout<<"0)NO Continuacion"<<endl;
//  				cout<<"1)Continuacion"<<endl;
//  				cin>>esContinuacion;

//  				if(esContinuacion){
//  					int IdPartidaAContinuar;
//  					dtPartidaIndividual** partidasSeleccionadas = sistema->listoPartidasInactivas(); //siendo partidasSeleccionadas una lista en orden cronologico de dtPartidaIndividual de las partidas inactivas del usuario.
					
// 					if(partidasSeleccionadas == NULL){//alto control paaaaaa
// 						cout<<"No hay partidas inactivas para el videojuego seleccionado"<<endl;
// 						return;
// 					}

//  					cout<<"Seleccione porfa el ID de la partida a continuar"<<endl;
//  					cin>>IdPartidaAContinuar;

// 					sistema->confirmarIndividual(*partidasSeleccionadas[IdPartidaAContinuar]);
// 					cout<<"Partida Inicializada con exito!"<<endl;
// 					return;

//  				}else{
//  					//aca entiendo formaremos un dtPartidaIndividual datosPartida con toda la info que hemos recolectado hasta ahora.
					

//  				}
 				
//  				cout<<"Partida Iniciada con exito!"<<endl;
//  				return;
//  				break;
			
//  			case 2://Multijugador
//  				bool esVivo;
//  				cout<<"Epicardo, sera una partida transmitida en vivo?"<<endl;
//  				cout<<"0)NO en vivo"<<endl;
//  				cout<<"1)en vivo"<<endl;
//  				cin>>esVivo;

//  				//jugadoresUnidosString listarNicks(nombreJuego); mostramos todos los nicks de los jugadores que tienen una sus activa para el juego que le pasamos por parametro (el que se consigió iterando hace un rato)
//  				//formamos dtPartidaMultijugador datosPartidaMulti con la info gathereada.
//  				//confirmarMultijugador(datosPartidaMulti);
//  				cout<<"Partida Iniciada con exito!"<<endl;
//  				break;
//  			default:
//  				cout<<"opciOwOn invalida"<<endl;
//  			}
//  		break;
		
//  		case 2:
//  			return;
//  		break;
		
//  		default:
//  		cout<<"opciOwOn invalida"<<endl;
//  			break;
//  		}
//      }while(optInicarPartida != 2);

//  }