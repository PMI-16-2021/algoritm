#include "graph.h"
#include <iostream>
int main()
{
	Graph g(6);
	g.addEdge(0, 1, 10);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 3, 4);
	g.addEdge(1, 4, 8);
	g.addEdge(3, 4, 1);
	g.addEdge(4, 5, 2);
	g.addEdge(2, 5, 11);

	std::cout << g.dijkstra(3, 5) << std::endl;
	return 0;
}