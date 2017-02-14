#include "state.h"

// ----------------------------------- State 0 -----------------------------------

State::State(string name) : name(name) {
}

State::~State() {
}

string State::getName() const {
    return name;
}

void State::setName(string name) {
    this->name = name;
}

ostream& operator<<(ostream& os, const State& s) {
    os << s.print() << endl;
    return os;
}

// ----------------------------------- State 1 -----------------------------------

State0::State0(string name) : name(name) {
}

State0::~State0() {
}

string State0::print() const {
    return name;
}

bool State0::transition(Automate & automate, Symbole *s) {
    if(Expression *e = dynamic_cast<Expression *>(s)) {
        switch(*e) {
            case PO :
            automate.pushSymbole(*e);
            automate.pushState(new State2("State 2"));
            return true;
            default: return false;
        }
    } else if(Nombre *n = dynamic_cast<Nombre *>(s)) {
        automate.pushSymbole(*n            );
        automate.pushState(new State3("State 3"));
    } else {
        return false;
    }

}
