#pragma once
#include "dijkstraAlgorithm.h"
#define MIN 9999

Graph::Graph() : size(5), count(0) {
    graphArray = new int* [size];
    for (int i = 0; i < size; i++) {
        graphArray[i] = new int[size];
        for (int j = 0; j < size; j++) {
            graphArray[i][j] = 0;
        }
    }
}

Graph::Graph(int _size) : size(_size), count(0) {
    graphArray = new int* [size];
    for (int i = 0; i < size; i++) {
        graphArray[i] = new int[size];
        for (int j = 0; j < size; j++) {
            graphArray[i][j] = 0;
        }
    }
}

Graph::~Graph() {
    for (int i = 0; i < size; ++i) {
        delete[] graphArray[i];
    }
    delete[] graphArray;
}

int Graph::minDistance(int* distance, bool* shortPath) {
    int min = MIN;
    int minIndex;
    for (int i = 0; i < size; i++) {
        if (shortPath[i] == false && distance[i] <= min) {
            min = distance[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void Graph::addEdge(int vertex1, int vertex2, int cost) {
    if (vertex1 == vertex2 || vertex1 >= size || vertex2 >= size || graphArray[vertex1][vertex2] != 0) {
        throw "This vertex is already used or >= size";
    }
    graphArray[vertex1][vertex2] = cost;
    graphArray[vertex2][vertex1] = cost;
    ++count;
}

void Graph::removeEdge(int vertex1, int vertex2) {
    if (vertex1 == vertex2 || vertex1 >= size || vertex2 >= size) {
        throw "This vertex is >= size";
    }
    graphArray[vertex1][vertex2] = 0;
    graphArray[vertex2][vertex1] = 0;
    --count;
}

int Graph::getCost(int vertex1, int vertex2) {
    return graphArray[vertex1][vertex2];
}

int Graph::countEdges() {
    return count;
}

int Graph::dijkstra(int from, int to) {
    if (from >= size || to >= size) {
        throw "This vertexes are >= size";
    }
    int* distance = new int[size];
    bool* shortPath = new bool[size];
    for (int i = 0; i < size; i++) {
        distance[i] = MIN;
        shortPath[i] = false;
    }
    distance[from] = 0;
    for (int count = 0; count < size - 1; count++) {
        int minDist = minDistance(distance, shortPath);
        shortPath[minDist] = true;
        for (int v = 0; v < size; v++) {
            if (!shortPath[v] && graphArray[minDist][v] != 0 && distance[minDist] != MIN && distance[minDist] + graphArray[minDist][v] < distance[v]) {
                distance[v] = distance[minDist] + graphArray[minDist][v];
            }
        }
    }
    for (int i = 0; i < size; i++) {
        std::cout << i << " to " << from << ", Cost: " << distance[i] << '\n';
    }
    return distance[to];
}