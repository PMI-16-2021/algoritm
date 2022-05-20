#include "HashT.h"

int main()
{
    HashTable<string, int>* h = new HashTable<string, int>;
    h->add("Apple", 5);
    h->add("Pear", 15);
    h->add("Peach", 1);
    h->add("Cherry", 19);
    h->add("Blueberry", 11);
    h->add("Blackberry", 9);
    h->add("Grape", 7);
    h->add("Pomegranate", 10);
    h->values();
    cout << "\n";
    cout << "Size: " << h->sizeofTable() << "\n\n";
    h->pop("Pear");
    h->pop("Grape");
    h->values();
    cout << "\n";
    cout << "Get element value: " << h->get("Cherry") << "\n";
   
    system("pause");
    return 0;
}