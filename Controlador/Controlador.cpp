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

void Controlador::ingresoDatos(char* email, char* contrasenia){
    
}

void Controlador::ingresarEmpresa(char* nombreEmpresa){

}                                       
void Controlador::confirmarNuevoDesarrollador(){

}                                             
bool Controlador::ingresarNickname(char* nickname){

}                                           
void Controlador::ingresarDescripcion(char* descripcion){

}                                     
void Controlador::confirmarNuevoJugador(){

}                                                    
bool Controlador::ingresoData(char* email, char* contrasenia){

}                                
string** Controlador::listarCategoriaXNombre(){

}                                               
void Controlador::confirmar(dtCategoria datosCategoria){

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
dtVideoJuego** Controlador::listarVideojuegos(){

}                                              
void Controlador::asignarPuntaje(char* nombreVideojuego, int puntuacion){

}                     
string** Controlador::listarVideojuegosSuscripto(){

}                                           
dtPartidaIndividual** Controlador::listoPartidasInactivas(){

}                                 
void Controlador::confirmarIndividual(dtPartidaIndividual datosPartida){

}                      
string** Controlador::listarNicks(char* nombrejuego){

}                                        
void Controlador::confirmarMultijugador (dtPartidaMultijugador datosPartida){

}                
dtPartidaMultijugador** Controlador::listoPartidaMultijugador(){

}                              
void Controlador::confirmoAbandono(int idPartidaMulti){

}                                       
dtPartida** Controlador::listoPartidasActivas(){

}                                              
void Controlador::seleccionarPartida(int idPartida){

}                                         
dtVideoJuego** Controlador::seleccionarVideojuego(char* nombreVideojuego){

}                    
string** Controlador::listarVideojuegosPublicados(){

}                                          
void Controlador::confirmoEliminacion (char* nombreVideojuego){

}                               
string** Controlador::listaNombresVideojuegos(){

}

string** Controlador::mostrarEstadisticas(char* nombreJuego,string** opciones){

}           
