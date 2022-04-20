#include "HashTable.h"

Row::Row(string s, string n, double m)
{
    surname = s;
    name = n;
    mark = m;
}

HashTable::HashTable(int size)
{
    this->free_size = size;
    rows = new Row[size];
}

void HashTable::add(Row new_elem)
{
    int hash_index, hash_val;
    hash_val = hash(new_elem.surname, free_size);
    hash_index = hash_val;
    while (rows[hash_index].surname != "")
    {
        hash_index = (hash_index + hash_val) % free_size;
    }
    if (hash_index < free_size)
    {
        rows[hash_index] = new_elem;
        ++used_size;
    }
    else (cout << "Table is full!");
}

void HashTable::pop(string key)
{
    int index = find(key);
    if (index == -1) cout << "Element is not found!\n";
    else
    {
        int hash_index = index;
        while (rows[hash_index].surname != key)
        {
            hash_index = (hash_index + index) % free_size;
        }
        rows[hash_index].surname = rows[hash_index].name = "";
        rows[hash_index].mark = 0.;
    }
    --used_size;
}

void HashTable::clear()
{
    Row* temp = rows;
    delete[] temp;
    free_size = used_size = 0;
    rows = nullptr;
}

int HashTable::find(string find_key)
{
    int index = hash(find_key, free_size);
    if (isEmpty())
    {
        cout << "The table is empty!\n";
        return -1;
    }
    else
    {
        try
        {
            for (int i = 0; i < free_size; ++i)
            {
                if (rows[i].surname == find_key)
                {
                    return i;
                    break;
                }
            }
            throw "Such element doesn`t exist.\n";
        }
        catch (const char* ex)
        {
            cout << ex << "Error ";
        }
        return -2;
    }
}

void HashTable::print()
{
    if (isEmpty()) cout << "Hash table is empty!\n";
    else
    {
        cout << "Hash table:\n";
        for (int i = 0; i < free_size; ++i)
        {
            if (rows[i].surname != "")
                cout << i << " - " << rows[i] << '\n';
        }
    }
}

int hash(string key, int hash_length)
{
    int sum = 0;
    for (int i = 0; i < key.length(); i++)
    {
        sum += key[i];
    }
    return sum % hash_length;
}

std::istream& operator>>(std::istream& is, Row& elem)
{
    is >> elem.surname >> elem.name >> elem.mark;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Row& elem)
{
    os << elem.surname << ' ' << elem.name << " - " << elem.mark;
    return os;
}