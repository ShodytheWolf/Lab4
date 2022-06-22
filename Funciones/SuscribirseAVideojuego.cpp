#include <iostream>
#include <stdio.h>
#include "../IControlador/IControlador.h"
#include "../Fabrica/Fabrica.h"
#include "../Enumeration/enumSuscripcion.h"

using namespace std;

void suscribirseAVideojuego(){  //caso de uso 5

Fabrica fab;
IControlador* controlador = fab.getInterface();

int opcion = 0;
char confirmar;
char* nombreVideojuego;
enumSuscripcion tipoSus;
enumPago pago;
char selecPago;
char selecTipoSus;
dtVideoJuego** listJuegosDiff = controlador->listarVideojuegosDiferenciada();

cout << "|===========================|" << endl;
cout << " Suscribirse a un videojuego." << endl;
cout << "|===========================|" << endl;

cout << "Lista de videojuegos suscriptos y no suscriptos." << endl;

int i = 0;
while (listJuegosDiff[i]){
    cout << "Nº:" <<i+1 << listJuegosDiff[i] <<endl;
}

cout << "Ingrese nombre del videojuego a suscribirse:" << endl;
cin >> nombreVideojuego;
controlador->ingresarVideojuego(nombreVideojuego);
system ("clear");

bool suscripto = controlador->estaSuscripto(nombreVideojuego);

    if (!suscripto){ //si no tiene una suscripcion 
        
        cout << "Ingrese un metodo de Pago Paypal(p/P), Tarjeta(t/T). " << endl;
        cin >> selecPago;
        switch(selecPago){
            case 'p':
            case 'P':
                pago = Paypal;
                break;
            case 't':
            case 'T':
                pago = Tarjeta;
                break;
            default:
                cout << "Metodo de pago invalido. " << endl;
                break;
        }
        system ("clear");

        cout << "Ingrese un tipo de suscripción Anual(a/A), Mensual(m/M), Trimestral(t/T), Vitalicia(v/V)." << endl;
        cin >> selecTipoSus;
        switch(selecTipoSus){
            case 'a':
            case 'A':
                tipoSus = Anual;
                break;
            case 'm':
            case 'M':
                tipoSus = Mensual;
                break;
            case 't':
            case 'T':
                tipoSus = Trimestral;
                break;
            case 'v':
            case 'V':
                tipoSus = Vitalicia;
                break;
            default:
                cout << "Tipo invalido." << endl;
                break;
        }
        system ("clear");

        cout << "¿Desea confirmar?" << endl;
        cout << "Presione (s/S) para confirmar o cualquier tecla para cancelar" << endl;
        cin >> confirmar;
        if (confirmar == 's' || confirmar == 'S'){
        cout << "Compra realizada con éxito" << endl;
        controlador->nuevaSuscripcion(pago, tipoSus);
        delete nombreVideojuego, listJuegosDiff;
        return;
        }
        else { //cancelar
            cout << "Has cancelado la compra. " << endl;
            cout << "Pulsa ENTER para continuar..." << endl;
            getchar();
            getchar();
            delete nombreVideojuego, listJuegosDiff;
            return;
        } 
    }
    else { //tiene una suscripcion temporal 
        if(suscripto && tipoSus != Vitalicia){

            cout << "¿Desea dar de baja la suscripcion activa y crear una nueva?" << endl;
            cout << "Presione (s/S) para confirmar o cualquier tecla para cancelar" << endl;
            cin >> confirmar;
            if (confirmar == 's' || confirmar == 'S'){
                cout << "diste de baja una suscripcion" << endl;
                controlador->darDeBajaSuscripcion();
                cout << "Ingrese un metodo de Pago: " << endl;
                cin >> selecPago;
                switch(selecPago){
                    case 'p':
                    case 'P':
                        pago = Paypal;
                        break;
                    case 't':
                    case 'T':
                        pago = Tarjeta;
                        break;
                    default:
                        cout << "Metodo de pago invalido. " << endl;
                        break;
                }

                cout << "Ingrese un tipo de suscripción Anual(a/A), Mensual(m/M), Trimestral(t/T), Vitalicia(v/V)" << endl;
                cin >> selecTipoSus;
                switch(selecTipoSus){
                    case 'a':
                    case 'A':
                        tipoSus = Anual;
                        break;
                    case 'm':
                    case 'M':
                        tipoSus = Mensual;
                        break;
                    case 't':
                    case 'T':
                        tipoSus = Trimestral;
                        break;
                    case 'v':
                    case 'V':
                        tipoSus = Vitalicia;
                        break;
                    default:
                        cout << "Tipo invalido." << endl;
                        break;
                }

                if (confirmar == 's' || confirmar == 'S'){
                cout << "Compra realizada con éxito" << endl;                          
                controlador->nuevaSuscripcion(pago, tipoSus);
                delete nombreVideojuego, listJuegosDiff;
                return;
                }
            }
            else{
                cout << "No diste de baja la suscripción" << endl;
                cout << "Pulsa ENTER para continuar..." << endl;
                getchar();
                getchar();
                delete nombreVideojuego, listJuegosDiff;
                return;
            }
        }
    }
}