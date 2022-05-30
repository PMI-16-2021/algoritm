#include<iostream>
#include "graph.h"
using namespace std;

int main()
{
	Graph G(6);
	G.addEdge(0, 1, 1);
	G.addEdge(0, 2, 2);
	G.addEdge(1, 3, 3);
	G.addEdge(1, 4, 4);
	G.addEdge(3, 5, 5);
	G.addEdge(4, 5, 6);

	cout << "The shortest distance from 3 to 4: " << G.dijkstra(2, 3);
	cout << "\n\n";

	system("pause");
	return 0;
}