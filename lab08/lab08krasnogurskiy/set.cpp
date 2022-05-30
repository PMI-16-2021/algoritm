#include"set.h"

size_t MySet::get_position(char elem)
{
	return elem % 32;
}

size_t MySet::get_index(char elem)
{
	size_t to_return = elem / 32;
	return to_return;
}

size_t MySet::get_mask(char elem)
{
	return 1ull << get_position(elem);
}

void MySet::add_element(char elem)
{
	container[get_index(elem)] = container[get_index(elem)] | get_mask(elem);
}

void MySet::remove_element(char elem)
{
	container[get_index(elem)] = container[get_index(elem)] & (~get_mask(elem));
}

bool MySet::is_in_set(char elem)
{
	return (container[get_index(elem)] & get_mask(elem)) != 0;
}

MySet MySet::set_union(const MySet& other)
{
	MySet to_return;
	for (size_t i = 0; i < MySet::arr_size; i++)
	{
		to_return.container[i] = this->container[i] | other.container[i];
	}
	return to_return;
}

MySet MySet::set_intersect(const MySet& other)
{
	MySet to_return;
	for (size_t i = 0; i < MySet::arr_size; i++)
	{
		to_return.container[i] = this->container[i] & other.container[i];
	}
	return to_return;
}

MySet MySet::set_diff(const MySet& other)
{
	MySet to_return;
	for (size_t i = 0; i < MySet::arr_size; i++)
	{
		to_return.container[i] = (this->container[i] ^ other.container[i]) & this->container[i];
	}
	return to_return;
}