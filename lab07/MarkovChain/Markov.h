#pragma once
#include <iostream>
#include <vector>

using namespace std;

class String
{
private:
    char* str;
    int size;
public:

    String();
    String(const char* arr);
    int length();
    int length(const char* arr);
    int find_position(String change_string);
    void replace(String change_string, String replaced_string);

    String operator+(const String& arr);
    bool operator==(String& arr);
    char operator[](const int i);
    const char operator[](const int i) const;
    String operator=(String& arr);
    String operator=(const char* arr);

    friend ostream& operator<<(ostream& os, const String& string_);

};

struct Substitution 
{
    String change_string;
    String replace_string;
    bool is_last;

    Substitution();
    Substitution(String change_str, String replace_str, bool is_last);

    friend ostream& operator<<(ostream& os, const Substitution& sub);
};

String Markov(String string_, vector <Substitution> substitutions);