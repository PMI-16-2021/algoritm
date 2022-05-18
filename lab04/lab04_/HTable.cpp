#include "htable.h"

HTable::HTable() : capacity(0), size(10)
{
    table = new Row[size];
}

HTable::HTable(size_t _size): capacity(0), size(_size)
{
    table = new Row[size];
}

HTable::~HTable()
{
    delete[] table;
}

int HTable::hash(string key)
{
    int sum = 0;
    for (int i = 0; i < key.length(); ++i)
    {
        sum += key[i];
    }
    return sum % size;
}

void HTable::add(string key, string element)
{
    if (find(key))
    {
        throw "This key is already used";
    }
    if (capacity >= size)
    {
        cout<<"Your hash table is already full";
    }
    int index = hash(key);
    while (table[index].key != "" && table[index].key != key)
    {
        ++index;
        index %= size;
    }
    table[index] = Row(key, element);
    ++capacity;
}

bool HTable::find(string key)
{
    int index = hash(key);
    while (table[index].key != "" )
    {
        if (table[index].key == key)
        {
            return true;
        }
        ++index;
        index %= size;
    }

    return false;
}

void HTable::values()
{
    for (size_t i = 0; i < size; ++i)
    {
        if (table[i]. key == "")
        {
            cout << "№" << i;
            cout<< " key : ";  cout.width(20);cout << " value : " << '\n';
        }
        else
        {
            cout << "№" << i ;
            cout<< " key : " ;cout << table[i].key ;cout.width(15);cout<< "  value :  " << table[i].value << '\n';
        }
    }
}

bool HTable::isEmpty()
{
    return capacity == 0;
}

int HTable::getSize()
{
    return capacity;
}

void HTable::pop(string key)
{
    int index = hash(key);
    List<Row> temp;
    while (table[index].key != "") //check
    {
        if (table[index].key == key) // when we find
        {
            table[index].key = "";
            --capacity;
            ++index;
            index %= size;
        }
        temp.addBack(table[index]);
        table[index].key = "";
        --capacity;
        ++index;
        index %= size;
    }
    while (!temp.isEmpty())
    {
        add(temp.top()->value.key, temp.top()->value.value);
        temp.delFirst();
    }
}

