#include <iostream>
#pragma once
using namespace std;
template<typename T>
struct Member{     // == struct Pair - element of queue with value, his priority and pointer on next ( list with priotity)
    T value;
    int priority;
    Member<T> * link;
    Member( T data, int prior) : value(data), priority(prior) , link(nullptr){}
};

template <typename T>
class Queue_withP {// queue with priority
private:
    Member<T>* top; // pointer on head of queue
    int size;
public:
     Queue_withP() : top(nullptr){}
     ~Queue_withP(){clear();};
    T getTop(); // get value of top
    bool isEmpty(); // method check if queue is empty (have 0 elements ) or not
    void enqueue(T elem, int priority ); // add(push) a value of T- type  to our queue
    void dequeue(); // delete (pop) a value from head of queue == delete a mem with the highest priority
    void print(); // print all members
    void clear();
};

template< typename T>
void Queue_withP<T>::print() {
    Member<T>* temp; // create a temporary pointer
    if (top == nullptr)
    {
       throw  "\nStack is empty\n";
    }
    else
    {
        temp = top; // this pointer == top
        while (temp != nullptr)
        {
            std::cout << temp->value << "\n";
            temp = temp->link; // change on next member
        }
    }
}


template<typename T>
T Queue_withP<T>::getTop()
{
    return top->value;
}

template<typename T>
bool Queue_withP<T>::isEmpty()
{
    if(top== nullptr)
    {
        return true;
    }

    return false;
}

template<typename T>
void Queue_withP<T>::enqueue(T elem, int priority)
{
    Member<T>* member = new Member<T>(elem, priority);
    Member<T>* temp = top;
    if (isEmpty())
    {
        top= member;
        return;
    }
    if (top->priority > priority)
    {
        member->link = top;
        top= member;
    }
    else
    {
        while (temp->link != nullptr && temp->link->priority < priority)
        {
            temp = temp->link;
        }
        member->link = temp->link;
        temp->link = member;
    }

}

template<typename T>
void Queue_withP<T>::dequeue()
{
    if(isEmpty())
    {
        throw "Queue is empty, push something ";
    }
    Member<T>* temp = top;
     top=top->link;
     delete temp;
}

template<typename T>
void Queue_withP<T>::clear()
{
  if(isEmpty())
  {
      return;
  }
  while(!isEmpty())
  {
      dequeue();
  }
}




