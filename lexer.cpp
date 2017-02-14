#include "lexer.h"

Lexer::Lexer() : index(0){
}

Lexer::~Lexer(){
    deleteSymboles();
}

void Lexer::read(string s) {
    deleteSymboles();
    for(unsigned int i=0;i<s.length();i++) {
        if (s[i] >= 48 && s[i] <= 57){
            string chaine = "";
            do {
                chaine += s[i];
                i++;
            } while(s[i] >= 48 && s[i] <= 57 && i < s.length());
            symboles.push_back(new Nombre(stoi(chaine), ENTIER));
            i--;
        } else {
            Symbole *sym = nullptr;
            switch(s[i]) {
                case ' ':
                case '\n': 
                case '\t': break;
                case '+' : sym = new Symbole(ADD);break;
                case '*' : sym = new Symbole(MUL);break;
                case '(' : sym = new Symbole(PO);break;
                case ')' : sym = new Symbole(PF);break;
                default: cout << "ERROR : caractere " << s[i] << " lu" << endl;
            }
            if(sym != nullptr) {
                symboles.push_back(sym);
            }
        }
    }
}

deque<Symbole*> Lexer::getSymboles() const {
    return symboles;
}

string Lexer::print() const {
    string chaine = "";
    int ind = 0;
    deque<Symbole*>::const_iterator i = symboles.begin();
    while(i != symboles.end()) {
        if(ind == index) 
            chaine += "-> ";
        chaine += (*i)->print() + "\n";
        ind++;
        i++;
    }
    return chaine;
}

Symbole* Lexer::next() const {
    if(index < symboles.size())
        return symboles[index];
    else
        return nullptr;
}

Symbole* Lexer::shift() {
    if(index < symboles.size())
        return symboles[index++];
    else
        return nullptr;
}

void Lexer::deleteSymboles() {
    index = 0;
    while(!symboles.empty()) {
        Symbole *s = this->symboles.back();
        symboles.pop_back();
        if(s != nullptr) {
           delete s;
        }
    }
}

ostream& operator<<(ostream& os, const Lexer& l) {
    os << l.print() << endl;
    return os;
}
