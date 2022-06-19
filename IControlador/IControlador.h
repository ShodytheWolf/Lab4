#ifndef ICONTROLADOR_H
#define ICONTROLADOR_H
#include "../Datatypes/dtCategoria.h"
#include "../Datatypes/dtPartidaIndividual.h"
#include "../Datatypes/dtPartidaMultijugador.h"
#include "../Enumeration/enumSuscripcion.h"
#include "../Enumeration/enumPago.h"
#include "../Datatypes/dtVideoJuego.h"
#include "../Datatypes/dtJugador.h"
#include <iostream>

using namespace std;
class IControlador{

    private: 

    public:
        virtual ~IControlador();

        virtual void ingresoDatos(string email, string contrasenia) = 0;                                //1
        virtual void ingresarEmpresa(char* nombreEmpresa) = 0;                                        //2
        virtual void confirmarNuevoDesarrollador() = 0;                                               //3
        virtual bool ingresarNickname(char* nickname) = 0;                                            //4
        virtual void ingresarDescripcion(string descripcion) = 0;                                      //5
        virtual void confirmarNuevoJugador() = 0;                                                     //6
        virtual bool ingresoData(string email, string contrasenia) = 0;                                 //7
        virtual string** listarCategoriaXNombre() = 0;                                                //8
        virtual void confirmar(dtCategoria datosCategoria) = 0;                                       //9
        virtual dtCategoria** listarGenero() = 0;                                                         //10
        virtual dtCategoria** listarPlataforma() = 0;                                                     //11
        virtual dtCategoria** listarOtro() = 0;                                                           //12
        virtual void publicarVideojuego(dtVideoJuego datosJuegos,dtCategoria**                          //13
        genero, dtCategoria** plataforma, dtCategoria** otros) = 0;
        virtual dtVideoJuego** listarVideojuegosDiferenciada() = 0;                                   //14
        virtual void ingresarVideojuego(char* nombreVideojuego) = 0;                                  //15
        virtual void nuevaSuscripcion(enumPago metodoDePago, enumSuscripcion tipoSuscripcion) = 0;    //16
        virtual void darDeBajaSuscripcion() = 0;                                                      //17
        virtual dtVideoJuego** listarVideojuegos() = 0;                                               //18
        virtual void asignarPuntaje(char* nombreVideojuego, int puntuacion) = 0;                      //19
        virtual string** listarVideojuegosSuscripto() = 0;                                            //20
        virtual dtPartidaIndividual** listoPartidasInactivas() = 0;                                   //21
        virtual void confirmarIndividual(dtPartidaIndividual datosPartida) = 0;                       //22
        virtual string** listarNicks(char* nombreVideojuego) = 0;                                          //23
        virtual void confirmarMultijugador (dtPartidaMultijugador datosPartida) = 0;                  //24
        virtual dtPartidaMultijugador** listoPartidaMultijugador() = 0;                               //25
        virtual void confirmoAbandono(int idPartidaMulti) = 0;                                        //26
        virtual dtPartida** listoPartidasActivas() = 0;                                               //27
        virtual void seleccionarPartida(int idPartida) = 0;                                           //28
        virtual dtVideoJuego** seleccionarVideojuego(char* nombreVideojuego) = 0;                     //29
        virtual string** listarVideojuegosPublicados() = 0;                                           //30
        virtual void confirmoEliminacion (char* nombreVideojuego) = 0;                                //31
        virtual string** listaNombresVideojuegos() = 0;                                               //32                                                     //32
        virtual string** mostrarEstadisticas(char* nombreVideojuego,string** opciones)  = 0;          //33
                                                                       
        
};


#endif