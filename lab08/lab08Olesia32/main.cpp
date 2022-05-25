#include <iostream>
#include "my_set.h"
using namespace std;

int main() {
	MySet<char> S1;
	S1.Add('e');
	S1.Add('x');
	S1.Add('a');
	S1.Add('m');
	S1.Add('p');
	S1.Add('l');
	S1.Add('e');
	S1.Print();
	MySet<char> S2;
	S2.Add('m');
	S2.Add('y');
	S2.Add('s');
	S2.Add('e');
	S2.Add('t');
	S2.Print();
	MySet<char> diff;
	MySet<char> inter;
	MySet<char> s_diff;
	MySet<char> un;
	cout << "\nDifference: \n";
	diff = S1.Difference(S2);
	diff.Print();
	cout << "\nIntersection: \n";
	inter = S1.Intersection(S2);
	inter.Print();
	cout << "\nSymmetricDifference: \n";
	s_diff = S1.SymmetricDifference(S2);
	s_diff.Print();
	cout << "\nUnion: \n";
	un = S1.Union(S2);
	un.Print();
	system("pause");
	return 0;
}