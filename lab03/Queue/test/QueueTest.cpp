//
// Created by Ostap Kilbasovych on 11.04.2022.
//

#include <Queue.h>
#include <gtest/gtest.h>

TEST(QueueTestSuite, popChecking) {
    QueueWithPriority<int> queueWithPriority;
    queueWithPriority.Push(1, 2);
    queueWithPriority.Push(10, 1);
    queueWithPriority.Push(12, 2);
    queueWithPriority.Push(5, 5);
    queueWithPriority.Push(11, 6);
    queueWithPriority.Push(6, 7);
    queueWithPriority.Push(0, 10);
    queueWithPriority.Pop();
    queueWithPriority.Pop();
    queueWithPriority.Pop();
    queueWithPriority.Pop();

    EXPECT_EQ(queueWithPriority.Top(), 1);
}

TEST(QueueTestSuite, pushChecking) {
    QueueWithPriority<int> queueWithPriority;
    queueWithPriority.Push(1, 2);
    queueWithPriority.Push(10, 1);
    queueWithPriority.Push(12, 2);
    queueWithPriority.Push(5, 5);
    queueWithPriority.Push(11, 6);

    EXPECT_EQ(queueWithPriority.Top(), 11);
}

TEST(QueueTestSuite, clearChecking){
    QueueWithPriority<int> queueWithPriority;
    queueWithPriority.Push(1, 2);
    queueWithPriority.Push(10, 1);
    queueWithPriority.Push(12, 2);
    queueWithPriority.Push(5, 5);
    queueWithPriority.Push(11, 6);
    queueWithPriority.Clear();

    EXPECT_EQ(queueWithPriority.Count(), 0);
}

TEST(QueueTestSuite, copyConstructorChecking){
    QueueWithPriority<int> queueWithPriority1;
    queueWithPriority1.Push(11, 1);
    queueWithPriority1.Push(7, 3);
    QueueWithPriority<int> queueWithPriority2(queueWithPriority1);

    EXPECT_EQ(queueWithPriority2.Top(), 7);
}

TEST(QueueTestSuite, topChecking){
    QueueWithPriority<int> queueWithPriority1;
    queueWithPriority1.Push(10, 1);
    queueWithPriority1.Push(12, 2);
    queueWithPriority1.Push(5, 5);
    queueWithPriority1.Push(11, 6);

    EXPECT_EQ(queueWithPriority1.Top(), 11);
    EXPECT_EQ(queueWithPriority1.Top(), 11);
}
