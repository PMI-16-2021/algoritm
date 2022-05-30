#pragma once
#include <iostream>

template <typename T>
class MySet {
private:
	T* value;
	int size;
	int count;

public:
	MySet();//+
	MySet(int _size);//+
	~MySet();//+
	void add(T _value);//+
	void remove(T _value);//+
	int len();//+
	bool in(T _value);//+
	MySet<T> unionSet(MySet<T>& other);
	MySet<T> intersectionSet(MySet<T>& other);//+
	MySet<T> differenceSet(MySet<T>& other);//+
	MySet<T> symmetricDifferenceSet(MySet<T>& other);//+
	void print() const;//+

	T operator[](int i);
};

template <typename T>
MySet<T>::MySet() :size(10), count(0) {
	value = new T[size];
}

template <typename T>
MySet<T>::MySet(int _size) : size(_size), count(0) {
	value = new T[size];
}

template <typename T>
MySet<T>::~MySet() {}

template <typename T>
void MySet<T>::add(T _value) {
	if (!in(_value)) {
		if (size == count) {
			size += 10;
			T* local = new T[size];
			for (int i = 0; i < count; ++i) {
				local[i] = value[i];
			}
			delete[] value;
			value = local;
			local = nullptr;
		}
		value[count] = _value;
		++count;
	}
}

template <typename T>
void MySet<T>::remove(T _value) {
	if (!in(_value)) {
		std::cout << "Not found this value";
	}
	for (int i = 0; i < count; ++i) {
		if (value[i] == _value) {
			T* local = new T[size];
			for (int j = 0; j < i; ++j) {
				local[i] = value[j];
			}
			for (int j = i; j < count; ++j) {
				local[j] = value[j + 1];
			}
			--count;
			delete[] value;
			value = local;
			local = nullptr;
			break;
		}
	}
}

template <typename T>
int MySet<T>::len() {
	return count;
}

template <typename T>
bool MySet<T>::in(T _value) {
	//if (count == 0) {
	//	return false;
	//}
	for (int i = 0; i < count; ++i) {
		if (value[i] == _value) {
			return true;
		}
	}
	return false;
}

template <typename T>
MySet<T> MySet<T>::unionSet(MySet<T>& other) {
	int _size = count + other.count;
	MySet<T> local(_size);
	for (int i = 0; i < count; ++i) {
		local.add(value[i]);
	}
	for (int i = 0; i < other.count; ++i) {
		local.add(other.value[i]);
	}
	return local;
}

template <typename T>
MySet<T> MySet<T>::intersectionSet(MySet<T>& other) {
	MySet<T> local;
	for (int i = 0; i < count; ++i) {
		if (other.in(value[i])) {
			local.add(value[i]);
		}
	}
	return local;
}

template <typename T>
MySet<T> MySet<T>::differenceSet(MySet<T>& other) {
	MySet<T> local;
	for (int i = 0; i < count; ++i) {
		if (!other.in(value[i])) {
			local.add(value[i]);
		}
	}
	return local;
}

template <typename T>
MySet<T> MySet<T>::symmetricDifferenceSet(MySet<T>& other) {
	MySet<T> inter = intersectionSet(other);
	MySet<T> uni = unionSet(other);
	for (int i = 0; i < uni.count; ++i) {
		if (inter.value[i] == uni.value[i]) {
			uni.remove(value[i]);
		}
	}
	return uni;
}

template <typename T>
void MySet<T>::print() const {
	if (count == 0) {
		std::cout << "Set is empty!";
	}
	else {
		std::cout << "{ ";
		for (int i = 0; i < count; ++i) {
			if (i < count - 1) {
				std::cout << value[i] << ", ";
			}
			else std::cout << value[i] << " ";

		}
		std::cout << "}.\n";
	}
}

template <typename T>
T MySet<T>::operator[](int i) {
	return value[i];
}

