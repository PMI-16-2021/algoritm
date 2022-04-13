#pragma once
#include<iostream>

struct StackNode {
	int value;              //value
	StackNode* next;        //pointer to next one
};

class Stack {
private:
	StackNode* sTop;        //main pointer to struct
public:
	Stack() { sTop = nullptr; }    //default constructor
	void push(int value);          //insert element
	void pop();                    //remove top element
	bool empty();                  //test whether container is empty
	int size();                    //return size
	int top();                     //access next element
	void swap(Stack& S);           //swap stacks
	void emplace(int value);       //construct and insert element
	void print();                  //print stack

};
