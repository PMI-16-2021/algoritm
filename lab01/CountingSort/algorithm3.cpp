#include <iostream>
#include "algorithm3.h"
using namespace std;

void countSort(int array[], int size) {
    // ����� ��������� �� ���� �������� (max+1),���
    // �� �� ������ ��������� ���� �� int count(max+1) � C++ ���� ��
    // �� �� ������� �������� �������� ���'��.
    // ����, ���� ����� �������� ��������.
    int output[10];
    int count[10];
    int max = array[0];

    // ������ ��������� ������� ������
    for (int i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    // ���������� �������� ����� ���� ������.
    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    // ������ ������� ������� ��������
    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    // ������ ����������� ������� ������� ������
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // ������ ������ ������� �������� ��������� ������ � ����� count, �
        // �������� �������� � ��������� �����
    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // ������� ���������� �������� � ����������� �����
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}