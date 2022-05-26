//
// Created by Ostap Kilbasovych on 26.05.2022.
//

#include "MyString.h"

#ifndef MARKOVALG_BADRULEEXCEPTION_H
#define MARKOVALG_BADRULEEXCEPTION_H


class BadRuleException {
private:
    MyString myString;
public:
    BadRuleException(const MyString& string) : myString(string){
    }
    void getMessage() const{
        std::cout << "Detected incorrect rule in Markov Algorithm :" << myString << "\n";
    }
};


#endif //MARKOVALG_BADRULEEXCEPTION_H
