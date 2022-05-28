#pragma once
#include <iostream>
#include <vector>

class Node {
public:
    int key_;
    Node* left_;
    Node* right_;
    int height_;
};

int height_(Node* N);
int max(int a, int b);
Node* newNode(int key);
Node* rightRotate(Node* y);
Node* leftRotate(Node* x);
int getBalance(Node* N);

Node* deleteNode(Node* root, int key);
Node* insert(Node* node, int key);
std::vector<int> preOrder(Node* root, std::vector<int>& result);
std::vector<int> postOrder(Node* root, std::vector<int>& result);
std::vector<int> infixOrder(Node* root, std::vector<int>& result);

void preOrderPrint(Node* root);
void postOrderPrint(Node* root);
void infixOrderPrint(Node* root);