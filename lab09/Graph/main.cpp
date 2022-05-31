#include<iostream>
#include"graph.h"
using namespace std;
int main() {
	vector<int>vertex = { 1,2,3,4,5 };
    vector<vector<int>> edge = { {1,2,3}, {4,5,6}, {23,5,3}, {2,4,8}, {3,5,6}};
    Graph graph(vertex, edge);
    graph.Print();
    graph.Dijkstra(1, 5);
    graph.Dijkstra(1, 3);
	system("pause");
	return 0;
}