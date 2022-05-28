#pragma once
#include "list.h"
using namespace std;

template<typename T>
struct Pair
{
    T value;
    int priority;
    Pair(T _val, int _prior);
    Pair(const Pair<T>& other);
    void Print() const;
};

template<typename T>
Pair<T>::Pair(T _val, int _prior) : value(_val), priority(_prior)
{
}

template<typename T>
Pair<T>::Pair(const Pair<T>& other) : value(other.value), priority(other.priority)
{
}

template<typename T>
void Pair<T>::Print() const
{
    cout << "p: " << priority << " v: " << value;
}

template<typename T>
class PriorityQueue
{
private:
    List<Pair<T>> item_;

public:
    PriorityQueue();
    ~PriorityQueue();
    size_t Size() const { return item_.Size(); }
    const T& Top() const;
    bool IsEmpty() const;
    void Enqueue(T val, int prior);
    T Dequeue();
    void DeleteFirst();
    void ClearQueue();
    void PrintQueue() const;
    ListNode<Pair<T>>& AtIndex(int index) const;
};

template<typename T>
PriorityQueue<T>::PriorityQueue() : item_()
{
}

template<typename T>
PriorityQueue<T>::~PriorityQueue()
{
    item_.Clear();
}

template<typename T>
const T& PriorityQueue<T>::Top() const
{
    return item_.Front().value;
}

template<typename T>
bool PriorityQueue<T>::IsEmpty() const
{
    return item_.IsEmpty();
}

template<typename T>
void PriorityQueue<T>::Enqueue(T val, int prior)
{
    if (item_.IsEmpty())
    {
        item_.PushBack(Pair<T>(val, prior));
    }
    else if (prior < item_.Front().priority)
    {
        item_.PushFront(Pair<T>(val, prior));
    }
    else if (prior > item_.Back().priority)
    {
        item_.PushBack(Pair<T>(val, prior));
    }
    else
    {
        ListNode<Pair<T>>* temp = item_.Begin();
        int position = 0;
        while (temp->value.priority <= prior && temp->ptr_next != nullptr)
        {
            temp = temp->ptr_next;
            position++;
        }
        item_.Insert(position, Pair<T>(val, prior));
        temp = nullptr;
    }
}

template<typename T>
T PriorityQueue<T>::Dequeue()
{
    return item_.PopFront().value;
}

template<typename T>
void PriorityQueue<T>::DeleteFirst()
{
    item_.DeleteHead();
}

template<typename T>
void PriorityQueue<T>::ClearQueue()
{
    item_.Clear();
}

template<typename T>
void PriorityQueue<T>::PrintQueue() const
{
    ListNode<Pair<T>>* temp = item_.Begin();
    while (temp != nullptr)
    {
        temp->value.Print();
        cout << endl;
        temp = temp->ptr_next;
    }
}

template<typename T>
ListNode<Pair<T>>& PriorityQueue<T>::AtIndex(int index) const
{
    return item_[index];
}