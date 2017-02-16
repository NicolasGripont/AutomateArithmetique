#include "state.h"
#include "number.h"
#include "numberexpression.h"
#include "plusbinaryexpression.h"
#include "multiplybinaryexpression.h"
#include "simpleexpression.h"

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
    os << s.print();
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

bool State0::transition(Automate & automate, Symbol *s) {
    if(s != nullptr) {
        Number *n = nullptr;
        Expression *e = nullptr;
        switch(s->getType()) {
            case ERR :
                return false;
            case PO :
                automate.pushState(new State2("2"));
                automate.pushSymbol(new Symbol(s->getType()));
                automate.shift();
                break;
            case INT :
                n = (Number *) s;
                automate.pushState(new State3("3"));
                automate.pushSymbol(new Number(n->getNumber(), n->getType()));
                automate.shift();
                break;
            default :
                e = dynamic_cast<Expression *>(automate.topSymbol());
                if(e != nullptr) {
                    automate.pushState(new State1("1"));
                } else {
                    return false;
                }
        }
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

bool State1::transition(Automate & automate, Symbol *s) {
    if(s != nullptr) {
        switch(s->getType()) {
            case ADD : 
                automate.pushState(new State4("4"));
                automate.pushSymbol(new Symbol(s->getType()));
                automate.shift();
                break;
            case MUL :
                automate.pushState(new State5("5"));
                automate.pushSymbol(new Symbol(s->getType()));
                automate.shift();
                break;
            case END :
                automate.shift();
                break;
            default :
                return false;
        }
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

bool State2::transition(Automate & automate, Symbol *s) {
    if(s != nullptr) {
        Number *n = nullptr;
        Expression *e = nullptr;
        switch(s->getType()) {
            case ERR :
                return false;
            case PO :
                automate.pushState(new State2("2"));
                automate.pushSymbol(new Symbol(s->getType()));
                automate.shift();
                break;
            case INT :
                n = (Number *) s;
                automate.pushState(new State3("3"));
                automate.pushSymbol(new Number(n->getNumber(), n->getType()));
                automate.shift();
                break;
            default :
                e = dynamic_cast<Expression *>(automate.topSymbol());
                if(e != nullptr) {
                    automate.pushState(new State6("6"));
                } else {
                    return false;
                }
        }
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

bool State3::transition(Automate & automate, Symbol *s) {
    if(s != nullptr) {
        Number *n = nullptr;
        switch(s->getType()) {
            case END : 
            case PF :
            case ADD :
            case MUL :
                n = (Number *) automate.popSymbol();
                automate.popState();
                automate.pushSymbol(new NumberExpression(n->getNumber()));
                delete n;
                break;
            default :
                return false;
        }
        return true;
    }
    return false;
}

// ----------------------------------- State 4 -----------------------------------
State4::State4(string name) : State(name) {
}

State4::~State4() {
}

string State4::print() const {
    return name;
}

bool State4::transition(Automate & automate, Symbol *s) {
    if(s != nullptr) {
        Number *n = nullptr;
        Expression *e = nullptr;
        switch(s->getType()) {
            case ERR :
                return false;
            case PO :
                automate.pushState(new State2("2"));
                automate.pushSymbol(new Symbol(s->getType()));
                automate.shift();
                break;
            case INT :
                n = (Number *) s;
                automate.pushState(new State3("3"));
                automate.pushSymbol(new Number(n->getNumber(), n->getType()));
                automate.shift();
                break;
            default :
                e = dynamic_cast<Expression *>(automate.topSymbol());
                if(e != nullptr) {
                    automate.pushState(new State7("7"));
                } else {
                    return false;
                }
        }
        return true;
    }
    return false;
}

// ----------------------------------- State 5 -----------------------------------
State5::State5(string name) : State(name) {
}

State5::~State5() {
}

string State5::print() const {
    return name;
}

bool State5::transition(Automate & automate, Symbol *s) {
    if(s != nullptr) {
        Number *n = nullptr;
        Expression *e = nullptr;
        switch(s->getType()) {
            case ERR :
                return false;
            case PO :
                automate.pushState(new State2("2"));
                automate.pushSymbol(new Symbol(s->getType()));
                automate.shift();
                break;
            case INT :
                n = (Number *) s;
                automate.pushState(new State3("3"));
                automate.pushSymbol(new Number(n->getNumber(), n->getType()));
                automate.shift();
                break;
            default :
                e = dynamic_cast<Expression *>(automate.topSymbol());
                if(e != nullptr) {
                    automate.pushState(new State8("8"));
                } else {
                    return false;
                }
        }
        return true;
    }
    return false;
}

// ----------------------------------- State 6 -----------------------------------
State6::State6(string name) : State(name) {
}

State6::~State6() {
}

string State6::print() const {
    return name;
}

bool State6::transition(Automate & automate, Symbol *s) {
    if(s != nullptr) {
        switch(s->getType()) {
            case ADD :
                automate.pushState(new State4("4"));
                automate.pushSymbol(new Symbol(s->getType()));
                automate.shift();
                break;
            case MUL :
                automate.pushState(new State5("5"));
                automate.pushSymbol(new Symbol(s->getType()));
                automate.shift();
                break;
            case PF :
                automate.pushState(new State9("9"));
                automate.pushSymbol(new Symbol(s->getType()));
                automate.shift();
                break;
            default :
                return false;
        }
        return true;
    }
    return false;
}

// ----------------------------------- State 7 -----------------------------------
State7::State7(string name) : State(name) {
}

State7::~State7() {
}

string State7::print() const {
    return name;
}

bool State7::transition(Automate & automate, Symbol *s) {
    if(s != nullptr) {
        Expression *eL = nullptr;
        Expression *eR = nullptr;
        switch(s->getType()) {
            case MUL :
                automate.pushState(new State5("5"));
                automate.pushSymbol(new Symbol(s->getType()));
                automate.shift();
                break;
            case ADD :
            case PF :
            case END :
                eR = (Expression *) automate.popSymbol();
                delete automate.popSymbol();
                eL = (Expression *) automate.popSymbol();
                automate.pushSymbol(new PlusBinaryExpression(eL,eR));
                automate.popState();
                automate.popState();
                automate.popState();
                break;
            default :
                return false;
        }
        return true;
    }
    return false;
}

// ----------------------------------- State 8 -----------------------------------
State8::State8(string name) : State(name) {
}

State8::~State8() {
}

string State8::print() const {
    return name;
}

bool State8::transition(Automate & automate, Symbol *s) {
    if(s != nullptr) {
        Expression *eL = nullptr;
        Expression *eR = nullptr;
        switch(s->getType()) {
            case ADD :
            case MUL :
            case PF :
            case END :
                eR = (Expression *) automate.popSymbol();
                delete automate.popSymbol(); // pour le +
                eL = (Expression *) automate.popSymbol();
                automate.pushSymbol(new MultiplyBinaryExpression(eL,eR));
                automate.popState();
                automate.popState();
                automate.popState();
                break;
            default :
                return false;
        }
        return true;
    }
    return false;
}

// ----------------------------------- State 9 -----------------------------------
State9::State9(string name) : State(name) {
}

State9::~State9() {
}

string State9::print() const {
    return name;
}

bool State9::transition(Automate & automate, Symbol *s) {
    if(s != nullptr) {
        Expression *e = nullptr;
        switch(s->getType()) {
            case ADD :
            case MUL :
            case PF :
            case END :
                delete automate.popSymbol();
                e = (Expression *) automate.popSymbol();
                delete automate.popSymbol();
                automate.pushSymbol(new SimpleExpression(e));
                automate.popState();
                automate.popState();
                automate.popState();
                break;
            default :
                return false;
        }
        return true;
    }
    return false;
}
