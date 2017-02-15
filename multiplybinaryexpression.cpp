#include <sstream>

#include "multiplybinaryexpression.h"

MultiplyBinaryExpression::MultiplyBinaryExpression(Expression* el, Expression* er) : BinaryExpression(el,er)
{
}

MultiplyBinaryExpression::~MultiplyBinaryExpression()
{
}

int MultiplyBinaryExpression::eval() {
    return this->expressionLeft->eval() * this->expressionRight->eval();
}

string MultiplyBinaryExpression::print() const{
    stringstream ss;
    ss << "E(" << this->expressionLeft->print() << "*" << this->expressionRight->print()  << ")";
    return ss.str();
}
