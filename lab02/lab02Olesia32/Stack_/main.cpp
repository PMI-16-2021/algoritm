#include "set_of_stack.h"
#include <iostream>
using namespace std;

int main() {
	SetOfStack<string> S1(3, 4);
	S1.PushSet("1984");
	S1.PushSet("Lord of the Rings");
	S1.PushSet("The Little Prince");
	S1.PushSet("The Hunger Games");
	S1.PushSet("Dune");
	S1.PushSet("To Kill a Mockingbird");
	S1.PushSet("Solar machine");
	S1.PushSet("Forest Song");
	S1.PushSet("Harry Potter and the Deathly Hallows");
	cout << "Set of books: \n";
	S1.PrintSet();
	S1.EmptySet();
	S1.PrintSet();
	system("pause");
	return 0;
}