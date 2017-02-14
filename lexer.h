#ifndef LEXER_H
#define LEXER_H
#include <iostream>
#include <deque>

#include "symbole.h"
#include "expression.h"
#include "nombre.h"

using namespace std;

class Lexer
{
private:
    deque<Symbole *> symboles;
    unsigned int index;
    void deleteSymboles();
public:
    Lexer();
    ~Lexer();
    void read(string s);
    Symbole * shift();
    Symbole * next() const;
    deque<Symbole*> getSymboles() const;
    string print() const;

    friend ostream& operator<<(ostream& os, const Lexer& l);
};

#endif // LEXER_H
