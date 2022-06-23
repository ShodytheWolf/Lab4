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
    char* Usrnickname; //delete 
    char* nombreEmpresa; //delete
    char confirmacion;
    char reintento;
    string correo;
    string contrasenia;
    string desc;
    char tipoUsr;
    string** listJugadores = controlador->jugadores(); //delete
    cout << "|=============|" << endl;
    cout << " Alta usuario." << endl;
    cout << "|=============|" << endl;
    cout << "Ingrese un correo: ";
    cin >> correo;
    cout << "\nIngrese una contrasenia: ";
    cin >> contrasenia;
    bool alta = controlador->ingresoData(correo, contrasenia); //verificacion si existe correo
    system ("clear");
    //ALT      
    cout << "¿Desea registrar un desarrollador o un jugador?" << endl;
    cout << "Para registrar un desarrollador presione(d/D)" << endl;
    cout << "Para registrar un jugador presione (j/J)." << endl;
    cin >> tipoUsr;
    system ("clear");   
    switch(tipoUsr){
        case 'd':
        case 'D':
            cout << "Para registrar un desarrollador ingrese el nombre de la empresa: ";
            cin >> nombreEmpresa;
            //OPT
            cout << "¿Desea confirmar?" << endl;    //confirmar
            cout << "Presione (s/S) para confirmar." << endl;
            cin >> confirmacion;
            system ("clear");
            if (confirmacion == 's' || confirmacion == 'S'){
                controlador->ingresarEmpresa(nombreEmpresa);
                controlador->confirmarNuevoDesarrollador();
            }
            else { 
                cout << "Usted cancelo el alta."<< endl;
            }
            delete nombreEmpresa, listJugadores, Usrnickname;
        break; //breakesito
        case 'j':
        case 'J':
            cout << "Para registrar un jugador ingrese su nickname: ";
            cin >> Usrnickname;
            //LOOP
            while(!verificarEnLista(listJugadores,Usrnickname)){ //mientras no este en lista
                cout << "El nickname ingresado ya existe. ¿Desea intentar nuevamente?(S/N)"<< endl;              
                switch(reintento){
                    case 'S':
                    case 's':
                        cin >> Usrnickname;
                        break; //breaksito
                    case 'N':
                    case 'n':
                        cout << "Has cancelado el ingreso." << endl;
                        delete nombreEmpresa, listJugadores, Usrnickname;
                        return;
                }
            }
            controlador->ingresarNickname(Usrnickname);
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
                cout << "Has cancelado el registro.";
            }
        break;
    }
    delete nombreEmpresa, listJugadores, Usrnickname;
}