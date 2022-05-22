#include "String.h"

String::StringElem::StringElem(StringElem* _next_char) : elem('""'), next_char(next_char) {}

String::StringElem::StringElem(char val, StringElem* _next_char) : elem(val), next_char(_next_char) {}

String::String() : length_(0), head_(nullptr), tail_(nullptr){}

String::String(const char* arr) {
    StringElem* temp =  new StringElem(arr[0], nullptr);
    head_ = temp;
    StringElem* anchor = head_;
    int i = 1;
    while(arr[i] != '\0') {
        temp = new StringElem(arr[i]);
        head_->next_char = temp;
        head_ = head_->next_char;
        ++i;
    }
    tail_ = head_;
    head_ = anchor;
    length_ = i;
}

String::String(const String &other) {
    if(this->length_ > 0) {
        Clear();
    }
    length_ = other.length_;
    StringElem* temp = other.head_;
    head_ = new StringElem(temp->elem);
    StringElem* anchor = head_;
    while(temp->next_char != other.tail_->next_char) {
        temp = temp->next_char;
        head_->next_char = new StringElem(temp->elem);
        head_ = head_->next_char;
    }
    tail_ = head_;
    head_ = anchor;
}

String::~String() {
    Clear();
}

void String::PrintToStream(std::ostream& out) const {
    StringElem* temp = head_;
    while(temp != nullptr) {
        out << temp->elem;
        temp = temp->next_char;
    }
}

std::ostream& operator<<(std::ostream& out, const String& string) {
    string.PrintToStream(out);
    return out;
}


size_t String::Length() const {
    return length_;
}

char& String::Front() const {
    return head_->elem;
}

char& String::Back() const {
    return tail_->elem;
}

void String::Assign(const char& letter, size_t at) {
    if (at >= length_ || at < 0) {
        throw std::out_of_range("out of range");
    }
    StringElem *temp = head_;
    for (int i = 0; i < at; i++) {
        temp = temp->next_char;
    }
    temp->elem = letter;
    temp = nullptr;
}

void String::Assign(const char* letter, size_t from, size_t letter_size) {
    if (from >= length_ || from < 0) {
        throw std::out_of_range("out of range");
    }
    if((length_-from) < letter_size) {
        StringElem* temp = head_;
        for(int i = 0; i < from; i++) {
            temp = temp->next_char;
        }
        int j = 0;
        while(temp != nullptr) {
            temp->elem = letter[j];
            temp = temp->next_char;
            j++;
        }
        for(int i = j; i < letter_size; i++) {
            tail_->next_char = new StringElem(letter[i]);
            tail_ = tail_->next_char;
        }
        length_ += (letter_size-(length_-from));
    }
    else{
        StringElem* temp = head_;
        for(int i = 0; i < from; i++) {
            temp = temp->next_char;
        }
        for(int i = 0; i < letter_size; i++) {
            temp->elem = letter[i];
            temp = temp->next_char;
        }
    }
}

bool String::Replace(size_t from, size_t to, const String &other) { // [from,to) !!
    if(from < 0 || from > length_) {
        throw std::out_of_range("out of range");
    }
    if(other == "") {
        Assign(char (0),from);
        length_ = (length_ - (to-from)) + other.length_;
        return true;
    }
    if(from == 0) {
        StringElem* other_temp = other.head_;
        StringElem* temp = new StringElem(other_temp->elem);
        other_temp = other_temp->next_char;
        StringElem* next_link = head_;
        StringElem* cleaner = head_;
        StringElem* ptr_cleaner = cleaner;
        head_ = temp;
        for(int i = 0; i < to; i++) {
            next_link = next_link->next_char;
        }
        for(int i = 0; i < other.length_-1 && i >= 0; i++) {
            temp->next_char = new StringElem(other_temp->elem);
            temp = temp->next_char;
            other_temp = other_temp->next_char;
        }
        temp->next_char = next_link;
        for (int i = 0; i < to; i++) {
            cleaner->elem = char(0);
            cleaner = cleaner->next_char;
            ptr_cleaner->next_char = nullptr;
            ptr_cleaner = cleaner;
        }
        length_ = (length_ - (to-from)) + other.length_;
        return true;
    }
    else {
        StringElem* temp = head_;
        StringElem* other_temp = other.head_;
        for(int i = 0; i < from-1; i++) { // stops before elements that will replaced
            temp = temp->next_char;
        }
        StringElem* cleaner = temp->next_char;  // deletes replaced elements
        StringElem* ptr_cleaner = cleaner;
        StringElem* next_link = (temp->next_char!= nullptr) ? temp->next_char : temp;  // next_link goes to the first element after elements that will be replaced
        for (int i = 0; i < (to-from); i++) {
            next_link = next_link->next_char;
        }
        for(int i = 0; i < other.length_; i++) {
            temp->next_char = new StringElem(other_temp->elem);
            temp = temp->next_char;
            other_temp = other_temp->next_char;
        }
        temp->next_char = next_link;
        for (int i = 0; i < (to-from); i++) {
            cleaner->elem = char(0);
            cleaner = cleaner->next_char;
            ptr_cleaner->next_char = nullptr;
            ptr_cleaner = cleaner;
        }
        length_ = (length_ - (to-from)) + other.length_;
        return true;
    }
    return false;
}

void String::Clear() {
    StringElem* ptr_clean = head_;
    while(head_ != nullptr){
        head_->elem = char(0);
        head_ = head_->next_char;
        ptr_clean->next_char = nullptr;
        ptr_clean = head_;
    }
    tail_ = nullptr;
    length_ = 0;
}

void String::Insert(size_t at, const char* letter, size_t count) {
    if (at < 0 || at > length_) {
        throw std::out_of_range("out of range");
    }
    StringElem* temp = head_;
    for(int i = 0; i < at-1; i++) {
        temp = temp->next_char;
    }
    StringElem* next_link = (temp->next_char!= nullptr) ? temp->next_char : temp;
    for(int i = 0; i < count; i++){
        temp->next_char = new StringElem(letter[i]);
        temp = temp->next_char;
    }
    if(at == length_) {  // if elements were added in the end of list
        tail_ = temp;
    }
    else {
        temp->next_char = next_link;
    }
    length_ += count;
}

void String::Insert(size_t this_offset, const String& other, size_t other_offset, size_t count) {
    if(this_offset < 0 || this_offset > length_ || other_offset < 0 || other_offset > other.length_) {
        throw std::out_of_range("out of range");
    }
    StringElem* temp = head_;
    for(int i = 0; i < this_offset-1; i++) {
        temp = temp->next_char;
    }
    StringElem* next_link = (temp->next_char!= nullptr) ? temp->next_char : temp;
    StringElem* other_temp = other.head_;
    for(int i = 0; i < count; i++){
        temp->next_char = new StringElem(other_temp->elem);
        temp = temp->next_char;
        other_temp = other_temp->next_char;
    }
    if(this_offset == length_){
        tail_ = temp;
    }
    else {
        temp->next_char = next_link;
    }
}

size_t String::Find(const String& other) const {
    size_t ret_index = 0;
    StringElem* temp = head_;
    size_t other_length = other.length_;
    size_t delta = 0;
    while(temp != nullptr){
        delta = other_length;
        while(temp != nullptr && temp->elem != other.Front()) {
            temp = temp->next_char;
            ret_index++;
        }
        StringElem* other_temp = other.head_;
        while(temp != nullptr && other_temp != nullptr && temp->elem == other_temp->elem) {
            temp = temp->next_char;
            other_temp = other_temp->next_char;
            ret_index++;
            --other_length;
        }
        if(other_length == 0) {  // if found
            return (ret_index-delta);
        }
        else{  // if sub-string is not fully equal to other - next iteration
            other_length = other.length_;
            delta = 0;
        }
    }
    // if not found
    return length_+1;
}

String String::operator+(const String &other) const {
    String ret_str(*this); // copy first part
    StringElem* other_temp = other.head_;
    StringElem* ret_temp = ret_str.tail_;
    while(other_temp != nullptr){
        ret_temp->next_char = new StringElem(other_temp->elem);
        ret_temp = ret_temp->next_char;
        other_temp = other_temp->next_char;
    }
    return ret_str;
}

bool String::operator==(const String &other) const {
    if(length_ != other.length_){
        return false;
    }
    StringElem* temp = head_;
    StringElem* other_temp = other.head_;
    for(int i = 0; i < length_; i++) {
        if(temp->elem != other_temp->elem) {
            return false;
        }
        temp = temp->next_char;
        other_temp = other_temp->next_char;
    }
    return true;
}

char& String::operator[](size_t position) const {  // doesn't check if index is valid
    StringElem* temp = head_;
    for(int i = 0;  i < position; i++){
        temp = temp->next_char;
    }
    return temp->elem;
}








