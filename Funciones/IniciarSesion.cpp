#include <iostream>
#include "../Fabrica/Fabrica.h"
#include "../IControlador/IControlador.h"

using namespace std;

void iniciarSesion(){
    Fabrica f;
    IControlador* sistema = f.getInterface();
    string email, contrasenia;
    int op;
    bool existeUsuario = false;
    do{
        cout << "Ingrese una opción numerica" 
        << "1-Ingresar email\n" 
        <<"2-Ingresar contraseña\n"
        <<"3-Confirmar\n"
        <<"4-Cancelar"
        <<endl;
        cin >> op; 
        switch(op){
            case 1:
                cout << "Ingrese su email: " <<endl;
                cin >> email;
                break;
            case 2:
                cout << "Ingrese su contraseña: " <<endl;
                cin >> contrasenia; 
                break;
            case 3:
                existeUsuario = sistema->ingresoData(email, contrasenia, true);
                if(!existeUsuario)
                    cout << "Email o contraseña incorrectos" <<endl;
                else
                    sistema->confirmarSesion();
                break;
            case 4: 
                return;
            default:
                cout << "Opción incorrecta por favor intente de nuevo" <<endl;
                break;
        }
    }while(!existeUsuario);
}