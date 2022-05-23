#include "String.h"

String::String() {
    length_ = 0;
    string_ = nullptr;
}

String::String(const char* arr) {
    length_ = strlen(arr);
    string_ = new char[length_];
    memcpy(string_, arr, length_);
}

String::String(const String &other) {
    length_= other.length_;
    string_ = new char[length_];
    memcpy(this->string_, other.string_, length_);
}

String::~String() {
    delete[] string_;
}

size_t String::Length() const {
    return length_;
}

void String::PrintToStream(std::ostream& out) const {
    for(int i = 0; i < length_; i++){
        out << string_[i];
    }
}

size_t String::Find(const String& other) const {
    if(other.length_ < length_) {
        size_t ret_index = 0;
        size_t other_length = other.length_;
        size_t delta = 0;
        int i = 0;
        while(i < length_) {
            delta = other_length;
            while(i < length_ && string_[i] != other.Front()) { // while possible start of other not found
                ++i;
                ++ret_index;
            }
            int j = 0;
            while(i < length_ && j < other.length_ && string_[i] == other.string_[j]) {
                ++ret_index;
                --other_length;
                ++i; ++j;
            }
            if(other_length == 0){ // if substring found
                return (ret_index-delta); // back to start of substring
            }
            else { // if sub-string is not fully equal to other - next iteration
                other_length = other.length_;
                delta = 0;
            }
        }
    }
    return length_+1;  // position of unexciting element count from 1 to length
}

char& String::Front() const {
    return string_[0];
}

void String::Replace(size_t from, size_t to, const String &other) {
    size_t new_mem = length_ - (to - from) + other.length_;
    char* new_str = new char[new_mem];
    memcpy(new_str, string_,from);
    memcpy(new_str+from, other.string_, other.length_);
    memcpy(new_str+from+other.length_, string_+to, length_-to);
    delete[] string_;
    string_ = new_str;
    length_ = new_mem;
    new_str = nullptr;
}

std::ostream& operator<<(std::ostream& out, const String& string) {
    string.PrintToStream(out);
    return out;
}

String String::operator+(const String& other)
{
    String res;
    res.length_ = this->length_ + other.length_;
    res.string_ = new char[res.length_];
    memcpy(res.string_, this->string_, this->length_);
    memcpy(res.string_ + this->length_, other.string_, other.length_);
    return res;
}

bool String::operator==(const String &other) {
    if(length_ != other.length_) {
        return false;
    }
    for(int i = 0; i < length_; i++){
        if(string_[i] != other.string_[i]) {
            return false;
        }
    }
    return true;
}

String &String::operator=(const String &other) {
    length_ = other.length_;
    delete[] string_;
    string_ = new char[length_];
    memcpy(string_, other.string_, length_);
    return *this;
}