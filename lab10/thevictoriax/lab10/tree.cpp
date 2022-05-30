#include <iostream>
#include "tree.h"
using namespace std;

TreeNode* Tree::rrRotation(TreeNode* &t)
{
	TreeNode* temp;
	temp = t->right;
	t->right = temp->left;
	temp->left = t;
	return temp;
}

TreeNode* Tree::llRotation(TreeNode*& t)
{
	TreeNode* temp;
	temp = t->left;
	t->left = temp->right;
	temp->right = t;
	return temp;
}

TreeNode* Tree::rRotation(TreeNode*& t)
{
	TreeNode* temp = t->left;
	t->left = temp->right;
	temp->right = t;
	t->height = max(height(t->left), height(t->right)) + 1;
	temp->height = max(height(temp->left), t->height) + 1;
	return temp;
}

TreeNode* Tree::lRotation(TreeNode*& t)
{
	TreeNode* temp = t->right;
	t->right = temp->left;
	temp->left = t;
	t->height = max(height(t->left), height(t->right)) + 1;
	temp->height = max(height(temp->right), t->height) + 1;
	return temp;
}

TreeNode* Tree::findMin(TreeNode* t)
{
	if (t == nullptr) 
	{
		return 0;
	}
	else if (t->left == nullptr) 
	{
		return t;
	}
	else 
	{
		return findMin(t->left);
	}
}

TreeNode* Tree::findMax(TreeNode* t)
{
	if(t == nullptr) 
	{
		return 0;
	}
	else if (t->right == nullptr) 
	{
	return t;
	}
	else 
	{
	return findMax(t->right);
	}
}

TreeNode* Tree::insert(int val, TreeNode* t)
{
	if (t == nullptr) 
	{
		t = new TreeNode;
		t->value = val;
		t->height = 0;
		t->left = t->right = nullptr;
	}
	else if (val < t->value) 
	{
		t->left = insert(val, t->left);
		if (height(t->left) - height(t->right) == 2) 
		{
			if (val < t->left->value) 
			{
				t = rRotation(t);
			}
			else 
			{
				t = rrRotation(t);
			}
		}
	}
	else if (val > t->value) 
	{
		t->right = insert(val, t->right);
		if (height(t->right) - height(t->left) == 2) 
		{
			if (val > t->right->value) 
			{
				t = lRotation(t);
			}
			else 
			{
				t = llRotation(t);
			}
		}
	}
	t->height = max(height(t->left), height(t->right)) + 1;
	return t;
}

TreeNode* Tree::remove(int val, TreeNode* t)
{
	TreeNode* temp;
	if (t == nullptr) 
	{
		return 0;
	}
	else if (val < t->value) 
	{
		t->left = remove(val, t->left);
	}
	else if (val > t->value) 
	{
		t->right = remove(val, t->right);
	}
	else if (t->left && t->right) 
	{
		temp = findMin(t->right);
		t->value = temp->value;
		t->right = remove(t->value, t->right);
	}
	else 
	{
		temp = t;
		if (t->left == nullptr)
		{
			t = t->right;
		}
		else if (t->right == nullptr)
		{
			t = t->left;
		}
		delete temp;
	}
	if (t == nullptr) 
	{
		return t;
	}
	t->height = max(height(t->left), height(t->right)) + 1;
	if (height(t->left) - height(t->right) == 2) 
	{
		if (height(t->left->left) - height(t->left->right) == 1) 
		{
			return lRotation(t);
		}
		else 
		{
			return llRotation(t);
		}
	}
	else if (height(t->right) - height(t->left) == 2) 
	{
		if (height(t->right->right) - height(t->right->left) == 1) 
		{
			return rRotation(t);
		}
		else 
		{
			return rrRotation(t);
		}
	}
	return t;
}

int Tree::height(TreeNode* t)
{
	if (t == nullptr) 
	{
		return -1;
	}
	else 
	{
		return t->height;
	}
}

int Tree::balance(TreeNode* t)
{
	if (t == nullptr) 
	{
		return 0;
	}
	else 
	{
		return height(t->left) - height(t->right);
	}
}

void Tree::inorder(TreeNode* t)
{
	if (t == nullptr) 
	{
		return;
	}
	else 
	{
		inorder(t->left);
		cout << t->value << " ";
		inorder(t->right);
	}
}

void Tree::preorder(TreeNode* t)
{
	if (t == nullptr) 
	{
		return;
	}
	else 
	{
		cout << t->value << " ";
		preorder(t->left);
		preorder(t->left);
	}
}

void Tree::postorder(TreeNode* t)
{
	if (t == nullptr) 
	{
		return;
	}
	else 
	{
		postorder(t->left);
		postorder(t->right);
		cout << t->value << " ";
	}
}

void Tree::clear(TreeNode* t)
{
	if (t == nullptr) 
	{
		return;
	}
	else 
	{
		clear(t->left);
		clear(t->right);
		delete t;
	}
}

bool Tree::find(int val, TreeNode*& t)
{
	if (!t) 
	{
		return false;
	}
	else 
	{
		if (val < t->value) 
		{
			find(val, t->left);
		}
		else 
		{
			if (val > t->value) 
			{
				find(val, t->right);
			}
			else 
			{
				return true;
			}
		}
	}
}

void Tree::print(TreeNode* t, short shft)
{
	if (t)
	{
		print(t->right, shft + 1);
		for (short i = 0; i < shft; ++i) cout << '\t';
		cout << t->value << '\n';
		print(t->left, shft + 1);
	}
}

Tree::Tree()
{
	root = nullptr;
}

Tree::~Tree()
{
	clear(root);
}

int Tree::height()
{
	if (!root)
	{
		return -1;
	}
	else
	{
		return root->height;
	}
}

void Tree::insert(int val)
{
	root = insert(val, root);
}

void Tree::remove(int val)
{
	root = remove(val, root);
}

bool Tree::find(int val)
{
	return find(val, root);
}

void Tree::print()
{
	std::cout << "--------------------------------------\n";
	print(root, 0);
	std::cout << "--------------------------------------\n";
}

