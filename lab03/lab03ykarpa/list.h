#pragma once
#include <iostream>

template <typename T>
struct Node {
    T value_;
    Node<T>* next_;
    Node(T value, Node<T>* next);
    Node(T value);
};

template<typename T>
Node<T>::Node(T value, Node<T>* next) {
    value_ = value;
    next_ = next;
}

template<typename T>
Node<T>::Node(T value) {
    value_ = value;
    next_ = nullptr;
}

template <typename T>
class List {
private:
    Node<T>* top_;
    Node<T>* last_;
public:
    List();
    List(Node<T>* top, Node<T>* last);
    ~List();

    Node<T>* top();
    Node<T>* last();
    int size() const;

    void addFront(T value);
    void addBack(T value);
    void insert(T index, Node<T>* value);

    void print();
    Node<T>* move(int index);
    Node<T>* clear(int index);
    void emptyList();
    void empty();
    bool isEmpty();
};
template<typename T>
List<T>::List() : top_(nullptr), last_(nullptr) {};

template<typename T>
List<T>::List(Node<T>* _first, Node<T>* _last) : top_(_first), last_(_last) {};

template<typename T>
List<T>::~List() {
    emptyList();
};

template<typename T>
Node<T>* List<T>::top() {
    return top_;
}

template<typename T>
Node<T>* List<T>::last() {
    return last_;
}

template<typename T>
int List<T>::size() const {
    int count = 0;
    Node<T>* temp = top_;
    while (temp != nullptr) {
        temp = temp->next_;
        ++count;
    }
    return count;
}
template<typename T>
void List<T>::addFront(T value) {
    Node<T>* node = new Node<T>(value, top_);
    if (top_ == nullptr) {
        last_ = node;
    }
    top_ = node;
    node = nullptr;
}

template<typename T>
void List<T>::addBack(T value) {
    Node<T>* temp = new Node<T>(value);
    if (top_ == nullptr) {
        top_ = last_ = temp;
        temp = nullptr;
    }
    last_->next_ = temp;
    last_ = temp;
}

template<typename T>
void List<T>::insert(T index, Node<T>* value) {
    Node<T>* temp = top_;
    int i = 0;
    while (temp != value) {
        temp = temp->next_;
        ++i;
    }
    temp = move(i);
    Node<T>* temp_1 = new Node<T>(index);
    if (i == 0) {
        temp_1->next_ = top_;
        top_ = temp_1;
    }
    else {
        temp = move(i - 1);
        temp_1->next_ = temp->next_;
        temp->next_ = temp_1;
    }
    temp_1 = nullptr;
}

template<typename T>
void List<T>::print() {
    if (top_ == nullptr) {
        std::cout << "List is empty." << "\n";
    }
    Node<T>* temp = top_;
    while (temp != nullptr) {
        std::cout << temp->value_ << " ";
        temp = temp->next_;
    }
    std::cout << "\n";
}

template <typename T>
Node<T>* List<T>::move(int index) {
    Node<T>* temp = top_;
    for (int i = 0; i < index; ++i) {
        temp = temp->next_;
    }
    return temp;
}

template<typename T>
void List<T>::emptyList() {
    while (top_ != nullptr) {
        int i = 0;
        clear(i);
        ++i;
    }
}

template<typename T>
void List<T>::empty() {
    while (top_ != nullptr) {
        Node<T>* temp = top_;
        top_ = top_->next_;
        delete temp;
    }
}

template<typename T>
bool List<T>::isEmpty() {
    return top_ == nullptr;
}

template<typename T>
Node<T>* List<T>::clear(int index) {
    if (top_ == nullptr) {
        throw "List is empty";
    }
    if ((index < 0) || (index >= size())) {
        throw "Index is invalid";
    }
    if (index == 0) {
        Node<T>* temp = top_;
        top_ = top_->next_;
        return temp;
        delete temp;
    }
    else {
        Node<T>* temp = move(index - 1);
        Node<T>* temp_1 = temp->next_;
        temp->next_ = temp_1->next_;
        return temp_1;
        delete temp_1;
    }
}