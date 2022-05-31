#pragma once
#include <string>
#include <iostream>

template <typename T>
struct Node {
    std::string key;
    T value;
    Node<T>* next;
    Node<T>* prev;

    Node(std::string k, T val);
    ~Node() {};
};

template <typename T>
Node<T>::Node(std::string k, T val) {
    key = k;
    value = val;
    next = nullptr;
    prev = nullptr;
}

template <typename T>
class HashTable {
private:
    int size;
    Node<T>* head;
    Node<T>* tail;
    int _hash(std::string k);
public:
    HashTable() : head(nullptr), tail(nullptr), size(0) {};
    ~HashTable();
    void add(std::string k, T val); 
    T get(std::string k);
    void pop(std::string k);
    void values();
};


template<typename T>
HashTable<T>::~HashTable() {
    Node<T>* iter = head;
    Node<T>* killer;
    while (iter != nullptr) {
        killer = iter;
        iter = iter->next;
        killer->next = nullptr;
        delete killer;
    }
    head = nullptr;
    tail = nullptr;
}

template<typename T>
void HashTable<T>::add(std::string k, T val) {
    Node<T>* temp;
    Node<T>* temp2;

    Node<T>* elem = new Node<T>(k, val);

    if (head == nullptr) {
        head = elem;
        tail = elem;
    }
    else if (k < head->key) {
        elem->next = head;
        elem->prev = nullptr;
        head = elem;
    }
    else if (k > tail->key) {
        tail->next = elem;
        elem->prev = tail;
        tail = elem;
    }
    else
    {
        temp = head;
        temp2 = head;
        while (temp->key < k) {
            temp2 = temp;
            temp = temp->next;
        }
        if (temp->key != k) {
            elem->next = temp;
            temp->prev = elem;
            temp2->next = elem;
            elem->prev = temp2;
        }
        else {
            delete elem;
            return;
        }
    }
    size++;
}

template<typename T>
int HashTable<T>::_hash(std::string k) {
    int temp = 0;
    for (int i = 0; i < k.length(); ++i) {
        temp += k[i];
    }
    return temp % size;
}

template<typename T>
T HashTable<T>::get(std::string k) {
    Node<T>* temp = head;
    while (temp != tail) {
        if (temp->key == k) {
            return temp->value;
        }
        temp = temp->next;
    }
    return 0;
}

template<typename T>
void HashTable<T>::pop(std::string k)
{
    Node<T>* temp = head;
    Node<T>* prv = nullptr;

    if (head == nullptr)
        return;
    else if (k < head->key || k > tail->key)
        return;

    for (int i = 0; i < size; ++i) {
        if (k == temp->key)
            break;
        prv = temp;
        temp = temp->next;
    }

    if (temp == head) {
        temp = head;
        head = head->next;
        if (head == nullptr) {
            tail = prv;
        }
        temp->next = nullptr;
    }
    else if (temp = tail) {
        prv->next = nullptr;
        tail = temp;
    }
    else {
        prv->next = temp->next;
        temp->next = nullptr;
    }
    delete temp;
    --size;

}

template<typename T>
void HashTable<T>::values() {

    Node<T>* temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->key << ' ' << temp->value << ' ' << '\n';
        temp = temp->next;
    }
    std::cout << '\n';
}





