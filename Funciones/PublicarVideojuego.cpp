#include <iostream>
#include <stdio.h>
#include "../IControlador/IControlador.h"
#include "../Fabrica/Fabrica.h"


using namespace std;

bool verificarCat(string** , string);
bool verificarEnLista(string** , string);
bool verificarCat(dtCategoria** listCat, string categoria);
void pausa();
void muestroList(dtCategoria** list);

void publicarVideojuego(){

    Fabrica fab;
    IControlador* controlador = fab.getInterface();

    //arr
    dtCategoria** listGeneros;
    dtCategoria** listPlataformas;
    dtCategoria** listOtros;
    
    string inGgenero;
    string inGplataforma;
    string inGotros;
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
    dtSuscripcion* costos = new dtSuscripcion(costoMensual,costoTrimestral, costoAnual, costoVitalicia);
    pausa();

    //generos
    int i = 0;
    do{
        cout << "Listado de generos:" << endl;
        listGeneros = controlador->listarGenero();
        muestroList(listGeneros); //muestro  
        cout << "Seleccione  un género (sensible a mayúsculas y minúsculas): " << endl;
        cin >> inGgenero;
        system("clear");
        if (listGeneros[0] !=NULL){   
            while(!verificarCat(listGeneros, inGgenero)){ //si no existe genero
                cout << "El género ingresado no existe. Intente nuevamente." << endl;
                muestroList(listGeneros);
                cout << "Seleccione un género, recuerde sensibilidad a las mayúsculas y minúsculas: " << endl;
                cin >> inGgenero;
                system("clear");
            }
        }
        
        dtCategoria* addCatGenero = new dtCategoria(inGgenero, NULL, Genero); //paso cat al dt
        listGeneros[i] = addCatGenero;
        cout << "¿Desea ingresar otro género? (S/N)" << endl;
        cin >> confirmar;
        i++;
    }while(confirmar == 'S'); 
    listGeneros[i+1] = NULL;
    pausa();

    i = 0;
    //plataformas
    do{
        cout << "Listado de plataforma:" << endl;
        listPlataformas = controlador->listarPlataforma(); //listo y muestro
        muestroList(listPlataformas);
        cout << "Seleccione  una plataforma (sensible a mayúsculas y minúsculas): " << endl;
        cin >> inGplataforma;
        system("clear");
        if (listPlataformas[0] != NULL){  
            while(!verificarCat(listPlataformas, inGplataforma)){   //si no existe plataforma 
                cout << "La plataforma ingresada no existe. Intente nuevamente." << endl;
                cout << "Seleccione una plataforma, recuerde sensibilidad a las mayúsculas y minúsculas: " << endl;
                muestroList(listPlataformas);
                cin >> inGplataforma;
                system("clear");
            }
        }
        int i = 0;
        dtCategoria* addCatPlataforma = new dtCategoria(inGplataforma, NULL, Plataforma); //paso cat al dt esta cat pasa por el control.
        listPlataformas[i] = addCatPlataforma;
        cout << "¿Desea ingresar otro género? (S/N)" << endl;
        cin >> confirmar;
    }while(confirmar == 'S');
    listPlataformas[i+1] = NULL;
    pausa();

    //otros
    i = 0;
    while(true){
        cout << "Listado de otras categorias: " << endl;
        listOtros = controlador->listarOtro(); //listo y muestro
        muestroList(listOtros);
        cout << "¿Desea seleccionar otros?" << endl;
        cout << "Presione (s/S) para confirmar o cualquier tecla para cancelar" << endl;
        cin >> confirmar;
        if (confirmar == 's' || confirmar == 'S'){
            cout << "Seleccione una categoría otros" << endl;
            cin >> inGotros;
            system("clear");
            if (listOtros[0] != NULL){
                while(!verificarCat(listOtros, inGotros)){
                    cout << "La categoría otros- ingresada no existe. Intente nuevamente." << endl;
                    cout << "Seleccione una categoria otros, recuerde sensibilidad a las mayúsculas y minúsculas: " << endl;
                    muestroList(listOtros);
                    cin >> inGotros;
                    system("clear");
                }
            }
            dtCategoria* addCatOtro = new dtCategoria(inGotros, NULL, Otro);
            listOtros[i] = addCatOtro;
            cout << "¿Desea ingresar otro género? (S/N)" << endl;
            if (confirmar == 'N')
                break;   
        } 
        else {
            cout << "No seleccionaste otros." << endl;
        }
    }
    listOtros[i+1] = NULL;
    pausa();


    cout << "Confirme si desea publicar un videojuego:" << endl;
    cout << "Presione (s/S) para confirmar o cualquier tecla para cancelar." << endl;
    cin >> confirmar;
    if (confirmar == 's' || confirmar == 'S'){
    cout << "Publicaste un videojuego." << endl;
    dtVideoJuego* datosJuegos = new dtVideoJuego(nombreVideojuego, NULL, descripcion, costos, NULL,0,0);
    controlador->publicarVideojuego(datosJuegos, listGeneros, listPlataformas, listOtros);
    } 
    else {
        cout << "cancelaste" << endl;
    }
    pausa();
}

//auxiliares
bool verificarCat(dtCategoria** listCat, string categoria){
    int i = 0;
    while(listCat[i]){
        if(listCat[i]->getNombre() == categoria)
            return true;
        i++;
    }
    return false;
}

void muestroList(dtCategoria** list){
    int i = 0;
    while (list[i]){
        cout << "Nº " <<i+1 << "-" << list[i] << endl; 
    }
}

void pausa(){
    cout << "Presione ENTER para continuar.... " << endl;
    getchar();
    getchar();
    system("clear");
}
