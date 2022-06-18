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


class Controlador {

    public:
        ~Controlador();
        static Controlador* getInstance();
        Usuario* ingresoDatos(string email, string contrasenia);                                //1
        Usuario* ingresarEmpresa(string nombreEmpresa);                                        //2
        bool confirmarNuevoDesarrollador(string email, string contrasenia, string nombreEmpresa);                                               //3
        bool ingresarNickname(char* nickname);                                            //4
        void ingresarDescripcion(char* descripcion);                                      //5
        void confirmarNuevoJugador();                                                     //6
        bool ingresoData(char* email, char* contrasenia);                                 //7
        string** listarCategoriaXNombre();                                                //8
        void confirmar(dtCategoria datosCategoria);                                       //9
        dtCategoria** listarGenero();                                                     //10
        dtCategoria** listarPlataforma();                                                 //11
        dtCategoria** listarOtro();                                                       //12
        void publicarVideojuego(dtVideoJuego datosJuegos,dtCategoria**                    //13
        genero, dtCategoria** plataforma, dtCategoria** otros);                             
        dtVideoJuego** listarVideojuegosDiferenciada();                                   //14
        void ingresarVideojuego(char* nombreVideojuego);                                  //15
        void nuevaSuscripcion(enumPago metodoDePago, enumSuscripcion tipoSuscripcion);    //16
        void darDeBajaSuscripcion();                                                      //17
        dtVideoJuego** listarVideojuegos();                                               //18
        void asignarPuntaje(char* nombreVideojuego, int puntuacion);                      //19
        string** listarVideojuegosSuscripto();                                            //20
        dtPartidaIndividual** listoPartidasInactivas();                                   //21
        void confirmarIndividual(dtPartidaIndividual datosPartida);                       //22
        string** listarNicks(char* nombrejuego);                                          //23
        void confirmarMultijugador (dtPartidaMultijugador datosPartida);                  //24
        dtPartidaMultijugador** listoPartidaMultijugador();                               //25
        void confirmoAbandono(int idPartidaMulti);                                        //26
        dtPartida** listoPartidasActivas();                                               //27
        void seleccionarPartida(int idPartida);                                           //28
        dtVideoJuego** seleccionarVideojuego(char* nombreVideojuego);                     //29
        string** listarVideojuegosPublicados();                                           //30
        void confirmoEliminacion (char* nombreVideojuego);                                //31
        string** listaNombresVideojuegos();                                               //32
        string** mostrarEstadisticas(char* nombreJuego,string** opciones) ;               //33
        void setUsers(OrderedDictionary* usuarios);
        OrderedDictionary* getUsers() const;
                                                                     

    private:
        Controlador();
        static Controlador* instance;
        /*char* emailUser;
        char* passUser;
        char* descripcionJuegador;
        char* nombreEmpresa;
        char* nickJugador;
        char* nombreVideojuego;
        int ultimaIdPartida;
        int ultimaIdComentario;*/

        //colecciones
        OrderedDictionary* usuarios;
        //IDictionary* usuarios = new OrderedDictionary();
        //IDictionary* categorias = new OrderedDictionary();
        //IDictionary* videojuegos = new OrderedDictionary();
    
        Usuario* u;
};
    

#endif
