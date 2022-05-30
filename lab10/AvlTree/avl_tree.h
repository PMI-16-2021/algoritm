#pragma once
#include <iostream>
#include <string>
#include <vector>

template<typename T>
struct Node {
	T value_;
	Node<T>* left_;
	Node<T>* right_;
	int height_;
	Node() : value_(T(0)), left_(nullptr), right_(nullptr), height_(0) {}
	Node(T _value, Node<T>* _left, Node<T>* _right, int _height)
		: value_(_value), left_(_left), right_(_right), height_(_height) {}
	T GetValue() const { return value_; }
};

template<typename T>
class AvlTree {
private:
	Node<T>* root_;
	int GetHeight(Node<T>* node);
	void Insert(T value, Node<T>*& node);
	Node<T>* FindMin(Node<T>* node);
	Node<T>* FindMax(Node<T>* node);
	Node<T>* RightTurn(Node<T>*& node);
	Node<T>* RightLeftTurn(Node<T>*& node);
	Node<T>* LeftTurn(Node<T>*& node);
	Node<T>* LeftRightTurn(Node<T>*& node);
	void Preorder(Node<T>*& t, std::vector<T>& output);
	void Inorder(Node<T>*& t, std::vector<T>& output);
	void Postorder(Node<T>*& t, std::vector<T>& output);
	void Balance(Node<T>*& node);
	void Print(Node<T>* node, int level) const;
	void ClearTree(Node<T>*& node);

public:
	AvlTree();
	~AvlTree();
	void Insert(T value);
	void Print() const;
	void Clear();
	void Preorder(std::vector<T>& output);
	void Inorder(std::vector<T>& output);
	void Postorder(std::vector<T>& output);
};
template<typename T>
AvlTree<T>::AvlTree() : root_(nullptr) {}
template<typename T>
AvlTree<T>::~AvlTree() {
	ClearTree(root_);
}

int GetMax(int a, int b) {
	return ((a > b) ? a : b);
}

template<typename T>
int AvlTree<T>::GetHeight(Node<T>* node) {
	int temp;
	if (node == nullptr) {
		return -1;
	}
	else {
		temp = node->height_;
		return temp;
	}
}
template<typename T>
void AvlTree<T>::Insert(T value, Node<T>*& node) {
	if (node == nullptr) {
		node = new Node<T>(value);
	}
	else {
		if (value < node->value_) {
			Insert(value, node->left_);
		}
		else {
			Insert(value, node->right_);
		}
	}
	Balance(node);
}
template <typename T>
Node<T>* AvlTree<T>::FindMin(Node<T>* node) {
	while (node->left_ != nullptr) {
		node = node->left_;
	}
	return node;
}
template <typename T>
Node<T>* AvlTree<T>::FindMax(Node<T>* node) {
	while (node->right_ != nullptr) {
		node = node->right_;
	}
	return node;
}
template <typename T>
Node<T>* AvlTree<T>::RightTurn(Node<T>*& node) {
	if (node->left_ != nullptr) {
		Node<T>* temp = node->left_;
		node->left_ = temp->right_;
		temp->right_ = node;
		node->height_ = GetMax(GetHeight(node->left_), GetHeight(node->right_)) + 1;
		temp->height_ = GetMax(GetHeight(temp->left_), temp->height_) + 1;
		return temp;
	}
	return node;
}
template <typename T>
Node<T>* AvlTree<T>::LeftTurn(Node<T>*& node) {
	if (node->right_ != nullptr) {
		Node<T>* temp = node->right_;
		node->right_ = temp->left_;
		temp->left_ = node;
		node->height_ = GetMax(GetHeight(node->left_), GetHeight(node->right_)) + 1;
		temp->height_ = GetMax(temp->height_, GetHeight(temp->right_)) + 1;
		return temp;
	}
	return node;
}
template <typename T>
Node<T>* AvlTree<T>::RightLeftTurn(Node<T>*& node) {
	node->left_ = LeftTurn(node->left_);
	return RightTurn(node);
}
template<typename T>
Node<T>* AvlTree<T>::LeftRightTurn(Node<T>*& node) {
	node->right_ = RightTurn(node->right_);
	return LeftTurn(node);
}
template <typename T>
void AvlTree<T>::Preorder(Node<T>*& t, std::vector<T>& output) {
	if (t != nullptr) {
		output.push_back(t->value_);
		Preorder(t->left_, output);
		Preorder(t->right_, output);
	}
}

template <typename T>
void AvlTree<T>::Inorder(Node<T>*& t, std::vector<T>& output) {
	if (t != nullptr) {
		Inorder(t->left_, output);
		output.push_back(t->value_);
		Inorder(t->right_, output);
	}
}

template <typename T>
void AvlTree<T>::Postorder(Node<T>*& t, std::vector<T>& output) {
	if (t != nullptr) {
		Postorder(t->left_, output);
		Postorder(t->right_, output);
		output.push_back(t->value_);
	}
}
template <typename T>
void AvlTree<T>::Balance(Node<T>*& node) {
	if (node == nullptr) {
		return;
	}
	if ((GetHeight(node->left_) - GetHeight(node->right_)) == 2) {
		if (GetHeight(node->left_->left_) < node->left_->value_) {
			node = RightTurn(node);
		}
		else {
			node = RightLeftTurn(node);
		}
	}
	if ((GetHeight(node->right_) - GetHeight(node->left_)) == 2) {
		if (GetHeight(node->right_->right_) > node->right_->value_) {
			node = LeftTurn(node);
		}
		else {
			node = LeftRightTurn(node);
		}
	}
	int lh, rh, h;
	lh = GetHeight(node->left_);
	rh = GetHeight(node->right_);
	h = GetMax(lh, rh);
	node->height_ = h + 1;
}
template<typename T>
void AvlTree<T>::Print(Node<T>* node, int level) const {
	if (node == NULL) {
		return;
	}
	int distance = 10;
	level += distance;
	Print(node->right_, level);
	std::cout << "\n\n";
	for (int i = distance; i < level; i++) {
		std::cout << "-";
	}
	std::cout << node->GetValue() << "\n";
	Print(node->left_, level);
}
template <typename T>
void AvlTree<T>::ClearTree(Node<T>*& node) {
	Node<T>* temp;
	if (node != nullptr) {
		ClearTree(node->left_);
		ClearTree(node->right_);
		temp = node;
		delete temp;
		node = nullptr;
	}
}
template<typename T>
void AvlTree<T>::Insert(T value) {
	Insert(value, root_);
}
template<typename T>
void AvlTree<T>::Print() const {
	Node<T>* temp = root_;
	Print(temp, 0);
}
template <typename T>
void AvlTree<T>::Clear() {
	ClearTree(root_);
}
template <typename T>
void AvlTree<T>::Postorder(std::vector<T>& output) {
	Postorder(root_, output);
}

template <typename T>
void AvlTree<T>::Inorder(std::vector<T>& output) {
	Inorder(root_, output);
}

template <typename T>
void AvlTree<T>::Preorder(std::vector<T>& output) {
	Preorder(root_, output);
}