#pragma once

template <typename T>
struct Pair
{
    T value;
    int priority;
    Pair<T>* next;

    Pair(T new_value, int value_priority);
};

template <typename T>
Pair<T>::Pair(T new_value, int value_priority)
    : value(new_value), priority(value_priority), next(nullptr) {}

template <typename T>
class PriorityQueue
{
private:
    Pair<T>* head;
    Pair<T>* tail;
    int size;
public:
    PriorityQueue();
    ~PriorityQueue();
    void deleteQueue();
    int getSize() const;
    T& top() const;
    bool isEmpty() const;
    void enqueue(T new_value, int value_priority);
    T dequeue();
    void print() const;
};

template <typename T>
PriorityQueue<T>::PriorityQueue()
    : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
PriorityQueue<T>::~PriorityQueue()
{
    deleteQueue();
}

template <typename T>
int PriorityQueue<T>::getSize() const
{
    return size;
}

template <typename T>
void PriorityQueue<T>::deleteQueue()
{
    while (size > 0)
    {
        this->dequeue();
    }
}

template <typename T>
T& PriorityQueue<T>::top() const
{
    return head->value;
}

template <typename T>
bool PriorityQueue<T>::isEmpty() const
{
    return head == nullptr;
}

template <typename T>
void PriorityQueue<T>::enqueue(T new_value, int value_priority)
{
    if (value_priority < 0)
        throw "Priority less than 0 is not acceptable\n";
    Pair<T>* elem = new Pair<T>(new_value, value_priority);
    if (isEmpty())
    {
        head = elem;
        tail = elem;
        elem = nullptr;
        ++size;
        return;
    }
    if (value_priority < head->priority)
    {
        elem->next = head;
        head = elem;
        ++size;
        return;
    }
    if (value_priority >= tail->priority)
    {
        tail->next = elem;
        tail = elem;
        ++size;
       return;
    }
    if (value_priority < tail->priority && value_priority > head->priority)
    {
        Pair<T>* temp = head;
        while (value_priority > temp->next->priority)
            temp = temp->next;
        elem->next = temp->next;
        temp->next = elem;
        ++size;
        return;
    }
}

template <typename T>
T PriorityQueue<T>::dequeue()
{
    if (isEmpty())
        throw "Queue is empty\n";
    Pair<T>* temp = head;
    head = head->next;
    delete temp;
    --size;
}

template <typename T>
void PriorityQueue<T>::print() const
{
    if (head == nullptr)
    {
        std::cout << "Queue is empty\n";
        return;
    }
    Pair<T>* local = head;
    while (local)
    {
        std::cout << local->value;
        local = local->next;
    }
    std::cout << "\n";
}