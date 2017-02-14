#include "symbole.h"

Symbole::Symbole()
{
}

Symbole::~Symbole() {

}

ostream& operator<<(ostream& os, const Symbole& s) {
    os << s.print() << endl;
    return os;
}
