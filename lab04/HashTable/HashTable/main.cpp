#include "hashtable.h"
#include <iostream>

int main() {
    HashTable<int> HT;
    std::cout << "Return 1 if queue is empty, else return 0: " << HT.isEmpty() << "\n";
    HT.add("First", 33);
    HT.add("Second", 5);
    HT.add("Third", 8);
    HT.add("Fourth", 7);
    HT.add("Fifth", 10);
    HT.add("Sixth", 15);
    HT.pop("Sixth");
    HT.values();
    std::cout << "Return 1 if queue is empty, else return 0: " << HT.isEmpty() << "\n";
    std::cout << "\nGet the value from key: " << HT.get("First");
    std::cout << "\nHash: " << HT._hash("Fifth");

    return 0;
}