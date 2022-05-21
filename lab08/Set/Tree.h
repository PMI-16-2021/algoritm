#pragma once
#include <iostream>
#include <vector>
using std::vector;

//Node template as unit
//of binary tree
template<typename T>
struct Node
{
	T key;
	Node* left;
	Node* right;
	Node(T _key, Node* _l = nullptr, Node* _r = nullptr) :
		key(_key), left(_l), right(_r){}
};

//Set template:
//binary tree structure
template<typename T>
class Set
{
private:
	Node<T>* root;                                       //pointer to all elements
	size_t n_of_elems;                                   //number of stored elems
	void insert(Node<T>*& n, T key);                     //private insert (no check for uniqueness)
	void erase(Node<T>*& n, T key);                      //private erase 
	bool find(Node<T>* n, T key) const;                  //private find
	void clearAll(Node<T>* n);                           //clears all
	void inorder(Node<T>* n) const;                      //print is ascending orded
	void getAll(Node<T>* n, vector<T>& vect) const;      //fills *vect* with all extracted elements
	void addToVect(Node<T>* n, vector<T>& vect) const;   //recursive all-element extreacter (for getAll() method)

public:
	Set();                                             //default
	Set(const Set<T>& other);                          //copy (uses operator=)
	~Set();                                            //delete dynamic mem correctly
	void add(T key);                                   //add with check on uniqueness
	void remove(T key);                                //remove (does nothing if doesn't exist)
	bool in(T key) const;                              //bool method for checking existence in Set
	size_t len() const;                                //number of elements in Set
	void print() const;                                //print in ascending order
	Set& operator=(const Set& other);                  //uses getAll
	Set& Union(const Set& other);                      //Set operations:
	Set& insersection(const Set& other);
	Set& difference(const Set& other);
	Set& symmetric_difference(const Set& other);
};

//checks if val with key exists
template<typename T>
bool Set<T>::find(Node<T>* n, T key) const
{
	if (!n)                      //false if node is nullptr
	{
		return false;
	}                            //else: node exists:
	else if (n->key == key)      //if key is equal
	{
		return true;             //exists!
	}
	else                         //if key is not equal
	{
		if (key < n->key)        //if key is lower
		{
			find(n->left, key);  //search in left subtree
		}
		else                     //key is bigger
		{
			find(n->right, key); //search in right subtree
		}
	}
}

//clear all nodes
template<typename T>
void Set<T>::clearAll(Node<T>* n)
{
	if (n)                           //if not nullptr
	{
		clearAll(n->left);           //go to left subtree
		clearAll(n->right);          //go to right subtree
		delete n;                    //delete this one after returning
	}
}

//prints is ascending order
template<typename T>
void Set<T>::inorder(Node<T>* n) const
{
	if(!n)
	{
		return;
	}
	inorder(n->left);            //find lowest
	std::cout << n->key << ' ';  //print
	inorder(n->right);           
}

//extract all values to vector
template<typename T>
void Set<T>::getAll(Node<T>* n, vector<T>& vect) const
{
	vect.reserve(n_of_elems);   //reserve number of values ontained in Set
	addToVect(root, vect);      //fill vector with elems
}

//fill vector with items
template<typename T>
void Set<T>::addToVect(Node<T>* n, vector<T>& vect) const
{
	if (!n)                     //if nullptr => return
	{
		return;
	}
	addToVect(n->left, vect);   //recursive left call
	vect.push_back(n->key);     //pushing back to vector
	addToVect(n->right, vect);  //recursive right call
}

//default constructor
template<typename T>
Set<T>::Set()
{
	root = nullptr;
	n_of_elems = 0;  //zero elems
}

//copy
template<typename T>
Set<T>::Set(const Set<T>& other)
{
	*this = other;               //simply operator =
}

template<typename T>
inline Set<T>::~Set()
{
	clearAll(root);             //delete all nodes
}

//add without hecking for being unique
template<typename T>
void Set<T>::insert(Node<T>*& n, T key)
{
	if (!n)                          //if lead to empty node
	{
		n = new Node<T>(key);        //change val of ptr
		++n_of_elems;                //contains + 1 element
	}
	else
	{	
		if (key < n->key)           //if key is lower
		{
			insert(n->left, key);   //continue inserting to left subtree
		}
		else                        //if key is bigger
		{
			insert(n->right, key);  //continue inserting to right subtree
		}
	}
}

//private to delete node
template<typename T>
void Set<T>::erase(Node<T>*& n, T key)
{
	if (n)                                    //if valid 
	{
		if (n->key == key)                    //if key is found
		{
			if (!n->left && !n->right)        //if zero sons
			{
				delete n;                     //delete this node
				n = nullptr;                  //this node == nullptr
				--n_of_elems;                 //-1 elem
				return;                       //finish
			}
			if (!n->left || !n->right)        //has one son
			{
				if (n->left)                  //if has left son only
				{
					Node<T>* temp = n->left;  //save address of node
					delete n;                 //delete noe in n
					n = temp;                 //change address of n ptr
					--n_of_elems;             //-1 elem
				}
				else if (n->right)            //has right son only
				{
					Node<T>* temp = n->right; //save right
					delete n;                 //clear data behind n ptr
					n = temp;                 //re-assign n
					--n_of_elems;             //decrease elem
				}
			}
			else                                        //if has 2 sons
			{
				Node<T>* replacement = n->right;       //find lowest 
				while (replacement->left)
				{
					replacement = replacement->left;   //in right subtree (lowest bigger than n->key)
				}
				n->key = replacement->key;             //chabge key
				erase(n->right, replacement->key);     //delete lowest bigger
			}
		}
		else                                           //key not that yet 
		{
			if (key < n->key)                          //if lower
			{
				erase(n->left, key);                   //search in left
			}
			else                                       //if bigger
			{
				erase(n->right, key);                  //search in right
			}
		}
	}
}

//check for uniqueness 
//and add
template<typename T>
void Set<T>::add(T key)
{
	if (!in(key))          //if not found in Set
	{
		insert(root, key); //insert
	}	
}

//simply erase
template<typename T>
void Set<T>::remove(T key)
{
	erase(root, key);   //if doesn't exist  
}                       //nothing will happen

//public bool-method ti check existence
//is Set
template<typename T>
inline bool Set<T>::in(T key) const
{
	return find(root, key);
}

//return no of stored elems
template<typename T>
inline size_t Set<T>::len() const
{
	return n_of_elems;
}

//print in ascending order
template<typename T>
void Set<T>::print() const
{
	inorder(root);
	std::cout << '\n';
}

template<typename T>
inline Set<T>& Set<T>::operator=(const Set& other)
{
	vector<T> temp_elems;                         //vector for all elems
	other.getAll(other.root, temp_elems);         //extract all elems to vector
	this->clearAll(root);                         //clear this Set
	n_of_elems = 0;                               //0 elems
	this->root = nullptr;                         //init roo with nullptr
	for (auto i = temp_elems.cbegin(); i < temp_elems.cend(); i++)
	{
		this->add(*i);  //add all from other 
	}
	return *this;
}

//union of sets (maintain uniqueness)
template<typename T>
Set<T>& Set<T>::Union(const Set& other)
{
	Set<T>* temp = new Set(*this);           //copy elems from first
	vector<T> temp_elems;                    //vector for elems of other
	other.getAll(other.root, temp_elems);    //extract elems from other
	for (auto i = temp_elems.cbegin(); i != temp_elems.cend(); ++i)
	{
		temp->add(*i);                       //add (checks uniqueness)
	}
	return *temp;
}

//only elems in common
template<typename T>
Set<T>& Set<T>::insersection(const Set& other)
{
	Set<T>* temp = new Set<T>;       //empty Set
	vector<T> temp_elems;            
	this->getAll(root, temp_elems);  //extract all elems from this
	for (auto i = temp_elems.cbegin(); i != temp_elems.cend(); i++) // for each in this Set
	{
		if (other.in(*i))                     //if other contains this elem      
		{
			temp->insert(temp->root, *i);     //insert (with no checking)
		}
	}
	return *temp;
}

//returns **this* without elems of *other*
template<typename T>
Set<T>& Set<T>::difference(const Set& other)
{
	Set<T>* temp = new Set<T>(*this);               //add elems of this
	vector<T> temp_elems;                      
	other.getAll(other.root, temp_elems);           //extract elems of other
	for (auto i = temp_elems.cbegin(); i != temp_elems.cend(); i++) 
	{                                 //for each in second Set 
		if (temp->in(*i))             //if first Set contains it
		{
			temp->remove(*i);         //remove it from first Set
		}
	}
	return *temp;
}

//all elems except from intersection
//of them both
template<typename T>
Set<T>& Set<T>::symmetric_difference(const Set& other)
{
	Set<T>* temp = new Set<T>(*this);                                //copy elems from first Set
	vector<T> temp_elems;
	other.getAll(other.root, temp_elems);                            //get All from second Set
	for (auto i = temp_elems.cbegin(); i != temp_elems.cend(); i++)  //for each in second
	{
		if (temp->in(*i))                  //if first contains it =>
		{
			temp->remove(*i);              //=> remove from first
		}
		else                               //first doesn't contain it
		{
			temp->insert(temp->root,*i);   //add it to first (with no checking)
		}
	}
	return *temp;
}
