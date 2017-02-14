#include "lexer.h"

Lexer::Lexer() : index(0){
}

Lexer::~Lexer(){
    deleteSymboles();
}


void Lexer::read(string s) {
    deleteSymboles();
    for(unsigned int i=0;i<s.length();i++) {
        if(s[i] == ' ' || s[i] == '\n' ||  s[i] == '\t'){

        } else if(s[i] == '+' || s[i] == '*' || s[i] == '(' || s[i] == ')') {
            symboles.push_back(new Expression(s[i]));
        } else if (s[i] >= 48 && s[i] <= 57){
            string chaine = "";
            do {
                chaine += s[i];
                i++;
            } while(s[i] >= 48 && s[i] <= 57 && i < s.length());
            symboles.push_back(new Nombre(stoi(chaine), ENTIER));
            i--;
        } else {
            cout << "ERREUR : caractere " << s[i] << " lu" << endl;
        }
    }
}

deque<Symbole*> Lexer::getSymboles() const {
    return symboles;
}

string Lexer::print() const {
    string chaine = "";
    deque<Symbole*>::const_iterator i = symboles.begin();
    while(i != symboles.end()) {
        chaine += (*i)->print() + "\n";
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
