#include <iostream>
#include <stdio.h>
#include "../IControlador/IControlador.h"
#include "../Fabrica/Fabrica.h"


using namespace std;

bool verificarCat(string** , string);
bool verificarEnLista(string** , string);
bool verificarCat(dtCategoria** listCat, string categoria);
bool verificarJuego(string** listJuegos, string nombreVideojuego);
void pausa();
void muestroList(dtCategoria** list);

void publicarVideojuego(){

    Fabrica fab;
    IControlador* controlador = fab.getInterface();

    //arr
    dtCategoria** listGeneros;
    dtCategoria** listPlataformas;
    dtCategoria** listOtros;
    string** listaJuegos;

    listaJuegos = controlador->listarTodosVJ();

    string inGgenero = "";
    string inGplataforma = "";
    string inGotros = "";
    float costoAnual;
    float costoMensual;
    float costoTrimestral;
    float costoVitalicia;
    string nombreVideojuego;
    string descripcion;
    char confirmar;

    cout << "|=======================|" << endl;
    cout << " Publicar un videojuego." << endl;
    cout << "|=======================|" << endl;

    cout << "Ingrese nombre del videojuego: " << endl;
    getchar();
    getline(cin,nombreVideojuego,'\n');

    //control de existencia del juego.
    while(verificarJuego(listaJuegos,nombreVideojuego)){
        cout << "El nombre del videojuego ya existe. Intente nuevamente." << endl;
        getline(cin,nombreVideojuego,'\n');
    }

    cout << "Ingrese descripción del videojuego: " << endl;
    getline(cin,descripcion,'\n');

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
    dtSuscripcion* costos = new dtSuscripcion(costoMensual,costoTrimestral, costoAnual, costoVitalicia, enumSuscripcion(NULL));
    pausa();

    //generos
    int i = 0;

   try{
        do{
            cout << "Listado de generos:" << endl;
            listGeneros = controlador->listarGenero();
            if (listGeneros[0] !=NULL){  // si la lista no esta vacia, si tiene algo en la pos 0  
            muestroList(listGeneros); //muestro  
            cout << "Seleccione  un género (sensible a mayúsculas y minúsculas): " << endl;
            getline(cin,inGgenero,'\n');
            system("clear");
                while(!verificarCat(listGeneros, inGgenero)){ //si no existe genero | tengo un problema aca
                    cout << "ingreso2: " << inGgenero << endl;
                    cout << listGeneros[i] << endl;
                    cout << "El género ingresado no existe. Intente nuevamente." << endl;
                    muestroList(listGeneros);
                    cout << "Seleccione un género, recuerde sensibilidad a las mayúsculas y minúsculas: " << endl;
                    getline(cin,inGgenero,'\n');
                    system("clear");
                }
            }
            //si esta vacia tira throw el backend de listarGenero

            dtCategoria* addCatGenero = new dtCategoria(inGgenero, "", Genero); //paso cat al dt
            listGeneros[i] = addCatGenero;
            cout << "¿Desea ingresar otro género? (S/N)" << endl;
            cin >> confirmar;
            getchar();//absorbo lo que esta en inGgenero
            i++;
        }while(confirmar == 'S' || confirmar == 's'); 
        listGeneros[i] = NULL;
        pausa();

        i = 0;
        //plataformas
        do{
            cout << "Listado de plataforma:" << endl;
            listPlataformas = controlador->listarPlataforma(); //listo y muestro
            muestroList(listPlataformas);
            cout << "Seleccione  una plataforma (sensible a mayúsculas y minúsculas): " << endl;
            getline(cin,inGplataforma,'\n');
            system("clear");
            if (listPlataformas[0] != NULL){  
                while(!verificarCat(listPlataformas, inGplataforma)){   //si no existe plataforma 
                    cout << "La plataforma ingresada no existe. Intente nuevamente." << endl;
                    cout << "Seleccione una plataforma, recuerde sensibilidad a las mayúsculas y minúsculas: " << endl;
                    muestroList(listPlataformas);
                    getline(cin,inGplataforma,'\n');
                    system("clear");
                }
            }
            dtCategoria* addCatPlataforma = new dtCategoria(inGplataforma, "", Plataforma); //paso cat al dt esta cat pasa por el control.
            listPlataformas[i] = addCatPlataforma;
            cout << "¿Desea ingresar otra plataforma (S/N) (sensible a mayúsculas y minúsculas)" << endl;
            cin >> confirmar;
            getchar();//absorbo lo que esta en inGgenero
            i++;
        }while(confirmar == 'S'|| confirmar == 's');
        listPlataformas[i] = NULL;
        pausa();

        //otros
        i = 0;
        while(true){
            cout << "Listado de otras categorias: " << endl;
            listOtros = controlador->listarOtro(); //listo y muestro
            muestroList(listOtros);
            cout << "¿Desea seleccionar otros?" << endl;
            cout << "Presione (s/S) para confirmar o (n/N) para cancelar" << endl;
            cin >> confirmar; 
            if (confirmar == 's' || confirmar == 'S' && confirmar != 'n' && confirmar != 'N'){
                cout << "Seleccione una categoría otros (sensible a mayúsculas y minúsculas)" << endl;
                getline(cin,inGotros,'\n');
                system("clear");
                if (listOtros[0] != NULL){
                    while(!verificarCat(listOtros, inGotros)){
                        cout << "La categoría otros- ingresada no existe. Intente nuevamente." << endl;
                        cout << "Seleccione una categoria otros, recuerde sensibilidad a las mayúsculas y minúsculas: " << endl;
                        muestroList(listOtros);
                        getline(cin,inGotros,'\n');
                        system("clear");
                    }
                }
                dtCategoria* addCatOtro = new dtCategoria(inGotros, "", Otro);
                listOtros[i] = addCatOtro;
                i++;
                cout << "¿Desea ingresar otra categoría (S/N)" << endl;
                cin >> confirmar;
                getchar();//absorbo lo que esta en inGgenero
                if (confirmar == 'N'|| confirmar == 'n')
                    break;   
            } 
            else {
                cout << "No seleccionaste otros." << endl;
                break;
            }
        }
        listOtros[i] = NULL;
        pausa();

        cout << "Confirme si desea publicar un videojuego:" << endl;
        cout << "Presione (s/S) para confirmar o cualquier tecla para cancelar." << endl;
        cin >> confirmar;
        if (confirmar == 's' || confirmar == 'S'){
            dtVideoJuego* datosJuegos = new dtVideoJuego(nombreVideojuego,"", descripcion, costos,"",0,0);
            controlador->publicarVideojuego(datosJuegos, listGeneros, listPlataformas, listOtros); //aca esta el drama
            cout << "Publicaste un videojuego." << endl;
        } 
        pausa();

   }catch(invalid_argument &e){
    cout << "error" << endl;
   }
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

bool verificarJuego(string** listJuegos, string nombreVideojuego){
    int i = 0;
    while(listJuegos[i]){
        if(listJuegos[i]->data() == nombreVideojuego)
            return true;
        i++;
    }
    return false;
}

void muestroList(dtCategoria** list){
    int i = 0;
    while (list[i]){
        cout << "Nº " << i+1 << "-" << list[i]->getNombre() << endl;
        ++i; 
    }
}

void pausa(){
    cout << "Presione ENTER para continuar.... " << endl;
    getchar();
    system("clear");
}
