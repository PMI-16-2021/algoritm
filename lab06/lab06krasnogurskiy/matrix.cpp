#include "matrix.h"
#include <vector>

SparseMatrix::Node::Node() :
	m_row(0),
	m_column(0),
	m_value(0),
	m_pleft(this),
	m_pupper(this)
{}

SparseMatrix::Node::Node(size_t _row, size_t _column, int _value) :
	m_row(_row),
	m_column(_column),
	m_value(_value),
	m_pleft(nullptr),
	m_pupper(nullptr)
{}

SparseMatrix::Node::Node(size_t _row, size_t _column, int _value, Node* _pleft, Node* _pupper) :
	m_row(_row),
	m_column(_column),
	m_value(_value),
	m_pleft(_pleft),
	m_pupper(_pupper)
{}

SparseMatrix::SparseMatrix(size_t _row_size, size_t _col_size)
{
	m_row_size = _row_size;
	m_col_size = _col_size;
	m_colheads = new Node[m_col_size];
	for (size_t i = 1; i < m_col_size; i++)
	{
		m_colheads[i].m_row = 0;
		m_colheads[i].m_column = i;
		m_colheads[i].m_value = 0;
		m_colheads[i].m_pleft = &m_colheads[i - 1];
		m_colheads[i].m_pupper = &m_colheads[i];
	}

	m_rowheads = new Node[m_row_size];
	for (size_t i = 1; i < m_row_size; i++)
	{
		m_rowheads[i].m_row = i;
		m_rowheads[i].m_column = 0;
		m_rowheads[i].m_value = 0;
		m_rowheads[i].m_pleft = &m_rowheads[i];
		m_rowheads[i].m_pupper = &m_rowheads[i - 1];
	}

	m_colheads[0].m_row = 0;
	m_colheads[0].m_column = 0;
	m_colheads[0].m_value = 0;
	m_colheads[0].m_pleft = &m_colheads[m_col_size - 1];
	m_colheads[0].m_pupper = &m_rowheads[m_row_size - 1];

	m_rowheads[0].m_row = 0;
	m_rowheads[0].m_column = 0;
	m_rowheads[0].m_value = 0;
	m_rowheads[0].m_pleft = &m_colheads[m_col_size - 1];
	m_rowheads[0].m_pupper = &m_rowheads[m_row_size - 1];
}

SparseMatrix::~SparseMatrix()
{
	for (uint32_t i = 1; i < m_row_size; i++)
	{
		clean_row(m_rowheads[i].m_pleft);
	}
	delete[] m_rowheads;
	delete[] m_colheads;
}

void SparseMatrix::print(std::ostream& out)
{
	std::vector<std::vector<Node>> matrix;
	matrix.resize(m_row_size);
	for (uint32_t i = 0; i < m_row_size; i++)
	{
		Node node = *m_rowheads[i].m_pleft;

		uint32_t j = 0;
		while (j < m_col_size)
		{
			matrix[i].push_back(node);
			if (node.m_column == 0)
			{
				break;
			}
			node = *node.m_pleft;
			j++;
		}
		auto to_remove = std::remove_if(matrix[i].begin(), matrix[i].end(), [](Node n) {return n.m_value == 0; });
		matrix[i].erase(to_remove, matrix[i].end());
		matrix[i].shrink_to_fit();

		int prev_col = -1;
		for (std::vector<Node>::reverse_iterator rit = matrix[i].rbegin(); rit != matrix[i].rend(); rit++)
		{
			for (int k = 0; k < rit->m_column - prev_col - 1; k++)
			{
				out << '0' << ' ';
			}
			out << rit->m_value << ' ';
			prev_col = (int)rit->m_column;
		}
		for (int k = prev_col + 1; k < (int)m_col_size; k++)
		{
			out << '0' << ' ';
		}
		out << '\n';
		matrix[i].clear();
		matrix[i].shrink_to_fit();
	}
}

SparseMatrix::Node* SparseMatrix::rprev(size_t _row, size_t _column)
{
	Node* p_rprev = &m_rowheads[_row];
	while (_column < p_rprev->m_pleft->m_column)
	{
		p_rprev = p_rprev->m_pleft;
	}
	return p_rprev;
}

SparseMatrix::Node* SparseMatrix::cprev(size_t _row, size_t _column)
{
	Node* p_cprev = &m_colheads[_column];
	while (_row < p_cprev->m_pupper->m_row)
	{
		p_cprev = p_cprev->m_pupper;
	}
	return p_cprev;
}

void SparseMatrix::set_value(size_t _row, size_t _column, int _value)
{
	if (_row >= m_row_size || _column >= m_col_size)
	{
		throw std::exception("set_value(): out of range");
	}
	Node* r_prev = rprev(_row, _column);
	Node* c_prev = cprev(_row, _column);
	bool present = r_prev->m_pleft->m_column == _column;
	if (present)
	{
		replace_value(_value, r_prev, c_prev);
	}
	else
	{
		new_node(_row, _column, _value, r_prev, c_prev);
	}
}

int SparseMatrix::get_value(size_t _row, size_t _column)
{
	if (_row < 0 || _row >= m_row_size || _column < 0 || _column >= m_col_size)
	{
		throw std::exception("get_value(): out of range");
	}
	int value = 0;
	Node* r_prev = rprev(_row, _column);
	bool present = r_prev->m_pleft->m_column == _column;
	if (present)
	{
		value = r_prev->m_pleft->m_value;
	}
	return value;
}

size_t SparseMatrix::get_row_size()
{
	return this->m_row_size;
}

size_t SparseMatrix::get_col_size()
{
	return this->m_col_size;
}

SparseMatrix& SparseMatrix::operator=(SparseMatrix& other)
{
	if (this == &other)
	{
		return *this;
	}
	for (uint32_t i = 1; i < m_row_size; i++)
	{
		clean_row(m_rowheads[i].m_pleft);
	}
	delete[] m_rowheads;
	delete[] m_colheads;
	m_row_size = other.m_row_size;
	m_col_size = other.m_col_size;
	m_colheads = new Node[m_col_size];
	for (uint32_t i = 1; i < m_col_size; i++)
	{
		m_colheads[i].m_row = 0;
		m_colheads[i].m_column = i;
		m_colheads[i].m_value = other.m_colheads[i].m_value;
		m_colheads[i].m_pleft = &m_colheads[i - 1];
		m_colheads[i].m_pupper = &m_colheads[i];
	}

	m_rowheads = new Node[m_row_size];
	for (uint32_t i = 1; i < m_row_size; i++)
	{
		m_rowheads[i].m_row = i;
		m_rowheads[i].m_column = 0;
		m_rowheads[i].m_value = other.m_rowheads[i].m_value;
		m_rowheads[i].m_pleft = &m_rowheads[i];
		m_rowheads[i].m_pupper = &m_rowheads[i - 1];
	}

	m_colheads[0].m_row = 0;
	m_colheads[0].m_column = 0;
	m_colheads[0].m_value = other.m_colheads[0].m_value;
	m_colheads[0].m_pleft = &m_colheads[m_col_size - 1];
	m_colheads[0].m_pupper = &m_rowheads[m_row_size - 1];

	m_rowheads[0].m_row = 0;
	m_rowheads[0].m_column = 0;
	m_rowheads[0].m_value = other.m_rowheads[0].m_value;
	m_rowheads[0].m_pleft = &m_colheads[m_col_size - 1];
	m_rowheads[0].m_pupper = &m_rowheads[m_row_size - 1];

	std::vector<std::vector<Node>> matrix;
	matrix.resize(m_row_size);
	for (uint32_t i = 0; i < m_row_size; i++)
	{
		Node node = *other.m_rowheads[i].m_pleft;

		uint32_t j = 0;
		while (j < m_col_size)
		{
			matrix[i].push_back(node);
			if (node.m_column == 0)
			{
				break;
			}
			node = *node.m_pleft;
			j++;
		}
		auto to_remove = std::remove_if(matrix[i].begin(), matrix[i].end(), [](Node n) {return n.m_value == 0; });
		matrix[i].erase(to_remove, matrix[i].end());
		matrix[i].shrink_to_fit();
		for (std::vector<Node>::reverse_iterator rit = matrix[i].rbegin(); rit != matrix[i].rend(); rit++)
		{
			set_value(rit->m_row, rit->m_column, rit->m_value);
		}
		matrix[i].erase(matrix[i].begin(), matrix[i].end());
		matrix[i].shrink_to_fit();
	}
	return *this;
}
////////////////////////
SparseMatrix& SparseMatrix::operator*(SparseMatrix& other)
{
	if (this->m_col_size != other.m_row_size)
	{
		throw std::exception("operator*(): leff matrix column-size is not equal right matrix row-size");
	}
	SparseMatrix matrix(3, 3);
	matrix = *this;

	for (uint32_t i = 1; i < m_row_size; i++)
	{
		clean_row(m_rowheads[i].m_pleft);
	}
	delete[] m_rowheads;
	delete[] m_colheads;

	m_row_size = matrix.m_row_size;
	m_col_size = other.m_col_size;
	m_colheads = new Node[m_col_size];
	for (uint32_t i = 1; i < m_col_size; i++)
	{
		m_colheads[i].m_row = 0;
		m_colheads[i].m_column = i;
		m_colheads[i].m_value = 0;
		m_colheads[i].m_pleft = &m_colheads[i - 1];
		m_colheads[i].m_pupper = &m_colheads[i];
	}

	m_rowheads = new Node[m_row_size];
	for (uint32_t i = 1; i < m_row_size; i++)
	{
		m_rowheads[i].m_row = i;
		m_rowheads[i].m_column = 0;
		m_rowheads[i].m_value = 0;
		m_rowheads[i].m_pleft = &m_rowheads[i];
		m_rowheads[i].m_pupper = &m_rowheads[i - 1];
	}

	m_colheads[0].m_row = 0;
	m_colheads[0].m_column = 0;
	m_colheads[0].m_value = 0;
	m_colheads[0].m_pleft = &m_colheads[m_col_size - 1];
	m_colheads[0].m_pupper = &m_rowheads[m_row_size - 1];

	m_rowheads[0].m_row = 0;
	m_rowheads[0].m_column = 0;
	m_rowheads[0].m_value = 0;
	m_rowheads[0].m_pleft = &m_colheads[m_col_size - 1];
	m_rowheads[0].m_pupper = &m_rowheads[m_row_size - 1];


	for (size_t i = 0; i < m_row_size; i++)
	{
		for (size_t j = 0; j < m_col_size; j++)
		{
			Node* row_element = matrix.m_rowheads[i].m_pleft;
			Node* col_element = other.m_colheads[j].m_pupper;
			int value = 0;
			multiply(row_element, col_element, value);
			if (value != 0)
			{
				set_value(i, j, value);
			}
		}
	}
	return *this;
}

SparseMatrix& SparseMatrix::operator*(int value)
{
	m_colheads[0].m_value *= value;
	for (size_t i = 0; i < m_row_size; i++)
	{
		m_rowheads[i].m_value *= value;
		Node* next = m_rowheads[i].m_pleft;
		while (next->m_column != 0)
		{
			next->m_value *= value;
			next = next->m_pleft;
		}
	}
	return *this;
}

SparseMatrix& SparseMatrix::operator+(SparseMatrix& other)
{
	if (this->m_row_size != other.m_row_size || this->m_col_size != other.m_col_size)
	{
		throw std::exception("adding two matrixs of different sizes");
	}
	this->m_colheads[0].m_value += other.m_rowheads[0].m_value;
	for (size_t i = 0; i < m_row_size; i++)
	{
		this->m_rowheads[i].m_value += other.m_rowheads[i].m_value;
		Node* this_element = this->m_rowheads[i].m_pleft;
		Node* other_element = other.m_rowheads[i].m_pleft;
		for (size_t j = 0; j < m_col_size; j++)
		{
			if (this_element->m_column == other_element->m_column)
			{
				if (other_element->m_column == 0)
				{
					break;
				}
				this_element->m_value += other_element->m_value;
				other_element = other_element->m_pleft;
			}
			else if (this_element->m_column < other_element->m_column)
			{
				set_value(i, other_element->m_column, other_element->m_value);
				other_element = other_element->m_pleft;
				if (other_element->m_column == 0)
				{
					break;
				}
			}

			while (this_element->m_column > other_element->m_column)
			{
				this_element = this_element->m_pleft;
			}
		}
	}
	return *this;
}

void SparseMatrix::multiply(Node* row_element, Node* col_element, int& value)
{
	if (col_element->m_row == row_element->m_column)
	{
		value += row_element->m_value * col_element->m_value;
		if (row_element->m_column == 0)
		{
			return;
		}
		row_element = row_element->m_pleft;
	}

	while (col_element->m_row < row_element->m_column)
	{
		row_element = row_element->m_pleft;
	}

	while (row_element->m_column < col_element->m_row)
	{
		col_element = col_element->m_pupper;
	}

	multiply(row_element, col_element, value);
}

void SparseMatrix::replace_value(int _new_value, Node* _rprev, Node* _cprev)
{
	Node* to_delete = _rprev->m_pleft;
	if (_new_value == 0 && to_delete->m_row != 0 && to_delete->m_column != 0)
	{
		_rprev->m_pleft = to_delete->m_pleft;
		_cprev->m_pupper = to_delete->m_pupper;
		delete to_delete;
	}
	else
	{
		_rprev->m_pleft->m_value = _new_value;
		_cprev->m_pupper->m_value = _new_value;
	}
}

void SparseMatrix::new_node(size_t _row, size_t _column, int _value, Node* _rprev, Node* _cprev)
{
	_rprev->m_pleft = new Node(_row, _column, _value, _rprev->m_pleft, _cprev->m_pupper);
	_cprev->m_pupper = _rprev->m_pleft;
}

void SparseMatrix::clean_row(Node* last_in_row)
{
	if (last_in_row->m_column == 0)
	{
		return;
	}
	else if (last_in_row->m_column == 1)
	{
		delete last_in_row;
		return;
	}
	else
	{
		Node* next = last_in_row->m_pleft;
		delete last_in_row;
		clean_row(next);
		next = nullptr;
	}
}
