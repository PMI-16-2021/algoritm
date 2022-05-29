#pragma once
#include <iostream>

template<typename T>
class InExeptions {
private:
	T elem;
public:
	InExeptions(T _elem) : elem(_elem) {};
	void Print() const {
		std::cout << "Element " << elem << " not found";
	};
};

template <typename T>
class MySet {
private:
	T* elements;
	int set_size;
	int capacity;
public:
	MySet();
	MySet(int _size);
	~MySet();
	void Add(T elem);
	void Remove(T elem);
	int Len() const;
	bool In(T elem) const;
	MySet<T> Union(MySet<T>& other) const;
	MySet<T> Intersection(MySet<T>& other);
	MySet<T> Difference(MySet<T>& other);
	MySet<T> SymmetricDifference(MySet<T>& other);
	void Print() const;
	T& operator[](int i);
	const T& operator[](int i) const;
};

template <typename T>
MySet<T>::MySet() : set_size(10), capacity(0) {
	elements = new T[set_size];
}

template<typename T>
MySet<T>::MySet(int _size) : set_size(_size), capacity(0) {
	elements = new T[set_size];
}

template<typename T>
MySet<T>::~MySet() {
}

template<typename T>
void MySet<T>::Add(T elem) {
	if (!In(elem)) {
		if (capacity == set_size) {
			set_size += 10;
			T* temp = new T[set_size];
			for (int i = 0; i < capacity; ++i) {
				temp[i + 1] = elements[i];
			}
			delete[] elements;
			elements = temp;
			temp = nullptr;
		}
		elements[capacity] = elem;
		++capacity;
	}
}

template<typename T>
void MySet<T>::Remove(T elem) {
	if (!In(elem)) {
		throw InExeptions<T>(elem);
	}
	for (int i = 0; i < capacity; ++i) {
		if (elements[i] == elem) {
			T* temp = new T[set_size];
			for (int j = 0; j < i; ++j) {
				temp[j] = elements[j];
			}
			for (int j = i; j < capacity; ++j) {
				temp[j] = elements[j + 1];
			}
			--capacity;
			delete[] elements;
			elements = temp;
			temp = nullptr;
			break;
		}
	}
}

template<typename T>
int MySet<T>::Len() const {
	return capacity;
}

template<typename T>
bool MySet<T>::In(T elem) const {
	if (capacity == 0) {
		return false;
	}
	for (int i = 0; i < capacity; ++i) {
		if (elements[i] == elem) {
			return true;
		}
	}
	return false;
}

template<typename T>
MySet<T> MySet<T>::Union(MySet<T>& other) const {
	int size_other = other.Len();
	MySet<T> UnionSet(capacity + size_other);
	for (int i = 0; i < capacity; ++i) {
		UnionSet.Add(elements[i]);
	}
	for (int i = 0; i < size_other; ++i) {
		UnionSet.Add(other[i]);

	}
	return UnionSet;
}

template<typename T>
MySet<T> MySet<T>::Intersection(MySet<T>& other) {
	MySet<T> IntersectionSet;
	for (int i = 0; i < capacity; ++i) {
		if (other.In(elements[i])) {
			IntersectionSet.Add(elements[i]);
		}
	}
	return IntersectionSet;
}

template<typename T>
MySet<T> MySet<T>::Difference(MySet<T>& other) {
	MySet<T> DifferenceSet;
	for (int i = 0; i < capacity; ++i) {
		if (!other.In(elements[i])) {
			DifferenceSet.Add(elements[i]);
		}
	}
	return DifferenceSet;
}

template<typename T>
MySet<T> MySet<T>::SymmetricDifference(MySet<T>& other) {
	MySet<T> SymmetricDifferenceSet;
	for (int i = 0; i < capacity; ++i) {
		if (!other.In(elements[i])) {
			SymmetricDifferenceSet.Add(elements[i]);
		}
	}
	for (int i = 0; i < other.Len(); ++i) {
		if (!In(other[i])) {
			SymmetricDifferenceSet.Add(other[i]);
		}
	}
	return SymmetricDifferenceSet;
}

template<typename T>
void MySet<T>::Print() const {
	if (capacity == 0) {
		std::cout << "Set is empty";
	}
	else {
		for (int i = 0; i < capacity; ++i) {
			std::cout << elements[i] << ", ";

		}
		std::cout << '\n';
	}
}

template<typename T>
T& MySet<T>::operator[](int i) {
	return elements[i];
}

template<typename T>
const T& MySet<T>::operator[](int i) const {
	return elements[i];
}
