#include "graph.h"

Graph::Graph() : count(0) {}

Graph::Graph(int _count) : count(_count) {
    adj_list = new List<NodeGraph>[count];
    dist = new int[count];
    prev = new int[count];
}

Graph::~Graph() {
    delete[] adj_list;
}

void Graph::ShowList(int src, List<NodeGraph> lt) const {
    using iter = List<NodeGraph>::Iter;
    NodeGraph tempNode;
    if (lt.IsEmpty()) {
        return;
    }
    for (iter i = lt.begin(); i != lt.end(); ++i) {
        tempNode = *i;
        cout << "(" << src << ")---(" << tempNode.dest << "|" << tempNode.cost << ") ";
    }
    cout << '\n';
}

void Graph::AddEdge(int _source, int _dest, int _cost) {
    NodeGraph newNode(_dest, _cost);
    adj_list[_source].AddBack(newNode);
    NodeGraph temp(_source, _cost);
    adj_list[_dest].AddBack(temp);
}

int Graph::GetDegreeVertex(int v) const {
    if (v < 0 || v > count) {
        throw "Bad index";
    }
    List<NodeGraph> temp = adj_list[v];
    int degree = temp.SizeList();
    return degree;
}

int Graph::GetCountEdge() const {
    int edges = 0;
    for (int i = 0; i < count; ++i) {
        List<NodeGraph> temp = adj_list[i];
        edges += temp.SizeList();
    }
    return edges / 2;
}

void Graph::RemoveEdge(int from, int to) {
    if (from < 0 || from > count || to < 0 || to > count) {
        throw "Bad index";
    }
    for (int i = 0; i < adj_list[from].SizeList(); ++i) {
        if (adj_list[from][i].dest == to) {
            adj_list[from].Del(i);
        }
    }
    for (int i = 0; i < adj_list[to].SizeList(); ++i) {
        if (adj_list[to][i].dest == from) {
            adj_list[to].Del(i);
        }
    }
}

int Graph::GetCountVertex() const {
    return count;
}

bool Graph::FindEdge(int from, int to) const {
    if (from < 0 || from > count || to < 0 || to > count) {
        throw "Bad index";
    }
    List<NodeGraph> temp = adj_list[from];
    using iter = List<NodeGraph>::Iter;
    for (iter it = temp.begin(); it != temp.end(); ++it) {
        if (it->value.dest == to) {
            return true;
        }
    }
    return false;
}

int Graph::GetCost(int from, int to) const {
    if (from < 0 || from > count || to < 0 || to > count) {
        throw "Bad index";
    }
    int cost = 0;
    List<NodeGraph> temp = adj_list[from];
    using iter = List<NodeGraph>::Iter;
    for (iter it = temp.begin(); it != temp.end(); ++it) {
        if (it->value.dest == to) {
            cost = it->value.cost;
        }
    }
    return cost;
}

bool Graph::IsEmpty() const {
    return count == 0;
}

void Graph::DisplayEdges() const {
    for (int i = 0; i < count; i++) {
        List<NodeGraph> tempList = adj_list[i];
        ShowList(i, tempList);
    }
}

void Graph::Dijkstra(int _start) {
    for (int i = 0; i < count; ++i) {
        dist[i] = 10000;
        prev[i] = -1;
    }
    dist[_start] = 0;
    MySet<int> S;
    List<int> Q;
    for (int i = 0; i < count; ++i) {
        Q.AddBack(i);
    }
    while (!Q.IsEmpty()) {
        int i = Q.FindMin();
        Q.Remove(i);
        S.Add(i);
        using iter = List<NodeGraph>::Iter;
        for (iter it = adj_list[i].begin(); it != adj_list[i].end(); ++it) {
            if ((dist[i] + (it->value.cost)) < dist[it->value.dest]) {
                dist[it->value.dest] = (dist[i] + (it->value.cost));
                prev[it->value.dest] = i;
            }
        }
    }
    for (int i = 0; i < count; ++i) {
        if (i != _start) {
            cout << _start << " to " << i << ", Cost: " << dist[i] << " Previous: " << prev[i] << '\n';
        }
    }
}

int* Graph::GetPrev() {
    return prev;
}

int* Graph::GetDist() {
    return dist;
}