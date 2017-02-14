#include "expression.h"

Expression::Expression(char c) : Symbole() {
    this->setType(c);
}

Expression::~Expression() {

}

expression Expression::getType() const {
    return type;
}

void Expression::setType(char c) {
    switch(c) {
        case '+' : type = ADD; break;
        case '*' : type = MUL; break;
        case '(' : type = PO; break;
        case ')' : type = PF; break;
        default: type = ERR;
    }
}

string Expression::print() const {
    switch(type) {
        case ADD : return "+";
        case MUL : return "*";
        case PO : return "(";
        case PF : return ")";
        default : return "ERR";
    }
}
