#include "pch.h"
#include <gtest/gtest.h>
#include "..//Tree/AVLTree.cpp"

AVLTree tree, tree1;

TEST(TestAVLTree, insert)
{
    EXPECT_NO_THROW(tree.insert(10));
    EXPECT_NO_THROW(tree.insert(20));
    EXPECT_NO_THROW(tree.insert(30));
    EXPECT_NO_THROW(tree.insert(40));
    EXPECT_NO_THROW(tree.insert(50));
    EXPECT_NO_THROW(tree.insert(25));
    /*
     *           30
     *          /  \
     *        20   40
     *       / \     \
     *      10 25    50
     */
    EXPECT_ANY_THROW(tree.insert(10));
    EXPECT_ANY_THROW(tree.insert(30));
    EXPECT_ANY_THROW(tree.insert(25));


    EXPECT_NO_THROW(tree1.insert(2));
    EXPECT_NO_THROW(tree1.insert(1));
    EXPECT_NO_THROW(tree1.insert(3));
    /*
     *              2
     *            /   \
     *           1     3
     */
    EXPECT_ANY_THROW(tree1.insert(1));
}

TEST(TestAVLTree, height)
{
    EXPECT_EQ(tree.height(), 2);
    EXPECT_EQ(tree1.height(), 1);
}

TEST(TestAVLTree, find)
{
    EXPECT_TRUE(tree.find(25));
    EXPECT_TRUE(tree.find(25));
    EXPECT_TRUE(tree.find(25));
    EXPECT_FALSE(tree.find(1));
    EXPECT_FALSE(tree.find(2345));
    EXPECT_FALSE(tree.find(100));
}

TEST(TestAVLTree, erase)
{
    EXPECT_NO_THROW(tree.erase(10));
    EXPECT_NO_THROW(tree.erase(20));
    EXPECT_NO_THROW(tree.erase(30));
    EXPECT_NO_THROW(tree.erase(40));
    EXPECT_NO_THROW(tree.erase(50));
    EXPECT_NO_THROW(tree.erase(25));

    EXPECT_ANY_THROW(tree1.erase(30));
    EXPECT_ANY_THROW(tree1.erase(25));

    EXPECT_NO_THROW(tree1.erase(1));
    EXPECT_NO_THROW(tree1.erase(2));
    EXPECT_NO_THROW(tree1.erase(3));
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
