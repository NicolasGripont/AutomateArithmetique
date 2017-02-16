#include <sstream>

#include "simpleexpression.h"

SimpleExpression::SimpleExpression(Expression* e) : Expression(), expression(e)
{
}

SimpleExpression::~SimpleExpression()
{
    if(expression != nullptr) {
        delete expression;
    }
}

int SimpleExpression::eval() {
    return this->expression->eval();
}

string SimpleExpression::print() const{
    stringstream ss;
    ss << "E(" << this->expression->print()  << ")";
    return ss.str();
}
