#include "graph.h"
using namespace std;

Graph::Graph() {
    int** graph_ = new int* [5];
    for (size_t i = 0; i < 5; i++) {
        graph_[i] = new int[5];
        for (size_t j = 0; j < 5; j++) {
            graph_[i][j] = 0;
        }
    }
    this->graph_ = graph_;
    this->number_of_vertexes_ = 5;
}

Graph::Graph(int number_of_vertexes_) {
    this->number_of_vertexes_ = number_of_vertexes_;
    this->graph_ = new int* [number_of_vertexes_];
    for (int i = 0; i < number_of_vertexes_; ++i) {
        this->graph_[i] = new int[number_of_vertexes_];
        for (size_t j = 0; j < number_of_vertexes_; ++j) {
            this->graph_[i][j] = 0;
        }
    }
}

Graph::~Graph() {
    delete[]graph_;
}

int Graph::getNumberOfVertexes() {
    return number_of_vertexes_;
}

void Graph::setVertex(int row, int col, int weight) {
    if (this->graph_[row][col] != 0) {
        cout << "You can't add vertex there!\n";
        exit(EXIT_FAILURE);
    }
    else {
        this->graph_[row][col] = weight;
        this->graph_[col][row] = weight;
    }
}

int Graph::getWeight(int row, int col) {
    return graph_[row][col];
}

bool Graph::areAdjacent(int first_vertex, int second_vertex) {
    return this->graph_[first_vertex][second_vertex] != 0;
}

int Graph::minDistance(vector<int> dist, vector<bool> t_set) {
    int min = INT_MAX;
    size_t min_index = 0;
    for (size_t i = 0; i < this->number_of_vertexes_; i++) {
        if (t_set[i] == false && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

vector<int> Graph::dijkstra(int src) {
    vector<int> dist(this->number_of_vertexes_, INT_MAX);
    vector<bool> t_set(this->number_of_vertexes_, false);
    dist[src] = 0;
    for (size_t count = 0; count < (this->number_of_vertexes_ - 1); count++) {
        int u = minDistance(dist, t_set);
        t_set[u] = true;
        for (int v = 0; v < this->number_of_vertexes_; v++) {
            if (!t_set[v] && this->graph_[u][v] && dist[u] != INT_MAX && dist[u] + this->graph_[u][v] < dist[v]) {
                dist[v] = dist[u] + this->graph_[u][v];
            }
        }
    }
    return dist;
}

void Graph::printSolution(vector<int> dist, int n) {
    cout << "Vertex   Distance from the beginning\n";
    for (size_t i = 0; i < number_of_vertexes_; i++) {
        cout << i << "\t\t" << dist[i] << "\n";
    }
}

void Graph::printGraph() {
    cout << "Matrix: \n";
    for (size_t i = 0; i < this->number_of_vertexes_; i++) {
        for (size_t j = 0; j < this->number_of_vertexes_; j++) {
            cout << this->graph_[i][j] << "  ";
        }
        cout << "\n";
    }
}