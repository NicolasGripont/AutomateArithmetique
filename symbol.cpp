#include "symbol.h"

Symbol::Symbol(SymbolType type) : type(type) {
}

Symbol::~Symbol() {

}

SymbolType Symbol::getType() const {
    return type;
}

void Symbol::setType(SymbolType type) {
    this->type = type;
}

string Symbol::print() const {
	switch(type) {
        case ADD : return "+";
        case MUL : return "*";
        case PO : return "(";
        case PF : return ")";
        case END : return "$";
        default : return "ERR";
    }
}

ostream& operator<<(ostream& os, const Symbol& s) {
    os << s.print() << endl;
    return os;
}
