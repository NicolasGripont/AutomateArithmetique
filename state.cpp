#include "state.h"

// ----------------------------------- State -----------------------------------
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

// ----------------------------------- State 0 -----------------------------------
State0::State0(string name) : State(name) {
}

State0::~State0() {
}

string State0::print() const {
    return name;
}

bool State0::transition(Automate & automate, Symbole *s) {
    if(s != nullptr) {
        switch(s->getType()) {
            case E : 
                automate.pushState(new State1("State 1"));
            case PO :
                automate.pushState(new State2("State 2"));
            case ENTIER :
                automate.pushState(new State3("State 3"));
            default :
                return false;
        }
        automate.pushSymbole(s);
        return true;
    }
    return false;
}

// ----------------------------------- State 1 -----------------------------------
State1::State1(string name) : State(name) {
}

State1::~State1() {
}

string State1::print() const {
    return name;
}

bool State1::transition(Automate & automate, Symbole *s) {
    if(s != nullptr) {
        switch(s->getType()) {
            case E : 
                automate.pushState(new State1("State 1"));
            case PO :
                automate.pushState(new State2("State 2"));
            case ENTIER :
                automate.pushState(new State3("State 3"));
            default :
                return false;
        }
        automate.pushSymbole(s);
        return true;
    }
    return false;
}

// ----------------------------------- State 2 -----------------------------------
State2::State2(string name) : State(name) {
}

State2::~State2() {
}

string State2::print() const {
    return name;
}

bool State2::transition(Automate & automate, Symbole *s) {
    if(s != nullptr) {
        switch(s->getType()) {
            case E : 
                automate.pushState(new State1("State 1"));
            case PO :
                automate.pushState(new State2("State 2"));
            case ENTIER :
                automate.pushState(new State3("State 3"));
            default :
                return false;
        }
        automate.pushSymbole(s);
        return true;
    }
    return false;
}

// ----------------------------------- State 3 -----------------------------------
State3::State3(string name) : State(name) {
}

State3::~State3() {
}

string State3::print() const {
    return name;
}

bool State3::transition(Automate & automate, Symbole *s) {
    if(s != nullptr) {
        switch(s->getType()) {
            case E : 
                automate.pushState(new State1("State 1"));
            case PO :
                automate.pushState(new State2("State 2"));
            case ENTIER :
                automate.pushState(new State3("State 3"));
            default :
                return false;
        }
        automate.pushSymbole(s);
        return true;
    }
    return false;
}