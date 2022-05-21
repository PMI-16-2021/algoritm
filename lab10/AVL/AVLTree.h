#pragma once
#include <iostream>

template<typename T>
struct Node
{
	T key;
	Node<T>* left;
	Node<T>* right;
	size_t height;
	Node(T _key, size_t _height = 0, Node<T>* _left = nullptr, Node<T>* _right = nullptr):
		key(_key), height(_height), left(_left), right(_right){}
};


template<typename T>
class Tree
{

private:
	Node<T>* root;

public:
	Tree();
	~Tree();
};