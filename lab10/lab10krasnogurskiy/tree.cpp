#include <iostream>
#include "tree.h"


int max(int a, int b)
{
    return (a > b) ? a : b;
}

AvlTree::AvlTree()
{
    root = nullptr;
    size = 0;
}

AvlTree::~AvlTree()
{
}

void AvlTree::insert(int key)
{
    root = insertByRoot(root, key);
    if (root)
    {
        size++;
    }
}

void AvlTree::printPreOrder()
{
    preOrder(root);
}

AvlTree::Node AvlTree::getRoot()
{
    if (root)
    {
        return *root;
    }
    else
    {
        Node* n = newNode(0);
        n->height = -1;
        return *n;
    }
}

int AvlTree::getBalanceAt(int key)
{
    return getBalance(search(root, key));
}

size_t AvlTree::getSize()
{
    return size;
}

AvlTree::Node AvlTree::getAt(int key)
{
    return *(search(root, key));
}

AvlTree::Node* AvlTree::insertByRoot(Node* subroot, int key)
{
    if (subroot == nullptr)
        return(newNode(key));

    if (key < subroot->key)
        subroot->left = insertByRoot(subroot->left, key);
    else if (key > subroot->key)
        subroot->right = insertByRoot(subroot->right, key);
    else
        return subroot;

    subroot->height = 1 + max(height(subroot->left),
        height(subroot->right));
    int balance = getBalance(subroot);

    if (balance > 1 && key < subroot->left->key)
        return rightRotate(subroot);

    if (balance < -1 && key > subroot->right->key)
        return leftRotate(subroot);

    if (balance > 1 && key > subroot->left->key)
    {
        subroot->left = leftRotate(subroot->left);
        return rightRotate(subroot);
    }

    if (balance < -1 && key < subroot->right->key)
    {
        subroot->right = rightRotate(subroot->right);
        return leftRotate(subroot);
    }

    return subroot;
}

AvlTree::Node* AvlTree::search(Node* root, int key)
{
    if (root == nullptr || root->key == key)
        return root;

    if (root->key < key)
        return search(root->right, key);

    return search(root->left, key);
}

int AvlTree::height(Node* N)
{
    if (N == nullptr)
        return 0;
    return N->height;
}

AvlTree::Node* AvlTree::newNode(int key)
{
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return(node);
}

AvlTree::Node* AvlTree::rightRotate(Node* subroot)
{
    Node* left = subroot->left;
    Node* leftRight = left->right;

    left->right = subroot;
    subroot->left = leftRight;

    subroot->height = max(height(subroot->left),
        height(subroot->right)) + 1;
    left->height = max(height(left->left),
        height(left->right)) + 1;

    return left;
}

AvlTree::Node* AvlTree::leftRotate(Node* subroot)
{
    Node* right = subroot->right;
    Node* rightLeft = right->left;

    right->left = subroot;
    subroot->right = rightLeft;

    subroot->height = max(height(subroot->left),
        height(subroot->right)) + 1;
    right->height = max(height(right->left),
        height(right->right)) + 1;

    return right;
}

int AvlTree::getBalance(Node* N)
{
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

void AvlTree::preOrder(Node* root)
{
    if (root != nullptr)
    {
        std::cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int AvlTree::Node::getKey()
{
    return key;
}

int AvlTree::Node::getHeight()
{
    return height;
}
