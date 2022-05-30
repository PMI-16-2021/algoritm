#include "pch.h"
#include <gtest/gtest.h>
#include "..//Dijkstra algorithm/Graph.cpp"

Graph graph(6);

/*
 *      Матриця суміжності неорінтованого графа                                     Найкоротші шляхи, якщо початкова точка (а):
 *          a   b   c   d   e   z                                                   a   b   c   d   e   z
 *      a   0   4   2   0   0   0                                                   0   3   2   5   5   10
 *      b   4   0   1   2   3   0                                                   -   c   a   b   c   e
 *      c   2   1   0   0   3   0                                                   Найкоротші шляхи, якщо початкова точка (d):
 *      d   0   2   0   0   1   10                                                  a   b   c   d   e   z
 *      e   0   3   3   1   0   5                                                   5   2   3   0   1   6
 *      z   0   0   0   10  5   0                                                   c   d   b   -   d   e
 *
 *      a-0, b-1, c-2, d-3, e-4, z-5
 */

TEST(DijkstraAlgorithmTest, add)
{
    EXPECT_NO_THROW(graph.add(0, 1, 4));
    EXPECT_NO_THROW(graph.add(0, 2, 2));
    EXPECT_NO_THROW(graph.add(1, 2, 1));
    EXPECT_NO_THROW(graph.add(1, 3, 2));
    EXPECT_NO_THROW(graph.add(1, 4, 3));
    EXPECT_NO_THROW(graph.add(2, 4, 3));
    EXPECT_NO_THROW(graph.add(3, 4, 1));
    EXPECT_NO_THROW(graph.add(3, 5, 10));
    EXPECT_NO_THROW(graph.add(4, 5, 5));

    EXPECT_NO_THROW(graph.add(0, 5, 100));

    EXPECT_ANY_THROW(graph.add(10, 2, 10));
    EXPECT_ANY_THROW(graph.add(0, 22, 1));
    EXPECT_ANY_THROW(graph.add(2, 2, 10));
    EXPECT_ANY_THROW(graph.add(3, 5, 10));
}

TEST(DijkstraAlgorithmTest, remove)
{
    EXPECT_ANY_THROW(graph.remove(6, 2));
    EXPECT_ANY_THROW(graph.remove(12, 22));
    EXPECT_ANY_THROW(graph.remove(2, 2));

    EXPECT_NO_THROW(graph.remove(0, 5));
}

TEST(DijkstraAlgorithmTest, DijkstraAlgorithmAndGetDistance)
{
    EXPECT_NO_THROW(graph.dijkstra(0));
    EXPECT_EQ(graph.getDistance(0), 0);
    EXPECT_EQ(graph.getDistance(1), 3);
    EXPECT_EQ(graph.getDistance(2), 2);
    EXPECT_EQ(graph.getDistance(3), 5);
    EXPECT_EQ(graph.getDistance(4), 5);
    EXPECT_EQ(graph.getDistance(5), 10);

    EXPECT_NO_THROW(graph.dijkstra(3));
    EXPECT_EQ(graph.getDistance(0), 5);
    EXPECT_EQ(graph.getDistance(1), 2);
    EXPECT_EQ(graph.getDistance(2), 3);
    EXPECT_EQ(graph.getDistance(3), 0);
    EXPECT_EQ(graph.getDistance(4), 1);
    EXPECT_EQ(graph.getDistance(5), 6);

    EXPECT_ANY_THROW(graph.dijkstra(6));
    EXPECT_ANY_THROW(graph.dijkstra(10));
    EXPECT_ANY_THROW(graph.dijkstra(-5));
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
