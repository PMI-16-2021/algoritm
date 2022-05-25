#pragma once
#include <iostream>
#include <string>
#include <vector>

template<typename T>
struct Node {
	T element;
	Node<T>* left;
	Node<T>* right;
	int height;
	Node() : element(0), left(nullptr), right(nullptr), height(0) {}
	Node(T _element) : element(_element), left(nullptr), right(nullptr), height(0){}
	Node(T _element, Node<T>* _left, Node<T>* _right, int _height) 
		: element(_element), left(_left), right(_right), height(_height) {}
};

template<typename T>
class AVLTree {
private:
	Node<T>* root;
	void Insert(T elem, Node<T>*& t);
	void Remove(T elem, Node<T>*& t);
	bool Find(T elem, Node<T>*& t);
	Node<T>* FindMin(Node<T>* t);
	Node<T>* FindMax(Node<T>* t);
	void Clean(Node<T>*& t);
	void Copy(Node<T>*& first, Node<T>*& second);
	Node<T>* NodeCopy(Node<T>*& t);
	void Balance(Node<T>*& t);
	int GetHeight(Node<T>* t);
	Node<T>* RightTurn(Node<T>*& t);
	Node<T>* RightLeftTurn(Node<T>*& t);
	Node<T>* LeftTurn(Node<T>*& t);
	Node<T>* LeftRightTurn(Node<T>*& t);
	void Print(Node<T>* t, int level) const;
	void Preorder(Node<T>*& t, std::vector<T>& output);
	void Inorder(Node<T>*& t, std::vector<T>& output);
	void Postorder(Node<T>*& t, std::vector<T>& output);

public:
	AVLTree();
	~AVLTree();
	void Insert(T elem);
	void Remove(T elem);
	bool Find(T elem);
	void Print() const;
	void Preorder(std::vector<T>& output);
	void Inorder(std::vector<T>& output);
	void Postorder(std::vector<T>& output);
};

int Max(int first, int second) {
	return ((first > second) ? first : second);
}

template<typename T>
void AVLTree<T>::Insert(T elem, Node<T>*& t) {
	if (t == nullptr) {
		t = new Node<T>(elem);
	}
	else {
		if (elem < t->element) {
			Insert(elem, t->left);
		}
		else {
			Insert(elem, t->right);
		}
	}
	Balance(t);
}

template <typename T>
Node<T>* AVLTree<T>::FindMin(Node<T>* t) {
	if (t == nullptr) {
		std::cout << "Tree is empty\n";
		return t;
	}
	else {
		while (t->left != nullptr) {
			t = t->left;
		}
		return t;
	}
}

template <typename T>
Node<T>* AVLTree<T>::FindMax(Node<T>* t) {
	if (t == nullptr) {
		std::cout << "Tree is empty\n";
		return t;
	}
	else {
		while (t->right != nullptr) {
			t = t->right;
		}
		return t;
	}
}

template <typename T>
bool AVLTree<T>::Find(T elem, Node<T>*& t) {
	if (!t) {
		return false;
	}
	else {
		if (elem < t->element) {
			Find(elem, t->left);
		}
		else {
			if (elem > t->element) {
				Find(elem, t->right);
			}
			else {
				return true;
			}
		}
	}
}

template <typename T>
void AVLTree<T>::Copy(Node<T>*& first, Node<T>*& second) {
	Clean(second);
	second = NodeCopy(first);
}

template <typename T>
void AVLTree<T>::Clean(Node<T>*& t) {
	Node<T>* vict;
	if (t != nullptr) {
		Clean(t->left);
		Clean(t->right);
		vict = t;
		delete vict;
		t = nullptr;
	}
}

template <typename T>
Node<T>* AVLTree<T>::NodeCopy(Node<T>*& t) {
	Node<T>* temp;
	if (t == nullptr) {
		return t;
	}
	else {
		temp = new Node<T>;
		temp->element = t->element;
		temp->left = NodeCopy(t->left);
		temp->right = NodeCopy(t->right);
		return temp;
	}
}

template <typename T>
void AVLTree<T>::Balance(Node<T>*& t) {
	if (t == nullptr) {
		return;
	}
	if ((GetHeight(t->left) - GetHeight(t->right)) == 2) {
		if (GetHeight(t->left->left) < t->left->element) {
			t = RightTurn(t);
		}
		else {
			t = RightLeftTurn(t);
		}
	}
	if ((GetHeight(t->right) - GetHeight(t->left)) == 2) {
		if (GetHeight(t->right->right) > t->right->element) {
			t = LeftTurn(t);
		}
		else {
			t = LeftRightTurn(t);
		}
	}
	int m, n, d;
	m = GetHeight(t->left);
	n = GetHeight(t->right);
	d = Max(m, n);
	t->height = d + 1;
}

template <typename T>
void AVLTree<T>::Remove(T elem, Node<T>*& t) {
	if (t != nullptr) {
		if (t->element == elem) {
			if (t->left == nullptr && t->right == nullptr) {
				delete t;
				t = nullptr;
			}
			else if (t->left == nullptr || t->right == nullptr) {
				if (t->left != nullptr) {
					Node<T>* temp = t->left;
					delete t;
					t = temp;
				}
				else if (t->right != nullptr) {
					Node<T>* temp = t->right;
					delete t;
					t = temp;
				}
			}
			else {
				Node<T>* temp = t->right;
				while (temp->left != nullptr) {
					temp = temp->left;
				}
				t->element = temp->element;
				Remove(temp->element, t->right);
			}
		}
		else {
			if (elem < t->element) {
				Remove(elem, t->left);
			}
			else {
				Remove(elem, t->right);
			}
		}
		Balance(t);
	}
}

template <typename T>
void AVLTree<T>::Preorder(Node<T>*& t, std::vector<T>& output) {
	if (t != nullptr) {
		output.push_back(t->element);
		Preorder(t->left, output);
		Preorder(t->right, output);
	}
}

template <typename T>
void AVLTree<T>::Inorder(Node<T>*& t, std::vector<T>& output) {
	if (t != nullptr) {
		Inorder(t->left, output);
		output.push_back(t->element);
		Inorder(t->right, output);
	}
}

template <typename T>
void AVLTree<T>::Postorder(Node<T>*& t, std::vector<T>& output) {
	if (t != nullptr) {
		Postorder(t->left, output);
		Postorder(t->right, output);
		output.push_back(t->element);
	}
}

template<typename T>
int AVLTree<T>::GetHeight(Node<T>* t) {
	int temp;
	if (t == nullptr) {
		return -1;
	}
	else {
		temp = t->height;
		return temp;
	}
}

template <typename T>
Node<T>* AVLTree<T>::RightTurn(Node<T>*& t) {
	if (t->left != nullptr) {
		Node<T>* temp = t->left;
		t->left = temp->right;
		temp->right = t;
		t->height = Max(GetHeight(t->left), GetHeight(t->right)) + 1;
		temp->height = Max(GetHeight(temp->left), temp->height) + 1;
		return temp;
	}
	return t;
}

template <typename T>
Node<T>* AVLTree<T>::LeftTurn(Node<T>*& t) {
	if (t->right != nullptr) {
		Node<T>* temp = t->right;
		t->right = temp->left;
		temp->left = t;
		t->height = Max(GetHeight(t->left), GetHeight(t->right)) + 1;
		temp->height = Max(temp->height, GetHeight(temp->right)) + 1;
		return temp;
	}
	return t;
}

template <typename T>
Node<T>* AVLTree<T>::RightLeftTurn(Node<T>*& t) {
	t->left = LeftTurn(t->left);
	return RightTurn(t);
}

template<typename T>
Node<T>* AVLTree<T>::LeftRightTurn(Node<T>*& t) {
	t->right = RightTurn(t->right);
	return LeftTurn(t);
}

template<typename T>
void AVLTree<T>::Print(Node<T>* t, int level) const {
	if (t != nullptr) {
		Print(t->left, level + 1);
		for (int i = 0; i < level; ++i) {
			std::cout << '\t';
		}
		std::cout << t->element << '\n';
		Print(t->right, level + 1);
	}
}

template<typename T>
AVLTree<T>::AVLTree() : root(nullptr) {}

template<typename T>
AVLTree<T>::~AVLTree() {
	Clean(root);
}

template<typename T>
void AVLTree<T>::Insert(T elem) {
	Insert(elem, root);
}

template<typename T>
void AVLTree<T>::Remove(T elem) {
	Remove(elem, root);
}

template<typename T>
bool AVLTree<T>::Find(T elem) {
	return Find(elem, root);
}

template<typename T>
void AVLTree<T>::Print() const {
	std::cout << "______________________________________\n";
	Print(root, 0);
	std::cout << "______________________________________\n";
}

template <typename T>
void AVLTree<T>::Postorder(std::vector<T>& output) {
	Postorder(root, output);
}

template <typename T>
void AVLTree<T>::Inorder(std::vector<T>& output) {
	Inorder(root, output);
}

template <typename T>
void AVLTree<T>::Preorder(std::vector<T>& output) {
	Preorder(root, output);
}

