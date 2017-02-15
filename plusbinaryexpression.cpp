#include <sstream>

#include "plusbinaryexpression.h"

PlusBinaryExpression::PlusBinaryExpression(Expression* el, Expression* er) : BinaryExpression(el,er)
{
}

PlusBinaryExpression::~PlusBinaryExpression()
{
}

int PlusBinaryExpression::eval() {
    return this->expressionLeft->eval() + this->expressionRight->eval();
}

string PlusBinaryExpression::print() const{
    stringstream ss;
    ss << "E(" << this->expressionLeft->print() << "+" << this->expressionRight->print()  << ")";
    return ss.str();
}
