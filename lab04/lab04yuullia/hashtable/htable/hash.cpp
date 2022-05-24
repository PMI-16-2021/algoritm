#include "hash.h"
using namespace std;


Element::Element() : key(), value(0) {}
Element::Element(string k, int v) : key(k), value(v) {}
Element::~Element(){};


    HashTable::HashTable(){}
    HashTable::HashTable(string k, int v) {
        add(k, v);
    }
    HashTable::~HashTable(){}

    int HashTable::_hash(std::string k) {
        int value = 0;
        for (int i = 0; i < k.length(); i++) {
            value += k[i];
        }
        return value % MAX;
    }

    void HashTable::add(std::string k, int v) {
        int index = _hash(k);
        for (int i = index; i < MAX; ++i) {
            if (dictionary[i].key == k) {
                throw "This word is already used";
            }
            ++i;
            i %= MAX;
        }
        while (dictionary[index].key != "" && dictionary[index].key != k) {
            ++index;
            index %= MAX;
        }
        dictionary[index].key = k;
        dictionary[index].value = v;
    }

    int HashTable::get(std::string k) {
        int index = _hash(k);
        for (int i = index; i < MAX; ++i) {
            if (dictionary[i].key == k) {
                return dictionary[index].value;
            }
            ++index;
            index %= MAX;
        }
        cout << "Key is not used.\n";
    }

    void HashTable::pop(std::string k) {
        int index = _hash(k);
        for (int i = index; i < MAX; ++i) {
            if (dictionary[i].key == k) {
                dictionary[index].key = "";
                dictionary[index].value = 0;
                return;
            }
            ++index;
            index %= MAX;
        }
        
    }

    int HashTable::elemCount() {
        int counter = 0;
        for (int i = 0; i < MAX; i++) {
            if (dictionary[i].key.length() > 0) {
                ++counter;
            }
        }
        return counter;
    }

    bool HashTable::isEmpty() {
        for (int i = 0; i < MAX; i++) {
            if (dictionary[i].key.length() > 0) {
                return false;
            }
        }
        return true;
    }

    void HashTable::values() {
        cout << "All values: \n";
        for (int i = 0; i < MAX; i++) {
            if (dictionary[i].key.length() > 0) {
                cout << "Key: " << dictionary[i].key;
                cout << ". Value: " << dictionary[i].value << endl;
            }
        }
    }