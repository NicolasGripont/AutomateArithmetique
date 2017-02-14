#ifndef STATE_H
#define STATE_H
#include <iostream>
#include "symbole.h"

using namespace std;
class Automate;

// ----------------------------------- State -----------------------------------
class State
{
protected:
    string name;
public:
    State(string name);
    virtual ~State();

    virtual string print() const = 0;
    virtual bool transition(Automate & automate, Symbole *s) = 0;

    string getName() const;
    void setName(string name);

    friend ostream& operator<<(ostream& os, const State& s);
};

// ----------------------------------- State 0 -----------------------------------

class State0 : public State
{
public:
    State0(string name);
    virtual ~State0();

    virtual string print() const;
    virtual bool transition(Automate & automate, Symbole *s);
};

// ----------------------------------- State 1 -----------------------------------

class State1 : public State
{
public:
    State1(string name);
    virtual ~State1();

    virtual string print() const;
    virtual bool transition(Automate & automate, Symbole *s);
};
// ----------------------------------- State 2 -----------------------------------

class State2 : public State
{
public:
    State2(string name);
    virtual ~State2();

    virtual string print() const;
    virtual bool transition(Automate & automate, Symbole *s);
};
// ----------------------------------- State 3 -----------------------------------

class State3 : public State
{
public:
    State3(string name);
    virtual ~State3();

    virtual string print() const;
    virtual bool transition(Automate & automate, Symbole *s);
};
#endif // STATE_H
