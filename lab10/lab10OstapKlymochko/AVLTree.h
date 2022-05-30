#pragma once
//��������� �����, ��� ������ � ��� ��� ���, ��: ������, ����, �������� �� ����� �� ������� ���� ������
struct Node
{
    int key, height;
    Node* l, * r;
    explicit Node(int key) : key(key), height(0), l(nullptr), r(nullptr) {}
};

class AVLTree
{
private:
    Node* root;
    int height(const Node* n) const; //��������� ������
    void updateHeight(Node* n);//������� ������ ��� �������
    void simpleRotateLeft(Node*& n);  //������� ������ �����
    void simpleRotateRight(Node*& n);  //������� ������ �������
    void doubleRotateLeft(Node*& n); //������ ������ ������ �����
    void doubleRotateRight(Node*& n);  //������ ������ ������ ��������
    void reBalance(Node*& n);     //������������� ������
    void insert(Node*& n, int key); //���������� ������� � ������
    void erase(Node*& n, int key);     //��������� ������� � ������
    bool find(Node*& n, int key);
    void inorder(Node* t);     //�������� ����� ������ ������
    void preorder(Node* t);     //��������� ����� ������ ������
    void postorder(Node* t);     //���������� ����� ������ ������
public:
    AVLTree();
    int height() const;
    void insert(int key);  //���������� ������� � ������
    void erase(int key);     //��������� �������
    void inorder();
    void preorder();
    void postorder();
    bool find(int key);
};