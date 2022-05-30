#pragma once
#include<string>
#include<vector>
using std::vector;
using std::string;

struct Data
{
    string key;
    int value;
};


class Table
{
private:
    vector<Data> array;
public:
    Table();
    Table(const vector <Data>& array);
    void clearTheMap();
    int sizeOfTheMap()const;
    bool isItem(const string& key)const;
    int itemValue(const string& key)const;
    void addTheItem(const string& key, const int& value);
    void deleteTheItem(const string& key);



};
