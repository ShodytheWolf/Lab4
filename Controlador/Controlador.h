#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "../IControlador/IControlador.h"
#include "../Usuario/Usuario.h"
#include "../Jugador/Jugador.h"
#include "../Categoria/Categoria.h"
#include "../Videojuego/Videojuego.h"

class Controlador: public IControlador{

    public:
        ~Controlador();
        static Controlador* getInstance(); 

        //Alta Usuario:
        //bool ingresoData(string email);                                                   //1
        string** jugadores(); 
        //en vez de ingresoDatos, usar ingreso data (op 7) que ya guarda el email y contrasenia y devuelve true 
        //si ya existe el usuario
        bool ingresoData(string email);                                                   //1 
        void ingresarEmpresa(const char* nombreEmpresa);                                        //2
        void confirmarNuevoDesarrollador();                                               //3
        bool ingresarNickname(const char* nickname);                                            //4
        void ingresarDescripcion(string descripcion);                                      //5
        void confirmarNuevoJugador();                                                      //6

        //Iniciar sesion:
        bool ingresoData(string email, string contrasenia, bool);                                //7
        char confirmarSesion();

        //Publicar Videojuego:
        dtCategoria** listarGenero();                                                     //10
        dtCategoria** listarPlataforma();                                                 //11
        dtCategoria** listarOtro();                                                       //12
        void publicarVideojuego(dtVideoJuego* datosJuegos,dtCategoria**                    //13
        genero, dtCategoria** plataforma, dtCategoria** otros);

        //Suscribirse a Videojuego:
        dtVideoJuego** listarVideojuegosDiferenciada();                                   //14
        void ingresarVideojuego(const char* nombreVideojuego);                                  //15
        bool estaSuscripto(const char* nombreVideojuego); //nueva
        void nuevaSuscripcion(enumPago metodoDePago, enumSuscripcion tipoSuscripcion);    //16
        void darDeBajaSuscripcion();                                                      //17

        //Iniciar Partida:
        string** listarVideojuegosSuscripto();                                            //20
        dtPartidaIndividual** listoPartidasInactivas();                                   //21
        void confirmarIndividual(dtPartidaIndividual *datosPartida);                       //22
        string** listarNicks(string nombreVideojuego);                                     //23
        void confirmarMultijugador (dtPartidaMultijugador *datosPartida);                  //24
        
        //Finalizar Partida:
        dtPartida** listoPartidasActivas();                                               //27
        void seleccionarPartida(int idPartida);                                           //28

        //Ver info Videojuego:
        string** listarTodosVJ();
        dtVideoJuego* seleccionarVideojuego(const char* nombreVideojuego);                     //29

        //Eliminar Videojuego
        string** listarVideojuegosPublicados();                                           //30
        void confirmoEliminacion (const char* nombreVideojuego);                                //31
        
        //Agregar Categoria:
        void nuevaCategoria(const char*, string, enumCategoria);

        //Asignar Puntaje
        void asignarPuntaje(const char*, int);

        //Cambiar fecha del sistema
        time_t* getFechaSistema();
        void setFechaSistema(tm);


    private:
        Controlador();
        static Controlador* instance;
        string emailUser;
        string passUser;
        string descripcionJuegador;
        const char* nombreEmpresa;
        const char* nickJugador;
        const char* nombreVideojuego;
        unsigned int ultimaIdPartida = 0;
        unsigned int ultimaIdComentario = 0;
        time_t horaActual = time(NULL);

        //pseudoatributos
        Usuario* loggedUser;

        //colecciones
        IDictionary* usuarios = new OrderedDictionary();
        IDictionary* categorias = new OrderedDictionary();
        IDictionary* videojuegos = new OrderedDictionary();
};
    

#endif