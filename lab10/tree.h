#pragma once
#include <iostream>
using namespace std;

struct AVLNode {
    friend class AVLTree;
    int key;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
}*root;

class AVLTree {
public:
    AVLTree() {
        root = nullptr;
    }
    ~AVLTree() {
        Destroy(root);
    }

    int max(int x, int y) {
        return (x > y) ? x : y;
    }
    int height(AVLNode* N) {
        if (N == nullptr) {
            return -1;
        }
        else {
            int left_height = height(N->left);
            int right_height = height(N->right);
            if (left_height > right_height) {
                return (left_height + 1);
            }
            else {
                return (right_height + 1);
            }
        }
    }
    bool isEmpty() {
        return root == nullptr;
    }

    bool search(int key) {
        AVLNode* temp = root, * parent = root;
        if (temp == nullptr) {
            cout << "\nThe AVL Tree is empty\n" << endl;
            return false;
        }
        else {
            while (temp != nullptr && temp->key != key) {
                parent = temp;
                if (temp->key < key) {
                    temp = temp->right;
                }
                else {
                    temp = temp->left;
                }
            }
        }

        if (temp == nullptr) {
            cout << "This element is NOT present in the tree!";
            return false;
        }
        else {
            cout << "\n" << "'" << key << "'" << " element is present in the tree! " << "\nIt's height is: " << temp->height << endl;
        }
        return true;
    }
    void Destroy(AVLNode* root)
    {
        if (root == nullptr) {
            return;
        }
        Destroy(root->left);
        Destroy(root->right);
        delete root;
    }

    static AVLNode* newNode(int key) {
        auto* node = (struct AVLNode*)
            malloc(sizeof(struct AVLNode));
        node->key = key;
        node->left = nullptr;
        node->right = nullptr;
        node->height = 0;
        return(node);
    }
    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }
    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }
    int getBalance(AVLNode* N) {
        if (N == nullptr) {
            return -1;
        }
        return height(N->left) - height(N->right);
    }
    AVLNode* insert(AVLNode* N, int key) {
        if (N == nullptr) {
            return(newNode(key));
        }
        if (key < N->key) {
            N->left = insert(N->left, key);
        }
        else if (key > N->key) {
            N->right = insert(N->right, key);
        }
        else {
            cout << "No duplicate values allowed!" << endl;
            return N;
        }
        N->height = max(height(N->left), height(N->right)) + 1;
        int balance = getBalance(N);

        if (balance > 1 && key < N->left->key) {
            return rightRotate(N);
        }

        if (balance < -1 && key > N->right->key) {
            return leftRotate(N);
        }

        if (balance > 1 && key > N->left->key) {
            N->left = leftRotate(N->left);
            return rightRotate(N);
        }

        if (balance < -1 && key < N->right->key) {
            N->right = rightRotate(N->right);
            return leftRotate(N);
        }
        return N;
    }
    static AVLNode* minValueNode(AVLNode* N) {
        AVLNode* current = N;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }
    AVLNode* deleteNode(AVLNode* root, int key) {
        if (root == nullptr) {
            return root;
        }
        if (key < root->key) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->key) {
            root->right = deleteNode(root->right, key);
        }
        else {
            if ((root->left == nullptr) || (root->right == nullptr)) {
                AVLNode* temp = root->left ? root->left : root->right;
                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                }
                else {
                    *root = *temp;
                }
                free(temp);
            }
            else {
                struct AVLNode* temp = minValueNode(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
        }
        if (root == nullptr) {
            return root;
        }
        int balance = getBalance(root);
        if (balance == 2 && getBalance(root->left) >= 0) {
            return rightRotate(root);
        }
        if (balance == 2 && getBalance(root->left) == -1) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance == -2 && getBalance(root->right) <= 0) {
            return leftRotate(root);
        }
        if (balance == -2 && getBalance(root->right) == 1) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
    }
    

    void print(AVLNode* ptr, int level) {
        int i;
        if (ptr != nullptr) {
            print(ptr->right, level + 1);
            printf("\n");
            if (ptr == root) {
                cout << "Root -> ";
            }
            for (i = 0; i < level && ptr != root; i++) {
                cout << "        ";
            }
            cout << ptr->key;
            print(ptr->left, level + 1);
        }
    }
};

