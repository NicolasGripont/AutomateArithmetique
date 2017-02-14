#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <iostream>
#include <string>
#include "symbole.h"

using namespace std;

enum expression {ADD, MUL, PO, PF, ERR};

class Expression : public Symbole
{
private:
    expression type;
public:
    Expression(char c);
    virtual ~Expression();
    expression getType() const;
    void setType(char c);

    virtual string print() const;
};

#endif // EXPRESSION_H
