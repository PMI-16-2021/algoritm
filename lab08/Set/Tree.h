#pragma once
#include <iostream>
#include <vector>
using std::vector;

template<typename T>
struct Node
{
	T key;
	Node* left;
	Node* right;
	Node(T _key, Node* _l = nullptr, Node* _r = nullptr) :
		key(_key), left(_l), right(_r){}
};


template<typename T>
class Set
{
private:
	Node<T>* root;
	size_t n_of_elems;
	void insert(Node<T>*& n, T key);
	void erase(Node<T>*& n, T key);
	bool find(Node<T>* n, T key) const;
	void clearAll(Node<T>* n);
	void inorder(Node<T>* n) const;
	void getAll(Node<T>* n, vector<T>& vect) const;
	void addToVect(Node<T>* n, vector<T>& vect) const;

public:
	Set();
	Set(const Set<T>& other);
	~Set();
	void add(T key);
	void remove(T key);
	bool in(T key) const;
	size_t length() const;
	void print() const;
	Set& operator=(const Set& other);
	Set& Union(const Set& other);
	Set& insersection(const Set& other);
	Set& difference(const Set& other);
	Set& symmetric_difference(const Set& other);
};

template<typename T>
bool Set<T>::find(Node<T>* n, T key) const
{
	if (!n)
	{
		return false;
	}
	else if (n->key == key)
	{
		return true;
	}
	else 
	{
		if (key < n->key)
		{
			find(n->left, key);
		}
		else
		{
			find(n->right, key);
		}
	}
}

template<typename T>
void Set<T>::clearAll(Node<T>* n)
{
	if (n)
	{
		clearAll(n->left);
		clearAll(n->right);
		delete n;
	}
}

template<typename T>
void Set<T>::inorder(Node<T>* n) const
{
	if(!n)
	{
		return;
	}
	inorder(n->left);
	std::cout << n->key << ' ';
	inorder(n->right);
}

template<typename T>
void Set<T>::getAll(Node<T>* n, vector<T>& vect) const
{
	vect.reserve(n_of_elems);
	addToVect(root, vect);
}

template<typename T>
void Set<T>::addToVect(Node<T>* n, vector<T>& vect) const
{
	if (!n)
	{
		return;
	}
	addToVect(n->left, vect);
	vect.push_back(n->key);
	addToVect(n->right, vect);
}

template<typename T>
Set<T>::Set()
{
	root = nullptr;
	n_of_elems = 0;
}

template<typename T>
Set<T>::Set(const Set<T>& other)
{
	*this = other;
}

template<typename T>
inline Set<T>::~Set()
{
	clearAll(root);
	root = nullptr;
}

template<typename T>
void Set<T>::insert(Node<T>*& n, T key)
{
	if (!n)
	{
		n = new Node<T>(key);
		++n_of_elems;
	}
	else
	{		if (key < n->key)
		{
			insert(n->left, key);
		}
		else
		{
			insert(n->right, key);
		}
	}
}

template<typename T>
void Set<T>::erase(Node<T>*& n, T key)
{
	if (n)
	{
		if (n->key == key)
		{
			if (!n->left && !n->right)
			{
				delete n;
				n = nullptr;
				--n_of_elems;
				return;
			}
			if (!n->left || !n->right) //1 син
			{
				if (n->left)
				{
					Node<T>* temp = n->left;
					delete n;
					n = temp;
					--n_of_elems;
				}
				else if (n->right)
				{
					Node<T>* temp = n->right;
					delete n;
					n = temp;
					--n_of_elems;
				}
			}
			else //2 сини
			{
				Node<T>* replacement = n->right;
				while (replacement->left)
				{
					replacement = replacement->left;
				}
				n->key = replacement->key;
				erase(n->right, replacement->key);
			}
		}
		else
		{
			if (key < n->key)
			{
				erase(n->left, key);
			}
			else 
			{
				erase(n->right, key);
			}
		}
	}
}

template<typename T>
void Set<T>::add(T key)
{
	if (!in(key))
	{
		insert(root, key);
	}	
}

template<typename T>
void Set<T>::remove(T key)
{
	erase(root, key);
}

template<typename T>
inline bool Set<T>::in(T key) const
{
	return find(root, key);
}

template<typename T>
inline size_t Set<T>::length() const
{
	return n_of_elems;
}

template<typename T>
void Set<T>::print() const
{
	inorder(root);
	std::cout << '\n';
}

template<typename T>
inline Set<T>& Set<T>::operator=(const Set& other)
{
	vector<T> temp_elems;
	other.getAll(other.root, temp_elems);
	this->clearAll(root);
	n_of_elems = 0;
	this->root = nullptr;
	for (auto i = temp_elems.cbegin(); i < temp_elems.cend(); i++)
	{
		this->add(*i);
	}
	return *this;
}

template<typename T>
Set<T>& Set<T>::Union(const Set& other)
{
	Set<T>* temp = new Set(*this);
	vector<T> temp_elems;
	other.getAll(other.root, temp_elems);
	for (auto i = temp_elems.cbegin(); i != temp_elems.cend(); ++i)
	{
		temp->add(*i);
	}

	return *temp;
}

template<typename T>
Set<T>& Set<T>::insersection(const Set& other)
{
	Set<T>* temp = new Set<T>;
	vector<T> temp_elems;
	this->getAll(root, temp_elems);
	for (auto i = temp_elems.cbegin(); i != temp_elems.cend(); i++)
	{
		if (other.in(*i))
		{
			temp->insert(temp->root, *i);
		}
	}
	return *temp;
}

template<typename T>
Set<T>& Set<T>::difference(const Set& other)
{
	Set<T>* temp = new Set<T>(*this);
	vector<T> temp_elems;
	other.getAll(other.root, temp_elems);
	for (auto i = temp_elems.cbegin(); i != temp_elems.cend(); i++)
	{
		if (temp->in(*i))
		{
			temp->remove(*i);
		}
	}
	return *temp;
}

template<typename T>
Set<T>& Set<T>::symmetric_difference(const Set& other)
{
	Set<T>* temp = new Set<T>(*this);
	vector<T> temp_elems;
	other.getAll(other.root, temp_elems);
	for (auto i = temp_elems.cbegin(); i != temp_elems.cend(); i++)
	{
		if (temp->in(*i))
		{
			temp->remove(*i);
		}
		else
		{
			temp->insert(temp->root,*i);
		}
	}

	return *temp;
}
