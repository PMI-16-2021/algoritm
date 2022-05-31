#include<iostream>
#include"hash_table.h"
using namespace std;
int main() {
    HashTable<int> H;
    HashTableNode<int> elem1("abc", 7);
    HashTableNode<int> elem2("qwe", 6);
    HashTableNode<int> elem3("asd", 5);
    HashTableNode<int> elem4("zxc", 4);
    HashTableNode<int> elem5("ost", 3);
    HashTableNode<int> elem6("yar", 2);
    HashTableNode<int> elem7("asdf", 1);
    H.Add(elem1);
    H.Add(elem2);
    H.Add(elem3);
    H.Add(elem4);
    H.Add(elem5);
    H.Add(elem6);
    H.Add(elem7);
    H.Values();
    std::cout << "\n";
    H.Pop("abc");
    H.Values();
    std::cout << "\n";
	system("pause");
	return 0;
}