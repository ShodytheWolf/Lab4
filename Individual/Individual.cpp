#include "Individual.h"

Individual::Individual()
{

}

Individual::~Individual()
{

}

Individual* Individual::getPartidaContinuada() {
    return this->partidaContinuada;
}

void Individual::setPartidaContinuada(Individual* partidaContinuada) {
    this->partidaContinuada = partidaContinuada;
}