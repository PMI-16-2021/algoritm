#pragma once
#include <iostream>
#include <string>
#include <vector>

template <typename T>
struct Node {
	T _value;
	Node<T>* _left;
	Node<T>* _right;
	int _height;
	Node() : _value(0), _left(nullptr), _right(nullptr), _height(0) {}
	Node(T value) : _value(value), _left(nullptr), _right(nullptr), _height(0) {}
};


template<typename T>
class Tree {
private:
	Node<T>* root;
	void insert(Node<T>*& N, T value);//+
	void remove(T value, Node<T>*& N);//+
	bool find(T value, Node<T>* N) const;//+
	void clean(Node<T>* N);//+
	int balance(Node<T>* N) const;//+
	void balanceTree(Node<T>*& N);
	int getHeight(Node<T>* N) const;//+
	void Height(Node<T>* N);//+
	void rightTurn(Node<T>*& N);//+
	void leftTurn(Node<T>*& N);//+
	void print(Node<T>* N, int level) const;//+
	void preorder(Node<T>* N);//+
	void inorder(Node<T>* N);//+
	void postorder(Node<T>* N);//+

public:
	Tree();//+                  
	~Tree();//+                 
	bool find(T value) const;//+
	void insert(T value);//+
	void remove(T value);//+
	void print() const;//+  
	int height() const;//+
};

template<typename T>
void Tree<T>::insert(Node<T>*& N, T value) {
	if (!N) {
		N = new Node<T>(value);
	}
	else {
		if (value > N->_value){
			insert(N->_left, value);
		}
		else {
			insert(N->_right, value);
		}
	}
	balanceTree(N);
}

template<typename T>
void Tree<T>::remove(T value, Node<T>*& N) {
	if (N != nullptr) {
		if (N->_value == value) {
			if (N->_left == nullptr && N->_right == nullptr) {
				delete N;
				N = nullptr;
			}
			else if (N->_left == nullptr || N->_right == nullptr) {
				if (N->_left != nullptr) {
					Node<T>* local = N->_left;
					delete N;
					N = local;
				}
				else if (N->_right != nullptr) {
					Node<T>* local = N->_right;
					delete N;
					N = local;
				}
			}
			else {
				Node<T>* local = N->_right;
				while (local->_left != nullptr) {
					local = local->_left;
				}
				N->_value = local->_value;
				remove(local->_value, N->_right);
			}
		}
		else {
			if (value < N->_value) {
				remove(value, N->_left);
			}
			else {
				remove(value, N->_right);
			}
		}
		balanceTree(N);
	}
}

template<typename T>
bool Tree<T>::find(T value, Node<T>* N) const {
	if (!N) {
		return false;
	} 
	else if (N->_value == value) {
		return true;
	}
	else {
		if (value > N->_value) 
		{
			find(value, N->_left);
		}
		else  
		{
			find(value, N->_right);
		}
	}
}

template<typename T>
void Tree<T>::clean(Node<T>* N) {
	if (N) {
		clean(N->_left);
		clean(N->_right);
		delete N;
	}
}

template<typename T>
int Tree<T>::balance(Node<T>* N) const{
	if (!N) {
		return 0;
	}     
	return (getHeight(N->_right) - getHeight(N->_left));
}

template<typename T>
void Tree<T>::balanceTree(Node<T>*& N)
{
	if (!N) {
		return;
	}
	int temp = balance(N);
	if (temp == -2) {
		if (balance(N->_left) == 1) {
			leftTurn(N->_left);
		}
		rightTurn(N);
	}
	else if (temp == 2) {
		if (balance(N->_right) == -1) {
			rightTurn(N->_right);
		}
		leftTurn(N);
	}
	Height(N);
}

template<typename T>
int Tree<T>::getHeight(Node<T>* N) const {
	if (!N) {
		return -1;
	}
	return N->_height;
}

template<typename T>
void Tree<T>::Height(Node<T>* N) {

	if (N) { 
		N->_height = std::max(getHeight(N->_left), getHeight(N->_right)) + 1;
	}
}

template<typename T>
void Tree<T>::rightTurn(Node<T>*& N) {
	Node<T>* a = N;
	Node<T>* b = N->_left;
	a->_left = b->_right;
	//b->_right = a;
	Height(a);
	Height(b);
	N = b;
}

template<typename T>
void Tree<T>::leftTurn(Node<T>*& N) {
	Node<T>* a = N;
	Node<T>* b = N->_right;
	a->_right = b->_left;
	//b->_left = a;
	Height(a);
	Height(b);
	N = b;
}

template<typename T>
void Tree<T>::print(Node<T>* N, int level) const {
	if (N)
	{
		print(N->_left, level + 1);
		for (int i = 0; i < level; ++i) std::cout << '\t';
		std::cout << N->_value << '\n';
		print(N->_right, level + 1);
	}
}

template<typename T>
void Tree<T>::preorder(Node<T>* N) {
	if (N) {
		std::cout << N->_value << ' ';
		preorder(N->_left);
		preorder(N->_left);
	}
}

template<typename T>
void Tree<T>::inorder(Node<T>* N) {
	if (N){
		inorder(N->_left);
		std::cout << N->_value << ' ';
		inorder(N->_right);
	}
}

template<typename T>
void Tree<T>::postorder(Node<T>* N) {
	if (N) {
		postorder(N->_left);
		postorder(N->_right);
		std::cout << N->_value << ' ';
	}
}

template<typename T>
Tree<T>::Tree() : root(nullptr) {}

template<typename T>
Tree<T>::~Tree() {
	clean(root);
}

template<typename T>
bool Tree<T>::find(T value) const {
	return find(value, root);
}

template<typename T>
void Tree<T>::insert(T value) {
	insert(root, value);
}

template<typename T>
void Tree<T>::remove(T value) {
	remove(value, root);
}

template<typename T>
void Tree<T>::print() const {
	std::cout << "______________________________________\n";
	print(root, 0);
	std::cout << "______________________________________\n";
}

template<typename T>
int Tree<T>::height() const {
	if (!root) {
		return -1;
	}
	return root->_height;
}