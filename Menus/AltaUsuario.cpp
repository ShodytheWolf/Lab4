#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "../IControlador/IControlador.h"
#include "../Fabrica/Fabrica.h"

using namespace std;

bool verificarEnLista(string** , string);

void altaUsuario(){

    Fabrica fab;
    IControlador* controlador = fab.getInterface();

    char confirmacion;
    string correo;
    string contrasenia;
    string desc;
    char tipoUsr;
    //bool existe = verificarEnLista();
    bool existe = false; // prueba
    cout << "Ingrese un correo: ";
    cin >> correo;
    cout << "\nIngrese una contrasenia: ";
    cin >> contrasenia;

    cout << "¿Desea registrar un desarrolladoro un usuario?" << endl;
    cout << "Para registrar un desarrollador presione(d/D)" << endl;
    cout << "Para registrar un usuario presione cualquier tecla." << endl;
    cin >> tipoUsr;

    if(tipoUsr == 'd' || tipoUsr == 'D'){
        char* nombreEmpresa;

        cout << "Para registrar un desarrollador ingrese el nombre: ";
        cin >> nombreEmpresa;
        controlador->ingresarEmpresa(nombreEmpresa);

        cout << "¿Desea confirmar?" << endl;
        cout << "Presione (s/S) para confirmar." << endl;
        cin >> confirmacion;
        
        if (confirmacion == 's' || confirmacion == 'S'){
            controlador->confirmarNuevoDesarrollador();
        }
        else {
            //menuPrincipal();
            cout << "cancelaste";
        }

    }else {
        char* nickname;
        cout << "Para registrar un jugador ingrese su nickname: ";
        cin >> nickname;
        
        while(existe == false){
          
        controlador->ingresarNickname(nickname);
        
        }
        
        cout << "Ingrese una descripción: ";
        cin >> desc;
        controlador->ingresarDescripcion(desc);
        cout << "¿Desea confirmar?" << endl;
        cout << "Presione (s/S) para confirmar." << endl;
        cin >> confirmacion;
        
        if (confirmacion == 's' || confirmacion == 'S'){
            controlador->confirmarNuevoDesarrollador();
        }
        else {
            //menuPrincipal();
            cout << "cancelaste";
        }
    }
}