#include <iostream>
#include <stdio.h>
#include "../IControlador/IControlador.h"
#include "../Fabrica/Fabrica.h"


using namespace std;

bool verificarEnLista(string** , string);

void publicarVideojuego(){

    Fabrica fab;
    IControlador* controlador = fab.getInterface();

    //arr
    dtCategoria** generos;
    dtCategoria** plataformas;
    dtCategoria** otros;
    

    float costoAnual;
    float costoMensual;
    float costoTrimestral;
    float costoVitalicia;
    char* nombreVideojuego;
    string descripcion;
    char confirmar;

    cout << "|=======================|" << endl;
    cout << " Publicar un videojuego." << endl;
    cout << "|=======================|" << endl;

    cout << "Ingrese nombre del videojuego: " << endl;
    cin >> nombreVideojuego;
    cout << "Ingrese descripción del videojuego: " << endl;
    cin >> descripcion;

    cout << "Ingrese costos por tipo de suscripción." << endl;

    cout << "Costo anual: " << endl;
    cin >> costoAnual;
    
    cout << "Costo trimestral: " << endl;
    cin >> costoTrimestral;

    cout << "Costo mensual: " << endl;
    cin >> costoMensual;

    cout << "Costo Vitalicia: " << endl;
    cin >> costoVitalicia;

    //guardar costos 

    cout << "Listado de generos:" << endl;

    dtCategoria** listGeneros = controlador->listarGenero(); 
    int i = 0;
        
    while(listGeneros[i]){
        cout << i+1 << "ª" << listGeneros[i]  << endl;

    }
    cout << "Seleccione  un género" << endl;
    do{
        dtCategoria genero;

        //seleccion
    }while(confirmar == 'p');

    cout << "Listado de plataforma:" << endl;
    dtCategoria** listPlataformas = controlador->listarPlataforma();
    int i = 0;
    while (listPlataformas[i]){
        cout << i+1 << "ª" << listPlataformas[i] << endl; 
    }
    cout << "Seleccione una plataforma" << endl;
    do{
    //seleccion

    }while(confirmar == 'p');

    cout << "Listado de otras categorias: " << endl;
    dtCategoria** listOtros = controlador->listarOtro();
    int i = 0;
    while (listOtros[i]){
        cout << i+1 << "ª" << listOtros[i] <<endl;
    }

    cout << "¿Desea seleccionar otros?" << endl;
    cout << "Presione (s/S) para confirmar o cualquier tecla para cancelar" << endl;
    cin >> confirmar;
    if (confirmar == 's' || confirmar == 'S'){
    cout << "seleccionaste otros" << endl;
    //seleccion.

    } 
    else {
        cout << "No seleccionaste otros." << endl;
    }

    cout << "Confirme si desea publicar un videojuego:" << endl;
    cout << "Presione (s/S) para confirmar o cualquier tecla para cancelar." << endl;
    cin >> confirmar;
    if (confirmar == 's' || confirmar == 'S'){
    cout << "Publicaste un videojuego." << endl;
    dtVideoJuego** datosJuegos;
    //controlador->publicarVideojuego(datosJuegos, categorias); como hacer la seleccion para pasar datos
    } 
    else {
        cout << "cancelaste" << endl;
    }
 
}

bool verificarCat(dtCategoria** listCat, string categoria){
    int i = 0;
    while(listCat[i]){
        if(listCat[i]->getNombre() == categoria)
            return true;
        i++;
    }
    return false;
}