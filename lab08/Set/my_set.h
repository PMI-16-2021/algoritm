#pragma once
#include <iostream>
#include <map>

template<typename T>
class MySet {
private:
    T* set_;
    size_t size_;
    size_t used_;
    bool IsFull() const;
    void Resize(size_t size);
    size_t FindElem(T _elem) const;
    void Shift(size_t to);   // shifts elements after deleting element at some position(to)
public:
    MySet();
    MySet(size_t _size);
    MySet(const MySet<T>& other);
    ~MySet();
    size_t GetUsed() const {return used_;}
    void Add(T _elem);  // check if already exists
    void Remove(T _elem);  // check if exists
    size_t Len() const;
    bool IsIn(T _elem) const;
    MySet<T> Union(const MySet<T>&other) const;
    MySet<T> Intersection(const MySet<T>& other) const;
    MySet<T> Difference(const MySet<T>& other) const;
    MySet<T> SymmetricDifference(const MySet<T>& other) const;
    void Print() const;
    T* GetSet() {return set_;} // for unit tests
};

template<typename T>
bool MySet<T>::IsFull() const {
    return size_ == used_;
}

template<typename T>
MySet<T>::MySet() : size_(10), used_(0), set_(new T[size_]) {}

template<typename T>
MySet<T>::MySet(size_t _size) : size_(_size), used_(0), set_(new T[size_]) {}

template<typename T>
MySet<T>::MySet(const MySet<T> &other) {
    size_ = other.size_;
    used_ = other.used_;
    for(int i = 0; i < other.used_; i++) {
        set_[i] = other.set_[i];
    }
}

template<typename T>
MySet<T>::~MySet() {
    delete[] set_;
}

template<typename T>
void MySet<T>::Add(T _elem) {
    if(IsIn(_elem)) {
        return;
    }
    if(IsFull()) {
        Resize(10);
    }
    set_[used_] = _elem;
    ++used_;
}

template<typename T>
void MySet<T>::Remove(T _elem) {  // if elem exists - remove, if not - do nothing
    if(IsIn(_elem)) {
        size_t index = FindElem(_elem);
        set_[index] = T(0);
        Shift(index);
        --used_;
    }
}

template<typename T>
size_t MySet<T>::Len() const {
    return used_;
}

template<typename T>
bool MySet<T>::IsIn(T _elem) const {
    for(int i = 0; i < used_; i++){
        if(set_[i] == _elem){
            return true;
        }
    }
    return false;
}

template<typename T>
MySet<T> MySet<T>::Union(const MySet<T> &other) const {
    size_t size = other.used_+used_;
    MySet<T> ret_set(size);
    for(int i = 0; i < used_; i++) {
        ret_set.Add(set_[i]);
    }
    for(int i = 0; i < other.used_; i++){
        ret_set.Add(other.set_[i]);
    }
    return ret_set;
}

template<typename T>
MySet<T> MySet<T>::Intersection(const MySet<T> &other) const {
    MySet<T> ret_set;
    for(int i = 0; i < used_; i++){
        if(other.IsIn(set_[i])){
            ret_set.Add(set_[i]);
        }
    }
    return ret_set;
}

template<typename T>
MySet<T> MySet<T>::Difference(const MySet<T> &other) const {
    MySet<T> ret_set;
    for(int i = 0; i < used_; i++) {
        if(!(other.IsIn(set_[i]))) {
            ret_set.Add(set_[i]);
        }
    }
    return ret_set;
}

template<typename T>
MySet<T> MySet<T>::SymmetricDifference(const MySet<T> &other) const {
    // union - intersection
    MySet<T> intersection = Intersection(other);
    MySet<T> union_ = Union(other);
    for(int i = 0; i < intersection.GetUsed(); i++) {
        union_.Remove(intersection.set_[i]);
    }
    return union_;
}

template<typename T>
void MySet<T>::Print() const {
    for(int i = 0; i < used_; i++) {
        std::cout << set_[i] << '\t';
    }
}

template<typename T>
void MySet<T>::Resize(size_t size) {
    size_ +=  size;
    T* temp = new T[size_];
    for(int i = 0; i < size_; i++){
        temp[i] = set_[i];
    }
    delete[] set_;
    set_ = temp;
    temp = nullptr;
}

template<typename T>
size_t MySet<T>::FindElem(T _elem) const {
    size_t index = 0;
    for(int i = 0; i < used_; i++) {
        if(set_[i] == _elem){
            index = i;
        }
    }
    return index;
}

template<typename T>
void MySet<T>::Shift(size_t to) {
    for(int i = to; i < used_; i++) {
        set_[i] = set_[i+1];
    }
}
