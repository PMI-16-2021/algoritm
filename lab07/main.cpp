#include <iostream>
#include "markov.h"

using namespace std;

Str MarkovRun(Str input);
int size(char* s)
{
	int i = 0;
	while (s[i] != '\0')
		i++;
	return i - 1;
}
int main()
{
	char x1[20] = "abfx";
	char y1[20] = "abbcsdf";
	Str x(x1);
	Str y(y1);
	x.print();
	x + y;
	x.print();
	x = MarkovRun(x);
	x.print();
}

Str MarkovRun(Str input)
{
	char x[3][3] = { "ab", "bc", "x" };
	char r[3][2] = { "1", "2", "5" };
	for (int j = 0; j < 3; j++)
	{
		while (input.search(x[j]) != -1)
		{
			int wher = input.search(x[j]);
			input.del(wher, size(x[j]));
			input.in(r[j], wher);
		}
	}
	return input;
}