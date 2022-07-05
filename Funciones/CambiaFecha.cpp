#include <iostream> 
#include "../IControlador/IControlador.h"
#include "../Fabrica/Fabrica.h"

using namespace std;

void cambiarFecha(){
    Fabrica f;
    IControlador* sistema = f.getInterface();
    tm fechaHora;
    char op = ' ';
    do{
        cout 
        << "Ingrese una opción numerica:\n"
        << "1-Ver fecha acutal\n" 
        << "2-Cambiar fecha\n"
        << "3-Salir"
        <<endl;
        cin >> op;
        switch(op){
            case '1':
                cout << "Fecha actual: " << ctime(sistema->getFechaSistema()) <<"\n\nPresione <enter>" <<endl;
                getchar();
                getchar();
                break;

            case '2':
                cout <<"Ingrese la fecha:\n" <<endl;
                cout << "Año: "; cin >> fechaHora.tm_year;
                fechaHora.tm_year -= 1900;
                cout << "Mes: "; cin >> fechaHora.tm_mon;
                cout << "Dia: "; cin >> fechaHora.tm_mday;
                cout << "Hora "; cin >> fechaHora.tm_hour;
                sistema->setFechaSistema(fechaHora);
                break;

            case '3':
                cout << "Volviendo al menu principal\n\nPresione <enter> para continuar" <<endl;
                getchar();
                getchar();
                system("clear");
                break;

            default:
                cout << "Opción incorrecta. Intente de nuevo." <<endl;
                break;
        }
    }while(op != '3');
}