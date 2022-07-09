#ifndef ICONTROLADOR_H
#define ICONTROLADOR_H
#include <ctime>
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

        //Alta Usuario:
        //virtual bool ingresoData(string email) = 0;                                //1
        virtual string** jugadores() = 0;
        virtual void ingresarEmpresa(const char* nombreEmpresa) = 0;                                        //2
        virtual void confirmarNuevoDesarrollador() = 0;                                               //3
        virtual bool ingresarNickname(const char* nickname) = 0;                                            //4
        virtual void ingresarDescripcion(string descripcion) = 0;                                      //5
        virtual void confirmarNuevoJugador() = 0;                                                      //6

        //Iniciar sesion:
        virtual bool ingresoData(string email, string contrasenia, bool) = 0;                                //7
        virtual char confirmarSesion() = 0;


        //Publicar Videojuego:
        virtual dtCategoria** listarGenero() = 0;                                                     //10
        virtual dtCategoria** listarPlataforma() = 0;                                                 //11
        virtual dtCategoria** listarOtro() = 0;                                                       //12
        virtual void publicarVideojuego(dtVideoJuego* datosJuegos,dtCategoria**                    //13
        genero, dtCategoria** plataforma, dtCategoria** otros) = 0;

        //Suscribirse a Videojuego:
        virtual dtVideoJuego** listarVideojuegosDiferenciada() = 0;                                   //14
        virtual void ingresarVideojuego(const char* nombreVideojuego) = 0;                                  //15
        virtual bool estaSuscripto(const char* nombreVideojuego) = 0;
        virtual void nuevaSuscripcion(enumPago metodoDePago, enumSuscripcion tipoSuscripcion) = 0;    //16
        virtual void darDeBajaSuscripcion() = 0;                                                      //17

        //Iniciar Partida:
        virtual string** listarVideojuegosSuscripto() = 0;                                            //20
        virtual dtPartidaIndividual** listoPartidasInactivas() = 0;                                   //21
        virtual int confirmarIndividual(dtPartidaIndividual *datosPartida) = 0;                       //22
        virtual string** listarNicks(string nombreVideojuego) = 0;                                          //23
        virtual int confirmarMultijugador(dtPartidaMultijugador *datosPartida) = 0;                  //24
        
        //Finalizar Partida:
        virtual dtPartida** listoPartidasActivas() = 0;                                               //27
        virtual void seleccionarPartida(int idPartida) = 0;                                           //28

        //Ver info Videojuego:
        virtual string** listarTodosVJ() = 0;
        virtual dtVideoJuego* seleccionarVideojuego(const char* nombreVideojuego) = 0;                     //29

        //Eliminar Videojuego
        virtual string** listarVideojuegosPublicados() = 0;                                           //30
        virtual void confirmoEliminacion (const char* nombreVideojuego) = 0;                                //31
        
        //Agregar Categoria:
        virtual void nuevaCategoria(const char*, string, enumCategoria) =0;                                                                              

        //Asignar Puntaje
        virtual void asignarPuntaje(const char*, int) = 0;

        //Cambiar fecha del sistema
        virtual void setFechaSistema(tm) = 0;
        virtual time_t* getFechaSistema() = 0; 

};


#endif