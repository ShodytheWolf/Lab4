#include "Menus.h"

void finalizarPartida(){
    int optFinalizarPartida;
    do{
        cout<<"Bienvenido a Finalizar Partida!"<<endl;
 	    cout<<"Seleccione una opcion a continuacion:"<<endl;
 	    cout<<"-------------------------------------"<<endl<<endl;
 	    cout<<"1)Finalizar Partida"<<endl;
 	    cout<<"2)Salir"<<endl;
        cin>>optFinalizarPartida;

        switch (optFinalizarPartida)
        {
        case 1:
            //SET<dtPartida> = listarPartidasActivas();
            int idPartidaAFinalizar;

            //entiendo que iteramos ese SET de dtsPartidas para mostrar IDs, Fecha de Comienzo y el nick del juego, y si es Individual, también se muestra

            //if(dtPartida == NULL){
                //return;
            //}else{

                //if(dtPartida->continuacion){
                    //mostramos el id de la partida anterior, junto con la respectiva info
            // }else{
                // if(dtPartida es multi xD){
                        //mostramos la respectiva info, incluyendo si es transmitida en Vivo o no, junto con los nicks de los ñerys que se unieron.
                //}else{
                        //es indi pero sin continuar, de vuelta mostramos la respectiva info
                    //}
                //}
             //}
            cout<<"Seleccione la partida que desea finalizar :3"<<endl;
            cin>>idPartidaAFinalizar;
            //CHECKAR QUE EL JUGADOR META BIEN LAS IDs
            //CHECKAR QUE EL JUGADOR META BIEN LAS IDs
            //CHECKAR QUE EL JUGADOR META BIEN LAS IDs
            //CHECKAR QUE EL JUGADOR META BIEN LAS IDs
            //CHECKAR QUE EL JUGADOR META BIEN LAS IDs

            //sistema->seleccionarPartida(idPartidaAFinalizar); uwuwuwuwuwu
            //segun la letra, aca tenemos que dar por finalizada la partida, que conlleva calcular la duracion de la misma en relacion a la fecha del sistema
            //y si es multi, cada jugador se retira a la misma hora c:
            cout<<"Partida finalizada! :D"<<endl;
        break;


        case 2:
            return;
        break;
        
        default:
            cout<<"OpciOwOn Invalida"<<endl;
            break;
        }

    }while(optFinalizarPartida != 2);
}