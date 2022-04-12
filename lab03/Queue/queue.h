#pragma once
#include<iostream>
using namespace std;

template <typename T>
class QueueP
{
private:
    T* A; 
    int* P; 
    int count; 

public:
    QueueP() { count = 0; }
    QueueP(const QueueP& _Q)
    {
        A = new T[_Q.count];
        P = new int[_Q.count];
        count = _Q.count;

        for (int i = 0; i < count; i++)
        {
            A[i] = _Q.A[i];
    
            P[i] = _Q.P[i];
        }
    }
    ~QueueP()
    {
        if (count > 0)
        {
            delete[] A;
            delete[] P;
        }
    }
    QueueP operator=(const QueueP& _Q);
    void Push(T item, int priority);
    T Pop();
    void Clear()
    {
        if (count > 0)
        {
            delete[] A;
            delete[] P;
            count = 0;
        }
    }
    int Count()
    {
        return count;
    }
    void Print(const char* objName);
};

template <typename T>
QueueP<T> QueueP<T>::operator=(const QueueP& _Q)
{
    if (count > 0)
    {
        delete[] A;
        delete[] P;
        count = 0;
    }
    A = new T[_Q.count];
    P = new int[_Q.count];
    count = _Q.count;
    for (int i = 0; i < count; i++)
    {
        A[i] = _Q.A[i];
        P[i] = _Q.P[i];
    }
    return *this;
}

template <typename T>
void QueueP<T>::Push(T item, int priority)
{
    T* A2 = new T[count + 1];
    int* P2 = new int[count + 1];
    int pos;
    if (count == 0)
    {
        pos = 0;
    }
    else
    {
        pos = 0;
        while (pos < count)
        {
            if (P[pos] < priority) break;
            pos++;
        }
    }
    for (int i = 0; i < pos; i++)
    {
        A2[i] = A[i];
        P2[i] = P[i];
    }
    A2[pos] = item;
    P2[pos] = priority;
    for (int i = pos + 1; i < count + 1; i++)
    {
        A2[i] = A[i - 1];
        P2[i] = P[i - 1];
    }
    if (count > 0)
    {
        delete[] A;
        delete[] P;
    }
    A = A2;
    P = P2;
    count++;
}

template <typename T>
T QueueP<T>::Pop()
{
    if (count == 0)
    {
        return 0;
    }
    T* A2 = new T[count - 1];
    int* P2 = new int[count - 1];
    T item;
    item = A[0];
    for (int i = 0; i < count - 1; i++)
    {
        A2[i] = A[i + 1];
        P2[i] = P[i + 1];
    }
    if (count > 0)
    {
        delete[] A;
        delete[] P;
    }
    count--;
    A = A2;
    P = P2;
    return item;
}

template <typename T>
void QueueP<T>::Print(const char* objName)
{
    cout << "Object: " << objName << endl;
    for (int i = 0; i < count; i++)
    {
        cout << A[i] << ":" << P[i] << "\t" << endl;
    }
    cout << endl;
    cout << "---------------" << endl;
}
