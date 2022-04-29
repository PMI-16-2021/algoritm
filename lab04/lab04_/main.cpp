#include <iostream>
#include "HTable.h"
#include "Tests.h"

int main() {
    Hash_Table Workers(6);
    Row w1("Demchuk", "Team-lead");
    Row w2("Dronyk","Architect");
    Row w3("Velguss","Manager");
    Row w4("Klymochko","Programmer");
    Row w5("Snigur","Football player");
    Workers.add(w1);
    Workers.add(w2);
    Workers.add(w3);
    Workers.add(w4);
    Workers.add(w5);
    Workers.values();

    cout<<"Searching for worker Snigur\n";
    if(Workers.find("Snigur"))
    {
        cout<<"This worker is found\n";
    }else
    {
        cout<<"This worker NOT found\n";
    }
    Workers.pop("Demchuk");

    cout<<"Count of table is "<< Workers.getSize()<<"\n";
    Workers.values();

    Test1();
    Test2();
    Test3();
    Test4();
    Test5();



    return 0;
}
