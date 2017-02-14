#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <iostream>
#include <string>
#include <map>
#include "symbole.h"

using namespace std;

class Expression : public Symbole
{
private:

public:
    Expression();
    virtual ~Expression();
    virtual int eval(const map<string, int>& valeurs) = 0;
    virtual string print() const = 0;
};

#endif // EXPRESSION_H
