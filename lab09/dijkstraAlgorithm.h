#pragma once
#include <iostream>

class Graph
{
private:
    int size;
    int count;
    int** graphArray;
    int minDistance(int* dist, bool* sptSet);
public:
    Graph();
    Graph(int _size);
    ~Graph();

    void addEdge(int vertex1, int vertex2, int weight);
    void removeEdge(int vertex1, int vertex2);
    int getCost(int vertex1, int vertex2);
    int countEdges();
    int dijkstra(int from, int to);
};