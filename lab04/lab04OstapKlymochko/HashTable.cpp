#include"HashTable.h"

using namespace std;


    size_t HashTable::hash(const string& key)
    {
        int sum = 0;

        for (char letter : key)
        {
            sum += letter;
        }

        return sum % hashGroups;
    }

    int HashTable::getTheItem(const string& key) const
    {
        return tables[hash(key)].itemValue(key);
    }

    void HashTable::addTheItemValue(const string& key, const int& value)
    {
        tables[hash(key)].addTheItem(key, value);
    }

    bool HashTable::isItemInTheTable(const string& key) const
    {
        return tables[hash(key)].isItem(key);
    }

    void HashTable::deleteTheItemFromTheTable(const string& key)
    {
        tables[hash(key)].deleteTheItem(key);
    }

    void HashTable::clearTheHashMap()
    {
        tables->clearTheMap();
    }

    int HashTable::sizeOfTheHashMap()const
    {
        return tables->sizeOfTheMap();
    }


