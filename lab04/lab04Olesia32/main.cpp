#include "hash_table.h"

int main() {
	HashTable<int> H1;
	H1.Add("Ferrero Rocher", 181);
	H1.Add("Raffaello", 120);
	H1.Add("MontBlank", 65);
	H1.Add("Trufalie", 88);
	H1.Add("Toffifee", 81);
	H1.Add("Sharm", 40);
	H1.Add("Milka", 75);
	H1.Add("Exclusive", 94);
	H1.Add("Bonjour", 56);
	H1.Add("KitKat", 60);
	H1.Values();
	cout << "\n\n";
	H1.Pop("Sharm");
	H1.Values();
	cout << H1.Size();
	system("pause");
	return 0;
}