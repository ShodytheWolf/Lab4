#ifndef ICONTROLADOR_H
#define ICONTROLADOR_H
#include "../Datatypes/dtCategoria.h"
#include "../Datatypes/dtPartidaIndividual.h"
#include "../Datatypes/dtPartidaMultijugador.h"
#include "../Enumeration/enumSuscripcion.h"
#include "../Enumeration/enumPago.h"


class IControlador{

    private: 

    public:

        virtual void ingresoDatos(char* email, char* contrasenia) = 0;              //1
        virtual void ingresarEmpresa(char* nombreEmpresa) = 0;                      //2
        virtual void confirmarNuevoDesarrollador() = 0;                             //3
        virtual bool ingresarNickname(char* nickname) = 0;                          //4
        virtual void ingresarDescripcion(char* descripcion) = 0;                    //5
        virtual void confirmarNuevoJugador() = 0;                                   //6
        virtual void ingresoDatos(char* email, char* contrasenia) = 0;              //7
        virtual void listarCateogriaXNombre() = 0; //SET <string>                   //8
        virtual void confirmar(dtCategoria datosCategoria) =  0;                    //9
        virtual void listarGenero() =  0; //SET <dtCategoria>                       //10
        virtual void listarPlataforma() =  0; //SET <dtCategoria>                   //11
        virtual void listarOtro() =  0; //SET <dtCategoria>                         //12
        //virtual void publicarVideojuego(dtVideojuego datosJuegos,SET <dtGenero>   //13
        //genero, SET<dtCategoria> plataforma, SET <dtCategoria> otros)
        virtual void listarVideojuegos() = 0; //SET <dtVideojuego>                  //14
        virtual void ingresarVideojuego(char* nombreVideojuego) = 0;                //15
        virtual void nuevaSuscripcion(enumPago metodoDePago, enumSuscripcion tipoSuscripcion) = 0; //16
        virtual void darDeBajaSuscripcion() = 0;                                    //17
        virtual void listarVideojuegos() = 0; //SET <dtVideojuego>                  //18
        virtual void asignarPuntaje(char* nombreVideojuego, int puntuacion) = 0;    //19
        virtual void listarVideojuegosSuscripto() = 0; //SET <string>               //20
        virtual void listoPartidasInactivas() = 0; //SET <dtPartidaIndividual>      //21
        virtual void confirmarIndividual(dtPartidaIndividual datosPartida) = 0;     //22
        //virtual SET<string> listarNicks(char* nombrejuego) = 0;                   //23
        virtual void confirmarMultijugador (dtPartidaMultijugador datosPartida) = 0;//24
        //virtual SET<dtPartidaMultijugador> listoPartidaMultijugador() = 0;        //25
        virtual void confirmoAbandono(int idPartidaMulti) = 0;                      //26
        //virtual SET<dtPartida> listoPartidasActivas() = 0;                        //27
        virtual void seleccionarPartida(int idPartida) = 0;                         //28
        virtual void enviaComentario(char* comentario) = 0;                         //29
        //virtual void SET <dtComentario> listarComentariosExistentes() = 0;          //30
        virtual void enviaComentario(int id, char* comentario) = 0;                         //31
        //virtual SET<dtVideojuego> seleccionarVideojuego(char* nombreVideojuego)=0; //32
        //virtual SET <dtJugador> listarJugadores() = 0;                            //33
        virtual void seleccionarJugador(char* nickname) = 0;                        //34
        //virtual SET<string> listarVdeiojuegosPublicados() = 0;                    //35
        virtual void confirmoEliminacion (char* nombreVideojuego) = 0;              //36
        //virtual SET<string> listarVideojuegos() = 0;                              //37
        //virtual SET<dtEstadistica> mostrarEstadisticas(char* nombreJuego,
        //SET<string> opciones) = 0;                                                //38
        
        virtual ~IControlador();

};


#endif