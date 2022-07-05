#include <iostream>
#include <stdio.h>
#include "../IControlador/IControlador.h"
#include "../Fabrica/Fabrica.h"
#include "../Enumeration/enumSuscripcion.h"
#include "../breakpoint.cpp"

using namespace std;

bool verificarEnLista(dtVideoJuego** list, string nombre);

void suscribirseAVideojuego(){  //caso de uso 5


Fabrica fab;
IControlador* controlador = fab.getInterface();

int i = 0;
int opcion = 0;
char confirmar;
string nombreVideojuego; //char* a string
enumSuscripcion tipoSus;
enumPago pago;
char selecPago;
char selecTipoSus;
dtVideoJuego** listJuegosDiff = controlador->listarVideojuegosDiferenciada();

try{
    cout << "|===========================|" << endl;
    cout << " Suscribirse a un videojuego." << endl;
    cout << "|===========================|" << endl;


    cout << "Lista de videojuegos suscriptos: " << endl;
    while (listJuegosDiff[i]){//mientras tenga jogos
        if(listJuegosDiff[i]->getEstaSuscripto()){//si esta suscrito
            cout << "\nNº:" << i+1 << " Juego:" <<  listJuegosDiff[i]->getNombreVideojuego() << "\nCosto Anual:" << //imprimo data
            listJuegosDiff[i]->getCostos()->getCostoAnual()<< "\nCosto Trimestral:" << 
            listJuegosDiff[i]->getCostos()->getCostoTrimestral() <<
            "\nCosto Mensual:"<< listJuegosDiff[i]->getCostos()->getCostoMensual() << "\nCosto Vitalicia:" << 
            listJuegosDiff[i]->getCostos()->getCostoVitalicia() << endl;
        }
        i++;
    }

    cout << "\nPresione ENTER para continuar.... " << endl;
    getchar();
    getchar();

    cout << "Lista de videojuegos no suscriptos" << endl;
    i = 0;
    while (listJuegosDiff[i]){//mientras tenga jogos
        if(!listJuegosDiff[i]->getEstaSuscripto()){ //si no esta suscrit
            cout << "\nNº:" << i+1 << " Juego:" <<  listJuegosDiff[i]->getNombreVideojuego() << "\nCosto Anual:" << //imprimo data
            listJuegosDiff[i]->getCostos()->getCostoAnual() << "\nCosto Trimestral:" << 
            listJuegosDiff[i]->getCostos()->getCostoTrimestral() <<
            "\nCosto Mensual: "<< listJuegosDiff[i]->getCostos()->getCostoMensual() << "\nCosto Vitalicia:" << 
            listJuegosDiff[i]->getCostos()->getCostoVitalicia() << endl;
        }
        i++;
    }

    cout << "\nPresione ENTER para continuar.... " << endl;
    getchar();

    cout << "Ingrese nombre del videojuego a suscribirse, respetando el formato:" << endl;
    cin >> nombreVideojuego;

    while(!verificarEnLista(listJuegosDiff, nombreVideojuego)){ //mientras que el juego no este en la lista porque el usuario es una verga
        cout << "El nombre ingresado no existe intente nuevamente." << endl;
        cin >> nombreVideojuego;
    }

    controlador->ingresarVideojuego(nombreVideojuego.data()); //ingreso nombre que recuerda el sistema.
    system ("clear");
    
    i = 0;
    dtVideoJuego* jogo;
    while(listJuegosDiff[i]){
        if(listJuegosDiff[i]->getNombreVideojuego() == nombreVideojuego){ //nombre del videojuego si es igual al ingresado
            jogo = listJuegosDiff[i];
            break;
        }
        i++;
    }

    bool suscripto = jogo->getEstaSuscripto(); //control si esta suscrito o no

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

            cout << "Ingrese un tipo de suscripción Anual(a/A), Mensual(m/M), Trimestral(t/T), Vitalicia(v/V)." << endl;
            cin >> selecTipoSus;
            
            switch(selecTipoSus){
                case 'a':
                case 'A':
                    tipoSus = An;
                    break;
                case 'm':
                case 'M':
                    tipoSus = Men;
                    break;
                case 't':
                case 'T':
                    tipoSus = Trim;
                    break;
                case 'v':
                case 'V':
                    tipoSus = Vit;
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
            controlador->nuevaSuscripcion(pago, tipoSus); //creo suscripcion
            return;
            }
            else { //cancelar suscripcion
                cout << "Has cancelado la compra. " << endl;
                cout << "Pulsa ENTER para continuar..." << endl;
                getchar();
                getchar();
                return;
            } 
        }
        else { //tiene una suscripcion temporal
            enumSuscripcion tipoSuscripto = jogo->getCostos()->getTipo(); //tipo de suscripcion para pasar por el if

            if(tipoSuscripto != Vit){ //si la suscripcion no es vitalicia

                cout << "¿Desea dar de baja la suscripcion activa y crear una nueva?" << endl;
                cout << "Presione (s/S) para confirmar o cualquier tecla para cancelar" << endl;
                cin >> confirmar;
                if (confirmar == 's' || confirmar == 'S'){
                    cout << "diste de baja una suscripcion" << endl;
                    controlador->darDeBajaSuscripcion(); //doy de baja suscripcion, añado a suscripciones inactivas.
                    

                    cout << "Ingrese un metodo de Pago Paypal(p/P), Tarjeta(t/T): " << endl;
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
                            tipoSus = An;
                            break;
                        case 'm':
                        case 'M':
                            tipoSus = Men;
                            break;
                        case 't':
                        case 'T':
                            tipoSus = Trim;
                            break;
                        case 'v':
                        case 'V':
                            tipoSus = Vit;
                            break;
                        default:
                            cout << "Tipo invalido." << endl;
                            break;
                    }

                    cout << "¿Desea confirmar?" << endl;
                    cin >> confirmar;
                    if (confirmar == 's' || confirmar == 'S'){
                    cout << "Compra realizada con éxito" << endl;                          
                    controlador->nuevaSuscripcion(pago, tipoSus); //creo suscirpcion
                    return;
                    }
                    else{
                        cout << "Cancelaste la compra, volviendo al menu..." << endl;
                        return;
                    }
                }
                else{
                    cout << "No diste de baja la suscripción" << endl;
                    cout << "Pulsa ENTER para continuar..." << endl;
                    getchar();
                    getchar();
                    return;
                }
            }
            else{
                cout << "No puedes suscribirte a este juego." << endl;
                cout << "Tienes una suscripcion vitalicia..." << endl;
                cout << "Pulsa ENTER para continuar..." << endl;
                getchar();
                getchar();
                return;
            }
        }
    }catch(invalid_argument &error){
        cout << error.what() << endl;
    }
}

bool verificarEnLista(dtVideoJuego** list, string nombre){
    int i = 0;
    while(list[i]){
        if(list[i]->getNombreVideojuego() == nombre)
            return true;
        i++;
    }
    return false;
}