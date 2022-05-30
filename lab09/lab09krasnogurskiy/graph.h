#pragma once

class Graph
{
public:
    Graph() = default;
    Graph(size_t _size);
    ~Graph();
    void addEdge(size_t vertex1, size_t vertex2, size_t weight);
    void removeEdge(size_t vertex1, size_t vertex2);
    int dijkstra(int src, int to);
private:
    int minDistance(int* dist, bool* sptSet);
    void printSolution(int* dist);
    size_t size;
    int** graph;
};