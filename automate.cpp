#include "automate.h"

Automate::Automate() {

}

Automate::~Automate() {
    deleteSymboles();
    deleteStates();
}

bool Automate::execute(string s) {
    chaine = s;
    deleteSymboles();
    deleteStates();
    lexer.read(s);
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
    chaine += "\n---------------- Symboles ----------------\n";
    stack<Symbole *> symboles2 = symboles;
    while(!symboles2.empty()) {
        Symbole *s = symboles2.top();
        symboles2.pop();
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

void Automate::pushSymbole(Symbole *s) {
   if(s != nullptr) {
     symboles.push(s);
   }
}

void Automate::popState() {
    states.pop();
}

void Automate::popSymbole() {
    symboles.pop();
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

void Automate::deleteSymboles() {
    while(!symboles.empty()) {
        Symbole *s = symboles.top();
        symboles.pop();
        if(s != nullptr) {
            delete s;
        }
    }
}

ostream& operator<<(ostream& os, const Automate& a) {
    os << a.print() << endl;
    return os;
}
