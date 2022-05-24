#pragma once

#include <iostream>
#include <string>

using namespace std;

struct Node
{ 
    int value;
    string key;
    Node* next;
    Node* prev;
    Node(string pkey, int pvalue)
    {
        key = pkey;
        value = pvalue;
        next = nullptr;
        prev = nullptr;
    }
};

class HashTable
{
private:
    Node* head;
    Node* tail; 
    int count;
public:
    ~HashTable()
    {
        Node* temp = head;
        Node* victim;
        while (temp != nullptr)
        {
            victim = temp;
            temp = temp->next;
            victim->next = nullptr;
            delete victim;
        }
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
    HashTable() : head(nullptr), tail(nullptr), count(0) {}
    void add(string pkey, int pvalue)
    {
        Node* temp, * local;

        Node* newNode = new Node(pkey, pvalue);
        if (newNode == nullptr)
            return;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            if (pkey < head->key)
            {
                newNode->next = head;
                newNode->prev = nullptr;
                head = newNode;
            }
            else if (pkey > tail->key)
            {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }

            else if (pkey == head->key || pkey == tail->key)
            {
                delete newNode;
                return;
            }
            else
            {
                temp = head;
                local = head;
                while (temp->key < pkey)
                {
                    local = temp;
                    temp = temp->next;
                }
                if (temp->key != pkey)
                {
                    newNode->next = temp;
                    temp->prev = newNode;
                    local->next = newNode;
                    newNode->prev = local;
                }
                else
                {
                    delete newNode;
                    return;
                }
            }
        }

        count++;
    }
    int hash_function(string pkey)
    {
        int temp = 0;
        for (size_t i = 0; i < pkey.length(); ++i)
        {
            temp += pkey[i];
        }
        return temp % count;
    }
    void pop(string pkey)
    {
        Node* temp = head;
        Node* local = nullptr;

        if (head == nullptr)
            return;
        else if (pkey < head->key || pkey > tail->key)
            return;

        for (int i = 0; i < count; ++i)
        {
            if (pkey == temp->key)
                break;
            local = temp;
            temp = temp->next;
        }
        if (temp)
        {
            if (temp == head)
            {
                temp = head;
                head = head->next;
                if (head == nullptr)
                    tail = nullptr;

                temp->next = nullptr;
            }
            else if (temp = tail)
            {
                local->next = nullptr;
                tail = local;
            }
            else
            {
                local->next = temp->next;
                temp->next = nullptr;
            }
            delete temp;
            --count;
        }
    }

    void values() const
    {
        Node* temp;
        if (head == nullptr)
        {
            cout << "Values: [ ]" << endl;
            return;
        }
        cout << "Values: [ ";
        temp = head;
        while (temp != nullptr)
        {
            cout << "[" << temp->key << ", " << temp->value << "]" << (temp != tail ? ", " : " ]");
            temp = temp->next;
        }
        cout << endl;
    }

    bool isEmpty()
    {
        if (!head)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int get(string pkey)
    {
        Node* temp = head;
        while (temp)
        {
            if (temp->key == pkey)
            {
                return temp->value;
            }
            temp = temp->next;
        }
        return -1;
    }

};