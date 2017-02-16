#ifndef SIMPLEEXPRESSION_H
#define SIMPLEEXPRESSION_H
#include <iostream>
#include <string>

#include "expression.h"

using namespace std;

class SimpleExpression : public Expression
{
    Expression* expression;
public:
    SimpleExpression(Expression* e);
    virtual ~SimpleExpression();
    virtual int eval();
    virtual string print() const;
};

#endif // SIMPLEEXPRESSION_H
