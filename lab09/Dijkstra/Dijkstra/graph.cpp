#include "graph.h"

Graph::Graph(std::vector<char> vertex, std::vector<std::vector<int>> matrix) {
    for (auto step = vertex.begin(); step < vertex.end(); step++) {
        nodes.emplace_back(new Node(*step));
    }
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] != 0) {
                nodes[i]->neighbours.emplace_back(nodes[j]);
            }
            else {
                nodes[i]->neighbours.emplace_back(nullptr);
            }
            nodes[i]->lengths.emplace_back(matrix[i][j]);
        }
    }
}
void Graph::scanGraph() {
    while (std::cin.peek() != '\n') {
        char letter;
        std::cin >> letter;
        nodes.emplace_back(new Node(letter));
    }
    for (int i = 0; i < nodes.size(); i++) {
        for (int j = 0; j < nodes.size(); j++) {
            int length;
            std::cin >> length;
            if (length != 0) {
                nodes[i]->neighbours.emplace_back(nodes[j]);
            }
            else {
                nodes[i]->neighbours.emplace_back(nullptr);
            }
            nodes[i]->lengths.emplace_back(length);
        }
    }
}
void Graph::printGraph() {
    for (int i = 0; i < nodes.size(); i++) {
        std::cout << nodes[i]->name << '(';
        for (int j = 0; j < nodes.size(); j++) {
            if (nodes[i]->neighbours[j] != nullptr) {
                std::cout << nodes[i]->neighbours[j]->name << ',';
            }
        }
        std::cout << ')';
        for (int j = 0; j < nodes.size(); j++) {
            std::cout << std::setw(4) << nodes[i]->lengths[j];
        }
        std::cout << '\n';
    }
}
std::vector<int> Graph::Dijkstra(char start) {
    int index = 0;
    for (index; nodes[index]->name != start; index++);
    Node* temp = nodes[index];
    temp->time = 0;
    while (!temp->checked) {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
        for (int i = 0; i < temp->neighbours.size(); i++) {
            if (temp->neighbours[i]) {
                if (temp->lengths[i] + temp->time < temp->neighbours[i]->time) {
                    temp->neighbours[i]->time = temp->lengths[i] + temp->time;
                }
                if (!temp->neighbours[i]->checked) {
                    q.push(std::make_pair(temp->neighbours[i]->time, i));
                }
            }
        }
        temp->checked = true;
        if (q.empty()) {
            break;
        }
        else {
            temp = temp->neighbours[q.top().second];
        }
    }
    std::vector<int> result;
    for (int i = 0; i < nodes.size(); i++) {
        result.push_back(nodes[i]->time);
        std::cout << start << " - " << nodes[i]->name << " = " << nodes[i]->time << '\n';
    }
    return result;
}