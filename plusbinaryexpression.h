#ifndef PLUSBINARYEXPRESSION_H
#define PLUSBINARYEXPRESSION_H

#include "binaryexpression.h"

using namespace std;

class PlusBinaryExpression : public BinaryExpression
{
public:
    PlusBinaryExpression(Expression* el, Expression* er);
    ~PlusBinaryExpression();
    virtual int eval();
    virtual string print() const;
};

#endif // PLUSBINARYEXPRESSION_H
