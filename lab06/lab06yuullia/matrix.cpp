#include "matrix.h"
using namespace std;

Element* SparseMatrix::prevByRow(int r, int c) {
	Element* previous = &rows[r];
	while (previous->left_elem->column > c) {
		previous = previous->left_elem;
	}
	return previous;
}
Element* SparseMatrix::prevByColumn(int r, int c) {
	Element* previous = &columns[c];
	while (previous->upper_elem->row > r) {
		previous = previous->upper_elem;
	}
	return previous;
}

SparseMatrix::SparseMatrix() : rowCount(0), columnCount(0), elements(0) {}
SparseMatrix::SparseMatrix(int rCount, int cCount) : rowCount(rCount), columnCount(cCount), elements(0) {
	rows.resize(rowCount);
	columns.resize(columnCount);
}
SparseMatrix::~SparseMatrix() {}

int SparseMatrix::get(int r, int c) {
	if (r > rowCount || c > columnCount || r < 0 ||  c < 0) {
		throw "Index error.";
	}
	Element* elPrevByRow = prevByRow(r, c);
	if (elPrevByRow->left_elem->column == c && elPrevByRow->left_elem->row == r) {
		return elPrevByRow->left_elem->val;
	}
	return 0;
}
void SparseMatrix::set(int r, int c, int v) {
	if (v == 0) {
		return;
	}
	if (r > rowCount || c > columnCount || r < 0 || c < 0) {
		throw "Index error.";
	}
	Element* elPrevByRow = prevByRow(r, c);
	Element* elPrevByColumn = prevByColumn(r, c);
	if (elPrevByColumn->upper_elem->row == r && elPrevByColumn->upper_elem->column == c) {
		if (v == 0) {
			Element* El = elPrevByRow->left_elem;
			elPrevByRow->left_elem = El->left_elem;
			elPrevByColumn->upper_elem = El->upper_elem;
			El = nullptr;
			++elements;
		}
		else {
			elPrevByRow->left_elem->val = v;
		}
	}
	else {
		Element* El = new Element;
		El->row = r;
		El->column = c;
		El->val = v;
		El->left_elem = elPrevByRow->left_elem;
		elPrevByRow->left_elem = El;
		El->upper_elem = elPrevByColumn->upper_elem;
		elPrevByColumn->upper_elem = El;
		++elements;
	}
}
bool SparseMatrix::isEmpty() const {
	return elements == 0;
}
//int SparseMatrix::size() const {
//return elements;
//}

void SparseMatrix::significantElements(vector<int>& v) {
	for (int r = 0; r < rowCount; ++r) {
		for (int c = 0; c < columnCount; ++c) {
			int val = get(r, c);
			if (val != 0) {
				v.push_back(val);
			}
		}
	}
}
SparseMatrix SparseMatrix::addition(SparseMatrix& SM) {
	if (SM.columnCount != columnCount || SM.rowCount != rowCount) {
		cout << "Can`t add these matrices.";
	}
	else {
		SparseMatrix resultM (rowCount, columnCount);
		for (int r = 0; r < rowCount; ++r) {
			for (int c = 0; c < columnCount; ++c) {
				int val = get(r, c) + SM.get(r, c);
				resultM.set(r, c, val);
			}
		}
		return resultM;
	}
}
SparseMatrix SparseMatrix::subtraction(SparseMatrix& SM) {
	if (SM.columnCount != columnCount || SM.rowCount != rowCount) {
		cout << "These matrices cannot be subtracted.";
	}
	else {
		SparseMatrix resultM(rowCount, columnCount);
		for (int r = 0; r < rowCount; ++r) {
			for (int c = 0; c < columnCount; ++c) {
				int val = get(r, c) - SM.get(r, c);
				resultM.set(r, c, val);
			}
		}
		return resultM;
	}
}
SparseMatrix SparseMatrix::multiplication(SparseMatrix& SM) {
	if (columnCount != SM.rowCount) {
		cout << "These matrices cannot be multiplied.";
	}
	SparseMatrix resultM(rowCount, SM.columnCount);
	int temp = int();
	for (int r = 0; r < rowCount; ++r) {
		for (int c = 0; c < SM.columnCount; ++c) {
			temp = int();
			for (int nc = 0; nc < columnCount; ++nc) {
				temp += get(r, nc) * SM.get(nc, c);
			}
			resultM.set(r, c, temp);
		}
	}
	return resultM;
}

void SparseMatrix::print() {
	for (int r = 0; r < rowCount; ++r) {
		for (int c = 0; c < columnCount; ++c) {
			cout << get(r, c) << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

