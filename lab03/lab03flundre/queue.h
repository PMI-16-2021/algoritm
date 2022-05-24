#pragma once
#include <iostream>

template <typename T>
struct Pair {
    T value;
    int priority;
    Pair() : value(0), priority(0) {};
    Pair(T val, int p) : value(val), priority(p) {};
    Pair& operator=(const Pair& P);
};


template <typename N>
struct Node {
    Pair<N> value_priority;
    Node<N>* next;
    Node(N val, int pr, Node<N>* pointer = nullptr) : next(pointer) {
        value_priority = Pair<N>(val, pr);
    }
    ~Node() {};
};

template<typename T>
Pair<T>& Pair<T>::operator=(const Pair& P)
{
    this->priority = P.priority;
    this->value = P.value;
    return *this;
}

template<typename L>
class List {
private:
    Node<L>* head;                                
    Node<L>* tail;                                
    int size;
public:
    List() : head(nullptr), tail(nullptr), size(0) {};
    ~List() {};
    void pushFront(L elem, int prior);
    void pushBack(L elem, int prior);
    void insert(L elem, int priot, Node<L>* node);
    Node<L>* getNode(int n);
    int sizeL();
    Node<L>* pop();
    void print();
};

template<typename L>
void List<L>::print() {
    Node<L>* temp = head;
    while (temp != nullptr) {
        std::cout << temp->value_priority.priority << '\t' << temp->value_priority.value << '\n';
        temp = temp->next;
    }
}

template<typename L>
void List<L>::pushFront(L elem, int prior) {
    Node<L>* temp = new Node<L>(elem, prior, head);

    if (sizeL() == 0) 
    {
        tail = temp; 
    }

    head = temp;    
    temp = nullptr;  
    size += 1;
}

template<typename L>
void List<L>::pushBack(L elem, int prior) {
    Node<L>* temp = new Node<L>(elem, prior, tail);

    if (sizeL() == 0)                                 
    {                                              
        head = temp;                               
        tail = temp;                               
        temp = nullptr;                            
        size += 1;                                   
        return;
    }

    tail->next = temp;
    temp = nullptr;
    size += 1;

}

template<typename L>
int List<L>::sizeL() {
    return size;
}

template<typename L>
void List<L>::insert(L elem, int priot, Node<L>* node){
    Node<L>* temp = node->next;                 
    node->next = new Node<L>(elem, priot, temp);   
    temp = nullptr;                                 
    size += 1;
    
}

template<typename L>
Node<L>* List<L>::getNode(int n) {
    if (head == nullptr) {
        return nullptr;
    }
    Node<L>* temp = head;
    int i = 0;
    while (i != n) {
        i += 1;
        temp = temp->next;
    }
    return temp;
}

template<typename L>
Node<L>* List<L>::pop()
{
    Node<L>* temp = head;
    head = head->next;
    size -= 1;
    return temp;
}


template<typename T>
class QueueP {
private:
    List<T> queue;
public:
    QueueP() : queue(List<T>()) {}
    ~QueueP() {};
    void enqueue(T elem, int pr);
    T dequeue();
    int size();
    bool isEmpty();
    T top();
    void print();
};

template<typename T>
void QueueP<T>::enqueue(T elem, int pr) {
    if (isEmpty()) {
        queue.pushFront(elem, pr);
    }
    else if (pr < queue.getNode(0)->value_priority.priority) {
        queue.pushFront(elem, pr);
    }
    else if (pr >= queue.getNode(queue.sizeL()-1)->value_priority.priority) {
        queue.pushBack(elem, pr);
    }
    else {
        Node<T>* temp = queue.getNode(0);
        while (pr >= temp->next->value_priority.priority) {
           temp = temp->next;
        }
        queue.insert(elem, pr, temp);
    }
}

template<typename T>
T QueueP<T>::dequeue() {
    return queue.pop()->value_priority.value;
}

template<typename T>
int QueueP<T>::size() {
    return queue.sizeL();
}

template<typename T>
bool QueueP<T>::isEmpty() {
    return queue.sizeL() == 0;
}

template<typename T>
T QueueP<T>::top() {
    return queue.getNode(0)->value_priority.value;
}

template<typename T>
void QueueP<T>::print() {
    std::cout << '\n' << "Queue:" << '\n';
    queue.print();
}