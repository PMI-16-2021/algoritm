#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>

class Graph {
    int** graph_;
    int number_of_vertexes_;
public:
    Graph();
    Graph(int number_of_vertexes_);
    ~Graph();

    int getNumberOfVertexes();
    void setVertex(int row, int col, int weight);
    int getWeight(int row, int col);

    bool areAdjacent(int first_vertex, int second_vertex);
    int minDistance(std::vector<int> dist, std::vector<bool> t_set);
    std::vector<int> dijkstra(int src);
    void printSolution(std::vector<int> dist, int n);
    void printGraph();
};