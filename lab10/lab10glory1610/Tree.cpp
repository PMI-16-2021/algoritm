#include "Tree.h"

void AVL::makeEmpty(Node* t) {
    if (t == nullptr) {
        return;
    }
    else {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
}

Node* AVL::insert(int data, Node* t) {
    if (t == nullptr) {
        t = new Node;
        t->data = data;
        t->height = 0;
        t->left = t->right = nullptr;
    }
    else if (data < t->data) {
        t->left = insert(data, t->left);
        if (height(t->left) - height(t->right) == 2) {
            if (data < t->left->data) {
                t = singleRightRotate(t);
            }
            else {
                t = doubleRightRotate(t);
            }
        }
    }
    else if (data > t->data) {
        t->right = insert(data, t->right);
        if (height(t->right) - height(t->left) == 2) {
            if (data > t->right->data) {
                t = singleLeftRotate(t);
            }
            else {
                t = doubleLeftRotate(t);
            }
        }
    }
    t->height = max(height(t->left), height(t->right)) + 1;
    return t;
}

Node* AVL::singleRightRotate(Node*& t) {
    Node* node = t->left;
    t->left = node->right;
    node->right = t;
    t->height = max(height(t->left), height(t->right)) + 1;
    node->height = max(height(node->left), t->height) + 1;
    return node;
}

Node* AVL::singleLeftRotate(Node*& t) {
    Node* node = t->right;
    t->right = node->left;
    node->left = t;
    t->height = max(height(t->left), height(t->right)) + 1;
    node->height = max(height(t->right), t->height) + 1;
    return node;
}

Node* AVL::doubleLeftRotate(Node*& t) {
    t->right = singleRightRotate(t->right);
    return singleLeftRotate(t);
}

Node* AVL::doubleRightRotate(Node*& t) {
    t->left = singleLeftRotate(t->left);
    return singleRightRotate(t);
}

Node* AVL::findMin(Node* t) {
    if (t == nullptr) {
        return 0;
    }
    else if (t->left == nullptr) {
        return t;
    }
    else {
        return findMin(t->left);
    }
}

Node* AVL::findMax(Node* t) {
    if (t == nullptr) {
        return 0;
    }
    else if (t->right == nullptr) {
        return t;
    }
    else {
        return findMax(t->right);
    }
}

Node* AVL::remove(int data, Node* t) {
    Node* temp;
    if (t == nullptr) {
        return 0;
    }
    // Searching for element
    else if (data < t->data) {
        t->left = remove(data, t->left);
    }
    else if (data > t->data) {
        t->right = remove(data, t->right);
    }
    // Element found with 2 children
    else if (t->left && t->right) {
        temp = findMin(t->right);
        t->data = temp->data;
        t->right = remove(t->data, t->right);
    }
    // With one or zero child
    else {
        temp = t;
        if (t->left == nullptr)
            t = t->right;
        else if (t->right == nullptr)
            t = t->left;
        delete temp;
    }
    if (t == nullptr) {
        return t;
    }
    t->height = max(height(t->left), height(t->right)) + 1;
    // If node is unbalanced
    // If left node is deleted, right case
    if (height(t->left) - height(t->right) == 2) {
        // right right case
        if (height(t->left->left) - height(t->left->right) == 1) {
            return singleLeftRotate(t);
        }
        // right left case
        else {
            return doubleLeftRotate(t);
        }
    }
    // If right node is deleted, left case
    else if (height(t->right) - height(t->left) == 2) {
        // left left case
        if (height(t->right->right) - height(t->right->left) == 1) {
            return singleRightRotate(t);
        }
        // left right case
        else {
            return doubleRightRotate(t);
        }
    }
    return t;
}

int AVL::height(Node* t) {
    if (t == nullptr) {
        return -1;
    }
    else {
        return t->height;
    }
}

int AVL::getBalance(Node* t) {
    if (t == nullptr) {
        return 0;
    }
    else {
        return height(t->left) - height(t->right);
    }
}

void AVL::inorder(Node* t) {
    if (t == nullptr) {
        return;
    }
    else {
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }
}

void AVL::postorder(Node* t) {
    if (t == nullptr) {
        return;
    }
    else {
        postorder(t->left);
        postorder(t->right);
        cout << t->data << " ";
    }
}

void AVL::preorder(Node* t) {
    if (t == nullptr) {
        return;
    }
    else {
        cout << t->data << " ";
        preorder(t->left);
        preorder(t->left);
    }
}

AVL::AVL() {
    root = nullptr;
}

int AVL::height() {
    if (!root) {
        return -1;
    }
    else {
        return root->height;
    }
}

void AVL::insert(int data) {
    root = insert(data, root);
}

void  AVL::remove(int data) {
    root = remove(data, root);
}

void  AVL::print() {
    inorder(root);
    cout << "\n";
}