#include <stdio.h>
#include <iostream>
#include "graph.h"
using namespace std;

int main() {
    Graph gr(8);
    gr.setVertex(0, 1, 4);
    gr.setVertex(0, 4, 3);
    gr.setVertex(1, 4, 2);
    gr.setVertex(1, 2, 5);
    gr.setVertex(2, 4, 3);
    gr.setVertex(4, 5, 6);
    gr.setVertex(2, 5, 1);
    gr.setVertex(2, 3, 5);
    gr.setVertex(5, 6, 5);
    gr.setVertex(3, 6, 2);
    gr.setVertex(3, 7, 7);
    gr.setVertex(6, 7, 4);

    gr.printGraph();

    gr.dijkstra(0);
    gr.printSolution(gr.dijkstra(0), gr.getNumberOfVertexes());

    system("pause");
    return 0;
}