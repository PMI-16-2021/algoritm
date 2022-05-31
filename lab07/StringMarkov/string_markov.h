#pragma once
#include <iostream>
#include<vector>

class String {
private:
    char* string_;
    int size_;
public:
    String();
    String(const char* arr);
    String(const String& other);
    ~String();
    char* GetString() { return string_; }
    int Lenght() const;
    void PrintToStream(std::ostream& out) const;
    int Find(const String& other) const;
    void Replace(int from, int to, const String& other);
    bool operator==(const String& other);
};

std::ostream& operator<<(std::ostream& out, const String& string);
String MarkovAlgorithm(std::vector<std::pair<String, String>>rules, String string);

String::String() {
    size_ = 0;
    string_ = nullptr;
}

String::String(const char* S) {
    size_ = strlen(S);
    string_ = new char[size_];
    memcpy(string_, S, size_);
}

String::String(const String& other) {
    size_ = other.size_;
    string_ = new char[size_];
    memcpy(this->string_, other.string_, size_);
}

String::~String() {
    delete[] string_;
}

int String::Lenght() const {
    return size_;
}

void String::PrintToStream(std::ostream& out) const {
    for (int i = 0; i < size_; i++) {
        out << string_[i];
    }
}

int String::Find(const String& tof) const {
    if (tof.size_ < size_) {
        int ret_index = 0;
        int tof_length = tof.size_;
        int delta;
        int i = 0;
        while (i < size_) {
            delta = tof_length;
            while (i < size_ && string_[i] != tof.string_[0]) {
                ++i;
                ++ret_index;
            }
            int j = 0;
            while (i < size_ && j < tof.size_ && string_[i] == tof.string_[j]) {
                ++ret_index;
                --tof_length;
                ++i; ++j;
            }
            if (tof_length == 0) {
                return (ret_index - delta);
            }
            else {
                tof_length = tof.size_;
                delta = 0;
            }
        }
    }
    return size_ + 1;
}


void String::Replace(int from, int to, const String& other) {
    int new_mem = size_ - (to - from) + other.size_;
    char* new_str = new char[new_mem];
    memcpy(new_str, string_, from);
    memcpy(new_str + from, other.string_, other.size_);
    memcpy(new_str + from + other.size_, string_ + to, size_ - to);
    delete[] string_;
    string_ = new_str;
    size_ = new_mem;
    new_str = nullptr;
}
bool String::operator==(const String& other) {
    if (size_ != other.size_) {
        return false;
    }
    for (int i = 0; i < size_; i++) {
        if (string_[i] != other.string_[i]) {
            return false;
        }
    }
    return true;
}
std::ostream& operator<<(std::ostream& out, const String& string) {
    string.PrintToStream(out);
    return out;
}

String MarkovAlgorithm(std::vector<std::pair<String, String>>rules, String string) {
    String& output = string;
    int string_len = string.Lenght();
    std::vector<std::pair<String, String>>::iterator it = rules.begin();
    while (it != rules.end()) {
        int pos = output.Find(it->first);
        if (pos != output.Lenght()+1) {
            output.Replace(pos, pos + it->first.Lenght(), it->second);
            if (output.Lenght() == (string_len - ((pos + it->first.Lenght()) - pos) + it->second.Lenght())) {
                string_len = output.Lenght();
                it = rules.begin();
            }
            else {
                it++;
            }
        }
        else {
            it++;
        }
    }
    return output;
}