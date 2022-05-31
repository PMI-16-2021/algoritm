#include <iostream>
#include "plurall.h"
using namespace std;

int main() {
	Set s;
	s.add(2);
	s.add(6);
	s.add(4);
	s.add(5);
	s.add(4);
	s.print();
	Set s1;
	s1.add(1);
	s1.add(2);
	s1.add(3);
	s1.add(4);
	s1.print();

	Set res;
	//res = s.unionn(s1);
	//res = s.intersection(s1);
	//res = s.difference(s1);
	res = s.symmetricDifference(s1);

	res.print();

	system("pause");
	return 0;
}