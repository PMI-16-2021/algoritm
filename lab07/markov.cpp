#include "markov.h"
#include <iostream>

using namespace std;

Str::Str(char* x)
{
	this->x = x;
	int i = 0;
	while (*(x + i) != '\0')
	{
		i++;
	}
	this->size = i;
}
Str Str::operator+(Str& y)
{
	int i = 0;
	while (y.x[i] != '\0')
	{
		this->x[i + this->size] = y.x[i];
		cout << this->x[i + this->size];
		i++;
	}
	cout << "\n";
	this->size += i;
	this->x[size + 1] = '\0';
	this->size++;
	return *this;
}
void Str::print()
{
	for (int i = 0; i < this->size - 1; i++)
		cout << x[i];
	cout << "\n";
}
int Str::search(char s)
{
	for (int i = 0; i < this->size - 1; i++)
		if (x[i] == s)
			return i;
	return -1;
}
int Str::search(char* s)
{
	int save = 0;
	for (int i = 0; i < this->size - 1; i++)
		if (x[i] == s[0])
			save = i;
	int i = 0;
	while (s[i] != '\0')
	{
		if (x[save + i] != s[i])
			return -1;
		i++;
	}
	return save;
}
void Str::in(char* s, int pos)
{
	int size = 0;
	while (s[size] != '\0')
		size++;
	size--;
	for (int i = this->size; i >= pos; i--)
	{
		x[i + size] = x[i];
	}
	this->size += size;
	for (int i = pos; i <= pos + size; i++)
	{
		x[i] = s[i - pos];
	}
}
void Str::del(int pos, int size)
{
	for (int i = pos; i <= this->size; i++)
	{
		x[i] = x[i + size];
	}
	this->size -= size;
}
