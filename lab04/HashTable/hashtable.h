#pragma once
#include <iostream>

template<typename T>
struct TableElem {
    std::string key;
    T value;
    TableElem() : value(T(0)) {}
    TableElem(std::string _key, T _val) : key(std::move(_key)), value(_val) {}
};

template<typename T>
class HashTable {
private:
    static const unsigned int kMaxSize_ = 10;
    TableElem<T> table_[kMaxSize_];
    unsigned int counter_;
    TableElem<T> FindByKey(std::string key);
public:
    HashTable();
    ~HashTable();
    unsigned int _hash(std::string key);
    void Add(TableElem<T>& _elem);
    T& Get(std::string key);
    T Pop(std::string key);
    void Values();
    bool IsEmpty() const { return counter_ == 0;}

    class Repetition {
    public:
        Repetition(const char* msg) { std::cerr<<msg<<'\n'; }
    };

    class EmptyException {
    public:
        EmptyException(const char* msg) { std::cerr<<msg<<'\n'; }
    };

    class NotFound {
    public:
        NotFound(std::string key) { std::cerr<<"There is not element with "<<key<<" key\n"; }
    };
};

template<typename T>
HashTable<T>::HashTable() : counter_(0) {}

template<typename T>
HashTable<T>::~HashTable(){}

template<typename T>
unsigned int HashTable<T>::_hash(std::string key) {
    unsigned int return_value = 0;
    if(key.length() == 1) {
        return_value = key[0];
    }
    else if(key.length() > 1) {
        return_value = key[0]*26 + key[1]; // f(sls2) = ksl*26 + ks2, ksl та ks2 - коди першої та другої літер.
    }
    return return_value % kMaxSize_;  // % kMaxSize to prevent exit out of range
}

template<typename T>
TableElem<T> HashTable<T>::FindByKey(std::string key) {
    TableElem<T> searched_elem;
    unsigned int index, hash_value;
    hash_value = _hash(key);
    index = hash_value;
    while(table_[index].key != key && table_[index].key != "") {
        if(index == 0) {
            ++index;
            ++hash_value;
        }
        index = (index + hash_value) % kMaxSize_;
    }
    if(table_[index].key == key) {
        searched_elem = table_[index];
    }
    else {
        throw NotFound(key);
    }
    return searched_elem;
}

template<typename T>
void HashTable<T>::Add(TableElem<T>& _elem) {
    if(counter_ == kMaxSize_) {
        throw EmptyException("You can't add to full table");
    }
    unsigned int index, hash_value;
    hash_value = _hash(_elem.key);
    index = hash_value;
    // if there is already free cell and if value is unique go to 107 line
    if(_elem.value == table_[index].value) {
        throw Repetition("Element with such already exists.");
    }
    while(table_[index].key != "") { // in case of collisions searching free cell
        if(_elem.value == table_[index].value) {
            throw Repetition("Element with such already exists.");
        }
        if(index == 0) { // to prevent endless loop
            ++index;
            ++hash_value;
        }
        index = (index + hash_value) % kMaxSize_;
    }
    table_[index] = _elem;
    ++counter_;
}

template<typename T>
T& HashTable<T>::Get(std::string key) {
    if(IsEmpty()) {
        throw EmptyException("You can't Get value from empty table.");
    }
    T return_value;
    return_value = FindByKey(key).value;
    return return_value;
}

template<typename T>
T HashTable<T>::Pop(std::string key) {
    if(IsEmpty()) {
        throw EmptyException("You can't Pop value from empty table.");
    }
    TableElem<T> temp = FindByKey(key);
    T ret_val = temp.value;
    unsigned int index, hash_value;
    hash_value = _hash(temp.key);
    index = hash_value;
    while(table_[index].key != key && table_[index].key != "") {
        if(index == 0) {
            ++index;
            ++hash_value;
        }
        index = (index + hash_value) % kMaxSize_;
    }
    table_[index].key = "";
    table_[index].value = NULL;
    --counter_;
    return ret_val;
}

template<typename T>
void HashTable<T>::Values()  {
    for(int i = 0; i < kMaxSize_; ++i){
        if(table_[i].key != "") {
            std::cout << "key: " << table_[i].key << " , value: " << table_[i].value << '\n';
        }
    }
}
