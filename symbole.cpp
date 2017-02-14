#include "symbole.h"

Symbole::Symbole(symbole type) : type(type) {
}

Symbole::~Symbole() {

}

symbole Symbole::getType() const {
    return type;
}

void Symbole::setType(symbole type) {
    this->type = type;
}

string Symbole::print() const {
	switch(type) {
        case ADD : return "+";
        case MUL : return "*";
        case PO : return "(";
        case PF : return ")";
        default : return "ERR";
    }
}

ostream& operator<<(ostream& os, const Symbole& s) {
    os << s.print() << endl;
    return os;
}
