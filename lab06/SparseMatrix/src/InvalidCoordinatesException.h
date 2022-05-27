#pragma once
#include <string>

class InvalidCoordinatesException {
private:
    std::string mMessage;
public:
    //constructor
    InvalidCoordinatesException(std::string mMessage);

    //method that will show info about exception
    void getMessage() const;
};
