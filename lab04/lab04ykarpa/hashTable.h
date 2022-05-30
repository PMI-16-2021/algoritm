#pragma once
#include <iostream>

struct TableElement {
	int key_;
	bool col_1_;
	char col_2_;
	double col_3_;
	TableElement();
	TableElement(int key, bool col_1, char col_2, double col_3);
	~TableElement();
	void print();
};

class HashTable {
private:
	static const size_t max_size_ = 10;
	TableElement table_[max_size_];
public:
	HashTable();
	size_t getHash(int key);
	void addRow(TableElement new_row);
	bool findByKey(int key, TableElement& found_element);
	bool get_col_1_by_index(size_t index);
	char get_col_2_by_index(size_t index);
	double get_col_3_by_index(size_t index);
	int tableSize();
	bool isFull();
	bool isEmpty();

	void printTable();

	void eraseByKey(int key);
	void substituteByKey(int key, TableElement& table);
};