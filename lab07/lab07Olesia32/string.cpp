#include "string.h"

String::String() : size(0), container(nullptr) {}

String::String(const char* cont) {
	size = strlen(cont);
	container = new char[size];
	memcpy(container, cont, size);
}

String::String(const String& S) {
	size = S.size;
	container = new char[size];
	memcpy(this->container, S.container, size);
}

String::~String() {
	delete[] container;
}

size_t String::lenght() const {
	return size;
}

int String::Find(const String& subtr) const {
	int counter = 0;
	int ctr = 0;
	int l = subtr.size;
	while (ctr <= (size - l) && l > 0) {
		if ((container[ctr]) == subtr.container[0]) {
			counter = 0;
			for (int count = ctr; count < (ctr + l); count++) {
				if (container[count] == subtr.container[counter])
					++counter;
				else {
					counter = 0;
					break;
				}
			}
			if (counter == l)
				return ctr;
		} ++ctr;
	}
	return -1;
}

void String::Replace(const String& from, const String& to) {
	int pos = Find(from);
	if (pos != -1) {
		Erase(pos, from.lenght());
		Insert(pos, to);
	}
}

void String::Erase(size_t pos, size_t len) {
	if (len == -1) {
		len = size - pos;
	}
	int rest = size - len - pos;
	for (int i = 0; i < rest; i++) {
		container[pos + i] = container[pos + len + i];
	}
	size -= len;
	Resize(size);
}

void String::Resize(size_t _size) {
	size = _size;
	char* new_str = new char[size];
	memcpy(new_str, container, size);
	container = new_str;
	new_str = nullptr;
}

void String::Insert(size_t pos, const String& str) {
	char* s = str.container;
	int i, n = str.lenght();
	int on = size;
	size += n;
	Resize(size);
	char* p = container + pos;
	for (i = on - 1; i >= 0; --i) {
		p[i + n] = p[i];
	}
	for (i = 0; i < n; i++) {
		*p++ = *s++;
	}
}

char& String::operator[](const int i) const {
	if (i >= 0 && i < size)
	{
		return container[i];
	}
	char else_value = '\0';
	return else_value;
}

String& String::operator=(const String& from) {
	if (this != &from) {
		delete[] container;
		size = from.size;
		container = new char[size];
		memcpy(container, from.container, size * sizeof(char));
	}
	return *this;
}

bool String::operator==(const String& other) {
	bool equal = true;
	equal &= size == other.size;
	if (equal) {
		equal &= 0 == memcmp(container, other.container, size);
	}
	return equal;
}

String String::operator+(const String& other) {
	String result;
	result.size = this->size + other.size;
	result.container = new char[result.size];
	memcpy(result.container, this->container, size);
	return result;
}

Rule::Rule() : pattern(""), replacement(""), terminal(false) {}

Rule::Rule(String _pattern, String _replacement) : pattern(_pattern), replacement(_replacement), terminal(false) {}

Rule::Rule(String _pattern, String _replacement, bool _terminal)
	: pattern(_pattern), replacement(_replacement), terminal(_terminal) {}



std::ostream& operator<<(std::ostream& out, const String& str) {
	for (int i = 0; i < str.lenght(); ++i) {
		out << str.container[i];
	}
	return out;
}

String Markov(std::vector<Rule> rules, String input) {
	if (rules.empty()) {
		throw "No rules";
	}
	String output = input;
	std::vector<Rule>::iterator iter = rules.begin();
	int count = 0;
	while (iter != rules.end()) {
		int pos = output.Find(iter->pattern);
		if (pos != -1) {
			output.Replace(iter->pattern, iter->replacement);
			if (iter->terminal) {
				break;
			}
			iter = rules.begin();
		}
		else {
			++iter;
		}
		++count;
	}
	if (count > 1000) {
		throw "Bad rules";
	}
	return output;
}
