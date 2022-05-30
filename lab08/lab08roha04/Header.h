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
	T* arr; // масив, що зберігає елементи мультимножини
	int* amount; // масив, що зберігає кількість елементів мультимножини
	int size; // розмір мультимножини

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
MySet<T>::MySet() // конструктор без параметрів
{
	arr = NULL; // присвоювання звичайний значень, щоб не було сміття у наших змінних
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
	if (amount) // очищення мультимножини - масиву її елементів та масиву кількості цих елементів
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
void MySet<T>::add(T element) // вставляє новий елемент в мультимножину
{
	if (in(element)) // якщо елемент вже міститься в мультимножині, тоді нам потрібно лише збільшити його кількість
	{
		for (int i = 0; i < size; ++i) // проходимось по усіх елементах
			if (arr[i] == element) // і якщо цей елемент є таким, який ми передали - збільшуємо кількість на одиницю і виходимо з функції
			{
				amount[i]++;
				return;
			}
	}
	else // якщо елементу нема в мультимножині - треба його вставити
	{
		T* newArr = new T[size + 1];
		int* newCount = new int[size + 1]; // створюємо нові два масиви для самих елементів та повторень цих елементів відповідно
		for (int i = 0; i < size; ++i) // якщо мультимножина до цього не було пустою, тоді треба перезаписати ці елементи і їх повторення
		{
			newArr[i] = arr[i];
			newCount[i] = amount[i];
		}
		newArr[size] = element; // останнім новим елементом буде той елемент, що ми хотіли додати, передавши його у функцію
		newCount[size] = 1; // оскільки ми цей елемент тільки вставили, кількість таких елементів рівна одиниці
		if (arr) // звільнення димнамічної пам'ять з-під старих масивів
			delete[] arr;
		if (amount)
			delete[] amount;
		arr = newArr; // переприсвоюємо ті масиви, що ми перестворили
		amount = newCount;
		size++; // ну і збільшуємо відповідно розмір мультимножини на одиницю, оскільки додали новий елемент
	}
}

template <typename T>
bool MySet<T>::in(T element) // перевіряє, чи заданий елемент вже існує в мультимножині
{
	if (size <= 0) // якщо розмір мультимножини не більший нуля, то значить елемента там існувати не може
	{
		return false;
	}
	if (arr != NULL && amount != NULL)
	{
		for (int i = 0; i < size; ++i)// в іншому випадку при проходимось циклом по кожному елементу і шукаємо цей елемент
			if (arr[i] == element)
				return true; // якщо знайшли, то виходимо з функції
	}
	return false; // якщо не знайшли, то ми дойдемо сюди і повернемо значення, що означатиме, що такого елемента нема
}

template <typename T>
int MySet<T>::getElementIndex(T element) // дістає індекс елемента в масиві
{
	for (int i = 0; i < size; ++i) // проходимось циклом, щоб знайти цей елемент
	{
		if (arr[i] == element) // якщо знайшли його - повертаємо його індекс
		{
			return i;
		}
	}
	return -1; // в іншому випадку вкажемо, що такого елемента нема, тобто повернемо неіснуючий індекс масивів -1
}

template <typename T>
T MySet<T>::getElementByIndex(int index) // дістає елемент за індексом в масиві
{
	for (int i = 0; i < size; ++i) // проходимось циклом, щоб знайти цей елемент
	{
		if (i == index) // якщо знайшли його - повертаємо елемент
		{
			return arr[i];
		}
	}
	return NULL; // в іншому випадку вкажемо, що такого елемента нема, тобто повернемо неіснуючий елемент NULL
}

template <typename T>
int MySet<T>::getElementAmount(T element) // функція, що знаходить кількість елементів
{
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == element) // тобто як тільки ми його знайшли
			return amount[i]; // повернемо значення за індексом в масиві, який відповідає за кількість елемента
	}
	return 0; // якщо такого елемента не знайдено - то значить його кількість 0
}

template <typename T>
void MySet<T>::remove(T element) // видалення елемента
{
	if (size <= 0) // якщо розмір не більше одиниці, то нема що видаляти
		return;
	if (in(element)) // перевіряємо, чи такий елемент взагалі існує в мультимножині
	{
		int index = getElementIndex(element); // якщо існує, то тоді шукаємо його індекс в масиві
		if (getElementAmount(element) > 1) // якщо кількість повторень цього елемента в масиві більша одиниці, то ми просто зменшуємо цю кількість на одиницію
		{
			amount[index]--;
			return;
		}

		T* newArr = new T[size - 1]; // в іншому випадку, коли розмір == 1, треба його видалити з мультимножини взагалі, тому ми створюємо додаткові масиви, розмір яких буде на одиницю менший від поточного
		int* newCount = new int[size - 1];
		for (int i = 0, k = 0; i < size; ++i)
		{
			if (i != index) // відповідно перезаписуємо усі значення, які були до цього, окрім того елемента, що видаляється (ми знаємо його індекс в масиві)
			{
				newArr[k] = arr[i];
				newCount[k] = amount[i];
				k++;
			}
		}
		if (arr) // видаляємо старі масиви
			delete[] arr;
		if (amount)
			delete[] amount;
		arr = newArr; // і перезаписуємо старими
		amount = newCount;
		size--; // відповідно зменшуємо розмір мультимножини на одиницю, бо повністю видалили елемент
		if (size == 0) // якщо мультимножина вже не містить елементів після видалення, очищаємо повністю
		{
			makeEmpty();
		}
	}
}

template <typename T>
void MySet<T>::print() // вивід мультимножини у вигляді "елемент - кількість такого елементу"
{
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " - " << amount[i] << endl;
	}
}

template <typename T>
MySet<T> MySet<T>::unionOther(const MySet<T>& other)
{
	MySet<T> newSet; // створюємо проміжну мультимножину
	if (size > 0)
	{
		newSet.arr = new T[size];
		newSet.amount = new int[size];
		newSet.size = size;
		for (int i = 0; i < size; ++i) // перезаписуємо повністю всі значення першої мультимножини
		{
			newSet.arr[i] = arr[i];
			newSet.amount[i] = amount[i];
		}
	}
	for (int i = 0; i < other.size; ++i) // а ось коли переписуємо елементи другої мультимножини, ми дивимось
	{
		if (!newSet.in(other.arr[i])) // чи такий елемент ще не існує в новій мультимножині, якщо не існує, то ми просто додаємо такий елемент в мультимножну
		{
			newSet.add(other.arr[i]);
			newSet.amount[newSet.getElementIndex(other.arr[i])] = other.amount[i]; // присвоюємо кількість другої мультимножини в нашу нову мультимножину для даного елемента
		}
		else // якщо елемент вже міститься в цій мультимножині, то нам треба лише перевірити, чия кількість елемента більше - в першій чи другій мультмножині
		{
			int elementAmountA = getElementAmount(other.arr[i]);
			int maxAmount = elementAmountA > other.amount[i] ? elementAmountA : other.amount[i]; // якщо кількість першої більша за другу, то встановлюємо кількість першої, в іншому випадку - другої мультимножини
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