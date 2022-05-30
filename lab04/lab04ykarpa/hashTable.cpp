#include "hashTable.h"
using namespace std;

TableElement::TableElement() {
	key_ = 0;
	col_1_ = true;
	col_2_ = 'c';
	col_3_ = 3.14159;
}

TableElement::TableElement(int key, bool col_1, char col_2, double col_3) {
	key_ = key;
	col_1_ = col_1;
	col_2_ = col_2;
	col_3_ = col_3;
}

TableElement::~TableElement() {
}

void TableElement::print() {
	cout << key_ << "\t" << col_1_ << "\t" << col_2_ << "\t" << col_3_ << endl;
}

size_t HashTable::getHash(int key) {
	size_t hash;
	hash = key % max_size_;
	return hash;
}

HashTable::HashTable() {
}

void HashTable::addRow(TableElement new_row) {
	size_t hash = getHash(new_row.key_);
	int rehash = 0;
	while (table_[(hash + rehash) % max_size_].key_ != 0) {
		if (rehash == max_size_) {
			cout << "Your table is full!" << endl;
			exit(EXIT_FAILURE);
		}
		rehash++;
	}
	table_[(hash + rehash) % max_size_] = new_row;
}

bool HashTable::findByKey(int key, TableElement& found_element) {
	bool found = false;
	size_t hash = getHash(key);
	int rehash = 0;
	while (table_[(hash + rehash) % max_size_].key_ != key && table_[(hash + rehash) % max_size_].key_ != 0) {
		if (rehash == max_size_) {
			cout << "Full!" << endl;
			exit(EXIT_FAILURE);
		}
		rehash++;
	}
	if (table_[(hash + rehash) % max_size_].key_ == key) {
		found_element = table_[(hash + rehash) % max_size_];
		found = true;
	}
	return found;
}

bool HashTable::get_col_1_by_index(size_t index) {
	return table_[index].col_1_;
}

char HashTable::get_col_2_by_index(size_t index) {
	return table_[index].col_2_;
}

double HashTable::get_col_3_by_index(size_t index) {
	return table_[index].col_3_;
}

void HashTable::printTable() {
	for (size_t i = 0; i < tableSize(); i++) {
		table_[i].print();
	}
}

int HashTable::tableSize() {
	int count = 0;
	for (size_t i = 0; i < max_size_; i++) {
		if (table_[i].key_ != 0) {
			++count;
		}
	}
	return count + 1;
}

bool HashTable::isFull() {
	return max_size_ == tableSize();
}

bool HashTable::isEmpty() {
	return tableSize() == 0;
}

void HashTable::eraseByKey(int key) {
	HashTable copy_of_table;
	for (size_t i = 0; i < max_size_; i++) {
		if (table_[i].key_ != 0) {
			if (table_[i].key_ != key) {
				copy_of_table.addRow(table_[i]);
			}
		}
	}
	for (size_t i = 0; i < max_size_; i++) {
		table_[i] = copy_of_table.table_[i];
	}
}

void HashTable::substituteByKey(int key, TableElement& table) {
	bool is_in_table = false;
	for (size_t i = 0; i < max_size_; i++) {
		if (table_[i].key_ == key) {
			is_in_table = true;
			table_[i] = table;
			break;
		}
	}
	if (!is_in_table) {
		addRow(table);
	}
}