#include<iostream>
#include"Markov.h"

using namespace std;

int main()
{

	vector<Replacement> substitutions;
	String message("LoremIpsum");
	Replacement substitution1("m", "n", false);
	substitutions.push_back(substitution1);
	Replacement substitution2("Ip", "s", false);
	substitutions.push_back(substitution2);
	Replacement substitution3("ss", "s", false);
	substitutions.push_back(substitution3);
	cout << "Substitutions : " << endl;
	for (vector<Replacement>::iterator i = substitutions.begin(); i != substitutions.end(); i++)
	{
		cout << *i;
	}
	String result = Markov(message, substitutions);
	cout << "String before: " << message << endl;
	cout << "String after: " << result << endl;





	system("pause");
	return 0;
}