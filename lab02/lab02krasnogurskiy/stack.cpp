#include"stack.h"

Stack::Stack():head(nullptr) {} 

Stack::Stack(int val){
	head = new Node(val, nullptr);
	++size_;
	next = nullptr;
}

Stack::~Stack(){} 

void Stack::push(int val){
	Node* next = new Node(val, head);
	head = next;
	++size_;
}

int Stack::pop(){
	int retValue = -1;
	if (!empty()) {
		retValue = head->val;
		delFirst();
	}
	--size_;

	return retValue;
}

bool Stack::empty() const{
	return (head == nullptr);
}

int Stack::size(){
	int size_ = 0;
	Node* temp = head;
	if (temp->pNext == nullptr) {
		return 0;
	}
	else {
		++size_;
		temp = temp->pNext;
	}

	return size_;
}

void Stack::swap(Stack& stack){
	Node* temp = this->head;
	this->head=stack.head;
	stack.head = temp;
}

void Stack::emplace(int& value){
	if (empty()){
		throw  "stack is empty";
	}
	else{
		Node* val = new Node(value, nullptr);
		val->pNext = head;
		head = val;
		head->val = value;
	}
}

int Stack::topVal()
{
	if (empty()) {
		throw "stack is empty";
	}
		
	return head->val;
}

void Stack::print() const{
	Node* temp;
	if (head == nullptr){
		throw "\n Stack is empty";
	}
	else {
		temp = head;
		while (temp != nullptr) {
			cout << temp->val << endl;
			temp = temp->pNext;
		}
	}
}

void Stack::delFirst(){
	if (empty()) {
		return;
	}
	else {
		Node* temp = head;
		head = head->pNext;
		delete temp;
		--size_;
	}
}




















