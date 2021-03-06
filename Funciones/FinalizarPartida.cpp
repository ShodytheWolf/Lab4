#include "Menus.h"
 #include "../IControlador/IControlador.h"
 #include "../Fabrica/Fabrica.h"
 #include "../bp.cpp"

 Fabrica* fabrica = new Fabrica();
 IControlador* sistema = fabrica->getInterface();

void finalizarPartida(){
    int optFinalizarPartida;
    do{
        bool tabien = false;
        int i = 0;
        int j = 0;
        dtPartida** partidasActivas;
        int idPartidaAFinalizar;

        cout<<"Bienvenido a Finalizar Partida!"<<endl;
 	    cout<<"Seleccione una opcion a continuacion:"<<endl;
 	    cout<<"-------------------------------------"<<endl<<endl;
 	    cout<<"1)Finalizar Partida"<<endl;
 	    cout<<"2)Salir"<<endl;
        cin>>optFinalizarPartida;

        switch (optFinalizarPartida)
        {
        case 1:
            partidasActivas = sistema->listoPartidasActivas();
            

            //entiendo que iteramos ese SET de dtsPartidas para mostrar IDs, Fecha de Comienzo y el nick del juego, y si es Individual, también se muestra
           
            if(!partidasActivas[0]){
                cout<<"No tenes ninguna partida activa"<<endl;
                return;
            };

            while(partidasActivas[i] != NULL){
                time_t horaAMostrar = partidasActivas[i]->getFecha();
                cout<<"\nID: "<<partidasActivas[i]->getIdPartida()<<endl
                
                <<"Fecha de Inicio: "<<ctime(&horaAMostrar)<<endl
                <<"Nombre del videojuego: "<<partidasActivas[i]->getNombreVideojuego()<<endl;

                if (dynamic_cast<dtPartidaIndividual*>(partidasActivas[i]))
                {
                    dtPartidaIndividual* partiBand = dynamic_cast<dtPartidaIndividual*>(partidasActivas[i]);
                    cout<<((partiBand->getContinuacion() ? "Es continuacion":"NO es continuacion"))<<endl;
                }else{
                    dtPartidaMultijugador* partiMulta = dynamic_cast<dtPartidaMultijugador*>(partidasActivas[i]);
                    cout<<((partiMulta->getEnVivo() ? "Es en vivo":"NO es en vivo"))<<endl;

                    cout<<"Jugadores unidos:";
                    j = 0;
                    while(partiMulta->getjugadoresUnidos()[j] != NULL){
                        cout<<*partiMulta->getjugadoresUnidos()[j]<<", "<<endl;
                        j++;
                    }
                };
                i++;

            };

            while(true){
                cout<<"Seleccione la partida que desea finalizar"<<endl;
                cin>>idPartidaAFinalizar;

                i = 0;
                while (partidasActivas[i] != NULL)
                {
                    if(partidasActivas[i]->getIdPartida() == idPartidaAFinalizar){
                        tabien = true;
                    }
                    i++;
                }

                if (tabien)
                {
                    break;
                }
                cout<<"El ID insertado no fue encontrado"<<endl;
            }


            sistema->seleccionarPartida(idPartidaAFinalizar);
            //segun la letra, aca tenemos que dar por finalizada la partida, que conlleva calcular la duracion de la misma en relacion a la fecha del sistema
            //y si es multi, cada jugador se retira a la misma hora c:

            cout<<"Partida finalizada!"<<endl;
            return;
        break;


        case 2:
            return;
        break;
        
        default:
            cout<<"Opcion Invalida"<<endl;
            break;
        }

    }while(optFinalizarPartida != 2);
}