#include <iostream>
#include "hTable.h";
using namespace std;

Pair::Pair(std::string k, int val)
{
    key = k;
    value = val;
    next = nullptr;
    previous = nullptr;
}

HashTable::HashTable()
    :num(0), head(nullptr), tail(nullptr)
{
}

void HashTable::add(std::string k, int val)
{
    Pair* temp, * oneBefore, * newPair;

    newPair = new Pair(k, val);
    if (newPair == nullptr)
    {
        return;
    }

    if (head == nullptr)
    {
        head = newPair;
        tail = newPair;
    }

    else
    {
        if (k < head->key) //Put at head
        {
            newPair->next = head;
            newPair->previous = nullptr;
            head = newPair;
        }

        else if (k > tail->key) //put at tail
        {
            tail->next = newPair;
            newPair->previous = tail;
            tail = newPair;
        }
        
        else if (k == head->key || k == tail->key) // Do not insert if has already added
        {
            delete newPair;
            return;
        }
        
        else
        {
            temp = head;
            oneBefore = head;

            // Iterate through list to find position
            while (temp->key < k)
            {
                oneBefore = temp;
                temp = temp->next;
            }

            if (temp->key != k)
            {
                newPair->next = temp;
                temp->previous = newPair;
                oneBefore->next = newPair;
                newPair->previous = oneBefore;
            }
            else
            {
                delete newPair;
                return;
            }
        }
    }
    num++;
}

bool HashTable::pop(string k)
{
    Pair* temp, * prev;
    if (head == nullptr)
    {
        return false;
    }
    else if (k<head->key || k>tail->key)
    {
        return false;
    }
    temp = head;
    prev = nullptr;

    for (int i = 0; i < num; ++i)
    {
        if (k == temp->key)
        {
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if (temp != nullptr)
    {
        if (temp == head)
        {
            temp = head;
            head = head->next;
            if (head == nullptr)
            {
                tail = nullptr;
            }
            temp->next = nullptr;
        }
        else if (temp == tail)
        {
            prev->next = nullptr;
            tail = prev;
        }
        else
        {
            prev->next = temp->next;
            temp->next = nullptr;
        }
        delete temp;
        num--;
        return true;
    }
    return false;
}

int HashTable::get(std::string k)
{
    Pair* x = head;

    while (x != nullptr)
    {
        if (x->key == k)
        {
            return x->value;
        }
        x = x->next;
    }
}

int HashTable::hash(std::string k)
{
    int data = 0;
    for (int i = 0; i < k.length(); ++i)
    {
        data += k[i];
    }
    return data % num;
}

void HashTable::values()
{
    Pair* x;
    if (head == nullptr)
    {
        cout << "{}\n";
        return;
    }
    cout << "{ ";
    x = head;
    while (x != nullptr)
    {
        cout << "[" << x->key << ", " << x->value << "]" << (x != tail ? ", " : " }");
        x = x->next;
    }
}

bool HashTable::isEmpty()
{
    return num == 0;
}