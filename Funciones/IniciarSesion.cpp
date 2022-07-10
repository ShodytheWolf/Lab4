#include <iostream>
#include "../Fabrica/Fabrica.h"
#include "../IControlador/IControlador.h"

using namespace std;

void iniciarSesion(char &tU){
    Fabrica f;
    IControlador* sistema = f.getInterface();
    string email, contrasenia;
    char op = ' ';
    bool existeUsuario = false;
    try{
        do{
            cout << "Iniciar Sesion\n"<<endl;
            getchar();
            cout<< "Ingrese su email:" <<endl; 
            getline(cin,email,'\n');
            cout<<"Ingrese su contraseña:"<<endl; 
            getline(cin,contrasenia, '\n');
            existeUsuario = sistema->ingresoData(email, contrasenia, true);
            if(!existeUsuario){
                cout << "Email o contraseña incorrectos. Desea volver a intentar? S/N" <<endl;
                do{
                    cin >> op;
                    switch(op){
                        case 's':
                        case 'S':
                            op = '#';
                            break;
                        case 'n':
                        case 'N':
                            cout << "Volviendo al menu principal..." <<endl;
                            return;
                            break;
                        default:
                            cout << "Opcion incorrecta." <<endl;
                            break;
                    }
                }while(op != '#');
            }
            else{
                tU = sistema->confirmarSesion();
                system("clear");
            }
        }while(!existeUsuario);
    }catch(invalid_argument &e){
        cout << e.what() << " Registre un nuevo usuario para iniciar sesion" <<endl;
    }
}