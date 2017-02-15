#ifndef SYMBOLE_H
#define SYMBOLE_H
#include <iostream>
#include <string>

using namespace std;

enum symbole {ADD, MUL, PO, PF, ENTIER, END, E, ERR};

class Symbole
{
private:
	symbole type;
public:
    Symbole(symbole type);
    virtual ~Symbole();

    symbole getType() const;
    void setType(symbole type);

    virtual string print() const;
    friend ostream& operator<<(ostream& os, const Symbole& s);
};

#endif // SYMBOLE_H
