#pragma once
#include <iostream>
using namespace std;
class Set
{
private:
	int capacity;
	int count;
	int* value;
public:
	Set(int size) : capacity(size), count(0) { value = new int[size]; }
	Set() :capacity(5), count(0) { value = new int[capacity]; }
	~Set() { }
	void Remove(int element)
	{
		if (!In(element))
			cout << "Value doesn`t exist: " << element << endl;
		for (int i = 0; i < count; ++i)
		{
			if (value[i] == element)
			{
				int* temp = new int[capacity];
				for (int j = 0; j < i; ++j)
					temp[i] = value[j];
				for (int j = i; j < count; ++j)
					temp[j] = value[j + 1];
				--count;
				delete[] value;
				value = temp;
				temp = nullptr;
				break;
			}
		}
	}
	void Add(int element)
	{
		if (!In(element))
		{
			if (capacity == count)
			{
				capacity += 10;
				int* temp = new int[capacity];
				for (int i = 0; i < count; ++i)
					temp[i] = value[i];
				delete[] value;
				value = temp;
				temp = nullptr;
			}
			value[count] = element;
			++count;
		}
		else 
			return;
	}
	bool In(int element)
	{
		for (int i = 0; i < count; ++i)
		{
			if (value[i] == element)
				return true;
		}
		return false;
	}



	Set operator%(Set& S)//there is not other operator`s symbol to overload =/
	{
		int size = count + S.count;
		Set temp(size);
		for (int i = 0; i < count; ++i)
			temp.Add(value[i]);
		for (int i = 0; i < S.count; ++i)
			temp.Add(S.value[i]);
		return temp;
	}
	Set UnionSet(Set& S)
	{
		int size = count + S.count;
		Set temp(size);
		for (int i = 0; i < count; ++i)
			temp.Add(value[i]);
		for (int i = 0; i < S.count; ++i)
			temp.Add(S.value[i]);
		return temp;
	}
	


	Set operator*(Set& S)
	{
		Set temp;
		for (int i = 0; i < count; ++i)
		{
			if (S.In(value[i]))
				temp.Add(value[i]);
		}
		return temp;
	}
	Set IntersectionSet(Set& S)
	{
		Set temp;
		for (int i = 0; i < count; ++i)
		{
			if (S.In(value[i]))
				temp.Add(value[i]);
		}
		return temp;
	}



	Set SymmetricDifferenceSet(Set& S)
	{
		Set intersection = IntersectionSet(S);
		Set unionSet = UnionSet(S);
		for (int i = 0; i < unionSet.count; ++i)
		{
			if (intersection.value[i] == unionSet.value[i])
				unionSet.Remove(value[i]);
		}
		return unionSet;
	}
	Set operator+(Set& S)
	{
		Set intersection = IntersectionSet(S);
		Set unionSet = UnionSet(S);
		for (int i = 0; i < unionSet.count; ++i)
		{
			if (intersection.value[i] == unionSet.value[i])
				unionSet.Remove(value[i]);
		}
		return unionSet;
	}



	Set operator-(Set& S)
	{
		Set temp;
		for (int i = 0; i < count; ++i)
		{
			if (!S.In(value[i]))
				temp.Add(value[i]);
		}
		return temp;
	}
	Set DifferenceSet(Set& S)
	{
		Set temp;
		for (int i = 0; i < count; ++i)
		{
			if (!S.In(value[i]))
				temp.Add(value[i]);
		}
		return temp;
	}



	void print() const
	{
		if (count == 0)
			cout << "Empty" << endl ;
		else 
		{
			cout << "{ ";
			for (int i = 0; i < count; ++i)
				i < count - 1 ? cout << value[i] << ", " : cout << value[i] << " ";
			cout << "}" << endl;
		}
		cout << endl;
	}
	int operator[](int i) { return value[i]; }
	int Len() { return count; }
};
