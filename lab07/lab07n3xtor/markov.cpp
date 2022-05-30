#include"Markov.h"

NewStr::NewStr(const char* in)
{
    size = length(in);
    line = new char[size];
    for (int i = 0; i < size; ++i)
    {
        line[i] = in[i];
    }
}

int NewStr::length()
{
    size_t i = 0;
    while (line[i] != '\0')
    {
        i++;
    }
    return ++i;
}

int NewStr::length(const char* in)
{
    int i = 0;
    while (in[i] != '\0')
    {
        i++;
    }
    return ++i;
}

int NewStr::FindPosition(NewStr subString)
{
    int subString_Size = subString.size;
    int line_size = size;
    size_t i, j, p;
    for (i = 0; i < line_size; ++i)
    {
        if (subString[0] == line[i] && subString_Size == 2)
        {
            return i;
        }
        if (subString[0] == line[i])
        {
            for (p = 1, j = i + 1; p < subString_Size - 1 && j < line_size - 1; j++, p++)
            {
                if (subString[p] == line[j])
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

void NewStr::Replace(NewStr changed, NewStr replaced)
{
    size_t i, j;
    int index = FindPosition(changed);
    int changed_size = changed.size;
    int replaced_size = replaced.size;
    char* new_line = new char[size];
    int newLine_size = size;
    for (int i = 0; i < size; ++i)
    {
        new_line[i] = line[i];
    }
    size = size - changed_size + replaced_size;
    line = new char[size];
    for (i = 0; i < index; ++i)
    {
        line[i] = new_line[i];
    }
    for (j = 0, i = index; j < replaced_size - 1; ++j, ++i)
    {
        line[i] = replaced[j];
    }
    for (i = (index + replaced_size - 1), j = (index + changed_size - 1); j < newLine_size && i < size; ++j, ++i)
    {
        line[i] = new_line[j];
    }
    delete[] new_line;
}

NewStr NewStr::operator+(const NewStr& A)
{
    NewStr new_line;
    size_t i, p;
    new_line.size = size + A.size;
    new_line.line = new char[new_line.size];
    memcpy(new_line.line, this->line, this->size);
    memcpy(new_line.line + this->size, A.line, A.size);
    return new_line;
}

bool NewStr::operator==(const NewStr& A)
{
    if (size == A.size)
    {
        for (int i = 0; i < size; ++i)
        {
            if (line[i] == A.line[i])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

char& NewStr::operator[](const int i)
{
    if (i >= 0 && i < size)
    {
        return line[i];
    }
    char else_value = '\0';
    return else_value;
}

NewStr NewStr::operator=(NewStr& A)
{
    size = A.size;
    line = new char[size];
    for (int i = 0; i < size; ++i)
    {
        line[i] = A.line[i];
    }
    return *this;
}

NewStr NewStr::operator=(const char* A)
{
    size = strlen(A) + 1;
    line = new char[size];
    for (int i = 0; i < size; ++i)
    {
        line[i] = A[i];
    }
    return *this;
}

ostream& operator<<(ostream& os, const NewStr& A)
{
    for (int i = 0; i < A.size; ++i)
    {
        os << A.line[i];
    }
    return os;
}

istream& operator>>(istream& is, NewStr& A)
{
    char* input = new char[100];
    is.getline(input, 100);
    delete[] input;
    return is;
}

NewStr Markov(NewStr string_, std::vector<Rule> rules)
{
    for (int i = 0; i < rules.size(); ++i)
    {
        int change_index = string_.FindPosition(rules[i].change_string);
        if (change_index >= 0)
        {
            string_.Replace(rules[i].change_string, rules[i].replace_string);
            if (rules[i].is_last)
            {
                break;
            }
            i = -1;
        }
    }
    return string_;
}