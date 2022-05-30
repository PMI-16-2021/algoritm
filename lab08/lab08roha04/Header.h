#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

template <typename T>
class MySet
{
private:
	T* arr; // �����, �� ������ �������� �������������
	int* amount; // �����, �� ������ ������� �������� �������������
	int size; // ����� �������������

public:
	MySet();
	int len();
	void makeEmpty();
	bool isEmpty();
	void add(T element);
	bool in(T element);
	int getElementIndex(T element);
	T getElementByIndex(int index);
	int getElementAmount(T element);
	void remove(T element);
	void print();
	MySet<T> unionOther(const MySet<T>& other);
	MySet<T> intersection(MySet<T>& other);
	MySet<T> difference(MySet<T>& other);
	MySet<T> symmetric_difference(MySet<T>& other);
};

template <typename T>
MySet<T>::MySet() // ����������� ��� ���������
{
	arr = NULL; // ������������ ��������� �������, ��� �� ���� ����� � ����� ������
	amount = NULL;
	size = 0;
}

template <typename T>
int MySet<T>::len()
{
	return size;
}

template <typename T>
void MySet<T>::makeEmpty()
{
	if (amount) // �������� ������������� - ������ �� �������� �� ������ ������� ��� ��������
		delete[] amount;
	if (arr)
		delete[] arr;
	amount = NULL;
	arr = NULL;
	size = 0;
}

template <typename T>
bool MySet<T>::isEmpty()
{
	if (size <= 0)
		return true;
	return false;
}

template <typename T>
void MySet<T>::add(T element) // �������� ����� ������� � �������������
{
	if (in(element)) // ���� ������� ��� �������� � ������������, ��� ��� ������� ���� �������� ���� �������
	{
		for (int i = 0; i < size; ++i) // ����������� �� ��� ���������
			if (arr[i] == element) // � ���� ��� ������� � �����, ���� �� �������� - �������� ������� �� ������� � �������� � �������
			{
				amount[i]++;
				return;
			}
	}
	else // ���� �������� ���� � ������������ - ����� ���� ��������
	{
		T* newArr = new T[size + 1];
		int* newCount = new int[size + 1]; // ��������� ��� ��� ������ ��� ����� �������� �� ��������� ��� �������� ��������
		for (int i = 0; i < size; ++i) // ���� ������������� �� ����� �� ���� ������, ��� ����� ������������ �� �������� � �� ����������
		{
			newArr[i] = arr[i];
			newCount[i] = amount[i];
		}
		newArr[size] = element; // ������� ����� ��������� ���� ��� �������, �� �� ����� ������, ��������� ���� � �������
		newCount[size] = 1; // ������� �� ��� ������� ����� ��������, ������� ����� �������� ���� �������
		if (arr) // ��������� ��������� ���'��� �-�� ������ ������
			delete[] arr;
		if (amount)
			delete[] amount;
		arr = newArr; // �������������� � ������, �� �� ������������
		amount = newCount;
		size++; // �� � �������� �������� ����� ������������� �� �������, ������� ������ ����� �������
	}
}

template <typename T>
bool MySet<T>::in(T element) // ��������, �� ������� ������� ��� ���� � ������������
{
	if (size <= 0) // ���� ����� ������������� �� ������ ����, �� ������� �������� ��� �������� �� ����
	{
		return false;
	}
	if (arr != NULL && amount != NULL)
	{
		for (int i = 0; i < size; ++i)// � ������ ������� ��� ����������� ������ �� ������� �������� � ������ ��� �������
			if (arr[i] == element)
				return true; // ���� �������, �� �������� � �������
	}
	return false; // ���� �� �������, �� �� ������� ���� � ��������� ��������, �� ����������, �� ������ �������� ����
}

template <typename T>
int MySet<T>::getElementIndex(T element) // ���� ������ �������� � �����
{
	for (int i = 0; i < size; ++i) // ����������� ������, ��� ������ ��� �������
	{
		if (arr[i] == element) // ���� ������� ���� - ��������� ���� ������
		{
			return i;
		}
	}
	return -1; // � ������ ������� �������, �� ������ �������� ����, ����� ��������� ��������� ������ ������ -1
}

template <typename T>
T MySet<T>::getElementByIndex(int index) // ���� ������� �� �������� � �����
{
	for (int i = 0; i < size; ++i) // ����������� ������, ��� ������ ��� �������
	{
		if (i == index) // ���� ������� ���� - ��������� �������
		{
			return arr[i];
		}
	}
	return NULL; // � ������ ������� �������, �� ������ �������� ����, ����� ��������� ��������� ������� NULL
}

template <typename T>
int MySet<T>::getElementAmount(T element) // �������, �� ��������� ������� ��������
{
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == element) // ����� �� ����� �� ���� �������
			return amount[i]; // ��������� �������� �� �������� � �����, ���� ������� �� ������� ��������
	}
	return 0; // ���� ������ �������� �� �������� - �� ������� ���� ������� 0
}

template <typename T>
void MySet<T>::remove(T element) // ��������� ��������
{
	if (size <= 0) // ���� ����� �� ����� �������, �� ���� �� ��������
		return;
	if (in(element)) // ����������, �� ����� ������� ������ ���� � ������������
	{
		int index = getElementIndex(element); // ���� ����, �� ��� ������ ���� ������ � �����
		if (getElementAmount(element) > 1) // ���� ������� ��������� ����� �������� � ����� ����� �������, �� �� ������ �������� �� ������� �� ��������
		{
			amount[index]--;
			return;
		}

		T* newArr = new T[size - 1]; // � ������ �������, ���� ����� == 1, ����� ���� �������� � ������������� ������, ���� �� ��������� �������� ������, ����� ���� ���� �� ������� ������ �� ���������
		int* newCount = new int[size - 1];
		for (int i = 0, k = 0; i < size; ++i)
		{
			if (i != index) // �������� ������������ �� ��������, �� ���� �� �����, ���� ���� ��������, �� ����������� (�� ����� ���� ������ � �����)
			{
				newArr[k] = arr[i];
				newCount[k] = amount[i];
				k++;
			}
		}
		if (arr) // ��������� ���� ������
			delete[] arr;
		if (amount)
			delete[] amount;
		arr = newArr; // � ������������ �������
		amount = newCount;
		size--; // �������� �������� ����� ������������� �� �������, �� ������� �������� �������
		if (size == 0) // ���� ������������� ��� �� ������ �������� ���� ���������, ������� �������
		{
			makeEmpty();
		}
	}
}

template <typename T>
void MySet<T>::print() // ���� ������������� � ������ "������� - ������� ������ ��������"
{
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " - " << amount[i] << endl;
	}
}

template <typename T>
MySet<T> MySet<T>::unionOther(const MySet<T>& other)
{
	MySet<T> newSet; // ��������� ������� �������������
	if (size > 0)
	{
		newSet.arr = new T[size];
		newSet.amount = new int[size];
		newSet.size = size;
		for (int i = 0; i < size; ++i) // ������������ ������� �� �������� ����� �������������
		{
			newSet.arr[i] = arr[i];
			newSet.amount[i] = amount[i];
		}
	}
	for (int i = 0; i < other.size; ++i) // � ��� ���� ���������� �������� ����� �������������, �� ��������
	{
		if (!newSet.in(other.arr[i])) // �� ����� ������� �� �� ���� � ���� ������������, ���� �� ����, �� �� ������ ������ ����� ������� � ������������
		{
			newSet.add(other.arr[i]);
			newSet.amount[newSet.getElementIndex(other.arr[i])] = other.amount[i]; // ���������� ������� ����� ������������� � ���� ���� ������������� ��� ������ ��������
		}
		else // ���� ������� ��� �������� � ��� ������������, �� ��� ����� ���� ���������, ��� ������� �������� ����� - � ������ �� ����� �����������
		{
			int elementAmountA = getElementAmount(other.arr[i]);
			int maxAmount = elementAmountA > other.amount[i] ? elementAmountA : other.amount[i]; // ���� ������� ����� ����� �� �����, �� ������������ ������� �����, � ������ ������� - ����� �������������
			newSet.amount[newSet.getElementIndex(other.arr[i])] = maxAmount;
		}
	}
	return newSet;
}

template <typename T>
MySet<T> MySet<T>::intersection(MySet<T>& other)
{
	MySet<T> newSet;
	if (size > 0)
	{
		for (int i = 0, k = 0; i < size; ++i)
		{
			if (other.in(arr[i]))
			{
				newSet.add(arr[i]);
				newSet.amount[k++] = amount[i] > other.getElementAmount(arr[i]) ? other.getElementAmount(arr[i]) : amount[i];
			}
		}
	}
	return newSet;
}

template <typename T>
MySet<T> MySet<T>::difference(MySet<T>& other)
{
	MySet<T> newSet;
	if (size > 0)
	{
		for (int i = 0, k = 0; i < size; ++i)
		{
			if (!other.in(arr[i]))
			{
				newSet.add(arr[i]);
				newSet.amount[k++] = amount[i];
			}
		}
	}
	return newSet;
}

template <typename T>
MySet<T> MySet<T>::symmetric_difference(MySet<T>& other)
{
	MySet<T> newSet;
	int k = 0;
	if (size > 0)
	{
		for (int i = 0; i < size; ++i)
		{
			if (!other.in(arr[i]))
			{
				newSet.add(arr[i]);
				newSet.amount[k++] = amount[i];
			}
		}
	}
	for (int i = 0; i < other.size; ++i)
	{
		if (!in(other.getElementByIndex(i)))
		{
			newSet.add(other.getElementByIndex(i));
			newSet.amount[k++] = other.getElementAmount(other.getElementByIndex(i));
		}
	}
	return newSet;
}