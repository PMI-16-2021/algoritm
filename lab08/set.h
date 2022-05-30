#pragma once
#include <iostream>

template <typename T>
class Set {
private:
	T* value;
	int count;
	int size;
public:
	Set();
	Set(int _size);
	~Set();

	bool in(T val) const;
	void add(T val);
	void remove(T val);
	int len();
	Set<T> unionSet(Set<T>& other);
	Set<T> intersectionSet(Set<T>& other);
	Set<T> differenceSet(Set<T>& other);
	Set<T> symmetricDifferenceSet(Set<T>& other);
	void print() const;
	T& operator[](int i);
};

template <typename T>
Set<T>::Set() : size(10), count(0) {
	value = new T[size];
}

template<typename T>
Set<T>::Set(int _size) : size(_size), count(0) {
	value = new T[size];
}

template<typename T>
Set<T>::~Set() {}

template<typename T>
bool Set<T>::in(T val) const {
	if (count == 0) {
		return false;
	}
	for (int i = 0; i < count; ++i) {
		if (value[i] == val) {
			return true;
		}
	}
	return false;
}

template<typename T>
void Set<T>::add(T val) {
	if (!in(val)) {
		if (count == size) {
			size += 10;
			T* temp = new T[size];
			for (int i = 0; i < count; ++i) {
				temp[i + 1] = value[i];
			}
			delete[] value;
			value = temp;
			temp = nullptr;
		}
		value[count] = val;
		++count;
	}
}

template<typename T>
void Set<T>::remove(T val) {
	if (!in(val)) {
		throw "This element doesn`t exist";
	}
	for (int i = 0; i < count; ++i) {
		if (value[i] == val) {
			T* temp = new T[size];
			for (int j = 0; j < i; ++j) {
				temp[j] = value[j];
			}
			for (int j = i; j < count; ++j) {
				temp[j] = value[j + 1];
			}
			--count;
			delete[] value;
			value = temp;
			temp = nullptr;
			break;
		}
	}
}

template<typename T>
int Set<T>::len() {
	return count;
}

template<typename T>
Set<T> Set<T>::unionSet(Set<T>& other) {
	int otherSize = other.len();
	Set<T> newSet(count + otherSize);
	for (int i = 0; i < count; ++i) {
		newSet.add(value[i]);
	}
	for (int i = 0; i < otherSize; ++i) {
		newSet.add(other[i]);

	}
	return newSet;
}

template<typename T>
Set<T> Set<T>::intersectionSet(Set<T>& other) {
	Set<T> newSet;
	for (int i = 0; i < count; ++i) {
		if (other.in(value[i])) {
			newSet.add(value[i]);
		}
	}
	return newSet;
}

template<typename T>
Set<T> Set<T>::differenceSet(Set<T>& other) {
	Set<T> newSet;
	for (int i = 0; i < count; ++i) {
		if (!other.in(value[i])) {
			newSet.add(value[i]);
		}
	}
	return newSet;
}

template<typename T>
Set<T> Set<T>::symmetricDifferenceSet(Set<T>& other) {
	Set<T> newSet;
	for (int i = 0; i < count; ++i) {
		if (!other.in(value[i])) {
			newSet.add(value[i]);
		}
	}
	for (int i = 0; i < other.len(); ++i) {
		if (!in(other[i])) {
			newSet.add(other[i]);
		}
	}
	return newSet;
}

template<typename T>
void Set<T>::print() const {
	if (count == 0) {
		std::cout << "Set is empty";
	}
	else {
		for (int i = 0; i < count; ++i) {
			std::cout << value[i] << " ";

		}
		std::cout << '\n';
	}
}

template<typename T>
T& Set<T>::operator[](int i) {
	return value[i];
}