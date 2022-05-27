#pragma once

#include <iostream>

template<typename T>
class NotUniqueElementException {
private:
    T element;
public:
    //constructor
    NotUniqueElementException(T element) {
        this->element = element;
    };

    //method that will show info about exception
    void getMessage() const;
};

template<typename T>
void NotUniqueElementException<T>::getMessage() const {
    // inform user the reason of the exception
    std::cout << "Element : " << element << " already presents in the set \n";
}
