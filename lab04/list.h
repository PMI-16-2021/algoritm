#pragma once
#include<iostream>

template <typename T>
struct Node {
    T value;
    Node<T>* next;
    Node(T val, Node<T>* _next);
    Node(T val);
};

template<typename T>
Node<T>::Node(T val, Node<T>* _next) : value(val), next(_next) {}

template<typename T>
Node<T>::Node(T val) : value(val), next(nullptr) {}

template <typename T>
class List {
private:
    Node<T>* top;
    Node<T>* end;
public:
    List();
    List(Node<T>* _top, Node<T>* _end);
    ~List();

    Node<T>* showTop();
    Node<T>* showEnd();
    void pushFront(T elem);
    void pushBack(T elem);
    Node<T>* pop(int index);
    void popFront();
    Node<T>* move(int index);
    int sizeList();
    bool isEmpty();
    void insert(T item, Node<T>* elem);
    void empty();
    Node<T>* deleteFirst();
    void printList();
    void emptyList();
};
template<typename T>
List<T>::List() : top(nullptr), end(nullptr) {};

template<typename T>
List<T>::List(Node<T>* _top, Node<T>* _end) : top(_top), end(_end) {};

template<typename T>
List<T>::~List() {
    emptyList();
};

template <typename T>
Node<T>* List<T>::showTop() {
    return top;
}

template <typename T>
Node<T>* List<T>::showEnd() {
    return end;
}

template<typename T>
void List<T>::pushFront(T elem) {
    Node<T>* temp = new Node<T>(elem, top);
    if (top == nullptr) {
        end = temp;
    }
    top = temp;
    temp = nullptr;
}

template<typename T>
void List<T>::pushBack(T elem) {
    Node<T>* temp = new Node<T>(elem);
    if (top == nullptr) {
        top = end = temp;
    }
    end->next = temp;
    end = temp;
    temp = nullptr;
}

template<typename T>
Node<T>* List<T>::pop(int index) {
    if (top == nullptr) {
        throw "List is empty";
    }
    if ((index < 0) || (index >= sizeList())) {
        throw "Index is invalid";
    }
    if (index == 0) {
        Node<T>* temp = top;
        top = top->next;
        delete temp;
    }
    else {
        Node<T>* temp2 = move(index - 1);
        Node<T>* temp1 = temp2->next;
        temp2->next = temp1->next;
        return temp1;
        delete temp1;
    }
}

template <typename T>
void List<T>::popFront() {
    Node<T>* temp = top->next;
    T val = top->value;
    if (sizeList() == 1)
    {
        end = temp;
    }
    delete top;
    top = temp;
}

template <typename T>
Node<T>* List<T>::move(int index) {
    Node<T>* temp = top;
    for (int i = 0; i < index; ++i) {
        temp = temp->next;
    }
    return temp;
}

template<typename T>
int List<T>::sizeList() {
    int count = 0;
    Node<T>* temp = top;
    while (temp != nullptr) {
        temp = temp->next;
        ++count;
    }
    return count;
}

template<typename T>
bool List<T>::isEmpty() {
    return top == nullptr;
}

template<typename T>
void List<T>::insert(T item, Node<T>* elem) {
    Node<T>* temp = top;
    int i = 0;
    while (temp != elem) {
        temp = temp->next;
        ++i;
    }
    temp = move(i);
    Node<T>* vict = new Node<T>(item);
    if (i == 0) {
        vict->next = top;
        top = vict;
    }
    else {
        temp = move(i - 1);
        vict->next = temp->next;
        temp->next = vict;
    }
    vict = nullptr;
}

template<typename T>
void List<T>::empty() {
    while (top != nullptr) {
        Node<T>* temp = top;
        top = top->next;
        delete temp;
    }
}

template<typename T>
Node<T>* List<T>::deleteFirst() {
    return pop(0);
}

template<typename T>
void List<T>::printList() {
    if (top == nullptr) {
        std::cout << "List is empty" << '\n';
    }
    Node<T>* temp = top;
    while (temp != nullptr) {
        std::cout << temp->value << ' ';
        temp = temp->next;
    }
    std::cout << '\n';
}

template<typename T>
void List<T>::emptyList() {
    while (top != nullptr) {
        int i = 0;
        pop(i);
        ++i;
    }
}