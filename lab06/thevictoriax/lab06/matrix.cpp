#pragma once
#include <iostream>
#include "matrix.h"
using namespace std;

Data* Matrix::prevColumn(size_t line, size_t column)
{
	Data* previous = &cls[column];
	while (previous->up->line > line)
	{
		previous = previous->up;
	}
	return previous;
}

Data* Matrix::prevLine(size_t line, size_t column)
{
	Data* previous = &lns[line];
	while (previous->left->column > column)
	{
		previous = previous->left;
	}
	return previous;
}

void Matrix::addVal(Data* prevLine, Data* prevColumn, size_t line, size_t column, double val)
{
	Data* temp = new Data();
	temp->line = line;
	temp->column = column;
	temp->val = val;
	temp->left = prevLine->left;
	prevLine->left = temp;
	temp->up = prevColumn->up;
	prevColumn->up = temp;
}

void Matrix::changeVal(Data* prevLine, Data* prevColumn, size_t line, size_t column, double val)
{
	if (val == 0)
	{
		Data* del = prevLine->left;
		prevLine->left = del->left;
		prevColumn->up = del->up;
		delete del;
	}
	else
	{
		prevLine->left->val = val;
	}
}

Matrix::Matrix(size_t lnsCounter, size_t clsCounter) : linesCounter(lnsCounter), columnsCounter(clsCounter)
{
	lns.resize(linesCounter + 1);
	cls.resize(columnsCounter + 1);
}

double Matrix::getVal(size_t line, size_t column)
{
	double temp = 0;
	Data* prevCls = prevColumn(line, column);
	bool isIn = prevCls->up->line == line && prevCls->up->column == column;
	if (isIn)
	{
		temp = prevCls->up->val;
	}
	return temp;
}

void Matrix::setVal(size_t line, size_t column, double val)
{
	Data* prevCls = prevColumn(line, column);
	Data* prevLns = prevLine(line, column);
	bool isIn = prevCls->up->line == line && prevCls->up->column == column;
	if (isIn)
	{
		changeVal(prevLns, prevCls, line, column, val);
	}
	else
	{
		addVal(prevLns, prevCls, line, column, val);
	}
}

void Matrix::add(Matrix& a)
{
	for (size_t i = 1; i <= linesCounter; i++)
	{
		for (size_t j = 1; j <= columnsCounter; j++)
		{
			double val = getVal(i, j) + a.getVal(i, j);
			setVal(i, j, val);
		}
	}
}

void Matrix::subtraction(Matrix& a)
{
	for (size_t i = 1; i <= linesCounter; i++)
	{
		for (size_t j = 1; j <= columnsCounter; j++)
		{
			double val = getVal(i, j) - a.getVal(i, j);
			setVal(i, j, val);
		}
	}
}

void Matrix::multiply(Matrix& a)
{
	double temp = 0;
	Matrix M(linesCounter, a.columnsCounter);
	for (int i = 1; i <= linesCounter; i++)
	{
		for (int j = 1; j <= a.columnsCounter; j++)
		{
			for (int z = 1; z <= a.linesCounter; z++)
			{
				temp += getVal(i, z) * a.getVal(z, j);
			}
			M.setVal(i, j, temp);
			temp = 0;
		}
	}

	columnsCounter = a.columnsCounter;
	for (int i = 1; i <= linesCounter; i++)
	{
		for (int j = 1; j <= columnsCounter; j++)
		{
			setVal(i, j, M.getVal(i, j));
		}
	}
}

void Matrix::transposition()
{
	size_t _lines = columnsCounter;
	size_t _columns = linesCounter;
	Matrix M(_lines, _columns);

	for (int i = 1; i <= columnsCounter; i++)
	{
		for (int j = 1; j <= linesCounter; j++)
		{
			M.setVal(j, i, getVal(i, j));
		}
	}
	columnsCounter = _lines;
	linesCounter = _columns;
	for (int i = 1; i <= _lines; i++)
	{
		for (int j = 1; j <= _columns; j++)
		{
			setVal(i, j, M.getVal(i, j));
		}
	}
}

std::vector<double> Matrix::significant_elements()
{
	std::vector<double> Significant_elements;
	for (int i = 1; i <= linesCounter; i++)
	{
		for (int j = 1; j <= columnsCounter; j++)
		{
			if (getVal(i, j) != 0)
			{
				Significant_elements.push_back(getVal(i, j));
			}
		}
	}
	return Significant_elements;
}


void Matrix::print()
{
	for (int i = 1; i <= linesCounter; i++)
	{
		for (int j = 1; j <= columnsCounter; j++)
		{
			cout << getVal(i, j) << " ";
			if (j == columnsCounter)
			{
				cout << endl;
			}
		}
	}
}