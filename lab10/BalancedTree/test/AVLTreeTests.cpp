//
// Created by Ostap Kilbasovych on 26.05.2022.
//

#include <gtest/gtest.h>
#include "AVLTree.h"

TEST(AVLTreeTestSuite, heightMetodTest) {
    avlTree avl;
    EXPECT_EQ(avl.height(avl.root), 0);
    avl.root = avl.insert(avl.root, 4);
    avl.root = avl.insert(avl.root, 2);
    avl.root = avl.insert(avl.root, 3);
    avl.root = avl.insert(avl.root, 1);
    EXPECT_EQ(avl.height(avl.root), 3);
}

TEST(AVLTreeTestSuite, heightDifferenceMetodTest) {
    avlTree avl;
    avl.root = avl.insert(avl.root, 4);
    avl.root = avl.insert(avl.root, 2);
    avl.root = avl.insert(avl.root, 3);
    avl.root = avl.insert(avl.root, 1);
    avl.root = avl.insert(avl.root, 8);
    avl.root = avl.insert(avl.root, 11);
    avl.root = avl.insert(avl.root, 13);
    avl.root = avl.insert(avl.root, 10);
    EXPECT_EQ(avl.heightDifference(avl.root), -1);
}

TEST(AVLTreeTestSuite, insertMethodTest) {
    avlTree avl;
    avl.root = avl.insert(avl.root, 4);
    avl.root = avl.insert(avl.root, 2);
    avl.root = avl.insert(avl.root, 3);
    avl.root = avl.insert(avl.root, 1);
    avl.root = avl.insert(avl.root, 8);
    avl.root = avl.insert(avl.root, 11);
    avl.root = avl.insert(avl.root, 13);
    avl.root = avl.insert(avl.root, 10);

    testing::internal::CaptureStdout();
    avl.postorder(avl.root);
    std::string correctPostOrder = testing::internal::GetCapturedStdout();
    EXPECT_EQ("1  2  4  10  13  11  8  3  ", correctPostOrder);
}

TEST(AVLTreeTestSuite, removeMethodTest) {
    avlTree avl;
    avl.root = avl.insert(avl.root, 4);
    avl.root = avl.insert(avl.root, 2);
    avl.root = avl.insert(avl.root, 3);


    avl.root = avl.remove(avl.root, 4);
    testing::internal::CaptureStdout();
    avl.postorder(avl.root);
    std::string correctPostOrder = testing::internal::GetCapturedStdout();
    EXPECT_EQ("2  3  ", correctPostOrder);
}

TEST(AVLTreeTestSuite, findMaxMethodTest) {
    avlTree avl;
    avl.root = avl.insert(avl.root, 4);
    avl.root = avl.insert(avl.root, 2);
    avl.root = avl.insert(avl.root, 3);
    avl.root = avl.findMax(avl.root);

    EXPECT_EQ(4, avl.root->data);
}

TEST(AVLTreeTestSuite, findMinMethodTest) {
    avlTree avl;
    avl.root = avl.insert(avl.root, 4);
    avl.root = avl.insert(avl.root, 2);
    avl.root = avl.insert(avl.root, 3);
    avl.root = avl.findMin(avl.root);

    EXPECT_EQ(2, avl.root->data);
}

TEST(AVLTreeTestSuite, postOrderMethodTest) {
    avlTree avl;
    avl.root = avl.insert(avl.root, 4);
    avl.root = avl.insert(avl.root, 2);
    avl.root = avl.insert(avl.root, 3);
    avl.root = avl.insert(avl.root, 1);
    avl.root = avl.insert(avl.root, 8);
    avl.root = avl.insert(avl.root, 11);
    avl.root = avl.insert(avl.root, 13);
    avl.root = avl.insert(avl.root, 10);

    testing::internal::CaptureStdout();
    avl.postorder(avl.root);
    std::string correctPostOrder = testing::internal::GetCapturedStdout();
    EXPECT_EQ("1  2  4  10  13  11  8  3  ", correctPostOrder);
}

TEST(AVLTreeTestSuite, preOrderMethodTest) {
    avlTree avl;
    avl.root = avl.insert(avl.root, 4);
    avl.root = avl.insert(avl.root, 2);
    avl.root = avl.insert(avl.root, 3);
    avl.root = avl.insert(avl.root, 1);
    avl.root = avl.insert(avl.root, 8);
    avl.root = avl.insert(avl.root, 11);
    avl.root = avl.insert(avl.root, 13);
    avl.root = avl.insert(avl.root, 10);

    testing::internal::CaptureStdout();
    avl.preorder(avl.root);
    std::string correctPreOrder = testing::internal::GetCapturedStdout();
    EXPECT_EQ("3  2  1  8  4  11  10  13  ", correctPreOrder);
}

TEST(AVLTreeTestSuite, inOrderMethodTest) {
    avlTree avl;
    avl.root = avl.insert(avl.root, 4);
    avl.root = avl.insert(avl.root, 2);
    avl.root = avl.insert(avl.root, 3);
    avl.root = avl.insert(avl.root, 1);
    avl.root = avl.insert(avl.root, 8);
    avl.root = avl.insert(avl.root, 11);
    avl.root = avl.insert(avl.root, 13);
    avl.root = avl.insert(avl.root, 10);

    testing::internal::CaptureStdout();
    avl.inorder(avl.root);
    std::string correctInOrder = testing::internal::GetCapturedStdout();
    EXPECT_EQ("1  2  3  4  8  10  11  13  ", correctInOrder);
}

