#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <iostream>
#include <string>

#include "symbol.h"

using namespace std;

class Expression : public Symbol
{
private:

public:
    Expression();
    virtual ~Expression();
    virtual int eval() = 0;
    virtual string print() const = 0;
};

#endif // EXPRESSION_H
