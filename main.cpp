#include <iostream>

#include "automate.h"
#include "multiplybinaryexpression.h"
#include "plusbinaryexpression.h"
#include "numberexpression.h"
#include "simpleexpression.h"

using namespace std;

void test();
void showMenu();
void testExpression();

int main() {

//    test();
    showMenu();
//    testExpression();

    return 0;
}

void test() {
    Automate automate;
    if(automate.execute("3*(4+5)$", true)) {
        Expression *e = automate.getResult();
        cout << "Answer : " << *e << " = " << e->eval() << endl;
    } else {
        cout << "ERROR" << endl;
    }
}


void showMenu() {
    Automate automate;
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
            if(automate.execute(line)) {
                Expression *e = automate.getResult();
                cout << "Answer : " << *e << " = " << e->eval() << endl;
            } else {
                cout << "ERROR" << endl;
            }
            cout << endl;
        }

    } while (line.compare(exit) != 0);
}

void testExpression(){
    //(2+5)*(3+17)
    NumberExpression *ne1 = new NumberExpression(2);
    NumberExpression *ne2 = new NumberExpression(5);
    NumberExpression *ne3 = new NumberExpression(3);
    NumberExpression *ne4 = new NumberExpression(17);
    PlusBinaryExpression *pbe1 = new PlusBinaryExpression(ne1,ne2);
    PlusBinaryExpression *pbe2 = new PlusBinaryExpression(ne3,ne4);
    SimpleExpression *se1 = new SimpleExpression(pbe1);
    SimpleExpression *se2 = new SimpleExpression(pbe2);
    MultiplyBinaryExpression mbe = MultiplyBinaryExpression(se1,se2);
    cout << endl;
    cout << "(2+5)*(3+17)" << endl;
    cout << mbe.print() <<  " = " << mbe.eval() << endl;
    cout << endl;
}
