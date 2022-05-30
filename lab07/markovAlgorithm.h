#pragma once
#include <iostream>
#include <vector>

class String {
private:
    char* alphabet;
    int length;
public:
    String();
    String(const char* str);
    String(const String& other);
    ~String();

    int getLength() const;
    int find(const String& other) const;
    void resize(int l);
    void replace(const String& from, const String& to);
    void print(std::ostream& out) const;
    String operator+(const String& other);
    bool operator==(const String& other);
    String& operator=(const String& other);
    char& operator[](const int i) const;
    friend std::ostream& operator<<(std::ostream& out, const String& string);
};

struct Rule {
    String beforeReplace;
    String afterReplace;
    bool terminal;
    Rule();
    Rule(String before, String after);
    Rule(String before, String after, bool term);
};

String markovAlgorithm(std::vector<Rule> rules, String str);