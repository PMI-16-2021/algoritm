#include<iostream>
#include<cassert>
#include<iomanip>
using namespace std;
const int n = 10, col_rozr = 3;
void VstavkaSort(int, int*);
void QuickSort(int* array, int, int);
void sort(int*, int, int); //���������� ������� ���������� ������
void merge(int*, int, int, int, int); //������ ������������ ������
void sort_rozr(int[n][n], int[n], int);
int velich_rozr(int, int);
bool Test1();
bool Test2();
bool Test3();
bool Test4();
int main() {
	cout <<"Test1\n";
	assert(Test1());
	cout << "\nTest2\n";
	assert(Test2());
	cout << "\nTest3\n";
	assert(Test3());
	cout << "\nTest4\n";
	assert(Test4());
	return 0;
}
bool Test1() {
	int* arr1 = new int[n] {5,9,7,4,3,8,2,1,6,0};
	int* arr2 = new int[n] {0,1,2,3,4,5,6,7,8,9};//sorted
	cout << "\nUnsorted arr1: ";
	for (int i = 0; i < n; i++, cout << " ") cout << arr1[i];
	cout << "\nSorted arr2: ";
	for (int i = 0; i < n; i++, cout << " ") cout << arr2[i];
	VstavkaSort(n, arr1);
	cout << "\nSorted arrays:\narr1\tarr2\n";
	for (int i = 0; i < n; i++) {
		cout << setw(2) << arr1[i] << "\t" << setw(2) << arr2[i] << endl;
		if (arr1[i] != arr2[i]) return false;
	}
	cout << "\nTest1 passed successfully\n";
	return true;
}
bool Test2() {
	int* arr1 = new int[n] {5, 9, 7, 4, 3, 8, 2, 1, 6, 0};
	int* arr2 = new int[n] {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	cout << "\nUnsorted arr1: ";
	for (int i = 0; i < n; i++, cout << " ") cout << arr1[i];
	cout << "\nUnsorted arr2: ";
	for (int i = 0; i < n; i++, cout << " ") cout << arr2[i];
	VstavkaSort(n, arr1);
	QuickSort(arr2, 0, n - 1);
	cout << "\nSorted arrays:\narr1\tarr2\n";
	for (int i = 0; i < n; i++) {
		cout << setw(2) << arr1[i] << "\t" << setw(2) << arr2[i] << endl;
		if (arr1[i] != arr2[i]) return false;
	}
	cout << "\nTest2 passed successfully\n";
	return true;
}
bool Test3() {
	int* arr1 = new int[n] {5, 9, 7, 4, 3, 8, 2, 1, 6, 0};
	int* arr2 = new int[n] {0, 1, 2, 9, 8, 7, 6, 4, 5, 3};
	cout << "\nUnsorted arr1: ";
	for (int i = 0; i < n; i++, cout << " ") cout << arr1[i];
	cout << "\nUnsorted arr2: ";
	for (int i = 0; i < n; i++, cout << " ") cout << arr2[i];
	VstavkaSort(n, arr1);
	sort(arr2, 0, n - 1);
	cout << "\nSorted arrays:\narr1\tarr2\n";
	for (int i = 0; i < n; i++) {
		cout << setw(2) << arr1[i] << "\t" << setw(2) << arr2[i] << endl;
		if (arr1[i] != arr2[i]) return false;
	}
	cout << "\nTest3 passed successfully\n";
	return true;
}
bool Test4() {
	int* arr1 = new int[n] {0, 11, 22, 33, 44, 55, 66, 77, 88, 99};
	int arr2[n] = {66, 55, 44, 33, 22, 99, 88, 77, 11, 0};
	cout << "\nSorted arr1: ";
	for (int i = 0; i < n; i++, cout << " ") cout << arr1[i];
	cout << "\nUnsorted arr2: ";
	for (int i = 0; i < n; i++, cout << " ") cout << arr2[i];
	int dop_mas[n][n];
	VstavkaSort(n, arr1);
	for (int rozr = 1; rozr < 3; rozr++) sort_rozr(dop_mas, arr2, rozr);
	cout << "\nSorted arrays:\narr1\tarr2\n";
	for (int i = 0; i < n; i++) {
		cout << setw(2) << arr1[i] << "\t" << setw(2) << arr2[i] << endl;
		if (arr1[i] != arr2[i]) return false;
	}
	cout << "\nTest4 passed successfully\n";
	return true;
}
void VstavkaSort(int n, int* mas) {
	for (int m = 0; m < n - 1; m++)
	{
		int i_min, i_max;
		i_min = i_max = m;
		//����� ���������� �� ������������� �������� � ������
		for (int i = m + 1; i < n; i++)
		{
			if (mas[i] < mas[i_min])
				i_min = i;
			/*if (mas[i] > mas[i_max])
				i_max = i;*/
		}
		//���� �������� ������
		if (m != i_min) //���� �������� ������� �� � ������������
		{
			int c = mas[m];
			mas[m] = mas[i_min];
			mas[i_min] = c;
		}

	}
}
void QuickSort(int* array, int first, int last)
//���������� ������� �������� ���������� ������
//first, last - ������� ������� � ���� ������ ������, ��� ���������
{
	int v;
	int  left, right;
	left = first; right = last;
	//left, right - �������, �� ��������� ������� ������ �������� ���� ������
	int middle = (left + right) / 2; //������� �������� ������
	v = array[middle]; //������� ������� ������� ����� �� �� �������
	while (left <= right)
	{
		//������ ����������� �������� ����� �� v
		while (array[left] < v)
			left = left + 1;
		//�������� ����������� �������� ����� �� v
		while (array[right] > v)
			right = right - 1;
		if (left <= right)
		{
			//���� �������� �� ����� ��������� ������
			int x = array[left];
			array[left] = array[right];
			array[right] = x;
			left = left + 1;
			right = right - 1;
		}
	}
	//���������� ����� ������ ������ 
	if (first < right)
		QuickSort(array, first, right);
	if (left < last)
		QuickSort(array, left, last);
}
void sort(int* array, int start, int end) //���������� ������� ���������� ������
{
	//���������� ������� - �� ���� �������, �� ������� ���� ����
	if (end > start) //����� � ������ �� ���� �������� ��� �������������
	{
		int middle = (start + end) / 2; //������� �������� ������
		sort(array, start, middle); //���������� ����� �������� ������
		sort(array, middle + 1, end); //���������� ��� �������� ������
		merge(array, start, middle, middle + 1, end); //������ ���� ������������ ������� ������
	}
}

void merge(int* array, int start_1, int end_1, int start_2, int end_2)
{
	// ������ ������������ ��������, �������������� ��������� ����� temp
	// start_1, end_1 - ������� ������� � ���� ����� �������� ������
	// start_2, end_2 - ������� ������� � ���� ��� �������� ������
	int* temp = new int[end_2 - start_1 + 1];
	int i = start_1, j = start_2, k = 0;
	//i - �������� ��� ����� �������� ������
	//j - �������� ��� ��� �������� ������
	//k - �������� � ������������� ����� temp
	while (i <= end_1 && j <= end_2)
	{
		if (array[i] < array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}
	//���� � �������� � ����� ������� ������
	while (i <= end_1)
		temp[k++] = array[i++];
	//���� � �������� � ��� ������� ������
	while (j <= end_2)
		temp[k++] = array[j++];
	//���������� ������������� ������ temp � �������� ������� ��������� ������ array
	for (int i = 0; i < k; i++)
		array[start_1 + i] = temp[i];
	delete[] temp; //��������� ���'��, ������� �� ��������� ����� temp
}
void sort_rozr(int dop_mas[n][n], int mas[n], int rozr)
{
	int mas_col[n] = {0}, i, j, temp = 0;
	/*for (i = 0; i < n; i++)
		mas_col[i] = 0;*/
	for (i = 0; i < n; i++)
	{
		int a = velich_rozr(mas[i], rozr);
		dop_mas[mas_col[a]][a] = mas[i];
		mas_col[a]++;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < mas_col[i]; j++)
		{
			mas[temp] = dop_mas[j][i];
			temp++;
		}
	}
}
int velich_rozr(int chislo, int rozr)
{
	while (rozr > 1)
	{
		chislo /= 10;
		rozr--;
	}
	return chislo % 10;
}