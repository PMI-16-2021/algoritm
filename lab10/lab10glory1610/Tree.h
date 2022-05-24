#pragma once
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

class AVL {
private:
    Node* root;
    void makeEmpty(Node* t);
    Node* insert(int data, Node* t);
    Node* singleRightRotate(Node*& t);
    Node* singleLeftRotate(Node*& t);
    Node* doubleLeftRotate(Node*& t);
    Node* doubleRightRotate(Node*& t);
    Node* findMin(Node* t);
    Node* findMax(Node* t);
    Node* remove(int data, Node* t);
    int height(Node* t);
    int getBalance(Node* t);
    void inorder(Node* t);
    void postorder(Node* t);
    void preorder(Node* t);
public:
    AVL();
    int height();
    void insert(int data);
    void remove(int data);
    void print();
};