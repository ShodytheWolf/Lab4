#include <stdlib.h>
#include <iostream>
#include "IControlador/IControlador.cpp"
#include "Fabrica/Fabrica.cpp"

using namespace std;

void menuDesarrollador();
void menuJugador();
void menuPublicarVideojuego();
void menuSuscribirse();
void menuAsignarPuntaje();

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
    cout << "Presione ENTER para continuar..." << endl;
    getchar();
    getchar();
    system("clear");
        
   while (opcion <= 1 || opcion>= 8){
        try{
        
            switch(opcion){

                case 1:
                    //suscribirseAvideojuego();
					break;
                case 2:
                    //asignarpuntajeAvideojuego();
					break;
                case 3:
                    //iniciarPartida
					break;
                case 4:
                    //AbandonarPartidaMultijugador
					break;
                case 5:
                    //FinalizarPartida
					break;
                case 6:
                    //verInformaciondeVideojuego
					break;
                case 7:
                    //ModificarFechadelSistema
					break;
                case 8:
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

void menuPublicarVideojuego(){
	int opcion = 0;

	//dtVideojuego datosjuegos;
	//set<dtcategoria> categorias;

    cout << "|======================|" << endl;
    cout << " Publicar un videojuego." << endl;
    cout << "|======================|" << endl;
    
    cout << "1- Listar generos." << endl;
    cout << "2- Listar plataformas." << endl;
    cout << "3- Listar Otros." << endl;
    cout << "4- PublicarVideojuego." << endl;
    cout << "5- Salir." << endl;
    cin >> opcion;
    cout << "Presione ENTER para continuar..." << endl;
    getchar();
    getchar();
    system("clear");

	      
   while (opcion <= 1 || opcion>= 5){
        try{
            switch(opcion){
                case 1:
                    //listarGenero()<dtCategoria>;
					//seleccion
					break;
                case 2:
                    //listarPlataforma()<dtCategoria>
					//seleccion
					break;
                case 3:
                    //listarOtro()<dtCategoria>
					//if
					//seleccion
					break;
                case 4:
					//se insertan datos del jueguito
                    //publicarVideojuego(dtVideojuego datosjuego, set<categorias> categorias);
					//confirmacion if
					break;
                case 5:
                    //menuprincipal(); o menuDesarrollador();
				break;
                default: 
                cout << "Opción incorrecta guanaco." << endl;
				break;
            }
        }
        catch(invalid_argument& error){
        cout << error.what();
        }
    
   }

}

void menuSuscribirse(){
	int opcion = 0;

	

    cout << "|===========================|" << endl;
    cout << " Suscribirse a un videojuego." << endl;
    cout << "|===========================|" << endl;
    
    cout << "1- ListarVideojuegos." << endl;
    cout << "2- IngresarVideojuego." << endl;
    cout << "3- NuevaSuscripcion." << endl;
    cout << "4- Dar de Baja." << endl;
    cout << "5- Salir." << endl;
    cin >> opcion;
    cout << "Presione ENTER para continuar..." << endl;
    getchar();
    getchar();
    system("clear");

	      
   while (opcion <= 1 || opcion>= 5){
        try{
            switch(opcion){
                case 1:
                    //listarVideojuegosActivos();
                    //listarVideojuegosInActivos();
					break;
                case 2:
					//char* nombreVideojuego;
                    //ingresoVideojuego(nombreVideojuego)
					break;
                case 3:
					//enumPago metodoDePago;
					//enumSuscripcion tipoSuscripcion;
                    //nuevaSuscripcion(metodoDePago,tipoSuscripcion);
					break;
                case 4:
					//darDebaja();
					break;
                case 5:
                    //menuprincipal(); o menuJugador();
				break;
                default: 
                cout << "Opción incorrecta platita" << endl;
				break;
            }
        }
        catch(invalid_argument& error){
        cout << error.what();
        }
    
   }

}

void menuAsignarPuntaje(){
	int opcion = 0;

    cout << "|===============================|" << endl;
    cout << " Asignar puntaje a un videjuego." << endl;
    cout << "|===============================|" << endl;
    
    cout << "1- ListarVideojuegos." << endl;
    cout << "2- Asignar puntaje." << endl;
    cout << "3- Salir." << endl;
    cin >> opcion;
    cout << "Presione ENTER para continuar..." << endl;
    getchar();
    getchar();
    system("clear");

	      
   while (opcion <= 1 || opcion>= 3){
        try{
            switch(opcion){
                case 1:
                    //listarVideojuegos();
					break;
                case 2:
					//char* nombreVideojuego;
					//int puntuacion;
					//asignarPuntaje(nombreVideojuego, puntuacion);
					break;
                case 3:
                    //menuprincipal(); o menuJugador();
				break;
                default: 
                cout << "Opción incorrecta  mastercard." << endl;
				break;
            }
        }
        catch(invalid_argument& error){
        cout << error.what();
        }
    
   }

}

void menuPrincipal(){
    int opt;
	do{
		menuPrincipal();
        cout<<"Bienvenido a Steam barato!"<<endl;
	    cout<<"Seleccione una opcion a continuacion:"<<endl;
	    cout<<"-------------------------------------"<<endl<<endl;
	    cout<<"1)Alta de Usuario"<<endl;
	    cout<<"2)Iniciar Sesion"<<endl;
	    cout<<"3)Cargar datos de prueba"<<endl;
	    cout<<"4)Salir"<<endl;
		cin>>opt;

	switch(opt){
            case 1:
				//acá se llama a AltaUsuario
			break;

			case 2:
				//acá se inicia sesion
				//se mostrará 2 menus, el de desarrollador o el de jogador, dependiendo quién inicié sesión jaja xd
			break;

			case 3:
				//se cargaran datos de prueba
			break;

			case 4:
				return;
			break;

			default:
			cout<<"opcion invalida"<<endl;
		}
	}while(opt != 4);

}