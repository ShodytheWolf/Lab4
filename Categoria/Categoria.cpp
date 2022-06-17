#include "Categoria.h"

Categoria::Categoria(char* nombreCategoria, string descripcionCategoria, enumCategoria tipoCategoria)
{
    this->nombreCategoria = String(nombreCategoria);
    this->descripcionCategoria = descripcionCategoria;
    this->tipoCategoria = tipoCategoria;
}

Categoria::~Categoria()
{

}

String Categoria::getNombreCategoria() {
    return this->nombreCategoria;
}

void Categoria::setNombreCategoria(char* nombreCategoria) {
    this->nombreCategoria = String(nombreCategoria);
}

string Categoria::getDescripcionCategoria() {
    return this->descripcionCategoria;
}

void Categoria::setDescripcionCategoria(string descripcionCategoria) {
    this->descripcionCategoria = descripcionCategoria;
}

enumCategoria Categoria::getTipoCategoria() {
	return this->tipoCategoria;
}

void Categoria::setTipoCategoria(enumCategoria tipoCategoria) {
	this->tipoCategoria = tipoCategoria;
}