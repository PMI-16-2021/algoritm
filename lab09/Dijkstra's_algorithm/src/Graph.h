#pragma once

class Graph {
private:
    int **adjMatrix;
    int vertexCount;
    int *key;
    int *distance;
    int *parent;
public:
    //constructor which takes amount of vertexes
    Graph(int vertexCount);

    //destructor
    ~Graph();

    //method that adds edge
    void addEdgeDirectedWeight(int i, int j, int cost);

    //method that removes edge
    void removeEdgeUndirected(int i, int j);

    //method that sets value to the node
    void setValueToNode(int i, int value);

    //method that checks if two vertexes form edge
    //if isEdge returns element otherwise returns - 0
    int isEdge(int i, int j);

    //prints graph into console output
    void display();

    //initialize elements of graph
    void initializeState();

    // prints basic info about graph
    void showBasicInfo();

    // Dijkstra's algorithm
    void Dijkstra(int startNode);

    int isAllKeyTrue(); //0 means not MST, 1 means MST (MST - мінімальне дерево покриття)

    //returns min distance from node, if isn't possible to find min distance because they aren't connected returns MAX INT from climits
    int findMinDistanceNode();

};