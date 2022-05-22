#pragma once
#include <iostream>

class String {
private:
    struct StringElem {
        char elem;
        StringElem* next_char;
        StringElem(StringElem* _next_char = nullptr);
        StringElem(char val, StringElem* _next_char = nullptr);
    };
    StringElem* head_;
    StringElem* tail_;
    size_t length_;
public:
    // Constructors
    String();
    String(char letter);
    String(const char* arr);
    String(const String& other);
    ~String();
    //Methods
    void PrintToStream(std::ostream& out) const;
    size_t Length() const;
    char& Front() const;
    char& Back() const;
    void Assign(const char& letter, size_t at);
    void Assign(const char* letter, size_t from, size_t letter_size);
    bool Replace(size_t from, size_t to, const String& other);
    void Clear();
    void Insert(size_t at, const char* letter, size_t count);  // offset, c-string, amount of elements from letter
    void Insert(size_t this_offset, const String& other, size_t other_offset, size_t count); // offset, string, string offset, amount of elements from string
    size_t Find(const String& other) const;    // returns index of the first letter in found word
    // Operators
    String operator+(const String& other) const;
    bool operator==(const String& other) const;
    char& operator[](size_t position) const;
};

std::ostream& operator<<(std::ostream& out, const String& string);

