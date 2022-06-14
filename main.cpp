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

