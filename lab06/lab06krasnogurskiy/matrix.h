#pragma once
#include <iostream>

class SparseMatrix
{
public:
	SparseMatrix(size_t _row_size = 100, size_t _col_size = 100);
	~SparseMatrix();
	void print(std::ostream& out);
	void set_value(size_t _row, size_t _column, int _value);
	int get_value(size_t _row, size_t _column);
	size_t get_row_size();
	size_t get_col_size();
	SparseMatrix& operator=(SparseMatrix& other);
	SparseMatrix& operator*(SparseMatrix& other);
	SparseMatrix& operator*(int value);
	SparseMatrix& operator+(SparseMatrix& other);
	class Node
	{
		size_t m_row;
		size_t m_column;
		int m_value;
		Node* m_pleft;
		Node* m_pupper;
	public:
		Node();
		Node(size_t _row, size_t _column, int _value);
	private:
		Node(size_t _row, size_t _column, int _value, Node* _pleft, Node* _pupper);
		friend class SparseMatrix;
	};
private:
	Node* rprev(size_t _row, size_t _column);
	Node* cprev(size_t _row, size_t _column);
	void replace_value(int _new_value, Node* _rprev, Node* _cprev);
	void new_node(size_t _row, size_t _column, int _value, Node* _rprev, Node* _cprev);
	void clean_row(Node* last_in_row);
	void multiply(Node* row_element, Node* col_element, int& value);
	size_t m_row_size;
	size_t m_col_size;
	Node* m_rowheads;
	Node* m_colheads;
};