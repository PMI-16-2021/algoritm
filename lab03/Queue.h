#include "list.h"
#pragma once
template <typename T>
struct Pair
{
    T value;//data
    int prioity;
    Pair();
    Pair(T data, int prior);
    ~Pair();
    void printP(std::ostream& out)const;
};

template<typename T>
Pair<T>::Pair() : value(0), prioity(0){}

template<typename T>
Pair<T>::Pair(T data, int prior) : value(data), prioity(prior){}

template<typename T>
Pair<T>::~Pair() {}

template<typename T>
void Pair<T>::printP(std::ostream& out)const
{
  out<<"value : "<< value << " with  priority : " << prioity ;
}
template<typename T>
std::ostream & operator<<(std::ostream& out, const Pair<T>& P)
{
    P.printP(out);
    return out;
}

template<typename T>
class PQueue{
private:
    List<Pair<T>> item; // our element
public:
    PQueue();
    ~PQueue();
    void enqueue(T val, int p);//add an element to queue
    T dequeue();//delete an element from queue
    bool isEmpty();//check if is empty
    void print();//print queue
    int getSize();
    void clear();//clear all elements
};

template<typename T>
PQueue<T>::PQueue() : item(){}

template<typename T>
PQueue<T>::~PQueue() {}

template<typename T>
void PQueue<T>::enqueue(T val, int p)
{
    if(item.isEmpty())
    {
        item.push_front(Pair<T>(val,p));
    }
    else if (p<item.getTop()->data.prioity)
    {
        item.push_front(Pair<T>(val,p));
    }
    else if(p>item.getEnd()->data.prioity || p==item.getEnd()->data.prioity)
    {
        item.push_back(Pair<T>(val,p));
    }
    else
    {
        Node<Pair<T>>* temp =item.getTop();
        int counter =0;
        while(temp->next !=nullptr && p >= temp->data.prioity)
        {
            temp=temp->next;
            counter++;
        }
        item.insert(counter,Pair<T>(val,p));
        temp=nullptr;
    }
}

template<typename T>
T PQueue<T>::dequeue()
{
    if(isEmpty())
    {
        throw "Queue is empty";
    }

  return item.popFront().value;
}

template<typename T>
void PQueue<T>::print()
{
   item.print();
}

template<typename T>
bool PQueue<T>::isEmpty()
{
    return item.isEmpty();
}

template<typename T>
int PQueue<T>::getSize()
{
    return item.getSize();
}

template<typename T>
void PQueue<T>::clear()
{
  item.clear();
}
