#include "StringM.h"

#include <iostream>
#include <cstring>

String::String(const char* alphabet) {
    this->alphabet = _strdup(alphabet);
    for (length = 0; *(alphabet + length) != '\0'; length++);
}

char* String::find(String& substr) {
    if (substr.getStr()[0] == '\0') {
        return getStr();
    }
    if (substr.length <= length) {
        for (int i = 0; i <= length - substr.length; i++) {
            for (int j = 0; j < substr.length; j++) {
                if (alphabet[i + j] != substr.alphabet[j]) {
                    break;
                }
                else {
                    if (j == substr.length - 1) {
                        return alphabet + i;
                    }
                }
            }
        }
    }
    return nullptr;
}

void String::Replace(String& operand1, String& operand2) {
    if (operand1.alphabet[0] != '\0') {
        String start(find(operand1));
        String tail(start.getStr() + operand1.length);
        int len = length - start.length + operand2.length + tail.length + 1;
        char* concatenated = new char[len];
        for (int i = 0; i < length - start.length; i++) {
            concatenated[i] = getStr()[i];
        }
        for (int i = 0; i < operand2.length; i++) {
            concatenated[i + length - start.length] = operand2.getStr()[i];
        }
        for (int i = 0; i < tail.length + 1; i++) {
            concatenated[i + length - start.length + operand2.length] = tail.getStr()[i];
        }
        alphabet = concatenated;
        length = len - 1;
    }
    else {
        int len = operand2.length + length + 1;
        char* concatenated = new char[len];
        for (int i = 0; i < operand2.length; i++) {
            concatenated[i] = operand2.alphabet[i];
        }
        for (int i = 0; i < length + 1; i++) {
            concatenated[operand2.length + i] = alphabet[i];
        }
        alphabet = concatenated;
        length = len - 1;
    }
}

void String::MarkovAlgorithm(std::vector<std::pair<String, String>>& NAM) {
    for (int i = 0; i < NAM.size();) {
        if (find(NAM[i].first)) {
            if (NAM[i].second.getStr()[0] == '.') {
                String temp = NAM[i].second.alphabet + 1;
                Replace(NAM[i].first, temp);
                break;
            }
            Replace(NAM[i].first, NAM[i].second);
            i = 0;
            continue;
        }
        i++;
    }
}

char* String::getStr() {
    return alphabet;
}

int String::Length() {
    return length;
}