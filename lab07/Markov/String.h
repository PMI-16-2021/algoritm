#pragma once
#include <iostream>

class String {
private:
    char* string_;
    size_t length_;
public:
    String();
    String(const char* arr);
    String(const String& other);
    ~String();

    size_t Length() const;
    void PrintToStream(std::ostream& out) const;
    size_t Find(const String& other) const;
    char& Front() const;
    void Replace(size_t from, size_t to, const String &other);  // [from;to)
    String operator+(const String& other);
    bool operator==(const String& other);
    String& operator=(const String& other);
};

std::ostream& operator<<(std::ostream& out, const String& string);
