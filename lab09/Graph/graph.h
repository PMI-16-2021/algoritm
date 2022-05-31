#pragma once
#include<queue>
#include<iostream>
#include<vector>
#define infinity 100
using namespace std;

class Graph
{
private:
    int size_;
    vector<int> vertex_;
    int** matrix_;
public:
    Graph(vector<int>vertex, vector<vector<int>> edges);
    void Print();
    int Dijkstra(int start, int end);

};

Graph::Graph(vector<int> vertex, vector<vector<int>> edges) {
    this->vertex_ = vertex;
    size_ = vertex.size();
    matrix_ = new int* [size_];
    for (int i = 0; i < size_; ++i) {
        matrix_[i] = new int[size_];
    }
    for (int i = 1; i <= size_; ++i) {
        for (int j = 1; j <= size_; ++j) {
            matrix_[i - 1][j - 1] = 0;
            for (int k = 0; k < edges.size(); ++k) {
                if (edges[k][0] == i && edges[k][1] == j) {
                    matrix_[i - 1][j - 1] = edges[k][2];
                    break;
                }
            }
        }
    }
}

int Graph::Dijkstra(int start, int end) {
    --start; --end;
    vector<int> distance(size_, infinity);
    distance[start] = 0;
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, start));
    while (!q.empty()) {
        int len = q.top().first;
        int v = q.top().second;
        q.pop();
        if (len > distance[v]) continue;
        for (int i = 0; i < size_; ++i) {
            int to = i;
            int lenght = matrix_[v][i];
            if (matrix_[v][to] != 0 && distance[to] > distance[v] + lenght && lenght >= 0)
            {
                distance[to] = distance[v] + lenght;
                q.push(make_pair(distance[to], to));
            }
        }
    }
    if (distance[end] == infinity) {
        cout << "From " << start + 1 << " to " << end + 1 << " does not exist!" << endl;
        return infinity;
    }
    else {
        cout << "From " << start + 1 << " to " << end + 1 << ": " << distance[end] << endl;
        return distance[end];
    }
}

void Graph::Print() {
    for (int i = 0; i < size_; ++i) {
        for (int j = 0; j < size_; ++j) {
            cout << matrix_[i][j] << '\t';
        }
        cout << endl;
    }
}
