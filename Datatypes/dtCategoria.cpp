#include "dtCategoria.h"

dtCategoria::dtCategoria(string nombreCons, string desc, enumCategoria tipoCons){
    this->nombre = nombreCons;
    this->descripcion = desc;
    this->tipo = tipoCons;
};

dtCategoria::~dtCategoria(){

};

string dtCategoria::getDescripcion(){
    return this->descripcion;
};

string dtCategoria::getNombre(){
    return this->nombre;
};

enumCategoria dtCategoria::getTipo() {
	return this->tipo;
}
