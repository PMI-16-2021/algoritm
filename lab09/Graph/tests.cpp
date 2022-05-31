#include "tests.h"

void TestDijkstra() {
    Graph graph;
    graph.AddVertex(0);
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);
    graph.AddVertex(4);
    graph.AddVertex(5);
    graph.AddVertex(6);
    graph.AddVertex(7);
    graph.AddEdge(0,1,6);
    graph.AddEdge(0,2,5);
    graph.AddEdge(1,5,6);
    graph.AddEdge(2,3,3);
    graph.AddEdge(2,7,10);
    graph.AddEdge(2,5,7);
    graph.AddEdge(3,4,2);
    graph.AddEdge(5,6,6);
    graph.AddEdge(6,7,4);
    graph.AddEdge(4,5,1);
    int res = graph.DijkstraAlg(0,5);
    if(res == 11) {
        std::cout<< "test passed\n";
    }
    else {
        std::cerr << "test failed\n";
    }
}