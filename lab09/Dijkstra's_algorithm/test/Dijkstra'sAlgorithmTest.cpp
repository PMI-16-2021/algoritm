#include <gtest/gtest.h>
#include <Graph.h>

TEST(DjikstraAlgorithmTestSuite, isEdgeTest) {
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

    EXPECT_FALSE(graph1.isEdge(0, 2));
    EXPECT_TRUE(graph1.isEdge(2, 4));
}

TEST(DjikstraAlgorithmTestSuite, displayTest) {
    //here we use catcher of console output to check if information about graph visualises correct
    //as graph in our imagination is usually visual object
    Graph graph1(4);
    graph1.addEdgeDirectedWeight(0, 1, 10);
    graph1.addEdgeDirectedWeight(2, 1, 5);
    graph1.addEdgeDirectedWeight(1, 2, 1);
    graph1.addEdgeDirectedWeight(2, 2, 2);
    testing::internal::CaptureStdout();
    graph1.display();
    std::string output = testing::internal::GetCapturedStdout();
    std::string correctOutput = "\t   0 1 2 3 \n"
                                "Node[0] ->  0 10 0 0\n"
                                "Node[1] ->  0 0 1 0\n"
                                "Node[2] ->  0 5 2 0\n"
                                "Node[3] ->  0 0 0 0\n\n";
    EXPECT_EQ(output, correctOutput);
}

TEST(DjikstraAlgorithmTestSuite, initializeStateTest) {
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

    graph1.initializeState();
    graph1.showBasicInfo();
    testing::internal::CaptureStdout();
    std::string output = testing::internal::GetCapturedStdout();
    std::string correctOutput = "node: 0 Key: 0 distance: 2147483647 parent: -1\n"
                                "node: 1 Key: 0 distance: 2147483647 parent: -1\n"
                                "node: 2 Key: 0 distance: 2147483647 parent: -1\n"
                                "node: 3 Key: 0 distance: 2147483647 parent: -1\n"
                                "node: 4 Key: 0 distance: 2147483647 parent: -1\n\n";
}

TEST(DjikstraAlgorithmTestSuite, isAllKeyTrueTest) {
    Graph graph1(4);
    graph1.addEdgeDirectedWeight(0, 1, 10);
    graph1.addEdgeDirectedWeight(0, 2, 5);
    graph1.addEdgeDirectedWeight(0, 3, 1);
    graph1.addEdgeDirectedWeight(1, 0, 2);
    graph1.addEdgeDirectedWeight(0, 0, 4);
    graph1.addEdgeDirectedWeight(1, 1, 3);
    graph1.addEdgeDirectedWeight(1, 2, 9);
    graph1.addEdgeDirectedWeight(1, 3, 2);
    graph1.addEdgeDirectedWeight(2, 0, 7);
    graph1.addEdgeDirectedWeight(2, 1, 6);
    graph1.addEdgeDirectedWeight(2, 2, 3);
    graph1.addEdgeDirectedWeight(2, 3, 9);
    graph1.addEdgeDirectedWeight(3, 0, 2);
    graph1.addEdgeDirectedWeight(3, 1, 7);
    graph1.addEdgeDirectedWeight(3, 2, 6);
    graph1.addEdgeDirectedWeight(3, 3, 6);
    graph1.initializeState();
    graph1.setValueToNode(0, 7);
    graph1.setValueToNode(1, 2);
    graph1.setValueToNode(3, -2);
    EXPECT_FALSE(graph1.isAllKeyTrue());
    graph1.setValueToNode(2, 10);
    EXPECT_TRUE(graph1.isAllKeyTrue());
}

TEST(DjikstraAlgorithmTestSuite, findMinDistanceNodeTest) {
    Graph graph1(3);
    graph1.addEdgeDirectedWeight(0, 1, 10);
    graph1.addEdgeDirectedWeight(0, 2, 5);
    graph1.Dijkstra(0);

    EXPECT_EQ(graph1.findMinDistanceNode(), 1);
}

TEST(DjikstraAlgorithmTestSuite, DjikstraTest) {
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
    graph1.initializeState();
    testing::internal::CaptureStdout();
    graph1.Dijkstra(0);
    std::string output = testing::internal::GetCapturedStdout();
    std::string correctOutput = "\n"
                                "Dijkstra Shortest Path starts . . . \n"
                                "min: 0\n"
                                "Min Distant Node: 0 Cost: 0\n"
                                "Shortest Path: -1->0, Destination Node's cost is: 0\n"
                                "node: 0 Key: 1 distance: 0 parent: -1\n"
                                "node: 1 Key: 0 distance: 10 parent: 0\n"
                                "node: 2 Key: 0 distance: 2147483647 parent: -1\n"
                                "node: 3 Key: 0 distance: 5 parent: 0\n"
                                "node: 4 Key: 0 distance: 2147483647 parent: -1\n"
                                "min: 1\n"
                                "min: 3\n"
                                "Min Distant Node: 3 Cost: 5\n"
                                "Shortest Path: 0->3, Destination Node's cost is: 5\n"
                                "node: 0 Key: 1 distance: 0 parent: -1\n"
                                "node: 1 Key: 0 distance: 8 parent: 3\n"
                                "node: 2 Key: 0 distance: 14 parent: 3\n"
                                "node: 3 Key: 1 distance: 5 parent: 0\n"
                                "node: 4 Key: 0 distance: 7 parent: 3\n"
                                "min: 1\n"
                                "min: 4\n"
                                "Min Distant Node: 4 Cost: 7\n"
                                "Shortest Path: 3->4, Destination Node's cost is: 7\n"
                                "node: 0 Key: 1 distance: 0 parent: -1\n"
                                "node: 1 Key: 0 distance: 8 parent: 3\n"
                                "node: 2 Key: 0 distance: 13 parent: 4\n"
                                "node: 3 Key: 1 distance: 5 parent: 0\n"
                                "node: 4 Key: 1 distance: 7 parent: 3\n"
                                "min: 1\n"
                                "Min Distant Node: 1 Cost: 8\n"
                                "Shortest Path: 3->1, Destination Node's cost is: 8\n"
                                "node: 0 Key: 1 distance: 0 parent: -1\n"
                                "node: 1 Key: 1 distance: 8 parent: 3\n"
                                "node: 2 Key: 0 distance: 9 parent: 1\n"
                                "node: 3 Key: 1 distance: 5 parent: 0\n"
                                "node: 4 Key: 1 distance: 7 parent: 3\n"
                                "min: 2\n"
                                "Min Distant Node: 2 Cost: 9\n"
                                "Shortest Path: 1->2, Destination Node's cost is: 9\n"
                                "node: 0 Key: 1 distance: 0 parent: -1\n"
                                "node: 1 Key: 1 distance: 8 parent: 3\n"
                                "node: 2 Key: 1 distance: 9 parent: 1\n"
                                "node: 3 Key: 1 distance: 5 parent: 0\n"
                                "node: 4 Key: 1 distance: 7 parent: 3\n";
    EXPECT_EQ(output, correctOutput);
}
