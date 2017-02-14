#include "nombre.h"

Nombre::Nombre(int s, symbole type) : Symbole(type), n(s) {

}

Nombre::~Nombre() {

}

int Nombre::getNombre() const {
    return n;
}

void Nombre::setNombre(int n) {
    this->n = n;
}

string Nombre::print() const {
    stringstream ss;
    ss << this->n;
    return ss.str();
}
