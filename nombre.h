#ifndef NOMBRE_H
#define NOMBRE_H
#include <iostream>
#include <string>
#include <sstream>

#include "symbole.h"

using namespace std;

enum nombre {ENTIER};

class Nombre : public Symbole
{
private:
    nombre type;
    int n;
public:
    Nombre(int n, nombre type);
    virtual ~Nombre();
    nombre getType() const;
    int getNombre() const;
    void setType(nombre type);
    void setNombre(int n);

    virtual string print() const;
};

#endif // NOMBRE_H
