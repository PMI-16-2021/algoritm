#pragma once
#include<iostream>
#include<list>

class Graph
{
private:
    int V;
    std::list<std::pair<int, int>>* adj;
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void shortestPath(int s);
};


