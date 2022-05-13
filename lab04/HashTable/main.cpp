#include "hashtable.h"
#include "hashtable_test.h"

int main() {
    HashTable<int> table;
    TableElem<int> elem1("lolo", 3);
    TableElem<int> elem2("lop", 4);
    TableElem<int> elem3("fjh", 12);
    TableElem<int> elem4("llp", 4);
    TableElem<int> elem5("dolko", 76);
    TableElem<int> elem6("lokdown", 87);
    TableElem<int> elem7("fjs", 5);

    table.Add(elem1);
    table.Add(elem2);
    table.Add(elem3);
    table.Add(elem4);
    table.Add(elem5);
    table.Add(elem6);
    table.Add(elem7);
    table.Values();
    std::cout << "\n\n";
    std::cout << table.Pop("lop") << '\n';
    table.Values();
    std::cout << "\n\n";

    TestHash();
    TestAdd();
    TestPop();
    TestGet();

    return 0;
}
