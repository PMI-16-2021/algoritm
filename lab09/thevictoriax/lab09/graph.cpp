#include <iostream>
#include "graph.h"
using namespace std;

Graph::Graph(std::vector<char> vertex, std::vector<std::vector<int>> matrix) 
{
    for (auto step = vertex.begin(); step < vertex.end(); step++) 
    {
        nodes.emplace_back(new GraphNode(*step));
    }
    for (int i = 0; i < matrix.size(); i++) 
    {
        for (int j = 0; j < matrix[0].size(); j++) 
        {
            if (matrix[i][j] != 0) 
            {
                nodes[i]->near.emplace_back(nodes[j]);
            }
            else 
            {
                nodes[i]->near.emplace_back(nullptr);
            }
            nodes[i]->size.emplace_back(matrix[i][j]);
        }
    }
}

std::vector<int> Graph::algorithm(char start) 
{
    int count = 0;
    for (count; nodes[count]->name != start; count++);
    GraphNode* temp = nodes[count];
    temp->time = 0;
    while (!temp->check) 
    {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
        for (int i = 0; i < temp->near.size(); i++)
        {
            if (temp->near[i]) 
            {
                if (temp->size[i] + temp->time < temp->near[i]->time) 
                {
                    temp->near[i]->time = temp->size[i] + temp->time;
                }
                if (!temp->near[i]->check) 
                {
                    q.push(std::make_pair(temp->near[i]->time, i));
                }
            }
        }
        temp->check = true;
        if (q.empty()) 
        {
            break;
        }
        else 
        {
            temp = temp->near[q.top().second];
        }
    }
    std::vector<int> result;
    for (int i = 0; i < nodes.size(); i++) 
    {
        result.push_back(nodes[i]->time);
        cout << start << " - " << nodes[i]->name << " = " << nodes[i]->time << '\n';
    }
    return result;
}

void Graph::walkThrough() 
{
    while (std::cin.peek() != '\n') 
    {
        char letter;
        cin >> letter;
        nodes.emplace_back(new GraphNode(letter));
    }
    for (int i = 0; i < nodes.size(); i++) 
    {
        for (int j = 0; j < nodes.size(); j++) 
        {
            int length;
            std::cin >> length;
            if (length != 0) {
                nodes[i]->near.emplace_back(nodes[j]);
            }
            else 
            {
                nodes[i]->near.emplace_back(nullptr);
            }
            nodes[i]->size.emplace_back(length);
        }
    }
}

void Graph::print() 
{
    for (int i = 0; i < nodes.size(); i++) 
    {
        cout << nodes[i]->name << '(';
        for (int j = 0; j < nodes.size(); j++) 
        {
            if (nodes[i]->near[j] != nullptr) 
            {
                cout << nodes[i]->near[j]->name << ',';
            }
        }
        cout << ')';
        for (int j = 0; j < nodes.size(); j++) 
        {
            cout << std::setw(4) << nodes[i]->size[j];
        }
        cout << '\n';
    }
}
