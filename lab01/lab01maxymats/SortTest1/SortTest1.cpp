#include "pch.h"
#include "CppUnitTest.h"
#include "..//SortTest/Sort.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortTest1
{
	TEST_CLASS(SortTest1)
	{
	public:

		TEST_METHOD(TestBubbleSort1)
		{
			const int SIZE = 10;
			int Arr[SIZE] = { 2, 8, 5, 1, 20, 6, 4, 15, 9, 7 };
			int Sorted[SIZE] = { 1, 2, 4, 5, 6, 7, 8, 9, 15, 20 };
			int Reverse[SIZE] = { 20, 15, 9, 8, 7, 6, 5, 4, 2, 1 };
			//Assert::AreEqual(Arr[4], 20);

			BubbleSort(Arr, SIZE);
			//Assert::AreEqual(Arr[7], 9);
			for (int i = 0; i < SIZE; ++i) {
				Assert::AreEqual(Arr[i], Sorted[i]);
			}

			ReverseArray(Arr, SIZE);
			//Assert::AreEqual(Arr[9], 1);
			for (int i = 0; i < SIZE; ++i) {
				Assert::AreEqual(Arr[i], Reverse[i]);
			}
		}


		TEST_METHOD(TestQuickSort) {
			const int SIZE = 10;
			int Arr[SIZE] = { 2, 8, 5, 1, 20, 6, 4, 15, 9, 7 };
			int Sorted[SIZE] = { 1, 2, 4, 5, 6, 7, 8, 9, 15, 20 };
			int Reverse[SIZE] = { 20, 15, 9, 8, 7, 6, 5, 4, 2, 1 };
			//Assert::AreEqual(Arr[4], 20);

			QuickSort(Arr, 0, SIZE - 1);
			//Assert::AreEqual(Arr[7], 9);
			for (int i = 0; i < SIZE; ++i) {
				Assert::AreEqual(Arr[i], Sorted[i]);
			}

			ReverseArray(Arr, SIZE);
			//Assert::AreEqual(Arr[9], 1);
			for (int i = 0; i < SIZE; ++i) {
				Assert::AreEqual(Arr[i], Reverse[i]);
			}
		}

		TEST_METHOD(TestShellSort) {
			const int SIZE = 10;
			int Arr[SIZE] = { 2, 8, 5, 1, 20, 6, 4, 15, 9, 7 };
			int Sorted[SIZE] = { 1, 2, 4, 5, 6, 7, 8, 9, 15, 20 };
			int Reverse[SIZE] = { 20, 15, 9, 8, 7, 6, 5, 4, 2, 1 };
			//Assert::AreEqual(Arr[4], 20);

			ShellSort(Arr, SIZE);
			//Assert::AreEqual(Arr[7], 9);
			for (int i = 0; i < SIZE; ++i) {
				Assert::AreEqual(Arr[i], Sorted[i]);
			}

			ReverseArray(Arr, SIZE);
			//Assert::AreEqual(Arr[9], 1);
			for (int i = 0; i < SIZE; ++i) {
				Assert::AreEqual(Arr[i], Reverse[i]);
			}
		}

		TEST_METHOD(TestRadixSort) {
			const int SIZE = 10;
			int Arr[SIZE] = { 2, 8, 5, 1, 20, 6, 4, 15, 9, 7 };
			int Sorted[SIZE] = { 1, 2, 4, 5, 6, 7, 8, 9, 15, 20 };
			int Reverse[SIZE] = { 20, 15, 9, 8, 7, 6, 5, 4, 2, 1 };

			RadixSort(Arr, SIZE);
			//Assert::AreEqual(Arr[7], 9);
			for (int i = 0; i < SIZE; ++i) {
				Assert::AreEqual(Arr[i], Sorted[i]);
			}

			ReverseArray(Arr, SIZE);
			//Assert::AreEqual(Arr[9], 1);
			for (int i = 0; i < SIZE; ++i) {
				Assert::AreEqual(Arr[i], Reverse[i]);
			}
		}
	};
}