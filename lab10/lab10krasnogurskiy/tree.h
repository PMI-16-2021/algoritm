#pragma once

class AvlTree
{
public:
	class Node
	{
	private:
		friend class AvlTree;
		int key;
		Node* left;
		Node* right;
		int height;
	public:
		int getKey();
		int getHeight();
	};
	AvlTree();
	~AvlTree();
	void insert(int key);
	void printPreOrder();
	Node getRoot();
	Node getAt(int key);
	int getBalanceAt(int key);
	size_t getSize();
private:
	size_t size;
	Node* root;
	Node* insertByRoot(Node* root, int key);
	Node* search(Node* root, int key);
	int height(Node* N);
	Node* newNode(int key);
	Node* rightRotate(Node* y);
	Node* leftRotate(Node* x);
	int getBalance(Node* N);
	void preOrder(Node* root);
};