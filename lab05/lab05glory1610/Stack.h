#pragma once
#include<iostream>

struct StackNode {
	int value;              
	StackNode* next;        
};

class Stack {
private:
	StackNode* sTop;        
public:
	Stack() { sTop = nullptr; }  
	void push(int value);          
	int pop();                    
	bool empty();                  
	int size();            
	int top();                   
	void swap(Stack& S);         
	void emplace(int value);      
	void print();                
};
