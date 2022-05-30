#include <iostream>
#include "set.h"
using namespace std;

int main()
{
   Set S1;
   S1.add('7');
   S1.add('1'); 
   S1.add('h');
   Set S2;
   S2.add('6'); 
   S2.add('4'); 
   S2.add('i'); 

   cout << "Intersection set: \n";
   Set intersectionSet = S1.intersection(S2);
   intersectionSet.print();

   cout << "Union set: \n";
   Set unionSet = S1.unionSet(S2);
   unionSet.print();
  
   cout << "Difference set: \n";
   Set differenceSet = S1.difference(S2);
   differenceSet.print();

   cout << "Symmetric difference set: \n";
   Set symmetricDifferenceSet = S1.symmetric_difference(S2);
   symmetricDifferenceSet.print();

	system("pause");
	return 0;
}