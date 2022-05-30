#include <iostream>
#include "hash.h"
using namespace std;
int main() {

	HashTable ht;
	ht.add(5,"bubble_gum");
	ht.add(7, "fish_dori");
	ht.add(10, "dori");
	ht.add(3, "bubble_gum");
	ht.elements();
	cout << "\n";
	cout << "size: " << ht.size();
	cout << "\n";
	cout << "\n";
	cout << "value element fish dori: " << ht.get("fish_dori") << "\n";
	cout << "value element bubble_gum: " << ht.get("bubble_gum") << "\n";
	ht.pop("bubble_gum");
	cout << "value element bubble_gum: " << ht.get("bubble_gum") << "\n";
	cout << "\n";
	ht.elements();
	cout << "size: " << ht.size();
	cout << "\n";
	if (ht.isEmpty()) {
		cout << "ht is empty\n";
	}
	HashTable ht1;
	if (ht1.isEmpty()) {
		cout << "ht1 is empty\n";
	}

	system("pause");
	return 0;
}