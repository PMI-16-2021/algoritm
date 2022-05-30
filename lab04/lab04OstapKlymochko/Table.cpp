#include <iostream>
#include"Table.h"
using namespace std;


    Table::Table()
    : array(0)
    {

    }

    Table::Table(const vector <Data>& array) 
    : array(array) 
    {

    }

    void Table::clearTheMap()
    {
        array.clear();
    }

    int Table::sizeOfTheMap()const
    {
        return array.size();
    }

    bool Table::isItem(const string& key)const
    {
        for (int i = 0; i < array.size(); ++i)
        {
            if (key == array[i].key)
            {
                return true;
            }

        }
        return false;
    }

    int Table::itemValue(const string& key)const
    {
        for (int i = 0; i < array.size(); i++)
        {
            if (key == array[i].key)
            {
                return array[i].value;
            }
        }
        throw("No element with this key here\n");
    }

    void Table::addTheItem(const string& key, const int& value)
    {
        if (isItem(key))
        {
            throw("The key is already exist\n");
        }

        Data temp;
        temp.key = key;
        temp.value = value;

        array.push_back(temp);
    }

    void Table::deleteTheItem(const string& key)
    {
        if (!isItem(key))
        {
            throw("The key isn't exist\n");
        }
        auto iter = array.begin();

        for (int i = 0; i < array.size(); i++)
        {
            iter++;
            if (array[i].key == key)
            {
                break;
            }
        }
        array.erase(iter);
    }



