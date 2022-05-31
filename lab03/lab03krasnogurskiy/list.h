#pragma once
#include<iostream>

template <typename T>
struct Node {
    T value;
    Node<T>* link;
    Node(T value_, Node<T>* _link);
    Node(T value_);
};

template<typename T>
Node<T>::Node(T value_, Node<T>* _link) : value(value_), link(_link) {}

template<typename T>
Node<T>::Node(T value_) : value(value_), link(nullptr) {}

template <typename T>
class List {
private:
    Node<T>* head;
    Node<T>* tail;
public:
    List();
    List(Node<T>* head_, Node<T>* _last);
    ~List();

    Node<T>* begin();
    Node<T>* end();
    int sizeList();
    void addFront(T data);
    void addBack(T data);
    void insert(T item, Node<T>* elem);
    void empty();
    bool isEmpty();
    void print();
    Node<T>* move(int index);
    Node<T>* del(int index);
    void emptyList();
};
template<typename T>
List<T>::List() : head(nullptr), tail(nullptr) {};

template<typename T>
List<T>::List(Node<T>* head_, Node<T>* tail_) : head(head_), tail(tail_) {};

template<typename T>
List<T>::~List() {
    emptyList();
};

template<typename T>
Node<T>* List<T>::begin() {
    return head;
}

template<typename T>
Node<T>* List<T>::end() {
    return tail;
}

template<typename T>
int List<T>::sizeList() {
    int count = 0;
    Node<T>* temp = head;
    while (temp != nullptr) {
        temp = temp->link;
        ++count;
    }
    return count;

}

template<typename T>
void List<T>::addFront(T data) {
    Node<T>* temp = new Node<T>(data, head);
    if (head == nullptr) {
        tail = temp;
    }
    head = temp;
    temp = nullptr;
}

template<typename T>
void List<T>::addBack(T data) {
    Node<T>* temp = new Node<T>(data);
    if (head == nullptr) {
        head = tail = temp;
        temp = nullptr;
    }
    tail->link = temp;
    tail = temp;
}

template<typename T>
void List<T>::insert(T item, Node<T>* elem) {
    Node<T>* temp = head;
    int i = 0;
    while (temp != elem) {
        temp = temp->link;
        ++i;
    }
    temp = move(i);
    Node<T>* vict = new Node<T>(item);
    if (i == 0) {
        vict->link = head;
        head = vict;
    }
    else {
        temp = move(i - 1);
        vict->link = temp->link;
        temp->link = vict;
    }
    vict = nullptr;
}

template<typename T>
void List<T>::empty() {
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->link;
        delete temp;
    }
}

template<typename T>
bool List<T>::isEmpty() {
    return head == nullptr;
}

template<typename T>
void List<T>::print() {
    if (head == nullptr) {
        std::cout << "List is empty." << '\n';
    }
    Node<T>* temp = head;
    while (temp != nullptr) {
        std::cout << temp->value << ' ';
        temp = temp->link;
    }
    std::cout << '\n';
}

template <typename T>
Node<T>* List<T>::move(int index) {
    Node<T>* temp = head;
    for (int i = 0; i < index; ++i) {
        temp = temp->link;
    }
    return temp;
}

template<typename T>
Node<T>* List<T>::del(int index) {
    if (head == nullptr) {
        throw "List is empty";
    }

    if ((index < 0) || (index >= sizeList())) {
        throw "Index is invalid";
    }
    if (index == 0) {
        Node<T>* temp = head;
        head = head->link;
        return temp;
        delete temp;
    }
    else {
        Node<T>* temp = move(index - 1);
        Node<T>* vict = temp->link;
        temp->link = vict->link;
        return vict;
        delete vict;
    }
}

template<typename T>
void List<T>::emptyList() {
    while (head != nullptr) {
        int i = 0;
        del(i);
        ++i;
    }
}