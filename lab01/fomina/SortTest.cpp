#include "pch.h"
#include "CppUnitTest.h"
#include "..//sorting/sort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;



namespace SortTest
{
	TEST_CLASS(SortTest)
	{
	public:
		
		TEST_METHOD(SelectionSort1)
		{
			int n = 10;
			int* arr = new int [n] { 1, 6, 4, 3, 0, 5, 9, 8, 7, 2 };
			int* arrRes = new int [n] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			SelectionSort(arr, n);
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(arrRes[i], arr[i]);
			}
		}
		TEST_METHOD(SelectionSort2)
		{
			int n = 7;
			int* arr = new int [n] { 85, -5, 4, 0, 96, 4, 7};
			int* arrRes = new int [n] {-5, 0, 4, 4, 7, 85, 96 };
			SelectionSort(arr, n);
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(arrRes[i], arr[i]);
			}
		}
		TEST_METHOD(SelectionSort3)
		{
			int n = 10;
			int* arr = new int [n] { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
			int* arrRes = new int [n] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			SelectionSort(arr, n);
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(arrRes[i], arr[i]);
			}
		}



		TEST_METHOD(QuickSort1)
		{
			int n = 10;
			int* arr = new int [n] { 1, 6, 4, 3, 0, 5, 9, 8, 7, 2 };
			int* arrRes = new int [n] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			QuickSort(arr, n);
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(arrRes[i], arr[i]);
			}
		}
		TEST_METHOD(QuickSort2)
		{
			int n = 7;
			int* arr = new int [n] { 85, -5, 4, 0, 96, 4, 7};
			int* arrRes = new int [n] {-5, 0, 4, 4, 7, 85, 96 };
			QuickSort(arr, n);
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(arrRes[i], arr[i]);
			}
		}
		TEST_METHOD(QuickSort3)
		{
			int n = 10;
			int* arr = new int [n] { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
			int* arrRes = new int [n] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			QuickSort(arr, n);
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(arrRes[i], arr[i]);
			}
		}

		TEST_METHOD(CountSort1)
		{
			int n = 10;
			int* arr = new int [n] { 1, 6, 4, 3, 0, 5, 9, 8, 7, 2 };
			int* arrRes = new int [n] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			CountSort(arr, n);
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(arrRes[i], arr[i]);
			}
		}
		TEST_METHOD(CountSort2)
		{
			int n = 7;
			int* arr = new int [n] { 85, -5, 4, 0, 96, 4, 7};
			int* arrRes = new int [n] {-5, 0, 4, 4, 7, 85, 96 };
			CountSort(arr, n);
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(arrRes[i], arr[i]);
			}
		}
		TEST_METHOD(CountSort3)
		{
			int n = 10;
			int* arr = new int [n] { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
			int* arrRes = new int [n] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			CountSort(arr, n);
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(arrRes[i], arr[i]);
			}
		}

		TEST_METHOD(ShellSort1)
		{
			int n = 10;
			int* arr = new int [n] { 1, 6, 4, 3, 0, 5, 4, 8, 7, 2 };
			int* arrRes = new int [n] { 0, 1, 2, 3, 4, 4, 5, 6, 7, 8 };
			ShellSort(arr, n);
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(arrRes[i], arr[i]);
			}
		}
		TEST_METHOD(ShellSort2)
		{
			int n = 7;
			int* arr = new int [n] { 85, -5, 4, 0, 96, 4, 7};
			int* arrRes = new int [n] {-5, 0, 4, 4, 7, 85, 96 };
			ShellSort(arr, n);
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(arrRes[i], arr[i]);
			}
		}
		TEST_METHOD(ShellSort3)
		{
			int n = 10;
			int* arr = new int [n] { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
			int* arrRes = new int [n] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			ShellSort(arr, n);
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(arrRes[i], arr[i]);
			}
		}
	};
	
}
