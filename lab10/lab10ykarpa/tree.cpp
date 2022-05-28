#include "tree.h"
using namespace std;

int height_(Node* N) {
    if (N == NULL) {
        return 0;
    }
    return N->height_;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left_ != NULL) {
        current = current->left_;
    }
    return current;
}

Node* newNode(int key) {
    Node* node = new Node();
    node->key_ = key;
    node->left_ = NULL;
    node->right_ = NULL;
    node->height_ = 1; 
    return(node);
}

Node* rightRotate(Node* y) {
    Node* x = y->left_;
    Node* T2 = x->right_;
    x->right_ = y;
    y->left_ = T2;
    y->height_ = max(height_(y->left_), height_(y->right_)) + 1;
    x->height_ = max(height_(x->left_), height_(x->right_)) + 1;
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right_;
    Node* T2 = y->left_;
    y->left_ = x;
    x->right_ = T2;
    x->height_ = max(height_(x->left_), height_(x->right_)) + 1;
    y->height_ = max(height_(y->left_), height_(y->right_)) + 1;
    return y;
}

int getBalance(Node* N) {
    if (N == NULL) {
        return 0;
    }
    return height_(N->left_) - height_(N->right_);
}

Node* insert(Node* node, int key) {
    if (node == NULL) {
        return(newNode(key));
    }
    if (key < node->key_) {
        node->left_ = insert(node->left_, key);
    }
    else if (key > node->key_) {
        node->right_ = insert(node->right_, key);
    }
    else {
        return node;
    }
    node->height_ = 1 + max(height_(node->left_), height_(node->right_));

    int balance = getBalance(node);
    //Left Left Case
    if (balance > 1 && key < node->left_->key_) {
        return rightRotate(node);
    }
    //Right Right Case
    if (balance < -1 && key > node->right_->key_) {
        return leftRotate(node);
    }
    //Left Right Case
    if (balance > 1 && key > node->left_->key_) {
        node->left_ = leftRotate(node->left_);
        return rightRotate(node);
    }
    //Right Left Case
    if (balance < -1 && key < node->right_->key_) {
        node->right_ = rightRotate(node->right_);
        return leftRotate(node);
    }
    return node;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->key_) {
        root->left_ = deleteNode(root->left_, key);
    }
    else if (key > root->key_) {
        root->right_ = deleteNode(root->right_, key);
    }
    else {
        if ((root->left_ == NULL) || (root->right_ == NULL)) {
            Node* temp = root->left_ ? root->left_ : root->right_;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            }
            else {
                *root = *temp;
            }
            free(temp);
        }
        else {
            Node* temp = minValueNode(root->right_);
            root->key_ = temp->key_;
            root->right_ = deleteNode(root->right_, temp->key_);
        }
    }
    if (root == NULL) {
        return root;
    }
    root->height_ = 1 + max(height_(root->left_), height_(root->right_));

    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left_) >= 0) {
        return rightRotate(root);
    }
    if (balance > 1 && getBalance(root->left_) < 0) {
        root->left_ = leftRotate(root->left_);
        return rightRotate(root);
    }
    // Right Right Case  
    if (balance < -1 && getBalance(root->right_) <= 0) {
        return leftRotate(root);
    }
    // Right Left Case  
    if (balance < -1 && getBalance(root->right_) > 0) {
        root->right_ = rightRotate(root->right_);
        return leftRotate(root);
    }
    return root;
}

vector<int> preOrder(Node* root, vector<int>& result) {
    if (root != NULL) {
        result.push_back(root->key_);
        preOrder(root->left_, result);
        preOrder(root->right_, result);
    }
    return result;
}

vector<int> postOrder(Node* root, vector<int>& result) {
    if (root != NULL) {
        postOrder(root->left_, result);
        postOrder(root->right_, result);
        result.push_back(root->key_);
    }
    return result;
}

vector<int> infixOrder(Node* root, vector<int>& result) {
    if (root != NULL) {
        infixOrder(root->left_, result);
        result.push_back(root->key_);
        infixOrder(root->right_, result);
    }
    return result;
}

void preOrderPrint(Node* root) {
    if (root != NULL) {
        cout << root->key_ << " ";
        preOrderPrint(root->left_);
        preOrderPrint(root->right_);
    }
}

void postOrderPrint(Node* root) {
    if (root != NULL) {
        postOrderPrint(root->left_);
        postOrderPrint(root->right_);
        cout << root->key_ << " ";
    }
}
void infixOrderPrint(Node* root) {
    if (root != NULL) {
        infixOrderPrint(root->left_);
        cout << root->key_ << " ";
        infixOrderPrint(root->right_);
    }
}