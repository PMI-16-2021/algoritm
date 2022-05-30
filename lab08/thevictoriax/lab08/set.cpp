#include "set.h"
using namespace std;

Set::Set() : setSize(10), setCapacity(0)
{
	elements = new char[setSize];
}

Set::Set(int size) : setSize(size), setCapacity(0)
{
	elements = new char[setSize];
}

Set::~Set()
{

}

void Set::add(char elem)
{
	if (!in(elem))
	{
		if (setCapacity == setSize)
		{
			setSize += 10;
			char* temp = new char[setSize];
			for (int i = 0; i < setCapacity; ++i)
			{
				temp[i + 1] = elements[i];
			}
			delete[] elements;
			elements = temp;
			temp = nullptr;
		}
		elements[setCapacity] = elem;
		++setCapacity;
	}
}

void Set::remove(char elem)
{
	if (!(in(elem)))
	{
		throw "ERROR";
	}
	for (int i = 0; i < setCapacity; ++i)
	{
		if (elements[i] == elem)
		{
			char* temp = new char[setSize];
			for (int j = 0; j < i; ++j)
			{
				temp[j] = elements[j];
			}
			for (int j = i; j < setCapacity; ++j)
			{
				temp[j] = elements[j + 1];
			}
			--setCapacity;
			delete[] elements;
			elements = temp;
			temp = nullptr;
			break;
		}
	}
}

int Set::len() const
{
	return setCapacity;
}

bool Set::in(char elem) const
{
	for (int i = 0; i < setCapacity; ++i)
	{
		if (elements[i] == elem)
		{
			return true;
		}
	}
	return false;
}

Set Set::unionSet(Set& S) const 
{
	int s_size = S.len();
	Set temp(setCapacity + setSize);
	for (int i = 0; i < setCapacity; ++i)
	{
		temp.add(elements[i]);
	}
	for (int i = 0; i < S.setCapacity; ++i)
	{
		temp.add(S.elements[i]);
	}
	return temp;
}

char& Set::operator[](int temp)
{
	if (temp > setCapacity || temp < 0)
	{
		throw "ERROR";
	}
	return elements[temp];
}

Set Set::intersection(Set& S)
{
	Set temp;
	for (int i = 0; i < setCapacity; ++i)
	{
		if (S.in(elements[i]))
		{
			temp.add(elements[i]);
		}
	}
	return temp;
}

Set Set::difference(Set& S)
{
	Set temp;
	for (int i = 0; i < setCapacity; ++i)
	{
		if (!(S.in(elements[i])))
		{
			temp.add(elements[i]);
		}
	}
	return temp;
}

Set Set::symmetric_difference(Set& S)
{
	Set S1;
	Set temp = intersection(S);
		for (int i = 0; i < setCapacity; ++i)
		{
			if (!(temp.in(elements[i])))
			{
				S1.add(elements[i]);
			}
		}
		for (int i = 0; i < S.setCapacity; ++i)
		{
			if (!(temp.in(S[i])))
			{
				S1.add(S[i]);
			}
			return S1;
		}
}


void Set::print() const
{
	if (setCapacity == 0)
	{
		cout << "There aren't such set\n\n";
	}
	else
	{
		for (int i = 0; i < setCapacity; ++i)
		{
			cout << elements[i] << " " << "\n\n";
		}
	}
}

