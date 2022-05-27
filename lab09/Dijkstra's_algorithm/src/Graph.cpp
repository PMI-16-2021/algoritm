#include <climits>
#include <iostream>
#include "Graph.h"

//constructor which takes amount of vertexes
Graph::Graph(int vertexCount) {
    this->vertexCount = vertexCount;

    this->key = new int[vertexCount];
    this->distance = new int[vertexCount];
    this->parent = new int[vertexCount];

    adjMatrix = new int *[vertexCount];
    for (int i = 0; i < vertexCount; i++) {
        adjMatrix[i] = new int[vertexCount];
        for (int j = 0; j < vertexCount; j++)
            adjMatrix[i][j] = 0;
    }
}

//destructor
Graph::~Graph() {
    for (int i = 0; i < vertexCount; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

//initialize elements of graph
void Graph::initializeState() {
    for (int i = 0; i < this->vertexCount; i++) {
        this->key[i] = 0;                   // 0 = not in MST, 1 = in MST
        this->distance[i] = INT_MAX;        // initially distance is MAX INTEGER from climits
        this->parent[i] = -1;               // -1 = no parent, else parent
    }
}

//method that adds edge
void Graph::addEdgeDirectedWeight(int i, int j, int cost) {
    if (i >= 0 && i < vertexCount && j >= 0 && j < vertexCount) {
        adjMatrix[i][j] = cost;
    }
}

//method that sets value to the node
void Graph::setValueToNode(int i, int value) {
    this->key[i] = value;
}

//method that removes edge
void Graph::removeEdgeUndirected(int i, int j) {
    if (i >= 0 && i < vertexCount && j >= 0 && j < vertexCount) {
        adjMatrix[i][j] = 0;
        adjMatrix[j][i] = 0;
    }
}

//method that checks if two vertexes form edge
//if isEdge returns element otherwise returns - 0
int Graph::isEdge(int i, int j) {
    if (i >= 0 && i < vertexCount && j >= 0 && j < vertexCount) {
        return adjMatrix[i][j];
    } else {
        std::cout << "Invalid vertex number.\n";
        return 0;
    }
}

//prints graph into console output
void Graph::display() {
    //vertex
    int u, v;
    std::cout << "\t   ";
    for (u = 0; u < vertexCount; u++) {
        std::cout << u << " ";
    }
    for (u = 0; u < vertexCount; u++) {
        std::cout << "\nNode[" << (char) (u + 48) << "] -> ";
        for (v = 0; v < vertexCount; ++v) {
            std::cout << " " << adjMatrix[u][v];
        }
    }
    std::cout << "\n\n";
}

// prints basic info about graph
void Graph::showBasicInfo() {
    for (int i = 0; i < vertexCount; i++) {
        std::cout << "node: " << i << " Key: " << key[i]
                  << " distance: " << distance[i] << " parent: " << parent[i] << "\n";
    }
}

//0 means not MST, 1 means MST (MST - мінімальне дерево покриття)
int Graph::isAllKeyTrue() {
    for (int i = 0; i < this->vertexCount; i++) {
        if (this->key[i] == 0) {
            return 0;                               // not MST yet
        }
    }
    return 1;                                       // MST done
}

//returns min distance from node, if isn't possible to find min distance because they aren't connected returns MAX INT from climits
int Graph::findMinDistanceNode() {
    int minDistant = INT_MAX;
    int minDistantNode;

    for (int i = 0; i < vertexCount; i++) {
        if (minDistant > this->distance[i] && this->key[i] == 0) {
            //0 means that node is not in MST
            minDistantNode = i;
            minDistant = this->distance[i];
            std::cout << "min: " << minDistantNode << "\n";
        }
    }
    std::cout << "Min Distant Node: " << minDistantNode << " Cost: " << minDistant << "\n";
    return minDistantNode;
}

// Dijkstra's algorithm
void Graph::Dijkstra(int startNode) {
    std::cout << "\nDijkstra Shortest Path starts . . . \n";

    // initialization is done before call this method
    //start node's distance is 0
    this->distance[startNode] = 0;
    int minDistanceNode, i;

    // 0 means that the shortest path calculation is not done yet.
    while (!this->isAllKeyTrue()) {
        minDistanceNode = findMinDistanceNode();
        this->key[minDistanceNode] = 1;  // this node's shortes path is done
        std::cout << "Shortest Path: " << this->parent[minDistanceNode] << "->"
                  << minDistanceNode << ", Destination Node's cost is: " << distance[minDistanceNode] << "\n";

        for (i = 0; i < vertexCount; i++) {
            if (this->isEdge(minDistanceNode, i) && this->key[i] == 0) {
                if (this->distance[i] > this->distance[minDistanceNode]
                                        + adjMatrix[minDistanceNode][i]) {
                    this->distance[i] = this->distance[minDistanceNode]
                                        + adjMatrix[minDistanceNode][i];
                    this->parent[i] = minDistanceNode;
                }
            }
        }
        this->showBasicInfo();
    }

}
