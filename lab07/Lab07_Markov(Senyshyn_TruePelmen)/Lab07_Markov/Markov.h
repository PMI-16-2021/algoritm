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

    String(): str(nullptr), size(0){}
    String(const char* arr): size(Length(arr))
    {
        this->str = new char[size];
        for (int i = 0; i < size; i++)
            this->str[i] = arr[i];
    }
    ~String(){}
    int Length()
    {
        int i = 0;
        while (str[i] != '\0')
            i++;
        return i + 1;
    } 
    int Find(String change_string)
    {
        int size_of_change_string = change_string.size;
        int size_of_string = size;
        for (int i = 0; i < size_of_string; i++)
        {
            if (change_string[0] == str[i] && size_of_change_string == 2)
                return i;
            if (change_string[0] == str[i])
            {
                for (int p = 1, j = i + 1; p < size_of_change_string - 1 && j < size_of_string - 1; j++, p++)
                {
                    if (change_string[p] == str[j])
                        return i;
                    else
                        break;
                }
            }
        }
        return -1;
    } 
    int Length(const char* arr)
    {
        int i = 0;
        while (arr[i] != '\0')
            i++;
        return i + 1;
    }
   
    String operator=(String& arr)
    {

        size = arr.size;
        str = new char[size];
        for (int i = 0; i < size; i++)
            str[i] = arr.str[i];
        return *this;
    }
    

    String operator+(const String& arr)
    {
        String new_string;
        new_string.size = size + arr.size - 1;
        new_string.str = new char[new_string.size];
        for (int i = 0; i < size; i++)
            new_string.str[i] = str[i];
        for (int i = size - 1, j = 0; j < arr.size; i++, j++)
            new_string.str[i] = arr.str[j];
        return new_string;
    }
   
    char operator[](const int i)
    {
        if ( i < size && i >= 0)
            return str[i];
        return '\0';
    }
    const char operator[](const int i) const
    {
        if (i >= 0 && i < size)
            return str[i];
        return '\0';
    }
  
    String operator=(const char* arr)
    {

        size = Length(arr) + 1;
        str = new char[size];
        for (int i = 0; i < size; i++)
            str[i] = arr[i];
        return *this;
    }
     bool operator==(String& arr)
    {
        if (size == arr.size) {
            for (int i = 0; i < size; i++)
            {
                if (str[i] = arr.str[i])
                    return true;
            }
        }
        return false;
    }
    friend ostream& operator<<(ostream& os, const String& string_)
    {
        for (int i = 0; i < string_.size - 1; i++)
            os << string_.str[i];
        return os;
    }
    void replace(String change_string, String replaced_string)
    {
        int index = Find(change_string);
        int size_of_change_string = change_string.size;
        int size_of_replaced_string = replaced_string.size;
        char* new_string = new char[size];
        for (int i = 0; i < size; i++)
            new_string[i] = str[i];
        int size_of_new_string = size;
        size = size - size_of_change_string + size_of_replaced_string;
        this->str = new char[size];

        for (int i = 0; i < index; i++)
            this->str[i] = new_string[i];
        for (int j = 0, i = index; j < size_of_replaced_string - 1; j++, i++)
            this->str[i] = replaced_string[j];
        for (int i = (index + size_of_replaced_string - 1), j = (index + size_of_change_string - 1); j < size_of_new_string && i < size; j++, i++)
            this->str[i] = new_string[j];
        delete[] new_string;
    }
};

struct Replacement
{
    String changed_string;
    String replacing_string;
    bool is_last;
    Replacement(): changed_string(" "), replacing_string(" "), is_last(false){}
    Replacement(String change_str, String replace_str, bool is_last): changed_string(change_str), replacing_string(replace_str), is_last(is_last){}
    friend ostream& operator<<(ostream& os, const Replacement& rep)
    {
        os << "From " << rep.changed_string << " to " << rep.replacing_string << endl;
        return os;
    }
};

String Markov(String param_string, vector<Replacement> replacements)
{
    for (int i = 0; i < replacements.size(); i++)
    {
        int change_string_index = param_string.Find(replacements[i].changed_string);
        if (change_string_index >= 0)
        {
            param_string.replace(replacements[i].changed_string, replacements[i].replacing_string);
            if (replacements[i].is_last == true)
                break;
            i = -1;
        }
    }
    return param_string;
}
