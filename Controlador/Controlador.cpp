#include "Controlador.h"
#include <iostream>
#include <stdlib.h>

Controlador* Controlador::instance = nullptr;


Controlador::~Controlador(){

}

Controlador::Controlador(){

}

Controlador* Controlador::getInstance(){
    if( instance == nullptr ){
        instance = new Controlador();
    }
    return instance;
}

// bool Controlador::ingresoData(string email){

// }
string** Controlador::jugadores(){

}

void Controlador::ingresarEmpresa(char* nombreEmpresa){
    this->nombreEmpresa = String(nombreEmpresa);

}                                       
void Controlador::confirmarNuevoDesarrollador(){

}                                             
bool Controlador::ingresarNickname(char* nickname){

}                                           
void Controlador::ingresarDescripcion(string descripcion){

}                                     
void Controlador::confirmarNuevoJugador(){

}                                                    
bool Controlador::ingresoData(string email, string contrasenia){

}

void Controlador::confirmarSesion(){

}

dtCategoria** Controlador::listarGenero(){

}                                                   
dtCategoria** Controlador::listarPlataforma(){

}                                                
dtCategoria** Controlador::listarOtro(){

}                                                      
void Controlador::publicarVideojuego(dtVideoJuego datosJuegos,dtCategoria**                    
genero, dtCategoria** plataforma, dtCategoria** otros){

}                            
dtVideoJuego** Controlador::listarVideojuegosDiferenciada(){

}                                 
void Controlador::ingresarVideojuego(char* nombreVideojuego){

}
bool Controlador::estaSuscripto(char* nombreVideojuego){
    
}                                 
void Controlador::nuevaSuscripcion(enumPago metodoDePago, enumSuscripcion tipoSuscripcion){

}   
void Controlador::darDeBajaSuscripcion(){

}                                                   

string** Controlador::listarVideojuegosSuscripto(){
        
    /*
    if(dynamic_cast<Jugador*>(this->loggedUser)){

        string** lista = new string*[3];

    }else{
        throw invalid_argument("Usuario loggeado no es jugador!");
    }*/
    

}                                           
dtPartidaIndividual** Controlador::listoPartidasInactivas(){

}                                 
void Controlador::confirmarIndividual(dtPartidaIndividual datosPartida){

}                      
string** Controlador::listarNicks(char* nombreVideojuego){

}                                        
void Controlador::confirmarMultijugador (dtPartidaMultijugador datosPartida){

}                

dtPartida** Controlador::listoPartidasActivas(){

}                                              
void Controlador::seleccionarPartida(int idPartida){

}

string** Controlador::listarTodosVJ(){

}

dtVideoJuego* Controlador::seleccionarVideojuego(char* nombreVideojuego){

}                    
string** Controlador::listarVideojuegosPublicados(){
    //string** lista = new string*[aca pones el maximo de vj en sistema]
    //aca inicializas 
    //y despues cargas la lista
    //return lista; 

}                                          
void Controlador::confirmoEliminacion (char* nombreVideojuego){

}                               
