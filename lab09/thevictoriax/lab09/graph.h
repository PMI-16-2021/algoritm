#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>

class Graph 
{
private:
    class GraphNode 
    {
    public:
        std::vector<GraphNode*> near;
        std::vector<int> size;
        char name;
      
        GraphNode() = default;
        GraphNode(char name)
        {
            this->name = name;
        }
        int time = 2147483647;
        bool check = false;
    };
    std::vector<GraphNode*> nodes;
public:
    Graph() = default;
    Graph(std::vector<char> vertex, std::vector<std::vector<int>> matrix);
    std::vector<int> algorithm(char);
    void walkThrough();
    void print();
};