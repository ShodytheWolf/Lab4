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
            cout << "Ingrese una opción numerica\n" 
            << "1-Ingresar email\n" 
            <<"2-Ingresar contraseña\n"
            <<"3-Confirmar\n"
            <<"4-Cancelar"
            <<endl;
            cin.ignore() >> op;
            switch(op){
                case '1':
                    cout << "Ingrese su email: " <<endl;
                    cin >> email;
                    break;
                case '2':
                    cout << "Ingrese su contraseña: " <<endl;
                    cin >> contrasenia; 
                    break;
                case '3':
                    existeUsuario = sistema->ingresoData(email, contrasenia, true);
                    if(!existeUsuario)
                        cout << "Email o contraseña incorrectos" <<endl;
                    else{
                        tU = sistema->confirmarSesion();
                        system("clear");
                    }
                    break;
                case '4': 
                    return;
                default:
                    cout << "Opción incorrecta por favor intente de nuevo" <<endl;
                    break;
            }
        }while(!existeUsuario);
    }catch(invalid_argument &e){
        cout << e.what() << " Registre un nuevo usuario para iniciar sesion" <<endl;
    }
}