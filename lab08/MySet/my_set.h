#pragma once
#include <iostream>
template <typename T>
class MySet {
private:
	T* set_;
	int size_;
	int capacity_;
	void Resize(int size);
public:
	MySet();
	MySet(int size);
	~MySet();
	void Add(T element);
	void Remove(T element);
	int Len() const;
	bool In(T element) const;
	MySet<T> Union(MySet<T>& other) const;
	MySet<T> Intersection(MySet<T>& other) const;
	MySet<T> Difference(MySet<T>& other) const;
	MySet<T> SymmetricDifference(MySet<T>& other) const;
	void Print() const;
	T& operator[](int i);
	const T& operator[](int i) const;
};

template<typename T>
void MySet<T>::Resize(int size) {
	size_ += size;
	T* temp = new T[size_];
	for (int i = 0; i < capacity_; ++i) {
		temp[i + 1] = set_[i];
	}
	delete[] set_;
	set_ = temp;
	temp = nullptr;
}
template <typename T>
MySet<T>::MySet() : size_(10), capacity_(0) {
	set_ = new T[size_];
}
template<typename T>
MySet<T>::MySet(int size) : size_(size), capacity_(0) {
	set_ = new T[size_];
}

template<typename T>
MySet<T>::~MySet() {
}
template<typename T>
void MySet<T>::Add(T element) {
	if (!In(element)) {
		if (capacity_ == size_) {
			Resize(10);
		}
		set_[capacity_] = element;
		++capacity_;
	}
}
template<typename T>
void MySet<T>::Remove(T element) {
	if (!In(element)) {
		std::cerr << element << " : not found";
	}
	for (int i = 0; i < capacity_; ++i) {
		if (set_[i] == element) {
			T* temp = new T[size_];
			for (int j = 0; j < i; ++j) {
				temp[j] = set_[j];
			}
			for (int j = i; j < capacity_; ++j) {
				temp[j] = set_[j + 1];
			}
			--capacity_;
			delete[] set_;
			set_ = temp;
			temp = nullptr;
			break;
		}
	}
}
template<typename T>
int MySet<T>::Len() const {
	return capacity_;
}
template<typename T>
bool MySet<T>::In(T element) const {
	for (int i = 0; i < capacity_; ++i) {
		if (set_[i] == element) {
			return true;
		}
	}
	return false;
}
template<typename T>
MySet<T> MySet<T>::Union(MySet<T>& other) const {
	int n_size = other.Len();
	MySet<T> n_set(capacity_ + n_size);
	for (int i = 0; i < capacity_; ++i) {
		n_set.Add(set_[i]);
	}
	for (int i = 0; i < n_size; ++i) {
		n_set.Add(other[i]);

	}
	return n_set;
}
template<typename T>
MySet<T> MySet<T>::Intersection(MySet<T>& other) const {
	MySet<T> n_set;
	for (int i = 0; i < capacity_; ++i) {
		if (other.In(set_[i])) {
			n_set.Add(set_[i]);
		}
	}
	return n_set;
}
template<typename T>
MySet<T> MySet<T>::Difference(MySet<T>& other) const {
	MySet<T> n_set;
	for (int i = 0; i < capacity_; ++i) {
		if (!other.In(set_[i])) {
			n_set.Add(set_[i]);
		}
	}
	return n_set;
}
template<typename T>
MySet<T> MySet<T>::SymmetricDifference(MySet<T>& other) const {
	MySet<T> inter_set = Intersection(other);
	MySet<T> un_set = Union(other);
	for (int i = 0; i < inter_set.Len(); i++) {
		un_set.Remove(inter_set.set_[i]);
	}
	return un_set;
}
template<typename T>
void MySet<T>::Print() const {
	if (capacity_ == 0) {
		std::cerr << "Set is empty";
	}
	else {
		for (int i = 0; i < capacity_; ++i) {
			std::cout << set_[i] << ", ";

		}
	}
}
template<typename T>
T& MySet<T>::operator[](int i) {
	return set_[i];
}
template<typename T>
const T& MySet<T>::operator[](int i) const {
	return set_[i];
}