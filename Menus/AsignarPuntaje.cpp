#include "../Menus/Menus.h"

void asignarPuntajeAVideojuego(){ //caso de uso 6
    int opcion = 0;
    do{
        cout << "|===============================|" << endl;
        cout << " Asignar puntaje a un videjuego." << endl;
        cout << "|===============================|" << endl;

        cout << "1- ListarVideojuegos." << endl;
        cout << "2- Asignar puntaje." << endl;
        cout << "3- Salir." << endl;
        cin >> opcion;
        system("clear");

        try{
            switch(opcion){
                case 1:
                    cout << "Entraste a listarVideojuegos:" << endl;
                    return;
                    //listarVideojuegos();
                    break;
                case 2:
                    cout << "Entraste a asignar puntaje" << endl;
                    //char* nombreVideojuego;
                    //int puntuacion;
                    //cout << "Ingrese nombre del videojuego: " << endl;
                    //cin >> nombreVideojuego;
                    //cout << "Ingrese puntuación del videojuego: " << endl;
                    //cin >> puntuacion;
                    //asignarPuntaje(nombreVideojuego, puntuacion);
                    break;
                case 3:
                    cout << "Entraste a salir" << endl;
                break;
                default:
                    cout << "Opción incorrecta. Presione ENTER tecla para continuar nuevamente." << endl;
                    getchar();
                    getchar();
                    system("clear");
                break;
            }
        }
        catch(invalid_argument& error){
        cout << error.what();
        }
    } while(opcion >= 1 || opcion <= 3);

}