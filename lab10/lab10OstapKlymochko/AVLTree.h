#pragma once
//Структура вузол, яка містить у собі дані такі, як: Висота, ключ, вказівник на лівого та правого сина дерева
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
    int height(const Node* n) const; //Отримання висоти
    void updateHeight(Node* n);//Змінення висоти при повороті
    void simpleRotateLeft(Node*& n);  //Поворот дерева наліво
    void simpleRotateRight(Node*& n);  //Поворот дерева направо
    void doubleRotateLeft(Node*& n); //Двійний оворот дерева наліво
    void doubleRotateRight(Node*& n);  //Двійний оворот дерева напрраво
    void reBalance(Node*& n);     //Збалансування дерева
    void insert(Node*& n, int key); //Добавляємо елемент в дерево
    void erase(Node*& n, int key);     //Видаляємо елемент з дерева
    bool find(Node*& n, int key);
    void inorder(Node* t);     //Інфіксна форма запису дерева
    void preorder(Node* t);     //Префіксна форма запису дерева
    void postorder(Node* t);     //Постфіксна форма запису дерева
public:
    AVLTree();
    int height() const;
    void insert(int key);  //Вставляємо елемент у дерево
    void erase(int key);     //Видаляємо елемент
    void inorder();
    void preorder();
    void postorder();
    bool find(int key);
};