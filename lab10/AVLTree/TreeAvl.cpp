#include "TreeAvl.h"

void AVL_Tree::insertNode(int stuff)
{
    if (root == nullptr)
    {
        root = new Node();
        root->data = stuff;
        cout << "Element inserted.\n";
        root->height = 0;
        root->parent = nullptr;
    }
    else
    {
        auto linker = getRoot();
        Node* newnode = new Node();
        newnode->data = stuff;

        while (linker != nullptr)
        {
            if (linker->data > stuff) 
            {
                if (linker->left == nullptr) 
                {
                    linker->left = newnode;
                    newnode->height = 0;
                    newnode->parent = linker;
                    cout << "Element inserted.\n"; break;
                }
                else { linker = linker->left; }
            }
            else
            {
                if (linker->right == nullptr) 
                {
                    linker->right = newnode;
                    newnode->height = 0;
                    newnode->parent = linker;
                    cout << "Element inserted.\n"; break;
                }
                else { linker = linker->right; }
            }
        }
        rebalancer(newnode);
    }
}

void AVL_Tree::heightBalance(Node* temp)
{
    int l = -1, r = -1;
    if (temp->left) { l = temp->left->height; }
    if (temp->right) { r = temp->right->height; }
    temp->height = max(l, r) + 1;
}

void AVL_Tree::treeFix(Node* temp)
{
    if (balanceFactor(temp) == 2)
    {
        if (balanceFactor(temp->right) < 0) { rightRotate(temp->right); }
        leftRotate(temp);
        heightBalance(temp);
    }
    else if (balanceFactor(temp) == -2) 
    {
        if (balanceFactor(temp->left) > 0) { leftRotate(temp->left); }
        rightRotate(temp);
        heightBalance(temp);
    }
}

void AVL_Tree::rebalancer(Node* temp)
{
    if (temp == root) { treeFix(root); }
    else
    {
        while (temp != nullptr) 
        {
            heightBalance(temp);
            temp = temp->parent;
            if (temp) { treeFix(temp); }
        }
    }
}

void AVL_Tree::leftRotate(Node* x)
{
    Node* nw_node = new Node();
    if (x->right->left) { nw_node->right = x->right->left; }
    nw_node->left = x->left;
    nw_node->data = x->data;
    x->data = x->right->data;

    x->left = nw_node;
    if (nw_node->left) { nw_node->left->parent = nw_node; }
    if (nw_node->right) { nw_node->right->parent = nw_node; }
    nw_node->parent = x;

    if (x->right->right) { x->right = x->right->right; }
    else { x->right = nullptr; }

    if (x->right) { x->right->parent = x; }

    heightBalance(x->left);
    if (x->right) { heightBalance(x->right); }
    heightBalance(x);
}

void AVL_Tree::rightRotate(Node* x)
{
    Node* nw_node = new Node();
    if (x->left->right) { nw_node->left = x->left->right; }
    nw_node->right = x->right;
    nw_node->data = x->data;
    x->data = x->left->data;

    x->right = nw_node;
    if (nw_node->left) { nw_node->left->parent = nw_node; }
    if (nw_node->right) { nw_node->right->parent = nw_node; }
    nw_node->parent = x;

    if (x->left->left) { x->left = x->left->left; }
    else { x->left = nullptr; }

    if (x->left) { x->left->parent = x; }

    heightBalance(x->right);
    if (x->left) { heightBalance(x->left); }
    heightBalance(x);
}

Node* AVL_Tree::treeSearch(int stuff)
{
    auto temp = getRoot();
    if (temp == nullptr) { return nullptr; }

    while (temp) 
    {
        if (stuff == temp->data) { return temp; }
        else if (stuff < temp->data) { temp = temp->left; }
        else { temp = temp->right; }
    }
    return nullptr;
}

void AVL_Tree::preorderTraversal(Node* temp)
{
    if (temp == nullptr) { return; }
    cout << "->" << temp->data;
    preorderTraversal(temp->left);
    preorderTraversal(temp->right);
}

void AVL_Tree::postorderTraversal(Node* temp)
{
    if (temp == nullptr) { return; }
    postorderTraversal(temp->left);
    postorderTraversal(temp->right);
    cout << "->" << temp->data;
}

void AVL_Tree::removeNode(Node* Parent, Node* curr, int stuff)
{
    if (curr == nullptr) { return; }
    if (curr->data == stuff) {
        
        if (curr->left == nullptr && curr->right == nullptr) 
        {
            if (Parent->data == curr->data) { root = nullptr; }
            else if (Parent->right == curr) { Parent->right = nullptr; }
            else { Parent->left = nullptr; }
            rebalancer(Parent);
        }
       
        else if (curr->left != nullptr && curr->right == nullptr) 
        {
            int sp = curr->data;
            curr->data = curr->left->data;
            curr->left->data = sp;
            removeNode(curr, curr->left, stuff);
        }
        else if (curr->left == nullptr && curr->right != nullptr)
        {
            int sp = curr->data;
            curr->data = curr->right->data;
            curr->right->data = sp;
            removeNode(curr, curr->right, stuff);
        }
   
        else 
        {
            Node* temp = curr->right;
            int flag = 0;
            while (temp->left) { flag = 1; Parent = temp; temp = temp->left; }
            if (!flag) { Parent = curr; }
            int sp = curr->data;
            curr->data = temp->data;
            temp->data = sp;
            removeNode(Parent, temp, temp->data);
        }
    }
}

void AVL_Tree::remove(int stuff) 
{
    auto temp = root;
    auto Parent = temp;
    bool flag = false;
    if (temp == nullptr) { removeNode(nullptr, nullptr, stuff); }

    while (temp)
    {
        if (stuff == temp->data) { flag = true; removeNode(Parent, temp, stuff); break; }
        else if (stuff < temp->data) { Parent = temp; temp = temp->left; }
        else { Parent = temp; temp = temp->right; }
    }

    if (!flag) { cout << "Element doesn't exist in the table\n"; }
    else { cout << "Element removed.\n"; }
}