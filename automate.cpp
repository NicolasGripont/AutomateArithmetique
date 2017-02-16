#include "automate.h"

Automate::Automate() {

}

Automate::~Automate() {
    deleteSymbols();
    deleteStates();
}

bool Automate::execute(string s) {
    chaine = s;
    deleteSymbols();
    deleteStates();
    lexer.read(s);

//    while()
//    {

//    }

    return true;
}

string Automate::print() const {
    string chaine = "";
    chaine += "---------------- Lexer ----------------\n";
    chaine += lexer.print();
    chaine += "\n";
    stack<State *> states2 = states;
    chaine += "---------------- States ----------------\n";
    while(!states2.empty()) {
        State *s = states2.top();
        states2.pop();
        if(s != nullptr) {
            chaine += s->print();
        } else {
            chaine += "NULL";
        }
        chaine += "\n";
    }
    chaine += "\n--------------- Symbols ---------------\n";
    stack<Symbol *> symbols2 = symbols;
    while(!symbols2.empty()) {
        Symbol *s = symbols2.top();
        symbols2.pop();
        if(s != nullptr) {
            chaine += s->print();
        } else {
            chaine += "NULL";
        }
        chaine += "\n";
    }
    chaine += "\n";
    return chaine;
}

void Automate::pushState(State *s) {
    if(s!= nullptr) {
        states.push(s);
    }
}

void Automate::pushSymbol(Symbol *s) {
   if(s != nullptr) {
     symbols.push(s);
   }
}

State* Automate::popState() {
    State *s = states.top();
    states.pop();
    return s;
}

Symbol* Automate::popSymbol() {
    Symbol *s = symbols.top();
    symbols.pop();
    return s;
}

void Automate::deleteStates() {
    while(!states.empty()) {
        State *s = states.top();
        states.pop();
        if(s != nullptr) {
            delete s;
        }
    }
}

void Automate::deleteSymbols() {
    while(!symbols.empty()) {
        Symbol *s = symbols.top();
        symbols.pop();
        if(s != nullptr) {
            delete s;
        }
    }
}

ostream& operator<<(ostream& os, const Automate& a) {
    os << a.print() << endl;
    return os;
}
