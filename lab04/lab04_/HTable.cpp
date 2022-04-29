#include "HTable.h"

Row::Row(string key, string workplace)
{
    this->key = key;
    this->Workplace = workplace;

}

bool Row::IsEmpty()
{
    return (key == " ") ? true : false;
}

void Row::OutPut()
{
    cout << key << "\t" << Workplace << endl;
}

int HashIndex(string key, int hash_size)
{
    int Sum = 0;
    for (int i = 0; i < key.length(); ++i)
    {
        Sum += key[i];
    }
    return Sum % hash_size;
}

Hash_Table::Hash_Table(int size)
{
    this->capacity=size;
    Table = new Row[capacity];
}

Hash_Table::~Hash_Table()
{
    delete[] Table;
}

void Hash_Table::add(Row new_element)
{
    int new_index = HashIndex(new_element.key, capacity);
    if (Table[new_index].IsEmpty()) Table[new_index] = new_element;
    else
    {
        for (int i = 0; i < capacity; ++i)
        {
            if (Table[i].IsEmpty())
            {
                Table[i] = new_element;

                break;
            }
        }
    }
    ++count;
}

bool Hash_Table::find(string key)
{
    int index = HashIndex(key,capacity);
    while (Table[index].key != "" ) {
        if (Table[index].key == key) {
            return true;
        }
        ++index;
        index %= capacity;
    }

    return false;
}

void Hash_Table::pop(string key)
{
    int index = find(key);
    if (!find(key)) cout << "Element is not found!\n";
    else
    {
        int hash_index = index;
        while (Table[hash_index].key != key)
        {
            hash_index = (hash_index + index) % capacity;
        }
        Table[hash_index].key = Table[hash_index].Workplace = "";
    --count;
    }
}

void Hash_Table::values()
{
    for (int i = 0; i <capacity; ++i)
    {
        cout << " Worker" << i << " : \t";
        Table[i].OutPut();
    }
}

