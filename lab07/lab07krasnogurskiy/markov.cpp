#include "markov.h"
Rule::Rule(std::string _pattern, std::string _replacement, bool _terminal) :
	pattern(_pattern),
	replacement(_replacement),
	terminal(_terminal)
{}

std::string markovAlgorithm(std::vector<Rule> rules, std::string text){
	std::string result = text;
	auto it = rules.begin();

	while (it != rules.end()){
		size_t pos = result.find(it->pattern);
		if (pos != std::string::npos){
			result.replace(pos, it->pattern.length(), it->replacement);
			if (it->terminal){
				break;
			}
			it = rules.begin();
		}
		else{
			++it;
		}
	}
	return result;
}





















//String::String() : size(0), container(nullptr) {}
//
//String::String(const char* cont) {
//	size = strlen(cont);
//	container = new char[size];
//	memcpy(container, cont, size);
//}
//
//String::String(const String& S) {
//	size = S.size;
//	container = new char[size];
//	memcpy(this->container, S.container, size);
//}
//
//String::~String() {
//	delete[] container;
//}
//
//size_t String::lenght() const {
//	return size;
//}
//
//char& String::operator[](const int i) const {
//	if (i >= 0 && i < size)
//	{
//		return container[i];
//	}
//	char else_value = '\0';
//	return else_value;
//}
//
//String& String::operator=(const String& from) {
//	if (this != &from) {
//		delete[] container;
//		size = from.size;
//		container = new char[size];
//		memcpy(container, from.container, size * sizeof(char));
//	}
//	return *this;
//}
//
//bool String::operator==(const String& other) {
//	bool equal = true;
//	equal &= size == other.size;
//	if (equal) {
//		equal &= 0 == memcmp(container, other.container, size);
//	}
//	return equal;
//}
//
//String String::operator+(const String& other) {
//	String result;
//	result.size = this->size + other.size;
//	result.container = new char[result.size];
//	memcpy(result.container, this->container, size);
//	return result;
//}
//