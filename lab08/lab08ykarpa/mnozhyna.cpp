#include "mnozhyna.h"

MySet::MySet() {
    count_ = 0;
    capacity_ = 0;
    array_ = new char[capacity_];
}

MySet::MySet(size_t capacity) {
    count_ = 0;
    capacity_ = capacity;
    array_ = new char[capacity];
}

MySet::~MySet() {
    //delete[]array_;
}

void MySet::add(char elem_to_add) {
    if (!in(elem_to_add)) {
        if (count_ == capacity_) {
            capacity_ += 10;
            char* temp = new char[capacity_];
            for (size_t i = 0; i < count_; ++i) {
                temp[i] = array_[i];
            }
            delete[] array_;
            array_ = temp;
        }
        array_[count_] = elem_to_add;
        ++count_;
    }
}

void MySet::remove(char elem_to_remove) {
    char* arr = new char[capacity_];
    size_t position = 0;
    if (count_ > 0) {
        for (size_t i = 0; i < count_; ++i) {
            if (array_[i] == elem_to_remove) {
                position = i;
                break;
            }
        }
    }
    for (size_t i = 0; i < position; ++i) {
        arr[i] = array_[i];
    }
    for (size_t i = position; i < count_; ++i) {
        arr[i] = array_[i + 1];
    }
    if (count_ > 0) {
        delete[] array_;
    }
    array_ = arr;
    --count_;
}

int MySet::len() const {
    return count_;
}

bool MySet::in(char elem_to_find) const {
    for (size_t i = 0; i < count_; ++i) {
        if (array_[i] == elem_to_find) {
            return true;
        }
    }
    return false;
}

MySet MySet::Union(const MySet& other) const {
    MySet temp;
    for (size_t i = 0; i < count_; ++i) {
        temp.add(array_[i]);
    }
    for (size_t i = 0; i < other.count_; ++i) {
        temp.add(other.array_[i]);
    }
    return temp;
}

MySet MySet::intersection(const MySet& other) {
    MySet temp;
    for (size_t i = 0; i < count_; ++i) {
        if (other.in(array_[i])) {
            temp.add(array_[i]);
        }
    }
    return temp;
}

MySet MySet::difference(const MySet& other) {
    MySet temp;
    for (size_t i = 0; i < count_; ++i) {
        if (!(other.in(array_[i]))) {
            temp.add(array_[i]);
        }
    }
    return temp;
}

MySet MySet::symmetric_difference(MySet& other) {
    MySet temp;
    MySet intersection_ = intersection(other);
    for (size_t i = 0; i < count_; ++i) {
        if (!(intersection_.in(array_[i]))) {
            temp.add(array_[i]);
        }
    }
    for (size_t i = 0; i < other.count_; ++i) {
        if (!(intersection_.in(other[i]))) {
            temp.add(other[i]);
        }
    }
    return temp;
}

void MySet::print() const {
    std::cout << "{ ";
    for (size_t i = 0; i < count_ - 1; ++i) {
        std::cout << array_[i] << ", ";
    }
    for (size_t i = count_ - 1; i < count_; ++i) {
        std::cout << array_[i];
    }
    std::cout << " }\n";
}

char& MySet::operator[](size_t index) {
    return array_[index];
}