#pragma once

#include <iostream>
#include <vector>

class MyString {
private:
    size_t size;
    char *data;
public:
    // empty constructor
    MyString();

    // constructors with parameter
    MyString(const char *string);

    // copy constructor
    MyString(const MyString &string);

    // destructor
    ~MyString();

    // method that returns length of MyString
    size_t getLength() const;

    // Returns a newly constructed string object with its value initialized to a copy of a substring of this object.
    //The substring is the portion of the object that starts at character position pos and spans len characters (or until the end of the string, whichever comes first).
    MyString substr(size_t position, size_t length) const;

    // method that finds "string" starting position in the MyString
    // if the "string" is not present
    int find(const MyString &string) const;

    //replace text in myString from "from" to "to"
    //return false if operation isn't successful
    bool replace(const MyString &from, const MyString &to);

    //overloading operator "="
    MyString &operator=(const MyString &string);

    //adding two strings
    MyString operator+(const MyString &string);

    //operator of comparison
    bool operator==(const MyString &string) const;

    //iterator of MyString object
    class iterator {
    private:
        char *mPointer;
    public:
        iterator(char *pointer = nullptr);

        //basic iterator functionality
        iterator &operator++();

        char &operator*();

        bool operator!=(const iterator &otherIterator);

        bool operator==(const iterator &otherIterator);

        bool operator<(const iterator &otherIterator);
    };

    //returns iterator(pointer) to start of MyString
    iterator begin();

    //returns iterator(pointer) to the end of MyString
    iterator end();

    //overloading operator "<<" for MyString
    friend std::ostream &operator<<(std::ostream &out, const MyString &string);
};

//struct that represents Markov rule
struct Rule {
    MyString mFrom;             //original
    MyString mTo;               //to replace original
    bool mTerminal;           //check if terminal
    Rule(MyString from, MyString to, bool isTerminal = false) {
        mFrom = from;
        mTo = to;
        mTerminal = isTerminal;
    }

    Rule() {
        mFrom = "";
        mTo = "";
        mTerminal = false;
    }
};

//Markov algorithm
MyString markovAlgorithm(std::vector<Rule> &, MyString data);