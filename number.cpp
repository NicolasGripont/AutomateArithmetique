#include <sstream>

#include "number.h"

Number::Number(int s, SymbolType type) : Symbol(type), n(s) {

}

Number::~Number() {

}

int Number::getNumber() const {
    return n;
}

void Number::setNumber(int n) {
    this->n = n;
}

string Number::print() const {
    stringstream ss;
    ss << this->n;
    return ss.str();
}
