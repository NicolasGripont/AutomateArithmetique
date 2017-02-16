#ifndef STATE_H
#define STATE_H
#include <iostream>
#include "automate.h"
#include "symbol.h"

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
    virtual bool transition(Automate & automate, Symbol *s) = 0;

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
    virtual bool transition(Automate & automate, Symbol *s);
};

// ----------------------------------- State 1 -----------------------------------
class State1 : public State
{
public:
    State1(string name);
    virtual ~State1();

    virtual string print() const;
    virtual bool transition(Automate & automate, Symbol *s);
};

// ----------------------------------- State 2 -----------------------------------
class State2 : public State
{
public:
    State2(string name);
    virtual ~State2();

    virtual string print() const;
    virtual bool transition(Automate & automate, Symbol *s);
};

// ----------------------------------- State 3 -----------------------------------
class State3 : public State
{
public:
    State3(string name);
    virtual ~State3();

    virtual string print() const;
    virtual bool transition(Automate & automate, Symbol *s);
};

// ----------------------------------- State 4 -----------------------------------
class State4 : public State
{
public:
    State4(string name);
    virtual ~State4();

    virtual string print() const;
    virtual bool transition(Automate & automate, Symbol *s);
};

// ----------------------------------- State 5 -----------------------------------
class State5 : public State
{
public:
    State5(string name);
    virtual ~State5();

    virtual string print() const;
    virtual bool transition(Automate & automate, Symbol *s);
};

// ----------------------------------- State 6 -----------------------------------
class State6 : public State
{
public:
    State6(string name);
    virtual ~State6();

    virtual string print() const;
    virtual bool transition(Automate & automate, Symbol *s);
};

// ----------------------------------- State 7 -----------------------------------
class State7 : public State
{
public:
    State7(string name);
    virtual ~State7();

    virtual string print() const;
    virtual bool transition(Automate & automate, Symbol *s);
};

// ----------------------------------- State 8 -----------------------------------
class State8 : public State
{
public:
    State8(string name);
    virtual ~State8();

    virtual string print() const;
    virtual bool transition(Automate & automate, Symbol *s);
};

// ----------------------------------- State 9 -----------------------------------
class State9 : public State
{
public:
    State9(string name);
    virtual ~State9();

    virtual string print() const;
    virtual bool transition(Automate & automate, Symbol *s);
};

#endif // STATE_H
