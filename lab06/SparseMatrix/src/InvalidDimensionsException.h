#pragma once
#include <string>

class InvalidDimensionsException {
private:
    std::string mMessage;
public:
    //constructor
    InvalidDimensionsException(std::string mMessage);

    //method that will show info about exception
    void getMessage() const;
};
