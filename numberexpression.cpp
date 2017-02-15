#include <sstream>

#include "numberexpression.h"

NumberExpression::NumberExpression(const int v) : Expression(), value(v)
{
}


NumberExpression::~NumberExpression()
{
}

int NumberExpression::eval() {
    return this->value;
}

string NumberExpression::print() const{
    stringstream ss;
    ss << "E(" << this->value << ")";
    return ss.str();
}
