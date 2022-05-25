#include <Stack.h>
#include <gtest/gtest.h>


TEST(StackTestSuite, isEmptyChecking) {
    Stack stack1;
    Stack stack2;
    Stack stack3;
    stack1.push(3);
    stack2.push(3);
    stack2.pop();

    EXPECT_FALSE(stack1.isEmpty());
    EXPECT_TRUE(stack2.isEmpty());
    EXPECT_TRUE(stack3.isEmpty());
}


TEST(StackTestSuite, pushAndPopChecking) {
    Stack stack1;
    Stack stack2;
    Stack stack3;
    stack1.push(3);
    stack1.push(4.5);
    stack2.push(3);
    stack2.pop();
    stack3.push(1);
    stack3.push(5);
    stack3.pop();

    EXPECT_EQ(stack1.top(), 4.5);
    EXPECT_EQ(stack2.top(), 0);
    EXPECT_EQ(stack3.top(), 1);
}

TEST(StackTestSuite, topChecking) {
    Stack stack1;
    Stack stack2;
    Stack stack3;
    stack1.push(3);
    stack1.push(4);
    stack2.push(3);
    stack2.pop();
    stack3.push(1);
    stack3.push(5);
    stack3.pop();

    EXPECT_EQ(stack1.top(), 4);
    EXPECT_EQ(stack1.top(), 4); //check whether top doesn't change or delete elements if we use it twice
    EXPECT_EQ(stack2.top(), 0);
    EXPECT_EQ(stack3.top(), 1);
}

TEST(StackTestSuite, emptyChecking) {
    Stack stack1;
    Stack stack2;
    Stack stack3;
    stack1.push(3);
    stack1.push(4);
    stack2.push(3);
    stack2.push(3);
    stack1.push(2.1);
    stack1.empty();
    stack3.empty();

    EXPECT_TRUE(stack1.isEmpty());
    EXPECT_FALSE(stack2.isEmpty());
    EXPECT_TRUE(stack3.isEmpty());
}

TEST(StackTestSuite, emplaceChecking) {
    Stack stack1;
    Stack stack2;
    Stack stack3;
    stack1.push(3.4);
    double z = 1.3;
    stack1.emplace(z);
    double a = -3.14;
    stack2.emplace(a);
    stack3.push(0);
    stack3.push(-3.2);
    stack3.push(24.5);
    stack3.pop();
    double k = -4.3;
    stack3.emplace(k);

    EXPECT_EQ(stack1.top(), 1.3);
    EXPECT_EQ(stack2.top(), -3.14);
    EXPECT_EQ(stack3.top(), -4.3);
}

TEST(StackTestSuite, swapChecking) {
    Stack stack1;
    Stack stack2;
    Stack stack3;
    stack2.push(3.1);
    stack2.push(67);
    stack2.push(-26.4);
    stack3.push(0);
    stack3.push(-3.2);
    stack3.push(24.5);
    stack2.swap(stack3);

    EXPECT_EQ(stack2.size(), stack3.size());
    EXPECT_EQ(stack2.top(), 24.5);
    EXPECT_EQ(stack3.top(), -26.4);

    stack3.swap(stack1);
    EXPECT_EQ(stack1.top(), -26.4);
    EXPECT_TRUE(stack3.isEmpty());
}