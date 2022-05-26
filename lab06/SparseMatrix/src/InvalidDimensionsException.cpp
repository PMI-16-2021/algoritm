#include "InvalidDimensionsException.h"
#include <iostream>

InvalidDimensionsException::InvalidDimensionsException(std::string message) {
    this->mMessage = message;
}

void InvalidDimensionsException::getMessage() const {
    // inform user the reason of the exception
    std::cout << mMessage;
}

