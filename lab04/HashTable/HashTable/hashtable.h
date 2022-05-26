#pragma once
#include <iostream>
#include <string>

template <typename T>
struct Node {
    std::string key;
    T value;
    Node<T>* next;
    Node<T>* prev;

    Node(std::string _key, T _value);
};

template <typename T>
Node<T>::Node(std::string _key, T _value) {
    key = _key;
    value = _value;
    next = nullptr;
    prev = nullptr;
}

template <typename T>
class HashTable {
private:
    int count;
    Node<T>* head;
    Node<T>* tail;

public:
    HashTable();//+
    ~HashTable();//+

    void add(std::string _key, T _value);//+
    T get(std::string _key);//+
    int _hash(std::string _key);//+
    void pop(std::string _key);
    void values() const;//+
    bool isEmpty();
};

template <typename T>
HashTable<T>::HashTable()
    : head(nullptr), tail(nullptr), count(0) {}

template <typename T>
HashTable<T>::~HashTable() {
    Node<T>* temp = head;
    Node<T>* victim;
    //remove node
    while (temp != nullptr) {
        victim = temp;
        temp = temp->next;
        victim->next = nullptr;
        delete victim;
    }
    //reinitialize
    head = nullptr;
    tail = nullptr;
    count = 0;
}

template <typename T>
void HashTable<T>::add(std::string _key, T _value) {
    Node<T>* temp, * local;

   Node<T>* newNode = new Node<T>(_key, _value);
    if (newNode == nullptr)
        return;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        // Put at head
        if (_key < head->key) {
            newNode->next = head;
            newNode->prev = nullptr;
            head = newNode;
        }
        // Put at tail
        else if (_key > tail->key) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        
        else if (_key == head->key || _key == tail->key) {
            delete newNode;
            return;
        }
        else {
            temp = head;
            local = head;
            // Iterate through list to find position
            while (temp->key < _key) {
                local = temp;
                temp = temp->next;
            }
            if (temp->key != _key) {
                newNode->next = temp;
                temp->prev = newNode;
                local->next = newNode;
                newNode->prev = local;
            }
            else {
                delete newNode;
                return;
            }
        }
    }

    count++;
}

template <typename T>
T HashTable<T>::get(std::string _key) {
    Node<T>* temp = head;
    while (temp) {
        if (temp->key == _key)
            return temp->value;

        temp = temp->next;
    }
    return T();
}

template <typename T>
int HashTable<T>::_hash(std::string _key) {
    int temp = 0;
    for (int i = 0; i < _key.length(); ++i) {
        temp += _key[i];
    }
    return temp % count;
}

template <typename T>
void HashTable<T>::pop(std::string _key) {
    Node<T>* temp = head;
    Node<T>* local = nullptr;

    if (head == nullptr)
        return;
    else if (_key < head->key || _key > tail->key)
        return;

    for (int i = 0; i < count; ++i) {
        if (_key == temp->key)
            break;
        local = temp;
        temp = temp->next;
    }
    if (temp) {
        if (temp == head) {
            temp = head;
            head = head->next;
            if (head = nullptr)
                tail = nullptr;

            temp->next = nullptr;
        }
        else if (temp = tail) {
            local->next = nullptr;
            tail = local;
        }
        else {
            local->next = temp->next;
            temp->next = nullptr;
        }
        delete temp;
        --count;
    }
}

template <typename T>
void HashTable<T>::values() const {
    Node<T>* temp;
    if (head == nullptr) {
        std::cout << "{ }\n";
        return;
    }
    std::cout << "{ ";
    temp = head;
    while (temp != nullptr) {
        std::cout << "[" << temp->key << ", " << temp->value << "]" << (temp != tail ? ", " : " }");
        temp = temp->next;
    }
    std::cout << "\n";
}

template <typename T>
bool HashTable<T>::isEmpty() {
    if (!head) {
        return true;
    }
    else return false;
}