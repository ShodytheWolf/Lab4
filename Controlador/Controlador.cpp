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

void Controlador::ingresoDatos(string email, string contrasenia){
    this->emailUser = email;
    this->passUser = contrasenia;
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
void Controlador::nuevaSuscripcion(enumPago metodoDePago, enumSuscripcion tipoSuscripcion){

}   
void Controlador::darDeBajaSuscripcion(){

}                                                   

string** Controlador::listarVideojuegosSuscripto(){

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

dtVideoJuego** Controlador::seleccionarVideojuego(char* nombreVideojuego){

}                    
string** Controlador::listarVideojuegosPublicados(){

}                                          
void Controlador::confirmoEliminacion (char* nombreVideojuego){

}                               
