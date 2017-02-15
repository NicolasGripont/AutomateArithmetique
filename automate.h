#ifndef AUTOMATE_H
#define AUTOMATE_H
#include <iostream>
#include <stack>

#include "lexer.h"
#include "symbol.h"
#include "expression.h"
#include "state.h"

using namespace std;

class State;

class Automate
{
private:
    Lexer lexer;
    stack<State *> states;
    stack<Symbol *> symbols;
    string chaine;
    void deleteStates();
    void deleteSymbols();

public:
    Automate();
    ~Automate();
    bool execute(string s);
    string print() const;

    void pushState(State *s);
    void pushSymbol(Symbol *s);
    void popState();
    void popSymbol();

    friend ostream& operator<<(ostream& os, const Automate& a);
};

#endif // AUTOMATE_H
