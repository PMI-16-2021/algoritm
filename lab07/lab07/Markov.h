#pragma once
#include<iostream>
#include<vector>
using std::ostream;
using std::istream;

class NewStr
{
private:
    char* line;
    int size;	//size of line
public:
    NewStr() :line(nullptr), size(0) {} //default constructor
    NewStr(const char* in); //constructor
    int length(); //function to find size of line
    int length(const char* in); //function to find size of line with another parametrs
    int FindPosition(NewStr substring); //find position of substring else return -1
    void Replace(NewStr changed, NewStr replaced); // function to replace one symbols to another
    NewStr operator +(const NewStr& A); //operator + to add one line to another
    bool operator ==(const NewStr& A); //equal operator
    char& operator [](const int i); // index operator
    NewStr operator =(NewStr& A); //operator =
    NewStr operator =(const char* A); //operator = with other parametrs
    friend ostream& operator<<(ostream& os, const NewStr& A);
    friend istream& operator>>(istream& is, NewStr& A);
};

struct Rule
{
    NewStr change_string;
    NewStr replace_string;
    bool is_last;

    Rule(): change_string(" "),replace_string(" "), is_last(false) {}
    Rule(NewStr pattern, NewStr replace_str, bool is_last)
    {
        change_string = pattern;
        this->replace_string = replace_str;
        this->is_last = is_last;
    }
};

NewStr Markov(NewStr string_, std::vector<Rule> rules);