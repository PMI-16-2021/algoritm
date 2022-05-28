#pragma once
#include<iostream>

template<typename T>
class MySet {
private:
    T* array;
    int size;
    int max_size;
public:
    MySet();
    MySet(int max_size);
    ~MySet();
    void add(T element);
    void remove(T element);
    int len() const;
    bool in(T element) const;
    MySet<T> Union(const MySet<T>& other) const;
    MySet<T> Intersection(const MySet<T>& other);
    MySet<T> Difference(const MySet<T>& other);
    MySet<T> Symmetric_difference(MySet<T>& other);
    void print() const;
    T& operator[](int index);
};

template<typename T>
MySet<T>::MySet() 
    : size(0), max_size(0), array(new T[max_size])
{}

template<typename T>
MySet<T>::MySet(int max_size_)
    : size(0), max_size(max_size_), array(new T[max_size_])
{}

template<typename T>
MySet<T>::~MySet()
{}

template<typename T>
void MySet<T>::add(T element) {
    if (!in(element)) {
        if (size == max_size) {
            max_size += 10;
            T* temp = new T[max_size];
            for (int i = 0; i < size; ++i) {
                temp[i] = array[i];
            }
            delete[] array;
            array = temp;
        }
        array[size] = element;
        ++size;
    }
}

template<typename T>
void MySet<T>::remove(T element) {
    T* temp = new T[max_size];
    int pos = 0;
    if (size > 0) {
        for (int i = 0; i < size; ++i) {
            if (array[i] == element) {
                pos = i;
                break;
            }
        }
    }
    for (int i = 0; i < pos; ++i) {
        temp[i] = array[i];
    }
    for (int i = pos; i < size; ++i) {
        temp[i] = array[i + 1];
    }
    if (size > 0) {
        delete[] array;
    }
    array = temp;
    --size;
}

template<typename T>
int MySet<T>::len() const {
    return size;
}

template<typename T>
bool MySet<T>::in(T element) const {
    if (size == 0) {
        return false;
    }
    for (int i = 0; i < size; ++i) {
        if (array[i] == element) {
            return true;
        }
    }
    return false;
}

template<typename T>
MySet<T> MySet<T>::Union(const MySet<T>& other) const {
    MySet<T> set;
    for (int i = 0; i < size; ++i) {
        set.add(array[i]);
    }
    for (int i = 0; i < other.size; ++i) {
        set.add(other.array[i]);
    }
    return set;
}

template<typename T>
MySet<T> MySet<T>::Intersection(const MySet<T>& other) {
    MySet<T> set;
    for (int i = 0; i < size; ++i) {
        if (other.in(array[i])) {
            set.add(array[i]);
        }
    }
    return set;
}

template<typename T>
MySet<T> MySet<T>::Difference(const MySet<T>& other) {
    MySet<T> set;
    for (int i = 0; i < size; ++i) {
        if (!other.in(array[i])) {
            set.add(array[i]);
        }
    }
    return set;
}

template<typename T>
MySet<T> MySet<T>::Symmetric_difference(MySet<T>& other) {
    MySet<T> set;
    for (int i = 0; i < size; ++i) {
        if (!other.in(array[i])) {
            set.add(array[i]);
        }
    }
    for (int i = 0; i < other.size; ++i) {
        if (!other.in(other[i])) {
            set.add(other[i]);
        }
    }
    return set;
}

template<typename T>
void MySet<T>::print() const {
    std::cout << "{ ";
    for (int i = 0; i < size-1; ++i) {
        std::cout << array[i] << ", ";
    }
    for (int i = size - 1; i < size; ++i) {
        std::cout << array[i];
    }
    std::cout << " }\n";
}

template<typename T>
T& MySet<T>::operator[](int index) {
    return array[index];
}