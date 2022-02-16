#include "algos.h"
#include <iostream>



void insertSort(int* array, int size)
{

	if (array == nullptr) throw BadPointer();
	if (size <= 0) throw BadSize(size);
	for (int external_index = 1; external_index < size; ++external_index)
	{

		int insert_element = array[external_index];
		int swap_index = external_index - 1;
		while (swap_index >= 0 && array[swap_index] > insert_element)
		{
			array[swap_index + 1] = array[swap_index];
			--swap_index;
		}
		array[swap_index + 1] = insert_element;
	}
}

void printArray(int* array, int size, std::ostream& out)
{
	for (int i = 0; i < size; ++i)
		out << array[i] << ' ';

}

void BadPointer::report(std::ostream& out) const
{
	out << "Array pointer is nullptr. Impossible to carry out the function.\n";
}



int BadSize::returnField() const
{
	return bad_index;
}

void BadSize::report(std::ostream& out) const
{
	out << "Bad array size: " << bad_index << '\n';
}