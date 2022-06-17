#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include "../Datatypes/dtCategoria.h"
#include "../Datatypes/dtPartidaIndividual.h"
#include "../Datatypes/dtPartidaMultijugador.h"
#include "../Enumeration/enumPago.h"
#include "../Enumeration/enumSuscripcion.h"
#include "../IControlador/IControlador.h"
#include "../colecciones-genericas/interfaces/ICollection.h"
#include "../colecciones-genericas/collections/OrderedDictionary.h"
#include "../colecciones-genericas/interfaces/IDictionary.h"


class Controlador: public IControlador{

    public:
        ~Controlador();
        static Controlador* getInstance();
        void holaMundo();
        // void ingresoDatos(char* email, char* contrasenia);              //1
        // void ingresarEmpresa(char* nombreEmpresa);                      //2
        // void confirmarNuevoDesarrollador();                             //3
        // bool ingresarNickname(char* nickname);                          //4
        // void ingresarDescripcion(char* descripcion);                    //5
        // void confirmarNuevoJugador();                                   //6
        // bool ingresoData(char* email, char* contrasenia);              //7
        // void listarCategoriaXNombre(); //SET <string>                   //8
        // void confirmar(dtCategoria datosCategoria);                    //9
        // void listarGenero(); //SET <dtCategoria>                       //10
        // void listarPlataforma(); //SET <dtCategoria>                   //11
        // void listarOtro(); //SET <dtCategoria>                         //12
        // // void publicarVideojuego(dtVideojuego datosJuegos,SET <dtGenero>   //13
        // //genero, SET<dtCategoria> plataforma, SET <dtCategoria> otros)
        // void listarVideojuegosDiferenciada(); //SET <dtVideojuego>                  //14
        // void ingresarVideojuego(char* nombreVideojuego);                //15
        // void nuevaSuscripcion(enumPago metodoDePago, enumSuscripcion tipoSuscripcion); //16
        // void darDeBajaSuscripcion();                                    //17
        // void listarVideojuegos(); //SET <dtVideojuego>                  //18
        // void asignarPuntaje(char* nombreVideojuego, int puntuacion);    //19
        // void listarVideojuegosSuscripto(); //SET <string>               //20
        // void listoPartidasInactivas(); //SET <dtPartidaIndividual>      //21
        // void confirmarIndividual(dtPartidaIndividual datosPartida);     //22
        // // SET<string> listarNicks(char* nombrejuego);                   //23
        // void confirmarMultijugador (dtPartidaMultijugador datosPartida);//24
        // // SET<dtPartidaMultijugador> listoPartidaMultijugador();        //25
        // void confirmoAbandono(int idPartidaMulti);                      //26
        // // SET<dtPartida> listoPartidasActivas();                        //27
        // void seleccionarPartida(int idPartida);                         //28
        // void enviaComentario(char* comentario);                         //29
        // //void SET <dtComentario> listarComentariosExistentes();          //30
        // void enviaComentario(int id, char* comentario);                         //31
        // // SET<dtVideojuego> seleccionarVideojuego(char* nombreVideojuego); //32
        // // SET <dtJugador> listarJugadores();                            //33
        // void seleccionarJugador(char* nickname);                        //34
        // // SET<string> listarVdeiojuegosPublicados();                    //35
        // void confirmoEliminacion (char* nombreVideojuego);              //36
        // // SET<string> listarVideojuegos();                              //37
        // // SET<dtEstadistica> mostrarEstadisticas(char* nombreJuego,
        // //SET<string> opciones);                                                //38

    private:
        Controlador();
        static Controlador* instance;
        char* emailUser;
        char* passUser;
        char* descripcionJuegador;
        char* nombreEmpresa;
        char* nickJugador;
        char* nombreVideojuego;
        int ultimaIdPartida;
        int ultimaIdComentario;

        //colecciones
        ICollection* usuarios;
        IDictionary* categorias = new OrderedDictionary();
        IDictionary* videojuegos = new OrderedDictionary();
};
    

#endif