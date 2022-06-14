#include "Categoria.h"

Categoria::Categoria(char* nombreCategoria, char* descripcionCategoria, enumCategoria tipoCategoria)
{
    this->nombreCategoria = nombreCategoria;
    this->descripcionCategoria = descripcionCategoria;
    this->tipoCategoria = tipoCategoria;
}

Categoria::~Categoria()
{

}

char* Categoria::getNombreCategoria() {
    return this->nombreCategoria;
}

void Categoria::setNombreCategoria(char* nombreCategoria) {
    this->nombreCategoria = nombreCategoria;
}

char* Categoria::getDescripcionCategoria() {
    return this->descripcionCategoria;
}

void Categoria::setDescripcionCategoria(char* descripcionCategoria) {
    this->descripcionCategoria = descripcionCategoria;
}

enumCategoria Categoria::getTipoCategoria() {
	return this->tipoCategoria;
}

void Categoria::setTipoCategoria(enumCategoria tipoCategoria) {
	this->tipoCategoria = tipoCategoria;
}