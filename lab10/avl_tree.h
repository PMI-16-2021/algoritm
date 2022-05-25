#pragma once
#include <iostream>

template<typename T>
struct Node {
private:
    T value_;
    int height_;
public:
    Node* left_;
    Node* right_;
    Node();
    Node(T _val, Node<T>* _left = nullptr, Node<T>* _right = nullptr, int _height = 0);
    ~Node();
    //methods
    T GetVal() const;
    int CheckBalance() const;
    bool IsBalanced() const;
    int Height() const;
    void SetHeight(int h);
    void SetVal(int v);
    void RenewHeight();
};

template<typename T>
Node<T>::Node() {
    value_ = T(0);
    left_ = nullptr;
    right_ = nullptr;
    height_ = 0;
}

template<typename T>
Node<T>::Node(T _val, Node<T> *_left, Node<T> *_right, int _height) {
    value_ = _val;
    left_ = nullptr;
    right_ = nullptr;
    height_ = _height;
}

template<typename T>
Node<T>::~Node() {
    value_ = T(0);
    left_ = nullptr;
    right_ = nullptr;
    height_ = -1;
}

template<typename T>
int Node<T>::CheckBalance() const {
    if(this == nullptr) {
        return -1;
    }
    return left_->Height() - right_->Height();
}

template<typename T>
T Node<T>::GetVal() const {
    return value_;
}

template<typename T>
int Node<T>::Height() const {
    if(this == nullptr) {  // if requested node doesn't exists
        return -1;
    }
    return std::max(left_->Height(), right_->Height()) + 1;
}

template<typename T>
void Node<T>::SetHeight(int h) {
    height_ = h;
}

template<typename T>
void Node<T>::SetVal(int v) {
    value_ = v;
}

template<typename T>
bool Node<T>::IsBalanced() const {
    if(CheckBalance() < std::abs(2)) {
        return true;
    }
    return false;
}

template<typename T>
void Node<T>::RenewHeight() {
    SetHeight(Height());
}

// not designed for duplicate values
template<typename T>
class Tree {
private:
    Node<T>* root_;                // top root in the tree

    Node<T>* DeleteNode(Node<T>* node, T val);
    Node<T>* RotateRight(Node<T>* node);  // takes unbalanced node
    Node<T>* RotateLeft(Node<T>* node);
    Node<T>* BalanceTree(Node<T>* node);   // re-balance tree in case if insertion or deletion caused unbalancing of the node
    Node<T>* InsertRec(Node<T>* node, T val);
    Node<T>* Find(T val) const;
    Node<T>* FindMin(Node<T>* node) const;  // finds minimum element in subtree
    Node<T>* FindMax(Node<T>* node) const;  // finds maximum element in subtree
    void Print(Node<T>* node, int space) const;
    void ClearTree(Node<T>* &node);  // takes original root!!!!!

public:
    Tree();
    ~Tree();
    void Clear();
    void Insert(T val);
    T Get(T val) const;
    int TreeHeight() const;
    void Print() const;
    void Remove(T val);
    bool IsIn(T val) const;
};

template<typename T>
Tree<T>::Tree() {
    root_ = NULL;
}

template<typename T>
Tree<T>::~Tree() {
    ClearTree(root_);
}

template<typename T>
Node<T>* Tree<T>::RotateRight(Node<T>* node) {
    Node<T>* next_root = node->left_;   // new root of node subtree after rotation
    Node<T>* left_subtree = next_root->right_; // future left subtree of node
    next_root->right_ = node; // node - root of right subtree
    node->left_ = left_subtree;  // next_root < [left_subtree] < node
    // switching heights
    node->SetHeight(node->Height());
    next_root->SetHeight(next_root->Height());
    return next_root;
}

template<typename T>
Node<T>* Tree<T>::RotateLeft(Node<T> *node) {
    Node<T>* next_root = node->right_;   // new root of node subtree after rotation
    Node<T>* right_subtree = next_root->left_; // future right subtree of node
    next_root->left_ = node;  // node - root of left subtree
    node->right_ = right_subtree;   // node < [left_subtree] < next_root
    // switching heights
    node->SetHeight(node->Height());
    next_root->SetHeight(next_root->Height());
    return next_root;
}

template<typename T>
bool Tree<T>::IsIn(T val) const {
    Node<T>* iter = root_;
    while(iter != nullptr && iter->GetVal() != val) {
        if(val > iter->GetVal()) {
            iter = iter->right_;
        }
        else {
            iter = iter->left_;
        }
    }
    if(iter == nullptr){  // if points after bottom node - not found
        return false;
    }
    return true;
}

template<typename T>
Node<T>* Tree<T>::BalanceTree(Node<T>* node) {
    int check_bal = node->CheckBalance();
    if(check_bal == -2) {
        if(node->right_->CheckBalance() == 1) { // check child node balance
            node->right_ = RotateRight(node->right_);
        }
        node = RotateLeft(node);
    }
    if(check_bal == 2) { // check child node balance
        if(node->left_->CheckBalance() == -1) {
            node->left_ = RotateLeft(node->left_);
        }
        node = RotateRight(node);
    }
    node->RenewHeight(); // checking if height of the node changed after inserting
    return node;
}

template<typename T>
void Tree<T>::Insert(T val) {
    if(root_ == NULL) {
        root_ = new Node<T>(val);
        return;
    }
    root_ = InsertRec(root_, val);
}

template<typename T>
Node<T>* Tree<T>::InsertRec(Node<T>* node, T val) {
    // Recursion search of val position in tree
    if(!node){   // if we got to node position of inserted element - base case
        node = new Node<T>(val);
        return node;
    }
    // after last recursive call in one of next cases will be : node->left = Node(val) ,
    // then last recursive call removes from callstack and we stay at pre-last recursive call(one of < or > case)
    // and since all statements already applied < if(!node), if(val<...), if(val>...), else >, we move to the end of statements
    if(val < node->GetVal()) {
        node->left_ = InsertRec(node->left_, val);
    }
    else if(val > node->GetVal()){
        node->right_ = InsertRec(node->right_, val);
    }
    else {
        std::cerr << "No Duplicate Values\n";
        return node;
    }
                                // node located top over node->left == Node(val), check balance in node subtree, and fix if needed
    return BalanceTree(node);  // after return node in Balance method, pre-last recursive call removes from callstack
                                // and wo go to the pre-pre-last (and so on in future returns) and now node is top over node(line224)
}

template<typename T>
Node<T>* Tree<T>::DeleteNode(Node<T>* node, T val) {
    if(node == NULL) {  // base case
        return node;
    }
    else if(val < node->GetVal()) { // if smaller go left
        node->left_ = DeleteNode(node->left_, val);
    }
    else if(val > node->GetVal()) { // if bigger go right
        node->right_ = DeleteNode(node->right_, val);
    }
    else { // if values match
        if(node->left_ == nullptr) {  // node with only right child or NO child
            Node<T>* temp = node->left_;
            delete node;
            node = nullptr;
            return temp;
        }
        if(node->right_ == nullptr) {  // node with only left child
            Node<T>* temp = node->right_;
            delete node;
            node = nullptr;
            return temp;
        }
        else { // node with two children
            Node<T>* temp = FindMin(node->right_);
            node->SetVal(temp->GetVal());
            node->right_ = DeleteNode(node->right_, temp->GetVal());
        }
    }
    return BalanceTree(node);
}

template<typename T>
Node<T>* Tree<T>::Find(T val) const {
    Node<T>* iter = root_;      // "iter"
    while(iter != nullptr && iter->GetVal() != val) {
        if(val > iter->GetVal()) {
            iter = iter->right_;
        }
        else {
            iter = iter->left_;
        }
    }
    return iter;
}

template<typename T>
int Tree<T>::TreeHeight() const {
    return root_->Height();
}

template<typename T>
void Tree<T>::ClearTree(Node<T>* &node) {
    if(node == nullptr) {
        return;
    }
    ClearTree(node->left_);
    ClearTree(node->right_);
    delete node;
    node = nullptr;
}

template<typename T>
void Tree<T>::Clear() {
    ClearTree(root_);
}

template<typename T>
Node<T>* Tree<T>::FindMin(Node<T>* node) const {
    Node<T>* search = node;
    while(search->left_ != nullptr) {
        search = search->left_;
    }
    return search;
}

template<typename T>
Node<T> *Tree<T>::FindMax(Node<T> *node) const {
    Node<T>* search = node;
    while(search->right_ != nullptr) {
        search = search->right_;
    }
    return search;
}

template<typename T>
void Tree<T>::Print(Node<T>* node, int space) const {
    if(node == NULL){
        return;
    }
    int distance = 30;
    space += distance;
    Print(node->right_, space);
    std::cout<<"\n\n";
    for (int i = distance; i < space; i++) {
        std::cout<<"-";
    }
    std::cout<< node->GetVal()<<"\n";
    Print(node->left_, space);
}

template<typename T>
void Tree<T>::Print() const {
    Node<T>* printer = root_;
    Print(printer, 0);
}

template<typename T>
void Tree<T>::Remove(T val) {
    DeleteNode(root_, val);
}

template<typename T>
T Tree<T>::Get(T val) const {
    Node<T>* found_ptr = Find(val); //  Find returns address of the node
    return (found_ptr != nullptr) ? found_ptr->GetVal() : -404;   // check if found, -404 - not found
}




