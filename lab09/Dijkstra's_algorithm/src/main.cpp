#include "Graph.h"

int main() {
    Graph graph1(5);
    graph1.addEdgeDirectedWeight(0, 1, 10);
    graph1.addEdgeDirectedWeight(0, 3, 5);
    graph1.addEdgeDirectedWeight(1, 2, 1);
    graph1.addEdgeDirectedWeight(1, 3, 2);
    graph1.addEdgeDirectedWeight(2, 4, 4);
    graph1.addEdgeDirectedWeight(3, 1, 3);
    graph1.addEdgeDirectedWeight(3, 2, 9);
    graph1.addEdgeDirectedWeight(3, 4, 2);
    graph1.addEdgeDirectedWeight(4, 0, 7);
    graph1.addEdgeDirectedWeight(4, 2, 6);

//    graph1.display();
    graph1.initializeState();
    int startNode = 0;
//    graph1.showBasicInfo();
    graph1.Dijkstra(startNode);
//    graph1.showBasicInfo();

    return 0;
}