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


    cout << "|=============|" << endl;
    cout << " Alta usuario." << endl;
    cout << "|=============|" << endl;


    cout << "Ingrese un correo: ";
    cin >> correo;
    cout << "\nIngrese una contrasenia: ";
    cin >> contrasenia;

    controlador->ingresoDatos(correo, contrasenia);

    cout << "¿Desea registrar un desarrolladoro un usuario?" << endl;
    cout << "Para registrar un desarrollador presione(d/D)" << endl;
    cout << "Para registrar un usuario presione cualquier tecla." << endl;
    cin >> tipoUsr;


    //ALT
    if(tipoUsr == 'd' || tipoUsr == 'D'){ //usuario desarrollador
        char* nombreEmpresa;

        cout << "Para registrar un desarrollador ingrese el nombre: ";
        cin >> nombreEmpresa;
        controlador->ingresarEmpresa(nombreEmpresa);

        //OPT
        cout << "¿Desea confirmar?" << endl;    //confirmar
        cout << "Presione (s/S) para confirmar." << endl;
        cin >> confirmacion;
        
        if (confirmacion == 's' || confirmacion == 'S'){
            controlador->confirmarNuevoDesarrollador();
        }
        else { //cancelar
            //menuPrincipal();
            cout << "cancelaste";
        }

    }else {                 //usuario Jugador
        char* nickname;
        cout << "Para registrar un jugador ingrese su nickname: ";
        cin >> nickname;
        
        //LOOP
        // while(verificarEnLista()){ //de donde viene el nickname para comparar si existe?
          
        // controlador->ingresarNickname(nickname);
        
        // }
        
        cout << "Ingrese una descripción: ";
        cin >> desc;
        controlador->ingresarDescripcion(desc);

        //OPT
        cout << "¿Desea confirmar?" << endl; //confirmar
        cout << "Presione (s/S) para confirmar." << endl;
        cin >> confirmacion;
        
        if (confirmacion == 's' || confirmacion == 'S'){
            controlador->confirmarNuevoJugador();
        }
        else {  //cancelar
            //menuPrincipal();
            cout << "cancelaste";
        }
    }
}