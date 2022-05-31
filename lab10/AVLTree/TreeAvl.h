#include <iostream>
using namespace std;

struct Node 
{
    int data{};
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
    int height;
};

class AVL_Tree
{
    Node* root;

public:
    AVL_Tree() : root(nullptr) {}

    Node* getRoot() { return root; }

    int max(int a, int b) { return (a > b ? a : b); }

    void insertNode(int stuff);

    int getHeight(Node* temp) { return ((temp == nullptr) ? -1 : temp->height); }

    int balanceFactor(Node* temp) { return (getHeight(temp->right) - getHeight(temp->left)); }

    void heightBalance(Node* temp);

    void treeFix(Node* temp);

    void rebalancer(Node* temp);

    void leftRotate(Node* x);

    void rightRotate(Node* x);

    Node* treeSearch(int stuff);

    void preorderTraversal(Node* temp);

    void postorderTraversal(Node* temp);

    void removeNode(Node* Parent, Node* curr, int stuff);

    void remove(int stuff);
};