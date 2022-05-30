#include"AVLTree.h"
#include<iostream>
#include<stdexcept>
using namespace std;


    int AVLTree::height(const Node* n) const
    {
        //���� n �� ������� nullptr, �� ������ �� 0.
        if (n)
        {
            return n->height;
        }
        else
        {
            return 0;
        }
    }

   
    void AVLTree::updateHeight(Node* n)
    {
        if (n)
        {
            n->height = 1 + std::max(height(n->l), height(n->r));
        }
    }


    void AVLTree::simpleRotateLeft(Node*& n)
    {
        Node* a = n, * b = a->r;
        a->r = b->l;
        b->l = a;
        updateHeight(a);
        updateHeight(b);
        n = b;
    }

    void AVLTree::simpleRotateRight(Node*& n)
    {
        Node* a = n, * b = a->l;
        a->l = b->r;
        b->r = a;
        updateHeight(a);
        updateHeight(b);
        n = b;
    }

    void AVLTree::doubleRotateLeft(Node*& n)
    {
        simpleRotateRight(n->r);
        simpleRotateLeft(n);
    }

    void AVLTree::doubleRotateRight(Node*& n)
    {
        simpleRotateLeft(n->l);
        simpleRotateRight(n);
    }

    void AVLTree::reBalance(Node*& n)
    {
        //����� ������� �� ���� = 0, �������� � ������
        if (!n)
        {
            return;
        }
        //���� ������ �� ���� ����� � ������ ���� -2, �� ������ ����� ����� ����� �� ������� ���� ������� ���� ���
        else if (height(n->l) - height(n->r) == -2)
        {
            //���� ������ ���� 1, �� ������ �������� ������� ����, ���� �, �� ������� �������
            if (n->r && height(n->r->l) - height(n->r->r) == 1)
            {
                doubleRotateLeft(n);
            }
            else
            {
                simpleRotateLeft(n);
            }
        }
        //���� ������ �� ���� ����� � ������ ���� +2, �� ������ ����� ����� ����� �� ������� ���� ����� ���� ���
        else if (height(n->l) - height(n->r) == 2)
        {
            //���� ������ ���� -1, �� ������ �������� ������� ������, ���� �, �� ������� �������
            if (n->l && height(n->l->l) - height(n->l->r) == -1)
            {
                doubleRotateRight(n);
            }
            else
            {
                simpleRotateRight(n);
            }
        }
        //������������ ������
        updateHeight(n);
    }

    void AVLTree::insert(Node*& n, int key)
    {
        //���� ���� ������� nullptr, �� ������� ����� ����
        if (!n)
        {
            n = new Node(key);
        }
        //���� �, �� ��������� ���������� ��� � �����
        else
        {
            if (key < n->key)
            {
                insert(n->l, key);
            }
            else if (key > n->key)
            {
                insert(n->r, key);
            }
            else
            {
                throw invalid_argument("Invalid argument");
            }
        }
        //������������ ������
        reBalance(n);
    }

    void AVLTree::erase(Node*& n, int key)
    {
        //���� �� ������� �������, ������ �������
        if (!n)
        {
            throw invalid_argument("Invalid argument");
        }
        //���� ������� �������
        else if (n->key == key)
        {
            //���� ���� ������ � ���� ����
            if (!n->l || !n->r)
            {
                if (n->l)
                {
                    Node* child = n->l;
                    delete n;
                    n = child;
                }
                else if (n->r)
                {
                    Node* child = n->r;
                    delete n;
                    n = child;
                }
            }
            //���� ��� ���� �
            else
            {
                Node* successor = n->r;
                while (successor->l)
                {
                    successor = successor->l;
                }
                n->key = successor->key;
                erase(n->r, successor->key);
            }
        }
        //���������� ��������� �����
        else
        {
            if (key < n->key)
            {
                erase(n->l, key);
            }
            else if (key > n->key)
            {
                erase(n->r, key);
            }
        }
        //������������ ������
        reBalance(n);
    }

    bool AVLTree::find(Node*& n, int key)
    {
        //���� �� ������� �������, ������ �������
        if (!n)
        {
            return false;
        }
        //���� ������� �������
        else if (n->key == key)
        {
            return true;
        }
        //���������� ��������� �����
        else
        {
            if (key < n->key)
            {
                find(n->l, key);
            }
            else if (key > n->key)
            {
                find(n->r, key);
            }
        }
    }

    void AVLTree::inorder(Node* t)
    {
        if (t == nullptr)
        {
            return;
        }
        inorder(t->l);
        cout << t->key << " ";
        inorder(t->r);
    }

    void AVLTree::preorder(Node* t)
    {
        if (t == nullptr)
        {
            return;
        }

        cout << t->key << " ";
        preorder(t->l);
        preorder(t->r);
    }

    void AVLTree::postorder(Node* t)
    {
        if (t == nullptr)
        {
            return;
        }
        postorder(t->l);
        postorder(t->r);
        cout << t->key << " ";
    }



    AVLTree::AVLTree() 
        : root(nullptr)
    {

    }

    int AVLTree::height() const
    {
        return (height(root) - 1);
    }

    void AVLTree::insert(int key)
    {
        insert(root, key);
    }

   
    void AVLTree::erase(int key)
    {
        erase(root, key);
    }

    void AVLTree::inorder()
    {
        inorder(root);
    }

    void AVLTree::preorder()
    {
        preorder(root);
    }

    void AVLTree::postorder()
    {
        postorder(root);
    }

    bool AVLTree::find(int key)
    {
        return find(root, key);
    }


