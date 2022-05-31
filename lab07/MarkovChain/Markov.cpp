#include "Markov.h"


String::String() 
{
    str = nullptr;
    size = 0;
}

String::String(const char* arr) 
{
    this->size = length(arr);
    this->str = new char[size];
    for (int i = 0; i < size; i++) 
    {
        this->str[i] = arr[i];
    }
}

int String::length() 
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i + 1;
}

int String::length(const char* arr)
{
    int i = 0;
    while (arr[i] != '\0')
    {
        i++;
    }
    return i + 1;
}

int String::find_position(String change_string) 
{
    int size_of_change_string = change_string.size;
    int size_of_string = size;
    for (int i = 0; i < size_of_string; i++)
    {
        if (change_string[0] == str[i] && size_of_change_string == 2)
        {
            return i;
        }
        if (change_string[0] == str[i]) 
        {
            for (int p = 1, j = i + 1; p < size_of_change_string - 1 && j < size_of_string - 1; j++, p++)
            {
                if (change_string[p] == str[j]) 
                {
                    return i;
                }
                else
                {
                    break;
                }
            }
        }
    }
    return -1;
}

void String::replace(String change_string, String replaced_string)
{
    int index = find_position(change_string);
    int size_of_change_string = change_string.size;
    int size_of_replaced_string = replaced_string.size;
    char* new_string = new char[size];
    for (int i = 0; i < size; i++) 
    {
        new_string[i] = str[i];
    }
    int size_of_new_string = size;
    size = size - size_of_change_string + size_of_replaced_string;
    this->str = new char[size];

    for (int i = 0; i < index; i++)
    {
        this->str[i] = new_string[i];
    }
    for (int j = 0, i = index; j < size_of_replaced_string - 1; j++, i++) 
    {
        this->str[i] = replaced_string[j];
    }
    for (int i = (index + size_of_replaced_string - 1), j = (index + size_of_change_string - 1);
        j < size_of_new_string && i < size; j++, i++)
    {
        this->str[i] = new_string[j];
    }
    delete[] new_string;
}

String String::operator+(const String& arr)
{
    String new_string;
    new_string.size = size + arr.size - 1;
    new_string.str = new char[new_string.size];
    for (int i = 0; i < size; i++) 
    {
        new_string.str[i] = str[i];
    }
    for (int i = size - 1, j = 0; j < arr.size; i++, j++) 
    {
        new_string.str[i] = arr.str[j];
    }

    return new_string;
}

bool String::operator==(String& arr) 
{
    if (size == arr.size) {
        for (int i = 0; i < size; i++)
        {
            if (str[i] = arr.str[i]) 
            {
                return true;
            }
        }
    }
    return false;
}

char String::operator[](const int i)
{
    if (i >= 0 && i < size)
    {
        return str[i];
    }
    return '\0';
}

const char String::operator[](const int i) const 
{
    if (i >= 0 && i < size)
    {
        return str[i];
    }
    return '\0';
}

String String::operator=(String& arr)
{

    size = arr.size;
    str = new char[size];
    for (int i = 0; i < size; i++)
    {
        str[i] = arr.str[i];
    }
    return *this;
}

String String::operator=(const char* arr)
{

    size = length(arr) + 1;
    str = new char[size];
    for (int i = 0; i < size; i++)
    {
        str[i] = arr[i];
    }
    return *this;
}

ostream& operator<<(ostream& os, const String& string_)
{
    for (int i = 0; i < string_.size - 1; i++)
    {
        os << string_.str[i];
    }
    return os;
}

Substitution::Substitution()
{
    change_string = " ";
    replace_string = " ";
    is_last = false;
}

Substitution::Substitution(String change_str, String replace_str, bool is_last)
{
    this->change_string = change_str;
    this->replace_string = replace_str;
    this->is_last = is_last;
}

ostream& operator<<(ostream& os, const Substitution& sub)
{
    os << "From " << sub.change_string << " to " << sub.replace_string << endl;
    return os;
}

String Markov(String string_, vector<Substitution> substitutions) 
{
    for (int i = 0; i < substitutions.size(); i++) 
    {
        int change_string_index = string_.find_position(substitutions[i].change_string);
        if (change_string_index >= 0) 
        {
            string_.replace(substitutions[i].change_string, substitutions[i].replace_string);
            if (substitutions[i].is_last == true)
            {
                break;
            }
            i = -1;
        }
    }

    return string_;
}

