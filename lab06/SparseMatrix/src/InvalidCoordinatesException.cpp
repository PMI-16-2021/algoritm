#include "InvalidCoordinatesException.h"
#include <iostream>

InvalidCoordinatesException::InvalidCoordinatesException(std::string message) {
    this->mMessage = message;
}

void InvalidCoordinatesException::getMessage() const {
    // inform user the reason of the exception
    std::cout << mMessage;
}

