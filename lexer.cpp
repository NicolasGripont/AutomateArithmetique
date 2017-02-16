#include "lexer.h"
#include "number.h"


Lexer::Lexer() : index(0){
}

Lexer::~Lexer(){
    deleteSymbols();
}

void Lexer::read(string s) {
    deleteSymbols();
    for(unsigned int i=0;i<s.length();i++) {
        if (s[i] >= 48 && s[i] <= 57){
            string chaine = "";
            do {
                chaine += s[i];
                i++;
            } while(s[i] >= 48 && s[i] <= 57 && i < s.length());
            symbols.push_back(new Number(stoi(chaine), INT));
            i--;
        } else {
            Symbol *sym = nullptr;
            switch(s[i]) {
                case ' ':
                case '\n':
                case '\t': break;
                case '$': sym = new Symbol(END);break;
                case '+' : sym = new Symbol(ADD);break;
                case '*' : sym = new Symbol(MUL);break;
                case '(' : sym = new Symbol(PO);break;
                case ')' : sym = new Symbol(PF);break;
                default: cout << "ERROR : caractere " << s[i] << " lu" << endl;
            }
            if(sym != nullptr) {
                symbols.push_back(sym);
            }
        }
    }
}

deque<Symbol*> Lexer::getSymbols() const {
    return symbols;
}

string Lexer::print() const {
    string chaine = "";
    int ind = 0;
    deque<Symbol*>::const_iterator i = symbols.begin();
    while(i != symbols.end()) {
        if(ind == index)
            chaine += "-> ";
        chaine += (*i)->print() + "\n";
        ind++;
        i++;
    }
    return chaine;
}

Symbol* Lexer::next() const {
    if(index < symbols.size())
        return symbols[index];
    else
        return nullptr;
}

Symbol* Lexer::shift() {
    if(index < symbols.size())
        return symbols[index++];
    else
        return nullptr;
}

void Lexer::deleteSymbols() {
    index = 0;
    while(!symbols.empty()) {
        Symbol *s = this->symbols.back();
        symbols.pop_back();
        if(s != nullptr) {
           delete s;
        }
    }
}

ostream& operator<<(ostream& os, const Lexer& l) {
    os << l.print() << endl;
    return os;
}
