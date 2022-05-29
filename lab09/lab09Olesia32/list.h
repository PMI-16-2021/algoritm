#pragma once
#include<iostream>

template <typename T>
struct Node {
    T value;
    Node<T>* link;
    Node();
    Node(T _value, Node<T>* _link);
    Node(T _value);
};

template<typename T>
Node<T>::Node() : value(), link(nullptr) {}

template<typename T>
Node<T>::Node(T _value, Node<T>* _link) : value(_value), link(_link) {}

template<typename T>
Node<T>::Node(T _value) : value(_value), link(nullptr) {}

template <typename T>
class List {
private:
    Node<T>* first;
    Node<T>* last;
public:
    class Iter {
    private:
        Node<T>* L;
    public:
        Iter() : L(nullptr) {}
        Iter(List<T>& lst) : L(lst.first) {}
        Iter(Node<T>* node) : L(node) {}
        T& operator*() { return L->value; }
        Node<T>* operator->() { return this->L; }
        Iter& operator++() { L = L->link; return *this; }
        bool operator!=(const Iter& it) { return this->L != it.L; }
    };
    Iter begin() const { return Iter(first); }
    Iter end() const { return Iter(); }
    List();
    List(Node<T>* _first, Node<T>* _last);
    ~List();
    Node<T>* Begin();
    Node<T>* End();
    int SizeList();
    void AddFront(T data);
    void AddBack(T data);
    void Insert(T item, Node<T>* elem);
    void Print();
    void Empty();
    void Remove(T val);
    bool IsEmpty();
    T FindMin();
    Node<T>* Move(int index);
    Node<T>* Del(int index);
    void EmptyList();
    T& operator[](int i);
    const T& operator[](int i) const;
};
template<typename T>
List<T>::List() : first(nullptr), last(nullptr) {};

template<typename T>
List<T>::List(Node<T>* _first, Node<T>* _last) : first(_first), last(_last) {};

template<typename T>
List<T>::~List() {
    EmptyList();
};

template <typename T>
Node<T>* List<T>::Move(int index) {
    Node<T>* temp = first;
    for (int i = 0; i < index; ++i) {
        temp = temp->link;
    }
    return temp;
}

template<typename T>
void List<T>::AddFront(T data) {
    Node<T>* temp = new Node<T>(data, first);
    if (first == nullptr) {
        last = temp;
    }
    first = temp;
    temp = nullptr;
}

template<typename T>
void List<T>::AddBack(T data) {
    Node<T>* temp = new Node<T>(data);
    if (IsEmpty()) { 
        first = temp;                               
        last = temp;                           
        temp = nullptr;
        return;
    }
    else {
        last->link = temp;                
        last = temp; 
    }
}

template<typename T>
void List<T>::Insert(T item, Node<T>* elem) {
    Node<T>* temp = first;
    int i = 0;
    while (temp != elem) {
        temp = temp->link;
        ++i;
    }
    temp = Move(i);
    Node<T>* vict = new Node<T>(item);
    if (i == 0) {
        vict->link = first;
        first = vict;
    }
    else {
        temp = Move(i - 1);
        vict->link = temp->link;
        temp->link = vict;
    }
    vict = nullptr;
}

template<typename T>
void List<T>::Print() {
    if (first == nullptr) {
        std::cout << "List is empty." << '\n';
    }
    Node<T>* temp = first;
    while (temp != nullptr) {
        std::cout << temp->value << ' ';
        temp = temp->link;
    }
    std::cout << '\n';
}

template<typename T>
void List<T>::Empty() {
    while (first != nullptr) {
        Node<T>* temp = first;
        first = first->link;
        delete temp;
    }
}

template<typename T>
void List<T>::Remove(T val) {
    for (int i = 0; i < SizeList(); ++i) {
        Node<T>* temp = Move(i);
        if (temp->value == val) {
            Del(i);
            break;
        }
    }
}

template<typename T>
bool List<T>::IsEmpty() {
    return first == nullptr;
}

template<typename T>
Node<T>* List<T>::Begin() {
    return first;
}

template<typename T>
Node<T>* List<T>::End() {
    return last;
}

template<typename T>
T List<T>::FindMin() {
    T min = first->value;
    for (int i = 0; i < SizeList(); ++i) {
        Node<T>* temp = Move(i);
        if (temp->value < min) {
            min = temp->value;
        }
    }
    return min;
}


template<typename T>
int List<T>::SizeList() {
    int count = 0;
    Node<T>* temp = first;
    while (temp != nullptr) {
        temp = temp->link;
        ++count;
    }
    return count;

}

template<typename T>
Node<T>* List<T>::Del(int index) {
    if (first == nullptr) {
        throw "List is empty";
    }

    if ((index < 0) || (index >= SizeList())) {
        throw "Index is invalid";
    }
    if (index == 0) {
        Node<T>* temp = first;
        first = first->link;
        return temp;
        delete temp;
    }
    else {
        Node<T>* temp = Move(index - 1);
        Node<T>* vict = temp->link;
        temp->link = vict->link;
        return vict;
        delete vict;
    }
}

template<typename T>
void List<T>::EmptyList() {
    while (first != nullptr) {
        int i = 0;
        Del(i);
        ++i;
    }
}

template<typename T>
T& List<T>::operator[](int i) {
    Node<T>* temp = Move(i);
    return temp->value;
}

template<typename T>
const T& List<T>::operator[](int i) const {
    Node<T>* temp = Move(i);
    return temp->value;
}
