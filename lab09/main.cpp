#include "dijkstraAlgorithm.h"
using namespace std;

int main()
{
	Graph G(7);
	G.addEdge(0, 1, 14);
	G.addEdge(0, 2, 9);
	G.addEdge(1, 3, 6);
	G.addEdge(1, 4, 3);
	G.addEdge(3, 5, 4);
	G.addEdge(3, 6, 2);
	G.addEdge(4, 5, 8);

	cout << "Minimal distance from " << 1 << " to " << 5 << ": " << G.dijkstra(1, 5);
	cout << '\n';
	return 0;
}