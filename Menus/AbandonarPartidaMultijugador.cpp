#include "Menus.h"

void menuAbandonarPartidaMultijugador(){
    int optAbandonarPartida;
    do{
        cout<<"Bienvenido a Abandonar Partida Multijogador!"<<endl;
 	    cout<<"Seleccione una opcion a continuacion:"<<endl;
 	    cout<<"-------------------------------------"<<endl<<endl;
 	    cout<<"1)Listar Videojuegos Suscriptos"<<endl;
 	    cout<<"2)Salir"<<endl;
 	    cin>>optAbandonarPartida;

        switch (optAbandonarPartida)
        {
        case 1:
            int idPartidaMulti;
           /*SET<dtPartidaMultijugador> = listoPartidaMultijugador(); conseguimos todas las partidas multis que el jugador se ha unido, pero no finalizado.
            entiendo que luego iteramos para mostrar esas partidas, incluyiendo el id, fecha y hora de comienzo, nombre del videojogo y es en vivo.
            cout<<"Ingrese el ID de la partida que desea abandonar"<<endl;*/
            cin>>idPartidaMulti;
            //confirmoAbandono(idPartidaMulti); listo el pollo!
            cout<<"Se abandono la partida con exito"<<endl;
        break;
        
        case 2:
            return;
        break;


        default:
            cout<<"opciOwOn invalida"<<endl;
        break;
        }

    }while(optAbandonarPartida != 2);
};