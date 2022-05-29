#include <iostream>
#include "graph.h"
using namespace std;

int main() {
    Graph G(5);
    G.AddEdge(0, 1, 10);
    G.AddEdge(0, 3, 30);
    G.AddEdge(0, 4, 100);
    G.AddEdge(1, 2, 50);
    G.AddEdge(2, 3, 20);
    G.AddEdge(2, 4, 10);
    G.AddEdge(3, 4, 60);
    G.DisplayEdges();
    cout << "\nShortest paths: \n";
    G.Dijkstra(0);
	system("pause");
	return 0;
}