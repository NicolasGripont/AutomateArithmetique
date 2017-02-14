#ifndef NOMBRE_H
#define NOMBRE_H
#include <iostream>
#include <string>
#include <sstream>

#include "symbole.h"

using namespace std;

class Nombre : public Symbole
{
private:
    int n;
public:
    Nombre(int n, symbole type);
    virtual ~Nombre();

    int getNombre() const;
    void setNombre(int n);

    virtual string print() const;
};

#endif // NOMBRE_H
