#pragma once
#include <iostream>
struct Djkstra
{
	int vertex1, 
		vertex2, 
		distance;
};

class Graph
{
private:
	size_t amount;
	int** matrix;

public:
	//Graph();
	Graph(int size);
	~Graph();
	void add_edge(int v1, int v2, size_t weight);
	void djskra(int start) const;





};

