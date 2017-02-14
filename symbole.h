#ifndef SYMBOLE_H
#define SYMBOLE_H
#include <iostream>
#include <string>

using namespace std;

class Symbole
{
public:
    Symbole();
    virtual ~Symbole();
    virtual string print() const = 0;
    friend ostream& operator<<(ostream& os, const Symbole& s);
};

#endif // SYMBOLE_H
