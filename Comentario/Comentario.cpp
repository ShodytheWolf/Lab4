#include "Comentario.h"

Comentario::Comentario()
{

}

Comentario::~Comentario()
{

}

int Comentario::getIdNumerico() {
	return this->idNumerico;
}
void Comentario::setIdNumerico(int idNumerico) {
	this->idNumerico = idNumerico;
}


time_t Comentario::getHoraEnvio() {
	return this->horaEnvio;
}
void Comentario::setHoraEnvio(time_t horaEnvio) {
	this->horaEnvio = horaEnvio;
}

string Comentario::getText() {
	return this->text;
}

void Comentario::setText(string text) {
	this->text = text;
}