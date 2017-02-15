#ifndef NUMBER_H
#define NUMBER_H
#include <iostream>
#include <string>


#include "symbol.h"

using namespace std;

class Number : public Symbol
{
private:
    int n;
public:
    Number(int n, SymbolType type);
    virtual ~Number();

    int getNumber() const;
    void setNumber(int n);

    virtual string print() const;
};

#endif // NUMBER_H
