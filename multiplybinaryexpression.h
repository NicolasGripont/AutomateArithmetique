#ifndef MULTIPLYBINARYEXPRESSION_H
#define MULTIPLYBINARYEXPRESSION_H

#include "binaryexpression.h"

using namespace std;

class MultiplyBinaryExpression : public BinaryExpression
{
public:
    MultiplyBinaryExpression(Expression *el, Expression *er);
    ~MultiplyBinaryExpression();
    virtual int eval();
    virtual string print() const;
};

#endif // MULTIPLYBINARYEXPRESSION_H
