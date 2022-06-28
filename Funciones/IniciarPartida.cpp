//#include "Menus.h"
#include "../IControlador/IControlador.h"
#include "../Fabrica/Fabrica.h"

bool verificarEnLista(string**, string);

void iniciarPartida(){
	Fabrica fabrica;
	IControlador* sistema = fabrica.getInterface();
    int optInicarPartida;
      do{
		bool esContinuacion = false;
		bool esVivo = false;
		int i = 0;
		dtPartidaIndividual* datosPartida;
		dtPartidaMultijugador* datosPartidaMulti;
		string** nicksJugadoresUnidos;
		string** juegosSuscriptos;
		int IdPartidaAContinuar = 0;

  		cout<<"Bienvenido a Iniciar Partida!"<<endl;
 	    cout<<"Seleccione una opcion a continuacion:"<<endl;
 	    cout<<"-------------------------------------"<<endl<<endl;
 	    cout<<"1)Listar Videojuegos Suscriptos"<<endl;
  	    cout<<"2)Salir"<<endl;
  		cin>>optInicarPartida;

		char* juegoAIniciar;
 		switch(optInicarPartida)
 		{
 		case 1:
			int eleccion;
 			int multiOIndividual;
 			juegosSuscriptos = sistema->listarVideojuegosSuscripto();//entro, consigo la lista de juegos, e inicializo juegosSuscriptos.
			//CUIDADO, VER TRY AND CATCH
				//CUIDADO, VER TRY AND CATCH
					//CUIDADO, VER TRY AND CATCH
						//CUIDADO, VER TRY AND CATCH
							//CUIDADO, VER TRY AND CATCH
								//CUIDADO, VER TRY AND CATCH
									//CUIDADO, VER TRY AND CATCH
										//CUIDADO, VER TRY AND CATCH
											//CUIDADO, VER TRY AND CATCH


			if(!juegosSuscriptos[0]){
				cout<<"jugador no tiene juegos suscriptos (pobre)"<<endl;
				return;
			}


			i = 0;
			while (juegosSuscriptos[i] != NULL)//HOW
			{
				cout<<*juegosSuscriptos[i]<<endl;
			};

			//me fijo que esta bien escrito lo que me pasa el usuario.
			bool taBienEscrito;
			do{
 				cout<<"Seleccione el nombre del juego que desea iniciar partida"<<endl;
 				cin>>juegoAIniciar;
				taBienEscrito = verificarEnLista(juegosSuscriptos, string(juegoAIniciar));
			}while(taBienEscrito != true);

			


 			cout<<"Epicardo, sera una multijugador o individual my brudda?"<<endl;
 			cout<<"1)Individual"<<endl;
 			cout<<"2)Multijogador"<<endl;
 			cin>>multiOIndividual;

 			switch (multiOIndividual)
 			{
 			case 1:     //INDIVIDUAL
 				cout<<"Epicardo, sera una continuacion de una anterior?"<<endl;
 				cout<<"1)NO Continuacion"<<endl;
 				cout<<"2)Continuacion"<<endl;
 				cin>>eleccion;

				if(eleccion == 2){//SI LA PARTIDA ES CONTINUADA
					esContinuacion = true;
					dtPartidaIndividual** partidasSeleccionadas = sistema->listoPartidasInactivas(); //siendo partidasSeleccionadas una lista en orden cronologico de dtPartidaIndividual de las partidas inactivas del usuario.
					
					//Controlo que las partidas que consegui no sean vacias.
					if(!partidasSeleccionadas[0]){//asi accedo a espacios de memOwOria directamente.
						cout<<"No hay partidas inactivas para el videojuego seleccionado"<<endl;
						return;
					}

					//listo las partidas que consegui
					i = 0;
					while(partidasSeleccionadas[i] != NULL){//HOW
						if(string(partidasSeleccionadas[i]->getNombreVideojuego()) == string(juegoAIniciar)){//HOW
							cout<<"ID: "<<partidasSeleccionadas[i]->getIdPartida()<<"-Duracion: "<<partidasSeleccionadas[i]->getDuracion()<<"-Fecha: "<<partidasSeleccionadas[i]->getFecha()<<endl;
						};
						i++;
					};
					cout<<"Seleccione porfa el ID de la partida a continuar"<<endl;
 					cin>>IdPartidaAContinuar;
				};
				
				cout<<"Desea confirmar la partida?"<<endl;
				cout<<"1)Si"<<endl;
				cout<<"2)No"<<endl;
				cin>>eleccion;
				if(eleccion == 2){
					return;
				};

				datosPartida = new dtPartidaIndividual(0,string(juegoAIniciar),esContinuacion,IdPartidaAContinuar,float(0));
				sistema->confirmarIndividual(datosPartida);
				cout<<"Partida Inicializada con exito!"<<endl;
				return;
				//FIN CASO DE USO

			
 			case 2://Multijugador
 				esVivo = false;

 				cout<<"Epicardo, sera una partida transmitida en vivo?"<<endl;
 				cout<<"1)en vivo"<<endl;
 				cout<<"2)NO en vivo"<<endl;
 				cin>>eleccion;

				if(eleccion == 1){
					esVivo = true;
				};
				
				nicksJugadoresUnidos = sistema->listarNicks(juegoAIniciar);//consigo todos los jugadores que estan suscriptos al juego en cuestion.

				i = 0;
				//itero para mostrar los nicks de los ñerys que también tienen el juego comprao
				while (nicksJugadoresUnidos[i] != NULL)
				{
					cout<<*nicksJugadoresUnidos[i]<<endl;
				};
				//no lo tenemos en consideracion en caso de que no haya jugadores


				//iteramos cuantas veces se quiera para conseguir un array con los nombres de los jugadores que se van a unir,cuidando que esten suscriptos claro.
				i = 0;
				string** nicksUnidos;//ACA SI HOW HOW HOW HOW HOW HOWO HOW HOW HOW OWO HOW HOW HOW
				int deseaSeguir;
				do{
					char* nombreAIngresar;
					cout<<"Ingrese el nombre DE A UNO de los jugadores que van a jugar con usted"<<endl;
					cin>>nombreAIngresar;

					if(verificarEnLista(nicksJugadoresUnidos,string(nombreAIngresar))){
						
						*nicksUnidos[i] = string(nombreAIngresar);
						i++;
						cout<<"se ingreso el nick del jugador"<<endl;
					}else{
						cout<<"NO se ingreso el nick del jugador"<<endl;
					}
					delete nombreAIngresar;

					cout<<"Desea seguir ingresando jugadores?"<<endl;
					cout<<"1)Si"<<endl;
					cout<<"2)No"<<endl;
					cin>>deseaSeguir;
					system("clear");
				}while(deseaSeguir != 2);


				int confirmar;
				cout<<"Desea confirmar la partida?"<<endl;
				cout<<"1)Si"<<endl;
				cout<<"2)No"<<endl;
				cin>>confirmar;
				if(confirmar == 2){
					return;
				};


				datosPartidaMulti = new dtPartidaMultijugador(0,0,juegoAIniciar,esVivo,string(NULL),nicksUnidos);
				sistema->confirmarMultijugador(datosPartidaMulti);
				cout<<"Partida Inicializada con exito!"<<endl;
				return;


 				cout<<"Nadie deberia ser capaz de caer en esta parte del Switch c:"<<endl;
 				break;
 			default:
 				cout<<"opciOwOn invalida"<<endl;
				return;
 			}
 		break;
		
 		case 2:
			cout<<"byeee~ :3"<<endl;
 			return;
 		break;
		
 		default:
 		cout<<"opciOwOn invalida"<<endl;
 			break;
 		}
    }while(optInicarPartida != 2);

}