#include "set.h"
using namespace std;

Set::Set() : size(10), count(0) {
	value = new int[size];
}
Set::Set(int s) : size(s), count(0) {
	value = new int[s];
}
Set::~Set() {}

void Set::add(int v) {
	if (!in(v)) {
		if (count == size) {
			size += 10;
			int* temp = new int[size];
			for (int i = 0; i < count; ++i) {
				temp[i + 1] = value[i];
			}
			delete[] value;
			value = temp;
			temp = nullptr;
		}
		value[count] = v;
		++count;
	}
}
void Set::remove(int v) {
	if (!in(v)) {
		throw "Not the element of set.";
	}
	for (int i = 0; i < count; ++i) {
		if (value[i] == v) {
			int* temp = new int[size];
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
bool Set::in(int v) const {
	if (count == 0) {
		return false;
	}
	for (int i = 0; i < count; ++i) {
		if (value[i] == v) {
			return true;
		}
	}
	return false;
}
int Set::len() {
	return count;
}

Set Set::unionS(Set& S) {
	int ssize = S.len();
	Set temp(count + ssize);
	for (int i = 0; i < count; ++i) {
		temp.add(value[i]);
	}
	for (int i = 0; i < ssize; ++i) {
		temp.add(S[i]);

	}
	return temp;
}
Set Set::intersectionS(Set& S) {
	Set temp;
	for (int i = 0; i < count; ++i) {
		if (S.in(value[i])) {
			temp.add(value[i]);
		}
	}
	return temp;
}
Set Set::differenceS(Set& S) {
	Set temp;
	for (int i = 0; i < count; ++i) {
		if (!S.in(value[i])) {
			temp.add(value[i]);
		}
	}
	return temp;
}
Set Set::symmetricDifferenceS(Set& S) {
	Set temp;
	for (int i = 0; i < count; ++i) {
		if (!S.in(value[i])) {
			temp.add(value[i]);
		}
	}
	for (int i = 0; i < S.len(); ++i) {
		if (!in(S[i])) {
			temp.add(S[i]);
		}
	}
	return temp;
}

int& Set::operator[](int i) {
	return value[i];
}

void Set::print() const {
	if (count == 0) {
		cout << "Set is empty";
	}
	else {
		cout << "Set: \n";
		for (int i = 0; i < count; ++i) {
			cout << value[i] << " ";
		}
	}
}


