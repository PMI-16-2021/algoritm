#pragma once
#include <iostream>
#include "Table.h"



class HashTable
{
private:

    static const size_t  hashGroups = 10;
    Table tables[hashGroups];

public:

  static size_t hash(const string& key);
  int getTheItem(const string& key) const;
  void addTheItemValue(const string& key, const int& value);
  bool isItemInTheTable(const string& key) const;
  void deleteTheItemFromTheTable(const string& key);
  void clearTheHashMap();
  int sizeOfTheHashMap()const;

};