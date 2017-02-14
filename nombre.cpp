#include "nombre.h"

Nombre::Nombre(int s, nombre type) : Symbole(), type(type), n(s) {
}

Nombre::~Nombre() {

}

nombre Nombre::getType() const {
    return type;
}

int Nombre::getNombre() const {
    return n;
}

void Nombre::setType(nombre type) {
    this->type = type;
}

void Nombre::setNombre(int n) {
    this->n = n;
}

string Nombre::print() const {
    stringstream ss;
    ss << this->n;
    return ss.str();
}
