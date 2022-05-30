#include <iostream>
#include "graph.h"
using namespace std;

int main()
{
	Graph graph({ 'a', 'b', 'c', 'd', 'e', 'f' },
		{ {1, 5, 7, 0, 0, 0},
		{ 3, 1, 2, 4, 0, 0},
		{5, 1, 0, 3, 7, 0},
		{ 2, 4, 0, 0, 1, 4},
		{1, 1, 0, 3, 0, 4},
		{0, 1, 0, 3, 7, 4} });

	graph.algorithm('e');

	
	return 0;
}