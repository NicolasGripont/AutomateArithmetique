#ifndef AUTOMATE_H
#define AUTOMATE_H
#include <iostream>
#include <stack>

#include "lexer.h"
#include "symbole.h"
#include "nombre.h"
#include "expression.h"
#include "state.h"

using namespace std;

class State;

class Automate
{
private:
    Lexer lexer;
    stack<State *> states;
    stack<Symbole *> symboles;
    string chaine;
    void deleteStates();
    void deleteSymboles();

public:
    Automate();
    ~Automate();
    bool execute(string s);
    string print() const;

    void pushState(State *s);
    void pushSymbole(Symbole *s);
    void popState();
    void popSymbole();

    friend ostream& operator<<(ostream& os, const Automate& a);
};

#endif // AUTOMATE_H
