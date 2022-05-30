#pragma once

class MySet
{
public:
	void add_element(char elem);
	void remove_element(char elem);
	bool is_in_set(char elem);

	MySet set_union(const MySet& other);
	MySet set_intersect(const MySet& other);
	MySet set_diff(const MySet& other);
private:
	static const size_t arr_size = 8; //256/32
	size_t container[arr_size] = { 0 };
	size_t get_position(char elem);
	size_t get_index(char elem);
	size_t get_mask(char elem);
};