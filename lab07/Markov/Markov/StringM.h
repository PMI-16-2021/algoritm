#include <iostream>
#include <vector>

class String {
private:
    char* alphabet;
    int length;
public:
    String(const char* alphabet);
    char* find(String& substr);
    void Replace(String& operand1, String& operand2);
    void MarkovAlgorithm(std::vector<std::pair<String, String>>& NAM);
    char* getStr();
    int Length();
};