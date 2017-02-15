#include "binaryexpression.h"

BinaryExpression::BinaryExpression(Expression* el, Expression* er) : Expression(), expressionLeft(el), expressionRight(er)
{
}

BinaryExpression::~BinaryExpression()
{
    if(expressionLeft != nullptr) {
        delete expressionLeft;
    }
    if(expressionRight != nullptr) {
        delete expressionRight;
    }
}
