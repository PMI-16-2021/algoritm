#pragma once
#include <string>
#include <iostream>
#include "Queue.h"
using std::string;
using std::ostream;
using std::pair;

//structure template TableElement that
//holds Assotiations: key - value 
template<typename T>
struct TableElem
{
    string key;       
    T value;

    TableElem(string _key = string(), T val = T());
    TableElem& operator=(const TableElem& other)
    {
        this->key = other.key;
        this->value = other.value;
        return *this;
    }
    friend ostream& operator<<(ostream& out, const TableElem& A)
    {
        out << "Key: " << A.key << "  value: " << A.value << '\n';
        return out;
    }
};

//constructor for a row
template<typename T>
TableElem<T>::TableElem(string _key, T val)
{
    value = val;
    key = _key;
}

//template class HashTable on array
//can add value, find it by key, remove Assotiation
template<typename T = int>
class HashTable
{
private:
    TableElem<T>* m_memory;                         //dynamic arr pointer
    int m_size;                                     //total size of dynamic arr
    int m_used;                                     //number of used rows
    int __hash(string key) const;                   //private methods to find hash
    bool get_index(string key, int& index) const;   //private method to get index if element exists

public:
    HashTable(int _size = 50);                      //default size = 50
    ~HashTable();                                   //destructs dybamic memory
    void add(string k, T elem);                     //adds Assotiation using __hash() method
    bool get(string key, TableElem<T>& found) const;//finds and returns Assotiation by key
    void pop(string key);                           //deletes certain row by key
    std::pair<TableElem<T>*, int> values()const;    //first return pointer to arr with all assotiations 
};                                                  //second returns its size

template<typename T>
HashTable<T>::HashTable(int _size): m_used(0)       //min size = 20 
{                                                   //(hash functions are bad to use with little range)
    m_size = (_size >= 50) ? _size : 50;             
    m_memory = new TableElem<T>[m_size];
}

//delete memory
template<typename T>
HashTable<T>::~HashTable()                          
{
    delete[] m_memory;
}

//add to the table using its key
template<typename T>
void HashTable<T>::add(string k, T elem)           
{
    if (m_used >= m_size)                 //if full
    { 
        std::cout << "Table is FULL!\n";  //retrun 
        return;
    }
    TableElem<T> temp;                    //temporaty TableElem for get() function
    if (get(k,temp))                      // if already exists ( if found using this key)
    {
        std::cout << "ERROR: Item with such key already exists!!!\n";
        return;                            //return
    }
    int hash = __hash(k);                  //find hash using key
    int pos = hash;                        //linear hash: ned one more param
    
    while (m_memory[hash].key != "")       //looking for empty row
    {
        hash += pos;                  
        hash= hash % (m_size - 7);         //changin has index
    }                                      //FOUND!!!
    ++m_used;                              //now increase number of used rows
    m_memory[hash] = TableElem<T>(k, elem);//write element to the table
}

//finds element if it exists using the key
template<typename T>
bool HashTable<T>::get(string key, TableElem<T>& found) const
{
    int place;                            //variable to write in by get_index()
    bool result = get_index(key, place);  //if found in table => result = true
                                          //place = index in m_mempry
    if (result)                           //if found
    {
        found = m_memory[place];          //write to reference variable
    }                                     //if not found then &found is uninitialised
    return result;                        //and return boolean
}

//removes row by key if row with such key exists
template<typename T>
void HashTable<T>::pop(string key)
{
    bool exists = false;                           //assume that desn't exist
    int place = 0 ;                                //variable to write hash in
    int h = __hash(key);                           //hash by key
    PriorityQueue<TableElem<T>> elems;             //my own Queue to store removed rows            
    
    exists = get_index(key, place);                //if exists => write its ind in place variable           
    if (exists)                                    
    { 
        m_memory[place].key = "";                  //key is empty => row acts like empty
        --m_used;                                  //decrease number of filled rows
        place = (place + h) % (m_size - 7);        //move to next hash position
        while (m_memory[place].key != "")          //stop only if dehash index points at empty row
        {                                           
            elems.enqueue(m_memory[place], 0);     //elem with index is saved to Queue
            m_memory[place].key = "";              //it is made empty
            place = (place + h) % (m_size - 7);    //hash is changed
        }                                          
    }
    while (!elems.isEmpty())                       //while all elems in Queue are not added
    {
        add(elems.top().key, elems.top().value);   //add it
        elems.dequeue();                           //move to next                   
    }
}

//constructs pair that returns:
//1 arr of all rows one by one
//2 size of than arr 
template<typename T>
std::pair<TableElem<T>*, int> HashTable<T>::values() const
{
    if (m_used == 0)                                      //if no rows
    {
        return std::pair<TableElem<T>*, int>(nullptr, -1);//return nullptr and -1
    }
    TableElem<T>* return_arr = new TableElem<T>[m_used];  //create empty arr of size of used rows

    int external_index = 0;                               //index to skip empty rows
    for (int i = 0; i < m_size; i++)                      //loop finishes if all tabe is checked
    {
        if (m_memory[i].key != "")                        //if key is not empty
        {
            return_arr[external_index] = m_memory[i];     //copy elem to arr
            ++external_index;                             //increase index
        }
    }
    return std::pair<TableElem<T>*, int>(return_arr, external_index); //return values
}

//hash algorithm
template<typename T>
int HashTable<T>::__hash(string key) const
{
    int sum = 0;                        //var for summing 
    int length = key.length();          //to not to use .length() every step in loop
    for (int i = 0; i < length; i++)    //get ASCII number of every char
    {
        sum += key[i];                  //add to sum
    }
    return sum % m_size;                //divide by size to keep in 0 to (size-1) range
}

//finds index of element with ceratin key
template<typename T>
bool HashTable<T>::get_index(string key, int& index) const
{
    bool result = false;                                  //assume that doesn't exist 
    int step = __hash(key);                               //get hash step value
    int hash = step;                                      //on 1st step pos = step value
    
    while (m_memory[hash].key != key && m_memory[hash].key != "")  //while key is not similar and row is not empty
    {
        hash = (hash + step) % (m_size - 7);              //look for element moving hash by spet
    }
    if (m_memory[hash].key == key)                        //if key is similar
    {
        index = hash;                                     //save index to reference variable
        result = true;                                    //set result flag to true
    }
    return result;                                        //return 
}

