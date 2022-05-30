#pragma once
#include <iostream>
#include <list>
#include <vector>

using std::list;
using std::string;
using std::vector;

class Edge {
private:
    int weight_;
    int dest_id_;  // id of the vertex to which goes edge
    string dest_city_;
public:
    Edge();
    Edge(int weight, int id, const string& city);
    int GetWeight() const;
    int GetDestId() const;
    string GetDestCity() const;
    void SetWeight(int weight);
    void SetDestId(int id);
};

class Vertex {
private:
    int id_;                // vertex identifier
    string city_;           // for example vertex is a city
    list<Edge> edge_list_;  // list of edges that are incident to this vertex

public:
    Vertex();
    Vertex(int id, string city);
    int GetId() const;
    string GetCity() const;
    list<Edge>& GetList();
    void SetId(int id);
    void SetCity(string city);
};

// non-oriented graph
class Graph {
private:
    vector<Vertex> vertices_;
    int FindVertex(int f_id) const;                  // returns position of vertex in vector
    bool HaveEdge(int id_x, int id_y);         // checks if there is such edge
    bool HaveVertex(int id);
public:
    void AddVertex(const Vertex& vertex);       // adds vertex if it is not here
    void AddVertex(int id, string city);
    bool IsAdjacent(int id_x, int id_y);        // tests whether there is an edge from the vertex x to the vertex y
    vector<Vertex> Neighbors(int id);     // returns all vertices y such that there is an edge from the vertex x to the vertex y
    void RemoveVertex(int remove_id);           // removes the vertex x, if it is there
    void AddEdge(int id_x, int id_y, int weight);           // adds the edge from the vertex x to the vertex y, if it is not there
    void RemoveEdge(int id_x, int id_y);        // removes the edge from the vertex x to the vertex y, if it is there
    void Print();
    size_t GraphSize() const;
    int Distance(int from, int to);
};