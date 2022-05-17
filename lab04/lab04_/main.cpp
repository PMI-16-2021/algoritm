#include "htable.h"
#include "Tests.h"
int main() {
    HTable H1(10);
    H1.add("Demchuk","Team-lead");
    H1.add("Dronyk","Architect");
    H1.add("Velguss","Manager");
    H1.add("Klymochko","Programmer");
    H1.add("Snigur","Football player");
    H1.values();
    cout << "\n\n";
    H1.pop("Demchuk");
    cout << "\n\n";
//    cout << H1.getSize();
    H1.values();
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}