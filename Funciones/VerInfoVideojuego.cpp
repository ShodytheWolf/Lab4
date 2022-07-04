#include <iostream>
#include "../IControlador/IControlador.h"
#include "../Fabrica/Fabrica.h"

bool verificarEnLista(string**, string);

using namespace std;

void verInformacionVideojuego(){
    Fabrica f;
    IControlador* sistema = f.getInterface();
    string** listaVJ = sistema->listarTodosVJ();
    string nombreVideojuego;
    int i = 0;
    cout << "Por favor elija un Videojuego ingresando su nombre:" <<endl;
    while(listaVJ[i]){
            cout << *listaVJ[i] <<endl;
            i++;
    }
    getchar();
    getline(cin,nombreVideojuego,'\n');
    while(!verificarEnLista(listaVJ, nombreVideojuego)){
        cout << "El juego no existe. Por favor intentelo de nuevo" <<endl;
        getline(cin,nombreVideojuego,'\n');
    }
    dtVideoJuego* listDatos = sistema->seleccionarVideojuego(nombreVideojuego.data());
    cout << "Datos para el videojuego " << listDatos->getNombreVideojuego() << ":\n"
    << "Descripcion: " << listDatos->getDescripcionJuego() <<"\n"
    << "Costos por tipo de suscripcion: \n"
    << "Mensual: " << listDatos->getCostos()->getCostoMensual() << "\n"
    << "Trimestral: " << listDatos->getCostos()->getCostoTrimestral() << "\n"
    << "Anual: " << listDatos->getCostos()->getCostoAnual() << "\n"
    << "Vitalicia: " << listDatos->getCostos()->getCostoVitalicia() << "\n"
    <<endl;
    i=0;
    cout << "Categorias del videojuego: " <<endl;
    while(listDatos->getCategorias()[i]){
        cout << "-" << *listDatos->getCategorias()[i] <<endl;
        i++;
    }
    cout << "Desarrollado por: " << listDatos->getNombreDesarrollador() <<"\n" 
    << "Puntaje promedio: " << listDatos->getPuntajePromedio() <<"\n"
    <<endl;
    //Mando en el datatype un -1 si quien ve la info es un jugador
    //en caso de no ser -1 es un desarrollador por lo que le muestro las horas totales del VJ
    if(listDatos->getHorasTotales() >= 0)
        cout << "Horas totales jugadas: " << listDatos->getHorasTotales() <<endl; 
}