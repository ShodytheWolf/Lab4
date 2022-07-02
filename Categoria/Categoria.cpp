#include "Categoria.h"

Categoria::Categoria(const char* nombreCategoria, string descripcionCategoria, enumCategoria tipoCategoria)
{
    setNombreCategoria(nombreCategoria);
    this->descripcionCategoria = descripcionCategoria;
    this->tipoCategoria = tipoCategoria;
}

Categoria::~Categoria()
{

}

String* Categoria::getNombreCategoria() {
    return this->nombreCategoria;
}

void Categoria::setNombreCategoria(const char* nombreCategoria) {
    this->nombreCategoria = new String(nombreCategoria);
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

dtCategoria* Categoria::getDtGenero(){
    dtCategoria* genero = new dtCategoria(string(this->nombreCategoria->getValue()), this->descripcionCategoria, Genero);
    return genero;
}
dtCategoria* Categoria::getDtPlataforma(){
    dtCategoria* plataforma = new dtCategoria(string(this->nombreCategoria->getValue()), this->descripcionCategoria, Plataforma);
    return plataforma;
}
dtCategoria* Categoria::getDtOtro(){
    dtCategoria* otro = new dtCategoria (string(this->nombreCategoria->getValue()), this->descripcionCategoria, Otro);
    return otro;
}