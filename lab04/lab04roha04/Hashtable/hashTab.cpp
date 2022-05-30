#include "Hashtable.h"


using namespace std;

TableElement::TableElement() {
	key = 0;
	column_1_ = true;
	column_2_ = 'c';
	column_3_ = 3.14159;
}

TableElement::TableElement(int key_, bool col_1, char col_2, double col_3) {
	key = key_;
	column_1_ = col_1;
	column_2_ = col_2;
	column_3_ = col_3;
}

TableElement::~TableElement() {
}

void TableElement::print() {
	cout << key << "\t" << column_1_ << "\t" << column_2_ << "\t" << column_3_ << endl;
}

size_t HashTable::getHash(int key_) {
	size_t hash;
	hash = key_ % maxSize_;
	return hash;
}

HashTable::HashTable() {
}

void HashTable::addRow(TableElement new_row) {
	size_t hash = getHash(new_row.key);
	int rehash = 0;
	while (table_[(hash + rehash) % maxSize_].key != 0) {
		if (rehash == maxSize_) {
			cout << "Table's full!" << endl;
			exit(EXIT_FAILURE);
		}
		rehash++;
	}
	table_[(hash + rehash) % maxSize_] = new_row;
}

bool HashTable::findByKey(int key, TableElement& found_element) {
	bool found = false;
	size_t hash = getHash(key);
	int rehash = 0;
	while (table_[(hash + rehash) % maxSize_].key != key && table_[(hash + rehash) % maxSize_].key != 0) {
		if (rehash == maxSize_) {
			cout << "Full!" << endl;
			exit(EXIT_FAILURE);
		}
		rehash++;
	}
	if (table_[(hash + rehash) % maxSize_].key == key) {
		found_element = table_[(hash + rehash) % maxSize_];
		found = true;
	}
	return found;
}

bool HashTable::get_col_1_by_index(size_t index) {
	return table_[index].column_1_;
}

char HashTable::get_col_2_by_index(size_t index) {
	return table_[index].column_2_;
}

double HashTable::get_col_3_by_index(size_t index) {
	return table_[index].column_3_;
}

void HashTable::printTable() {
	for (size_t i = 0; i < tableSize(); i++) {
		table_[i].print();
	}
}

int HashTable::tableSize() {
	int count = 0;
	for (size_t i = 0; i < maxSize_; i++) {
		if (table_[i].key != 0) {
			++count;
		}
	}
	return count + 1;
}

bool HashTable::isFull() {
	return maxSize_ == tableSize();
}

bool HashTable::isEmpty() {
	return tableSize() == 0;
}

void HashTable::eraseByKey(int key) {
	HashTable copy_of_table;
	for (size_t i = 0; i < maxSize_; i++) {
		if (table_[i].key != 0) {
			if (table_[i].key != key) {
				copy_of_table.addRow(table_[i]);
			}
		}
	}
	for (size_t i = 0; i < maxSize_; i++) {
		table_[i] = copy_of_table.table_[i];
	}
}

void HashTable::SubstituteByKey(int key, TableElement& table) {
	bool is_in_table = false;
	for (size_t i = 0; i < maxSize_; i++) {
		if (table_[i].key == key) {
			is_in_table = true;
			table_[i] = table;
			break;
		}
	}
	if (!is_in_table) {
		addRow(table);
	}
}