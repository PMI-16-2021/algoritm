#pragma once
#include <climits>
#include <iostream>
#include "graph.h"

int Graph::minDistance(int* dist, bool* sptSet)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < size; v++)
    {
        if (sptSet[v] == false && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}
void Graph::printSolution(int* dist)
{
    std::cout << "Vertex \t Distance from Source" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << i << " \t\t" << dist[i] << std::endl;
    }
}
Graph::Graph(size_t _size) : size(_size)
{
    graph = new int* [size];
    for (int i = 0; i < size; i++)
    {
        graph[i] = new int[size];
        for (int j = 0; j < size; j++)
        {
            graph[i][j] = 0;
        }
    }
}
Graph::~Graph()
{
    for (int i = 0; i < size; ++i)
    {
        delete[] graph[i];
    }
    delete[] graph;
}
void Graph::addEdge(size_t vertex1, size_t vertex2, size_t weight)
{
    if (vertex1 == vertex2 || vertex1 >= size || vertex2 >= size || graph[vertex1][vertex2] != 0)
    {
        throw std::invalid_argument("Invalid argument");
    }
    graph[vertex1][vertex2] = weight;
    graph[vertex2][vertex1] = weight;
}
void Graph::removeEdge(size_t vertex1, size_t vertex2)
{
    if (vertex1 == vertex2 || vertex1 >= size || vertex2 >= size)
    {
        throw std::invalid_argument("Invalid argument");
    }
    graph[vertex1][vertex2] = 0;
    graph[vertex2][vertex1] = 0;
}
int Graph::dijkstra(int src, int to)
{
    int* dist = new int[size];
    bool* sptSet = new bool[size];
    for (int i = 0; i < size; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;
    for (int count = 0; count < size - 1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < size; v++)
        {
            if (!sptSet[v] && graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printSolution(dist);
    return dist[to];
}
