#ifndef BINARYEXPRESSION_H
#define BINARYEXPRESSION_H

#include "expression.h"

using namespace std;

class BinaryExpression : public Expression
{
protected:
    Expression* expressionLeft;
    Expression* expressionRight;
public:
    BinaryExpression(Expression* el, Expression* er);
    ~BinaryExpression();
    virtual int eval() = 0;
    virtual string print() const = 0;
};

#endif // BINARYEXPRESSION_H
