#ifndef AUTOMATE_H
#define AUTOMATE_H
#include <iostream>
#include <stack>
#include <vector>

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
    vector<State *> garbage;
    stack<State *> states;
    stack<Symbol *> symbols;
    string chaine;
    void pushGarbage(State * s);
    void deleteStates();
    void deleteSymbols();
    void deleteGarbage();
    void init();

public:
    Automate();
    ~Automate();
    bool execute(string s, bool debug = false);
    string print() const;

    void pushState(State *s);
    void popState();

    void pushSymbol(Symbol *s);
    Symbol* popSymbol();
    Symbol* topSymbol();
    
    void shift();
    Expression * getResult() const;
    friend ostream& operator<<(ostream& os, const Automate& a);
};

#endif // AUTOMATE_H
