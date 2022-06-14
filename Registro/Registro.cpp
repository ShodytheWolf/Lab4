#include "Registro.h"

Registro::Registro(){}
Registro::Registro(float cantHoras,int puntajeJuego){
    this->cantHoras = cantHoras;
    this->puntajeJuego = puntajeJuego;
}
Registro::~Registro(){}
dtVideoJuego Registro::getDtJuego(){
    return this->dtVideoJuego;
}
void Registro::activarSuscripcion(enumSuscripcion tipoSuscripcion,enumPago metodoDePago){

}
void Registro::cancelSuscripcion(){

}
void Registro::eliminoContratacion(){

}
bool Registro::estaSuscrito(){
    
}
