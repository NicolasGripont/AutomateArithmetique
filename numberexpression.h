#ifndef NUMBEREXPRESSION_H
#define NUMBEREXPRESSION_H

#include "expression.h"

using namespace std;

class NumberExpression : public Expression
{
private:
    int value;

public:
    NumberExpression(const int v);
    ~NumberExpression();
    virtual int eval() ;
    virtual string print() const;
};

#endif // NUMBEREXPRESSION_H
