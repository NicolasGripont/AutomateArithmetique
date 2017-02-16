#include "automate.h"

Automate::Automate() {

}

Automate::~Automate() {
    deleteSymbols();
    deleteStates();
    deleteGarbage();
}

bool Automate::execute(string s, bool debug) {
    chaine = s;
    int iteration = 0;
    deleteSymbols();
    deleteStates();
    lexer.read(s);
    bool error = false;
    bool accepte = false;
    init();
    if(debug) {
        cout << "Iteration " << iteration << endl;
        cout << print() << endl;
    }
    while(!error && !accepte) {
        State *etatCourant = states.top();
        error = !etatCourant->transition(*this, lexer.next());
        if(lexer.next() == nullptr) {
            accepte = true;
        } else {
            accepte = false;
        }        
        if(debug) {
            iteration++;
            cout << "Iteration " << iteration << " - Error : " << error << " - Accepted : " << accepte << endl;
            cout << print() << endl;
        }
    }
    return !error || accepte;
}

Expression * Automate::getResult() const {
    return dynamic_cast<Expression *>(symbols.top());
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

void Automate::shift() {
    lexer.shift();
}

void Automate::pushGarbage(State *s) {
    if(s!= nullptr) {
        garbage.push_back(s);
    }
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

void Automate::popState() {
    State *s = states.top();
    states.pop();
    pushGarbage(s);
}

Symbol* Automate::popSymbol() {
    Symbol *s = symbols.top();
    symbols.pop();
    return s;
}

Symbol* Automate::topSymbol() {
    Symbol *s = symbols.top();
    return s;
}

void Automate::init() {
    deleteStates();
    deleteSymbols();
    pushState(new State0("0"));
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

void Automate::deleteGarbage() {
    while(!garbage.empty()) {
        State *s = garbage.back();
        garbage.pop_back();
        if(s != nullptr) {
            delete s;
        }
    }
}

ostream& operator<<(ostream& os, const Automate& a) {
    os << a.print();
    return os;
}
