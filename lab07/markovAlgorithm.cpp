#include "markovAlgorithm.h"

String::String() :alphabet(nullptr), length(0) {
}

String::String(const char* str) {
    length = strlen(str);
    alphabet = new char[length];
    memcpy(alphabet, str, length);
}

String::String(const String& other) {
    length = other.length;
    alphabet = new char[length];
    memcpy(this->alphabet, other.alphabet, length);
}

String::~String() {
    delete[] alphabet;
}

int String::getLength() const {
    return length;
}

int String::find(const String& other) const {
    int len = other.length;
    int temp = 0;
    int ctr = 0;
    while (temp <= (length - len) && len > 0) {
        if ((alphabet[temp]) == other.alphabet[0]) {
            ctr = 0;
            for (int count = temp; count < (temp + len); count++) {
                if (alphabet[count] == other.alphabet[ctr])
                    ++ctr;
                else {
                    ctr = 0;
                    break;
                }
            }
            if (ctr == len)
                return temp;
        } ++temp;
    }
    return -1;
}

void String::print(std::ostream& out) const {
    for (int i = 0; i < length; i++) {
        out << alphabet[i];
    }
}

std::ostream& operator<<(std::ostream& out, const String& string) {
    string.print(out);
    return out;
}

String String::operator+(const String& other) {
    String res;
    res.length = this->length + other.length;
    res.alphabet = new char[res.length];
    memcpy(res.alphabet, this->alphabet, this->length);
    memcpy(res.alphabet + this->length, other.alphabet, other.length);
    return res;
}

bool String::operator==(const String& other) {
    if (length != other.length) {
        return false;
    }
    for (int i = 0; i < length; i++) {
        if (alphabet[i] != other.alphabet[i]) {
            return false;
        }
    }
    return true;
}

String& String::operator=(const String& other) {
    length = other.length;
    delete[] alphabet;
    alphabet = new char[length];
    memcpy(alphabet, other.alphabet, length);
    return *this;
}

char& String::operator[](const int i) const {
    if (i >= 0 && i < length) {
        return alphabet[i];
    }
    char value = '\0';
    return value;
}

void String::resize(int l) {
    length = l;
    char* newString = new char[length];
    memcpy(newString, alphabet, length);
    alphabet = newString;
    newString = nullptr;
}

void String::replace(const String& from, const String& to) {
    int position = find(from);
    if (position != -1) {
        int temp = from.getLength();
        if (temp == -1) {
            temp = length - position;
        }
        int last = length - temp - position;
        for (int i = 0; i < last; i++) {
            alphabet[position + i] = alphabet[position + temp + i];
        }
        length -= temp;
        resize(length);
        char* s = to.alphabet;
        int i, n = to.getLength();
        int on = length;
        length += n;
        resize(length);
        char* p = alphabet + position;
        for (i = on - 1; i >= 0; --i) {
            p[i + n] = p[i];
        }
        for (i = 0; i < n; i++) {
            *p++ = *s++;
        }
    }
}

Rule::Rule()
    : beforeReplace(""), afterReplace(""), terminal(false) {}

Rule::Rule(String before, String after)
    : beforeReplace(before), afterReplace(after), terminal(false) {}

Rule::Rule(String before, String after, bool term)
    : beforeReplace(before), afterReplace(after), terminal(term) {}

String markovAlgorithm(std::vector<Rule> rules, String str) {
    if (rules.empty()) {
        throw "There are no rules";
    }
    String output = str;
    std::vector<Rule>::iterator it = rules.begin();
    int count = 0;
    while (it != rules.end()) {
        int pos = output.find(it->beforeReplace);
        if (pos != -1) {
            output.replace(it->beforeReplace, it->afterReplace);
            if (it->terminal) {
                break;
            }
            it = rules.begin();
        }
        else {
            ++it;
        }
        ++count;
    }
    if (count > 1000) {
        throw "There are some errors with rules";
    }
    return output;
}