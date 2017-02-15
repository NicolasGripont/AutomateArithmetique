#include <iostream>
#include "automate.h"
#include "multiplybinaryexpression.h"
#include "plusbinaryexpression.h"
#include "numberexpression.h"

using namespace std;

void test();
void showMenu();
void testExpression();

int main() {

    test();
    //showMenu();
//    testExpression();

    return 0;
}

void test() {
    Automate automate;
    automate.execute("5+3$");
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
            line += "$";
            //        TODO : analyser et évaluer l'expression

            cout << endl;
        }

    } while (line.compare(exit) != 0);
}

void testExpression(){
    NumberExpression *ne1 = new NumberExpression(2);
    NumberExpression *ne2 = new NumberExpression(5);
    NumberExpression *ne3 = new NumberExpression(3);
    NumberExpression *ne4 = new NumberExpression(17);
    PlusBinaryExpression *pbe1 = new PlusBinaryExpression(ne1,ne2);
    PlusBinaryExpression *pbe2 = new PlusBinaryExpression(ne3,ne4);
    MultiplyBinaryExpression mbe = MultiplyBinaryExpression(pbe1,pbe2);
    cout << mbe.print() <<  " = " << mbe.eval() << endl;
}
