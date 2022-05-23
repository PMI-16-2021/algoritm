#pragma once
#include"pch.h"
#include "CppUnitTest.h"
#include<iostream>
void swap(int* a, int* b);
void print(const int* array, const size_t n);
void quickSort(int* arr, const int left, const int right);
void shellSort(int* array, unsigned n);
void mergeSort(int array[], int const begin, int const end);
void merge(int array[], int const left, int const mid, int const right);
void insertionSort(int arr[], int n);
