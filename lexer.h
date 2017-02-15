#ifndef LEXER_H
#define LEXER_H
#include <iostream>
#include <deque>

#include "symbol.h"
#include "expression.h"

using namespace std;

class Lexer
{
private:
    deque<Symbol *> symbols;
    unsigned int index;
    void deleteSymbols();
public:
    Lexer();
    ~Lexer();
    void read(string s);
    Symbol * shift();
    Symbol * next() const;
    deque<Symbol*> getSymbols() const;
    string print() const;

    friend ostream& operator<<(ostream& os, const Lexer& l);
};

#endif // LEXER_H
