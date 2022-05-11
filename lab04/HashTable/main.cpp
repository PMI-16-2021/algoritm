#include "hashtable.h"
#include "hashtable_test.h"

int main() {
    HashTable<int> table;
    TableElem<int> elem1("lolo", 2);
    TableElem<int> elem0("olol", 2);
    TableElem<int> elem2("l", 45);
    TableElem<int> elem3("paul", 35);
    TableElem<int> elem4("rebeka", 5);
    TableElem<int> elem5("wow", 15);
    TableElem<int> elem6("leleka", 43);
    TableElem<int> elem7("richka", 23);
    TableElem<int> elem8("qweer", 47);
    TableElem<int> elem9("horror", 9);
    TableElem<int> elem10("sdw", 8);

    table.Add(elem0);
    table.Add(elem1);
    table.Add(elem2);
    table.Add(elem3);
    table.Add(elem4);
    table.Add(elem5);
    table.Add(elem6);
    table.Add(elem7);
    table.Add(elem8);
//    table.Add(elem9);
    table.Add(elem10);

    std::cout<<table.Get("lolo")<<'\n';
    std::cout<<table.Get("l")<<'\n';
    std::cout<<table.Get("paul")<<'\n';
    std::cout<<table.Get("rebeka")<<'\n';
    std::cout<<table.Get("wow")<<'\n';
    std::cout<<table.Get("leleka")<<'\n';
    std::cout<<table.Get("richka")<<'\n';
    std::cout<<table.Get("qweer")<<'\n';
//    std::cout<<table.Get("horror")<<'\n';
    std::cout<<table.Get("olol")<<'\n';
    std::cout<<table.Get("sdw")<<'\n';
    std::cout<<'\n';
    table.Values();
    std::cout<<"\n\n";
    std::cout<<table.Pop("leleka")<<'\n';
    std::cout<<'\n';
    table.Values();

    TestHash();
    TestAdd();
    TestGet();
    TestPop();
    return 0;
}
