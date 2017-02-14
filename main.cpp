#include <iostream>
#include "automate.h"

using namespace std;

int main() {
    Automate automate;
    automate.execute("(45+(56+78))*54");
    cout << automate << endl;
    return 0;
}
