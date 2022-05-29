#pragma once
#include<vector>
#include<iostream>
using namespace std;

template<typename T>
class Tree
{
private:
    struct Node
    {
        const T key;
        int height = 1;
        Node* left = nullptr;  //pointer on left
        Node* right = nullptr; //pointer on right
        Node(const T& key): key(key) {}
    };
public:
    Tree() {};
    Node* root = nullptr; //root of tree
    Tree& Insert(const T& value); //function to insert key into tree
    Tree& Remove(const T& value); //function to remove key from tree
    bool Contain(const T& value) const; //Find by key in tree
    int Get_Height(Node* node) const { return node != nullptr ? node->height : 0; }//method that returns height of the tree
    void Reset_height(Node* node); //Resets height of node based on height of child nodes
    int Balance_Factor(Node* node);
    bool Is_Balanced() { return Is_Bal(root); }
    bool Is_Bal(Node* node);
    Node* Rotate_Left(Node* node);//method that makes left rotation
    Node* Rotate_Right(Node* node);//method that makes right rotation
    Node* Balance(Node* node);    //method that balances tree
    Node* Insert(Node*, const T& value);
    Node* Remove(Node*, const T& value);
    Node* Find_Max(Node* node);    //method that finds max element in a tree
    Node* Remove_Max(Node* node);     //method that removes max element in a tree
    Node* Find(Node* node, const T& value) const;
    void Delete_Tree(Node* node);
    ~Tree() {Delete_Tree(root);}
    void Print(Node * t, int level) const;
    void Print() const;

};

template<typename T>
void Tree<T>::Reset_height(Tree::Node *node) {
    node->height = max(Get_Height(node->left), Get_Height(node->right)) + 1;
}
template<typename T>
int Tree<T>::Balance_Factor(Tree::Node *node)
{
    return Get_Height(node->right) - Get_Height(node->right);
}
template<typename T>
bool Tree<T>::Is_Bal(Tree::Node *node)
{
    bool return_value = true;
    return_value = Balance_Factor(node) <= 1 && Balance_Factor(node) >= -1;
    if (node->left != nullptr)
    {
        return_value = return_value && Is_Bal(node->left);
    }
    if (node->right != nullptr)
    {
        return_value = return_value && Is_Bal(node->right);
    }
    return return_value;
}


template<typename T>
inline bool Tree<T>::Contain(const T& value) const
{
    return Find(root, value) != nullptr;
}

template<typename T>
typename Tree<T>::Node* Tree<T>::Find(Node* node, const T& value) const
{
    if (node != nullptr)
    {
        if (value < node->key)
            return Find(node->left, value);
        if (node->key < value)
            return Find(node->right, value);
        return node;
    }
    return nullptr;
}

template<typename T>
Tree<T>& Tree<T>::Insert(const T& value)
{
    root = Insert(root, value);
    return *this;
}

template<typename T>
typename Tree<T>::Node* Tree<T>::Insert(Node* node, const T& value)
{
    if (node == nullptr)
        return new Node(value);
    if (value < node->key)
        node->left = Insert(node->left, value);
    else
        node->right = Insert(node->right, value);
    return Balance(node);
}

template<typename T>
Tree<T>& Tree<T>::Remove(const T& value)
{
    root = Remove(root, value);
    return *this;
}

template<typename T>
typename Tree<T>::Node* Tree<T>::Remove(Node* node, const T& value)
{
    if (node == nullptr)
        return nullptr;
    if (value < node->key)
        node->left = Remove(node->left, value);
    else
    {
        if (node->key < value)
            node->right = Remove(node->right, value);
        else
        {
            if (node->left == nullptr)
                return node->right;
            Node* max = Find_Max(node->left); //Find max element in left subtree
            max->left = Remove_Max(node->left);	//Remove max element from left subtree, but save it's left child if exists
            max->right = node->right; //To the right of max will be the root of the right subtree
            delete node;
            return Balance(max);
        }
    }
    return Balance(node);
}

template<typename T>
typename Tree<T>::Node* Tree<T>::Rotate_Left(Node* node) //if left smaller
{
    Node* new_node = node->right;
    node->right = new_node->left;
    new_node->left = node;
    Reset_height(node);
    Reset_height(new_node);
    return new_node;
}

template<typename T>
typename Tree<T>::Node* Tree<T>::Rotate_Right(Node* node) //if right smaller
{
    Node* new_node = node->left;
    node->left = new_node->right;
    new_node->right = node;
    Reset_height(node);
    Reset_height(new_node);
    return new_node;
}

template<typename T>
typename Tree<T>::Node* Tree<T>::Balance(Node* node)
{
    Reset_height(node);
    if (Balance_Factor(node) == 2) // right bigger
    {
        if (Balance_Factor(node->right) < 0) // right is smaller
        {
            node->right = Rotate_Right(node->right);
        }
        return Rotate_Left(node);
    }
    if (Balance_Factor(node) == -2) // left is bigger
    {
        if (Balance_Factor(node->left) > 0) //left is smaller
        {
            node->left = Rotate_Left(node->left);
        }
        return Rotate_Right(node);
    }
    return node;
}

template<typename T>
typename Tree<T>::Node* Tree<T>::Find_Max(Node* node)
{
    return node->right == nullptr ? node : Find_Max(node->right);
}

template<typename T>
typename Tree<T>::Node* Tree<T>::Remove_Max(Node* node)
{
    if (node->right == nullptr)
        return node->left;
    node->right = Remove_Max(node->right);
    return Balance(node);
}

template<typename T>
void Tree<T>::Delete_Tree(Tree::Node *node)
{
    if (node != nullptr)
    {
        Delete_Tree(node->left);
        Delete_Tree(node->right);
        delete node;
    }
}

template<typename T>
void Tree<T>::Print(Tree::Node *t, int level) const
{
    if (t != nullptr) {
        Print(t->left, level + 1);
        for (int i = 0; i < level; ++i) {
            std::cout << '\t';
        }
        std::cout << t->key << '\n';
        Print(t->right, level + 1);
    }
}

template<typename T>
void Tree<T>::Print() const
{
    std::cout << "--- --- --- --- --- --- --- \n";
    Print(root, 0);
    std::cout << "--- --- --- --- --- --- ---\n";
}







