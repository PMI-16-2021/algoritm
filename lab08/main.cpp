#include "set.h"
using namespace std;

int main() {
	Set<int> S1;
	S1.add(14);
	S1.add(4);
	S1.add(6);
	S1.add(3);
	S1.add(13);
	cout << "Set 1:\n";
	S1.print();
	Set<int> S2;
	S2.add(2);
	S2.add(3);
	S2.add(0);
	S2.add(14);
	cout << "\nSet 2:\n";
	S2.print();
	Set<int> unio;
	cout << "\nUnion set: \n";
	unio = S1.unionSet(S2);
	unio.print();
	Set<int> intersection;
	cout << "\nIntersection set: \n";
	intersection = S1.intersectionSet(S2);
	intersection.print();
	Set<int> difference1;
	cout << "\nDifference with set 1: \n";
	difference1 = S1.differenceSet(S2);
	difference1.print();
	Set<int> difference2;
	cout << "\nDifference with set 2: \n";
	difference2 = S2.differenceSet(S1);
	difference2.print();
	Set<int> symmetricDifference;
	cout << "\nSymmetric difference set: \n";
	symmetricDifference = S1.symmetricDifferenceSet(S2);
	symmetricDifference.print();

	return 0;
}