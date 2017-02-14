#include <iostream>
#include "automate.h"

using namespace std;

void test();
void showMenu();

int main() {

    test();
    //showMenu();

    return 0;
}

void test() {
    Automate automate;
    automate.execute("(45+(56+78))*54");
    cout << automate << endl;
}


void showMenu() {
    string exit = "exit";
    string line;

    cout << endl;
    cout << "Entrez 'exit' pour quitter le programme." << endl;

    do {
        line = "";
        cout << "Entrez une expression arithmétique (composée de nombres, '(', ')', '+', '*') :" << endl;
        getline(cin, line);

        if(!line.empty() && line.compare(exit) != 0) {
//        TODO : analyser et évaluer l'expression
            cout << endl;
        }

    } while (line.compare(exit) != 0);
}
