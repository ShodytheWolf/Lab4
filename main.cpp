#include <stdlib.h>
#include <iostream>
#include "IControlador/IControlador.cpp"
#include "Fabrica/Fabrica.cpp"

using namespace std;

void menuDesarrollador();

int main(){
    Fabrica* fabrica = new Fabrica();
    IControlador* sistema = fabrica->getInterface();
    menuDesarrollador();
    return 0;
}

void menuDesarrollador(){
    int opcion;
    cout << "Bienvenido al menu de Jugador\n" 
    "Por favor ingrese una opcion:\n" << endl;
    do{
    cout << 
    "1. Agregar categoría\n"
    "2. Publicar videojuego\n"
    "3. Eliminar videojuego\n"
    "4. Seleccionar estadísticas\n"
    "5. Consultar estadísticas\n"
    "6. Ver información de videojuego\n"
    "7. Modificar fecha del sistema\n"
    "8. Salir"
    <<endl;
    cin >> opcion;
    if( opcion < 1 || opcion>8 )
        cout << "Opcion incorrecta\n";
    }while(opcion < 1 || opcion > 8);
}
