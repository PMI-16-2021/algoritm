#include <iostream>
#include <vector>
using namespace std;

template<typename T>
struct Node {
	int column;
	int row;
	T value;
	Node* upper;
	Node* left;
	Node(): column(0), row(0), value(0), upper(this), left(this) {}
};

template<typename T>
class SparseMatrix {
private:
	vector<Node<T>> rows;
	vector<Node<T>> columns;
	int row_count;
	int column_count;
	int elements;
	Node<T>* GetPreviousByRow(int i, int j);
	Node<T>* GetPreviousByColumn(int i, int j);

public:
	SparseMatrix();
	SparseMatrix(int _row, int _column);
	~SparseMatrix();
	T Get(int i, int j);
	void Set(int i, int j, T value);
	void Erace(int i, int j);
	bool IsEmpty() const;
	int GetElementsCount() const;
	void SignificantElements(vector<T>& output);
	SparseMatrix<T> Addition(SparseMatrix<T>& matrix);
	SparseMatrix<T> Subtraction(SparseMatrix<T>& matrix);
	SparseMatrix<T> Multiplication(SparseMatrix<T>& matrix);
	void Print();
};

template<typename T>
Node<T>* SparseMatrix<T>::GetPreviousByRow(int i, int j) {
	Node<T>* prev = &rows[i];
	while (prev->left->column > j) {
		prev = prev->left;
	}
	return prev;
}

template<typename T>
Node<T>* SparseMatrix<T>::GetPreviousByColumn(int i, int j) {
	Node<T>* prev = &columns[j];
	while (prev->upper->row > i) {
		prev = prev->upper;
	}
	return prev;
}

template<typename T>
SparseMatrix<T>::SparseMatrix() : row_count(0), column_count(0), elements(0) {}

template<typename T>
SparseMatrix<T>::SparseMatrix(int _row, int _column) : row_count(_row), column_count(_column), elements(0) {
	rows.resize(row_count);
	columns.resize(column_count);
}

template<typename T>
SparseMatrix<T>::~SparseMatrix() {}

template<typename T>
T SparseMatrix<T>::Get(int i, int j) {
	if (i > row_count || i < 0 || j > column_count || j < 0) {
		throw "Bad index";
	}
	Node<T>* previous_by_row = GetPreviousByRow(i, j);
	bool is = previous_by_row->left->column == j && previous_by_row->left->row == i;
	if (is) {
		return previous_by_row->left->value;
	}
	return 0;
}

template<typename T>
void SparseMatrix<T>::Set(int i, int j, T value) {
	if (i > row_count || i < 0 || j > column_count || j < 0) {
		throw "Bad index";
	}
	if (value == 0) {
		return;
	}
	Node<T>* previous_by_row = GetPreviousByRow(i, j);
	Node<T>* previous_by_column = GetPreviousByColumn(i, j);
	bool is = previous_by_column->upper->row == i && previous_by_column->upper->column == j;
	if (is) {
		if (value == 0) {
			Node<T>* vict = previous_by_row->left;
			previous_by_row->left = vict->left;
			previous_by_column->upper = vict->upper;
			vict = nullptr;
			++elements;
		}
		else {
			previous_by_row->left->value = value;
		}
	}
	else {
		Node<T>* new_elem = new Node<T>;
		new_elem->row = i;
		new_elem->column = j;
		new_elem->value = value;
		new_elem->left = previous_by_row->left; 
		previous_by_row->left = new_elem;
		new_elem->upper = previous_by_column->upper;
		previous_by_column->upper = new_elem;
		++elements;
	}
	
}

template<typename T>
void SparseMatrix<T>::Erace(int i, int j) {
	if (i > row_count || i < 0 || j > column_count || j < 0) {
		throw "Bad index";
	}
	Node<T>* previous_by_row = GetPreviousByRow(i, j); 
	Node<T>* previous_by_column = GetPreviousByColumn(i, j);
	Node<T>* vict = previous_by_column->upper;             
	if (vict->row == i) {                                                 
		previous_by_column->upper = vict->upper; 
		previous_by_row->left = vict->left;
		--elements;                                         
		delete vict;                                   
	}
}

template<typename T>
bool SparseMatrix<T>::IsEmpty() const {
	if (elements == 0) {
		return true;
	}
	return false;
}

template<typename T>
int SparseMatrix<T>::GetElementsCount() const {
	return elements;
}

template<typename T>
void SparseMatrix<T>::SignificantElements(vector<T>& output) {
	for (int i = 0; i < row_count; ++i) {
		for (int j = 0; j < column_count; ++j) {
			T val = Get(i, j);
			if (val != 0) {
				output.push_back(val);
			}
		}
	}
}

template<typename T>
SparseMatrix<T> SparseMatrix<T>::Addition(SparseMatrix<T>& matrix) {
	if (matrix.column_count != column_count || matrix.row_count != row_count) {
		std::cout << "Bad size matrix";
	}
	else {
		SparseMatrix<T> new_matrix(row_count, column_count);
		for (int i = 0; i < row_count; ++i) {
			for (int j = 0; j < column_count; ++j) {
				T val = Get(i, j) + matrix.Get(i, j);
				new_matrix.Set(i, j, val);
			}
		}
		return new_matrix;
	}
}

template<typename T>
SparseMatrix<T> SparseMatrix<T>::Subtraction(SparseMatrix<T>& matrix) {
	if (matrix.column_count != column_count || matrix.row_count != row_count) {
		std::cout << "Bad size matrix";
	}
	else {
		SparseMatrix<T> new_matrix(row_count, column_count);
		for (int i = 0; i < row_count; ++i) {
			for (int j = 0; j < column_count; ++j) {
				T val = Get(i, j) - matrix.Get(i, j);
				new_matrix.Set(i, j, val);
			}
		}
		return new_matrix;
	}
}

template<typename T>
SparseMatrix<T> SparseMatrix<T>::Multiplication(SparseMatrix<T>& matrix) {
	if (column_count != matrix.row_count) {
		throw "Bad size";
	}
	SparseMatrix<T> new_matrix(row_count, matrix.column_count);
	T temp = T();
	for (int i = 0; i < row_count; ++i) {
		for (int j = 0; j < matrix.column_count; ++j) {
			temp = T();
			for (int n = 0; n < column_count; ++n) {
				temp += Get(i, n) * matrix.Get(n, j);
			}
			new_matrix.Set(i, j, temp);
		}
	}
	return new_matrix;
}

template<typename T>
void SparseMatrix<T>::Print() {
	for (int i = 0; i < row_count; ++i) {
		for (int j = 0; j < column_count; ++j) {
			std::cout << this->Get(i, j) << ' ';
		}
		std::cout << '\n';
	}
}