//
// Created by Ostap Kilbasovych on 26.05.2022.
//
#include "AVLTree.h"
#include <iostream>
#include <algorithm>

//method that returns height of the tree
int avlTree::height(treeNode *temp) {
    int h = 0;
    if (temp != nullptr) {
        //count left height
        int lHeight = height(temp->left);
        //count right height
        int rHeight = height(temp->right);
        //find max from leftHeight and rightHeight
        int maxHeight = std::max(lHeight, rHeight);
        h = maxHeight + 1;
    }
    return h;
}

//method that returns height difference
int avlTree::heightDifference(treeNode *temp) {
    int lHeight = height(temp->left);
    int rHeight = height(temp->right);
    int bFactor = lHeight - rHeight;
    return bFactor;
}

//method that makes right-right rotation
treeNode *avlTree::RRrotation(treeNode *parent) {
    treeNode *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

//method that makes left-left rotation
treeNode *avlTree::LLrotation(treeNode *parent) {
    treeNode *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

//method that makes left-right rotation
treeNode *avlTree::LRrotation(treeNode *parent) {
    treeNode *temp;
    temp = parent->left;
    parent->left = RRrotation(temp);
    return LLrotation(parent);
}

//method that makes right-left rotation
treeNode *avlTree::RLrotation(treeNode *parent) {
    treeNode *temp;
    temp = parent->right;
    parent->right = LLrotation(temp);
    return RRrotation(parent);
}

//method that balances tree
treeNode *avlTree::balance(treeNode *temp) {
    int balFactor = heightDifference(temp);
    if (balFactor > 1) {
        if (heightDifference(temp->left) > 0)
            temp = LLrotation(temp);
        else
            temp = LRrotation(temp);
    } else if (balFactor < -1) {
        if (heightDifference(temp->right) > 0)
            temp = RLrotation(temp);
        else
            temp = RRrotation(temp);
    }
    return temp;
}

//method that inserts value into a tree
treeNode *avlTree::insert(treeNode *root, int value) {
    if (root == nullptr) {
        root = new treeNode;
        root->data = value;
        root->left = nullptr;
        root->right = nullptr;
        return root;
    } else if (value < root->data) {
        root->left = insert(root->left, value);
        root = balance(root);
    } else if (value >= root->data) {
        root->right = insert(root->right, value);
        root = balance(root);
    }
    return root;
}

//prints tree into console output
void avlTree::display(treeNode *pointerToStart, int level) {
    int i;
    if (pointerToStart != nullptr) {
        display(pointerToStart->right, level + 1);
        printf("\n");
        if (pointerToStart == root) {
            std::cout << "Root -> ";
        }
        for (i = 0; i < level && pointerToStart != root; i++) {
            std::cout << "        ";
        }
        std::cout << pointerToStart->data;
        display(pointerToStart->left, level + 1);
    }
}

//prints elements into console output in inorder order
void avlTree::inorder(treeNode *tree) {
    if (tree == nullptr) {
        return;
    }
    inorder(tree->left);
    std::cout << tree->data << "  ";
    inorder(tree->right);
}

//prints elements into console output in preorder order
void avlTree::preorder(treeNode *tree) {
    if (tree == nullptr) {
        return;
    }
    std::cout << tree->data << "  ";
    preorder(tree->left);
    preorder(tree->right);
}

//prints elements into console output in postorder order
void avlTree::postorder(treeNode *tree) {
    if (tree == nullptr) {
        return;
    }
    postorder(tree->left);
    postorder(tree->right);
    std::cout << tree->data << "  ";
}

//method that finds min element in a tree
treeNode *avlTree::findMin(treeNode *tree) {
    if (tree == nullptr) {
        return nullptr;
    } else if (tree->left == nullptr) {
        return tree;
    } else {
        return findMin(tree->left);
    }
}

//method that finds max element in a tree
treeNode *avlTree::findMax(treeNode *tree) {
    if (tree == nullptr) {
        return nullptr;
    } else if (tree->right == nullptr) {
        return tree;
    } else {
        return findMax(tree->right);
    }
}

//method that deletes element from the tree
treeNode *avlTree::remove(treeNode *pointerToStart, int value) {
    treeNode *temp;
    // element not found
    if (pointerToStart == nullptr) {
        return nullptr;
    }
        // searching element
    else if (value < pointerToStart->data) {
        pointerToStart->left = remove(pointerToStart->left, value);
    } else if (value > pointerToStart->data) {
        pointerToStart->right = remove(pointerToStart->right, value);
    }
        // element has 2 children
    else if (pointerToStart->left && pointerToStart->right) {
        temp = findMin(pointerToStart->right);
        pointerToStart->data = temp->data;
        pointerToStart->right = remove(pointerToStart->right, pointerToStart->data);
    }
        // if element has 1 or 0 child
    else {
        temp = pointerToStart;
        if (pointerToStart->left == nullptr) pointerToStart = pointerToStart->right;
        else if (pointerToStart->right == nullptr) pointerToStart = pointerToStart->left;
        delete temp;
    }
    if (pointerToStart == nullptr) {
        return pointerToStart;
    }
    // check balanced
    pointerToStart = balance(pointerToStart);
}