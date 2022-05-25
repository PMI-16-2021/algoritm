#include "Markov.h"

int main()
{
	vector<Substitution> substitutions;
	String message("aaaaaaaaa");
	Substitution substitution1("aa", "a", false);
	substitutions.push_back(substitution1);
	Substitution substitution2("bb", "b", false);
	substitutions.push_back(substitution2);
	Substitution substitution3("cc", "c", true);
	substitutions.push_back(substitution3);
	cout << "Substitutions : " << endl;
	for (vector<Substitution>::iterator i = substitutions.begin(); i != substitutions.end(); i++)
	{
		cout << *i;
	}
	String result = Markov(message, substitutions);
	cout << "String before: " << message << endl;
	cout << "String after: " << result << endl;
}