#pragma once
#include <iostream>

//Node of tree
template<typename T>
struct Node
{
	T key;
	Node<T>* left;
	Node<T>* right;
	int height;
	Node(T _key, size_t _height = 0, Node<T>* _left = nullptr, Node<T>* _right = nullptr):
		key(_key), height(_height), left(_left), right(_right){}
};

//BST self-balansing class template
template<typename T>
class Tree
{
private:
	Node<T>* root;
	void clearAll(Node<T>* node);                   //method to delete tree
	void insert(Node<T>*& node, T key);             //insertion
	void erase(Node<T>*& node, T key);              //erase elem
	bool find(Node<T>* node, T key) const;          //says if elem's in the tree
	void rigtRot(Node<T>*& node);                   //right simple rotation
	void leftRot(Node<T>*& node);                   //left simple rotation
	int getBalance(Node<T>* node) const;            //get Balance of specific node
	int height(Node<T>* node) const;                //get height of specific node
	void updHeight(Node<T>* node);                  //update heights after insertion
	void balanceTree(Node<T>*& node);               //private method to balance tree
	void print(Node<T>* node, short shift) const;	//prints with a tree-like structure
	void inorder(Node<T>* node) const;              //left-root-right print
	void postorder(Node<T>* node) const;			//left-right-root print
	void preorder(Node<T>* node) const;				//root-left-right print
	
public:
	Tree();                  //default
	~Tree();                 //delete dynamic mem correctly (uses clearAll)
	bool find(T key) const;  //public bool-if-found method
	void insert(T key);      //public insert-by-key method
	void erase(T key);       //clear certain element
	void print() const;      //prints with a tree - like structure
	int height() const;      //returns height of the furhest leave
};

//used for destructor
template<typename T>
void Tree<T>::clearAll(Node<T>* node)
{
	if (node)                      //if not nullptr
	{
		clearAll(node->left);      //recursive call to left
		clearAll(node->right);     //recursive call to right
		delete node;               //delete this node after returning
	}
}

//private insertion
template<typename T>
void Tree<T>::insert(Node<T>*& node, T key)
{
 	if (!node)                          //if leads to empty node
	{
		node = new Node<T>(key);        //change val of ptr
	}
	else                                //if node exists
	{ 
		if (key < node->key)            //if key is lower
		{
			insert(node->left, key);    //continue inserting to left subtree
		}
		else                            //if key is bigger
		{
			insert(node->right, key);   //continue inserting to right subtree
		}
	}
	balanceTree(node);                  //in the end of each recursive call
}                                       //balance each node of tree that took part

//erase certain node
template<typename T>
void Tree<T>::erase(Node<T>*& node, T key)
{
	if (node)                                    //if valid 
	{
		if (node->key == key)                    //if key is found
		{
			if (!node->left && !node->right)     //if has zero sons
			{
				delete node;                     //delete this node
				node = nullptr;                  //this node == nullptr                    
				return;							 //finish
			}
			if (!node->left || !node->right)     //has one son
			{
				if (node->left)                  //if has left son only
				{
					Node<T>* temp = node->left;  //save address of node
					delete node;                 //delete noe in n
					node = temp;                 //change address of n ptr
					           
				}
				else if (node->right)            //has right son only
				{
					Node<T>* temp = node->right; //save right
					delete node;                 //clear data behind n ptr
					node = temp;                 //re-assign n            
				}
			}
			else                                          //if has 2 sons
			{
				Node<T>* replacement = node->right;       //find lowest 
				while (replacement->left)
				{
					replacement = replacement->left;       //in right subtree (lowest bigger than n->key)
				}
				node->key = replacement->key;               //change key
				erase(node->right, replacement->key);       //delete lowest bigger
			}
		}
		else                                    //key not that yet 
		{
			if (key < node->key)                //if lower
			{
				erase(node->left, key);         //search in left
			}
			else                                //if bigger equal
			{
				erase(node->right, key);        //search in right
			}
		}
		balanceTree(node);                      //maintain balance!!!
	}
}

//private finding
template<typename T>
inline bool Tree<T>::find(Node<T>* node, T key) const
{
	if (!node)                      //false if node is nullptr
	{
		return false;
	}                               //else: node exists:
	else if (node->key == key)      //if key is equal
	{
		return true;                //exists!
	}
	else                            //if key is not equal
	{
		if (key < node->key)        //if key is lower
		{
			find(node->left, key);  //search in left subtree
		}
		else                        //key is bigger
		{
			find(node->right, key); //search in right subtree
		}
	}
}

//right rotation
template<typename T>
void Tree<T>::rigtRot(Node<T>*& node)
{                             //      a-> 3     =>                     //
	Node<T>* a = node;        //         /      =>  a = 3              //
	Node<T>* b = node->left;  //   b->  2       =>  b = 2              //       node=>  2
	a->left = b->right;       //       /        =>  3->left = nullptr  //              / \ 
	b->right = a;		      //      1         =>  2->right = 3       //             1   3
	updHeight(a);             //                                       //
	updHeight(b);             //                                       //            balanced!
	node = b;                 //                => node = 2            //
}

template<typename T>
void Tree<T>::leftRot(Node<T>*& node)    
{                              //  a->    1                            //
	Node<T>* a = node;         //          \     =>  a = 1             //
	Node<T>* b = node->right;  //   b->     2    =>  b = 2             //        =>     2 
	a->right = b->left;        //            \   =>  1->right = nullptr//              / \ 
	b->left = a;               //			  3  =>  2->left = 1	   //             1   3 
	updHeight(a);              //				    				   //
	updHeight(b);              //                                      //            balanced!
	node = b;                  //                =>   node = 2         //
}

//difference of heights in subtrees
template<typename T>
int Tree<T>::getBalance(Node<T>* node) const
{
	if (!node)
	{
		return 0;         
	}      //height of right - height of left
	return (height(node->right) - height(node->left));
}

//height of node
template<typename T>
int Tree<T>::height(Node<T>* node) const
{
	if (!node)           //if nullpret => -1
	{
		return -1;
	}
	return node->height; //real node height: >=0
}

//update height after insertion or erasing
template<typename T>
void Tree<T>::updHeight(Node<T>* node)
{
	if (node)
	{                //increase by one through every node
		node->height = std::max(height(node->left), height(node->right)) + 1; 
	}                                                                           
}

//takes reference to change to 
//assingn new address to pointer
template<typename T>
void Tree<T>::balanceTree(Node<T>*& node)
{
	if (!node)                        //nothing to balance
	{
		return;                         
	}
	int temp = getBalance(node);          //save result to not to call twice
	if (temp == -2)                       //left is too big
	{
		if (getBalance(node->left) == 1)  //if inside requires balancing
		{
			leftRot(node->left);          //left rotate in child node
		}
		rigtRot(node);                    //else: just right rotate
	}
	else if(temp == 2)                    //right is too big
	{
		if (getBalance(node->right) == -1)//if inside requires balancing
		{
			rigtRot(node->right);         //right rotate in child
		}
		leftRot(node);                    //or just left
	}
	updHeight(node);                      //update heights
}

//nothing more
template<typename T>
Tree<T>::Tree()
{
	root = nullptr;
}

//one method
template<typename T>
Tree<T>::~Tree()
{
	clearAll(root);
}

//use private method 
template<typename T>
bool Tree<T>::find(T key) const
{
	return find(root, key);
}

//insert and balance (public)
template<typename T>
void Tree<T>::insert(T key)
{
	insert(root, key);
}

//delete and balance (public)
template<typename T>
void Tree<T>::erase(T key)
{
	erase(root, key);
}

//print with tree-like structure
template<typename T>
void Tree<T>::print() const
{
	std::cout << "--------------------------------------\n";
	print(root, 0);
	std::cout << "--------------------------------------\n";
}

//returns heitht of tree
template<typename T>
inline int Tree<T>::height() const
{
	if (!root)
	{
		return 0;
	}
	return root->height;
}

//private print method
template<typename T>
void Tree<T>::print(Node<T>* n, short shift) const
{
	if (n)
	{
		print(n->left, shift + 1);
		for (short i = 0; i < shift; ++i) std::cout << '\t';
		std::cout << n->key << '\n';
		print(n->right, shift + 1);
	}
}

//left-root-right print
template<typename T>
void Tree<T>::inorder(Node<T>* node) const
{
	if (node)
	{
		inorder(node->left);
		std::cout << node->key << ' ';
		inorder(node->right);
	}
}

//left-right-root print
template<typename T>
void Tree<T>::postorder(Node<T>* node) const
{
	if (node)
	{
		postorder(node->left);
		postorder(node->right);
		std::cout << node->key << ' ';
	}
}

//root-left-right print
template<typename T>
void Tree<T>::preorder(Node<T>* node) const
{
	if (node)
	{
		std::cout << node->key << ' ';
		preorder(node->left);
		preorder(node->left);
	}
}
