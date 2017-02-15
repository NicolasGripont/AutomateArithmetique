#ifndef SYMBOL_H
#define SYMBOL_H
#include <iostream>
#include <string>

using namespace std;

enum SymbolType {ADD, MUL, PO, PF, INT, END, E, ERR};

class Symbol
{
private:
    SymbolType type;
public:
    Symbol(SymbolType type);
    virtual ~Symbol();

    SymbolType getType() const;
    void setType(SymbolType type);

    virtual string print() const;
    friend ostream& operator<<(ostream& os, const Symbol& s);
};

#endif // SYMBOL_H
