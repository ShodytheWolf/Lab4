#include <stdlib.h>
#include <iostream>

using namespace std;



void menuPrincipal(){

	cout<<"Bienvenido a Steam barato!"<<endl;
	cout<<"Seleccione una opcion a continuacion:"<<endl;
	cout<<"-------------------------------------"<<endl<<endl;
	cout<<"1)Alta de Usuario"<<endl;
	cout<<"2)Iniciar Sesion"<<endl;
	cout<<"3)Cargar datos de prueba"<<endl;
	cout<<"4)Salir"<<endl;
}

int main(){
	int opt;
	do{
		menuPrincipal();
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
				return 0;
			break;

			default:
			cout<<"opcion invalida"<<endl;
		}
	}while(opt != 4);

    return 0;
}

int menuJugador(){

    int opcion = 0;

    cout << "=============" << endl;
    cout << "Menú jugador." << endl;
    cout << "=============" << endl;
    
    cout << "1- Suscribirse a un videojuego" << endl;
    cout << "2- Asignar puntaje a videojuego" << endl;
    cout << "3- Iniciar partida" << endl;
    cout << "4- Abandonar partida multijugador" << endl;
    cout << "5- Finalizar partida" << endl;
    cout << "6- Ver información de videojuego" << endl;
    cout << "7- Modificar fecha del sistema." << endl;
    cout << "8- Salir" << endl;
    cin >> opcion;
    cout << "Presione enter para continuar" << endl;
    getchar();
    getchar();
    system("clear");
        
   while (opcion <= 1 || opcion>= 8){
        try{
        
            switch(opcion){

                case 1:
                    //suscribirseAvideojuego();
                case 2:
                    //asignarpuntajeAvideojuego();
                case 3:
                    //iniciarPartida
                case 4:
                    //AbandonarPartidaMultijugador
                case 5:
                    //FinalizarPartida
                case 6:
                    //verInformaciondeVideojuego
                case 7:
                    //ModificarFechadelSistema
                case 8:
                    //menuprincipal();
                default: 
                cout << "Opción incorrecta pibe" << endl;
            }
        }
        catch(invalid_argument& error){
        cout << error.what();
        }
    
   }
}