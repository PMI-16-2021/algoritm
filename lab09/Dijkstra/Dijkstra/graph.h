#pragma once

#include <vector>
#include <iostream>
#include <iomanip>
#include <queue>


class Graph {
private:
    class Node {
    public:
        char name;
        int time = 2147483647;
        bool checked = false;
        std::vector<Node*> neighbours;
        std::vector<int> lengths;
        Node() = default;
        Node(char name) {
            this->name = name;
        }
    };
    std::vector<Node*> nodes;
public:
    Graph() = default;
    Graph(std::vector<char> vertex, std::vector<std::vector<int>> matrix);
    void scanGraph();
    void printGraph();
    std::vector<int> Dijkstra(char start);

};