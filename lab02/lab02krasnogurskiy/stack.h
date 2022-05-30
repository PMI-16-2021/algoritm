#pragma once
#include<iostream>
using namespace std;

struct Node {
	int val; //значення
	Node* pNext; // адреса в памяті наступного елемента, тобто наступного Ноду
	Node(int val, Node* pNext = nullptr) { //конструктор

		this->val = val;
		this->pNext = pNext;
	}
};

class Stack {
private:
	size_t size_;
	Node* head = nullptr; // вказівник на голову
	Stack* top;
public:
	Stack();
	Stack(int val);
	~Stack();

	Stack* next = nullptr;	// вказівник на наступний стек
	int size();				// отримує розмір стеку
	void push(int val);		// додає значення в стек
	int pop();				// видаляє ноду зі стеку
	bool empty() const;		// перевіряє чи стек пустий
	void swap(Stack& stack);// свапає за значеннями
	void emplace(int &value);// додає ноду до стеку
	int topVal();			// отримує значення 'голови'
	void delFirst();		// видаляє 'голову'
	void print() const;		// друкує
};











