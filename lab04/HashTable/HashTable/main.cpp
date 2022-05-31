#include "hashtable.h"

int main() {
    HashTable<int> HT;
    //std::cout << "Return 1 if queue is empty, else return 0: " << HT.IsEmpty() << "\n";
    HT.add("Giraffe", 33);
    HT.add("Cat", 5);
    HT.add("Dog", 8);
    HT.add("Lion", 7);
    HT.add("Elephant", 10);
    HT.add("Bee", 15);
	HT.add("Mouse", 4);
	HT.add("Horse", 17);
	HT.add("Rabbit", 22);
	HT.add("Fish", 11);
	HT.values();
	std::cout << "\n\n";
    HT.pop("Horse");
    HT.values();
   // std::cout << "Return 1 if queue is empty, else return 0: " << HT.IsEmpty() << "\n";
    //std::cout << "\nGet the value from key: " << HT.get("First");*/
   

    return 0;
}