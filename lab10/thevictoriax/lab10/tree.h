#pragma once
#include <iostream>

struct TreeNode
{
	int value;
	int height;
	TreeNode* left;
	TreeNode* right;
};

class Tree
{
private:
	TreeNode* root;
	TreeNode* insert(int val, TreeNode*t);
	TreeNode* remove(int val, TreeNode* t);
	TreeNode* rrRotation(TreeNode*& t);
	TreeNode* llRotation(TreeNode*& t);
	TreeNode* rRotation(TreeNode*& t);
	TreeNode* lRotation(TreeNode*& t);
	TreeNode* findMin(TreeNode* t);
	TreeNode* findMax(TreeNode* t);
	int height(TreeNode* t);
	int balance(TreeNode* t);
	void inorder(TreeNode* t);
	void preorder(TreeNode* t);
	void postorder(TreeNode* t);
	void clear(TreeNode* t);
	bool find(int val, TreeNode*& t);
	void print(TreeNode*t, short shft);
public:
	Tree();
	~Tree();
	int height();
	void insert(int val);
	void remove(int val);
	bool find(int val);
	void print();
};