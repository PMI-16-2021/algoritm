#pragma once

#include <iostream>

template<typename T>
class ElementNotFoundException {
private:
    T element;
public:
    //constructor
    ElementNotFoundException(T element) {
        this->element = element;
    };

    //method that will show info about exception
    void getMessage() const;
};

template<typename T>
void ElementNotFoundException<T>::getMessage() const {
    // inform user the reason of the exception
    std::cout << "You tried to access element : " << element << " but it doesn't exist \n";
}
