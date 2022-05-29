#include<iostream>
#include "list.h"
#include "set.h"
using namespace std;

struct NodeGraph {
    int dest;
    int cost;
    NodeGraph() : dest(0), cost(0) {}
    NodeGraph(int _dest, int _cost) : dest(_dest), cost(_cost) {}
};

class Graph {
private:
    int count;
    List<NodeGraph>* adj_list;
    int* dist;
    int* prev;
    void ShowList(int src, List<NodeGraph> lt) const;
public:
    Graph();
    Graph(int _count);
    ~Graph();
    void AddEdge(int _source, int _dest, int _cost);
    int GetCountVertex() const;
    int GetDegreeVertex(int v) const;
    int GetCountEdge() const;
    void RemoveEdge(int from, int to);
    bool FindEdge(int from, int to) const;
    int GetCost(int from, int to) const;
    bool IsEmpty() const;
    void DisplayEdges() const;
    void Dijkstra(int _start);
    int* GetPrev();
    int* GetDist();
};