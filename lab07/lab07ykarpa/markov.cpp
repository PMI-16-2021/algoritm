#include "markov.h"
using namespace std;

String::String() {
}

String::String(const char* string) {
	size_ = strlen(string);
	container_ = new char[size_];
	memcpy(container_, string, size_);
}

String::String(const String& other) {
	*this = other;
}

String::~String() {
	size_ = 0;
	delete[] container_;
}
String& String::operator=(const String& other) {
	delete[] container_;
	size_ = other.size_;
	container_ = new char[size_];
	memcpy(container_, other.container_, size_);
	return *this;
}

String String::operator+(const String& other) {
	String result;
	result.size_ = this->size_ + other.size_;
	result.container_ = new char[result.size_];
	memcpy(result.container_, this->container_, this->size_);
	memcpy(&result.container_[this->size_], other.container_, other.size_);
	return result;
}

bool String::operator==(const String& other) {
	bool are_equal;
	are_equal = this->size_ == other.size_;
	if (are_equal) {
		for (int i = 0; (i < size_) && are_equal; i++) {
			are_equal = this->container_[i] == other.container_[i];
		}
	}
	return are_equal;
}

char String::operator[](int n) {
	return container_[n];
}

size_t String::leng() {
	return size_;
}

int String::Find(String& what_to_find) {
	int k = -1;
	int i = 0;
	bool help = false;
	while (i < leng() && what_to_find.leng() != 0) {
		if ((*this)[i] == what_to_find[0]) {
			if (what_to_find.leng() == 1) {
				k = i;
				break;
			}
			for (int j = 1; j < what_to_find.leng(); j++) {
				if ((*this)[i + j] == what_to_find[j]) {
					k = i;
					help = true;
				}
				else {
					help = false;
					break;
				}
			}
			if (help) {
				break;
			}
		}
		i++;
	}
	return k;
}

void String::Replace(String what_to_find, String replacement) {
	int place_to_insert = (*this).Find(what_to_find);
	if (place_to_insert == -1) {
		return;
	}
	String str_result;
	str_result.size_ = this->size_ - what_to_find.size_ + replacement.size_;
	str_result.container_ = new char[str_result.size_];

	String str2;
	str2.size_ = this->size_ - place_to_insert - what_to_find.size_;
	str2.container_ = new char[str2.size_];
	memcpy(str2.container_, &this->container_[place_to_insert + what_to_find.size_], str2.size_);
	memcpy(str_result.container_, this->container_, place_to_insert);
	if (replacement.size_ != 0) {
		memcpy(&str_result.container_[place_to_insert], replacement.container_, replacement.size_);
	}
	memcpy(&str_result.container_[place_to_insert + replacement.size_], str2.container_, str2.size_);
	*this = str_result;
}

String String::for_bin_to_dec(rules_for_bin_to_dec& rule) {
	String str = *this;
	for (size_t i = 0; i < rule.to_replace.size();) {
		if (str.Find(rule.to_replace[i]) != -1) {
			str.Replace(rule.to_replace[i], rule.replacements[i]);
			i = 0;
		}
		else {
			++i;
		}
	}
	return str;
}

String String::for_multiply(rules_for_multiply& rule) {
	String str = *this;
	for (size_t i = 0; i < rule.to_replace.size();) {
		if (str.Find(rule.to_replace[i]) != -1) {
			str.Replace(rule.to_replace[i], rule.replacements[i]);
			i = 0;
		}
		else {
			++i;
		}
	}
	return str;
}

String String::for_my_rules(my_rules& rule) {
	int counter = 0;
	String str = *this;
	for (size_t i = 0; i < rule.to_replace.size();) {
		if (str.Find(rule.to_replace[i]) != -1) {
			str.Replace(rule.to_replace[i], rule.replacements[i]);
			i = 0;
			counter++;
			if (counter == 1000) {
				cout << "Your rules are wrong!" << endl;
				return "-1";
			}
		}
		else {
			++i;
		}
	}
	return str;
}

ostream& operator<<(ostream& out, const String& str) {
	for (size_t i = 0; i < str.size_; i++) {
		out << str.container_[i];
	}
	return out;
}