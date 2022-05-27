#include "MyString.h"
#include "BadRuleException.h"
#include <vector>

// empty constructor
MyString::MyString() {
    size = 0;
    data = nullptr;
}

// constructors with parameter
MyString::MyString(const char *string) {
    size = strlen(string);
    data = new char[size];
    memcpy(data, string, size);
}

// copy constructor
MyString::MyString(const MyString &string) {
    size = string.size;
    data = new char[size];
    memcpy(this->data, string.data, size);
}

// destructor
MyString::~MyString() {
    delete[] data;
}

// method that returns length of MyString
size_t MyString::getLength() const {
    return size;
}

// Returns a newly constructed string object with its value initialized to a copy of a substring of this object.
//The substring is the portion of the object that starts at character position pos and spans len characters (or until the end of the string, whichever comes first).
MyString MyString::substr(size_t position, size_t length) const {
    if (position + length > size) {
        throw std::out_of_range("Bad position detected");
    }
    MyString result;
    result.size = length;
    result.data = new char[length];
    memcpy(result.data, data + position, length);
    return result;
}

// method that finds "string" starting position in the MyString
// if the "string" is not present returns -1
int MyString::find(const MyString &string) const {
    int counter = 0;
    int internalCounter = 0;
    int length = string.size;
    while (internalCounter <= (size - length) && length > 0) {
        if ((data[internalCounter]) == string.data[0]) {
            counter = 0;
            for (int count = internalCounter; count < (internalCounter + length); count++) {
                if (data[count] == string.data[counter])
                    ++counter;
                else {
                    counter = 0;
                    break;
                }
            }
            if (counter == length)
                return internalCounter;
        }
        ++internalCounter;
    }
    return -1;
}

//replace text in myString from "from" to "to"
//return false if operation isn't successful
bool MyString::replace(const MyString &from, const MyString &to) {
    bool ifSuccessful = false;
    int fromPosition = (*this).find(from);
    if (fromPosition != -1) {
        MyString before = this->substr(0, fromPosition);
        int resFromPosition = fromPosition + from.getLength();
        int lengthOfNewStr = this->getLength() - resFromPosition;
        MyString after = this->substr(resFromPosition, lengthOfNewStr);
        *this = before + to + after;
        ifSuccessful = true;
    }
    return ifSuccessful;
}

//overloading operator "="
MyString &MyString::operator=(const MyString &string) {
    this->size = string.size;
    delete[] data;
    data = new char[size];
    memcpy(this->data, string.data, size);
    return *this;
}

//adding two strings
MyString MyString::operator+(const MyString &string) {
    MyString result;
    result.size = this->size + string.size;
    result.data = new char[result

            .size];
    memcpy(result.data, this->data, this->size);
    memcpy(result.data + this->size, string.data, string.size);
    return result;
}

//operator of comparison
bool MyString::operator==(const MyString &string) const {
    return (this->size == string.size) && (0 == memcmp(this->data, string.data, size));
}

//iterator methods
MyString::iterator MyString::begin() {
    return iterator(data);
}

MyString::iterator MyString::end() {
    return iterator(data + size);
}

std::ostream &operator<<(std::ostream &out, const MyString &string) {
    for (size_t i = 0; i < string.getLength(); i++) {
        out << string.data[i];
    }
    return out;
}

MyString::iterator::iterator(char *pointer) {
    mPointer = pointer;
}

MyString::iterator &MyString::iterator::operator++() {
    ++mPointer;
    return *this;
}

char &MyString::iterator::operator*() {
    return *mPointer;
}

bool MyString::iterator::operator!=(const iterator &otherIterator) {
    return mPointer != otherIterator.mPointer;
}

bool MyString::iterator::operator==(const iterator &otherIterator) {
    return mPointer == otherIterator.mPointer;
}

bool MyString::iterator::operator<(const iterator &otherIterator) {
    return mPointer < otherIterator.mPointer;
}

//Markov algorithm
MyString markovAlgorithm(std::vector<Rule> &rules, MyString data) {
    if (rules.empty()) {
        throw BadRuleException("No rules");
    }
    MyString result = data;
    std::vector<Rule>::iterator rulesIterator = rules.begin();
    int count = 0;
    while (rulesIterator != rules.end()) {
        int position = result.find(rulesIterator->mFrom);
        if (position != -1) {
            result.replace(rulesIterator->mFrom, rulesIterator->mTo);
            if (rulesIterator->mTerminal) {
                break;
            }
            rulesIterator = rules.begin();
        } else {
            ++rulesIterator;
        }
        ++count;
    }
    if (count > 1000) {
        throw BadRuleException(data);
    }
    return result;
}