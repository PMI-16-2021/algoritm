#include "pch.h"
#include "CppUnitTest.h"
#include"..\Sorts\sorts.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortsTest
{
	TEST_CLASS(SortsTest)
	{
	public:
		
		TEST_METHOD(Random_Bubble) {
			const size_t size = 10;
			int array[size] = { -4, -1, 7, 4, 9, 3, 4, -10, 0, -5 };
			int sorted_array[size] = { -10, -5, -4, -1, 0, 3, 4, 4, 7, 9 };
			BubbleSort(array, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], sorted_array[i]);
			}
		}

		TEST_METHOD(Reverse_Bubble) {
			const size_t size = 10;
			int array[size] = { 9, 7, 4, 4, 3, 0, -1, -4, -5, -10 };
			int sorted_array[size] = { -10, -5, -4, -1, 0, 3, 4, 4, 7, 9 };
			BubbleSort(array, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], sorted_array[i]);
			}
		}

		TEST_METHOD(Sorted_Bubble) {
			const size_t size = 10;
			int array[size] = { -10, -5, -4, -1, 0, 3, 4, 4, 7, 9 };
			int sorted_array[size] = { -10, -5, -4, -1, 0, 3, 4, 4, 7, 9 };
			BubbleSort(array, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], sorted_array[i]);
			}
		}

		TEST_METHOD(Random_Quick) {
			const size_t size = 10;
			int array[size] = { -4, -1, 7, 4, 9, 3, 4, -10, 0, -5 };
			int sorted_array[size] = { -10, -5, -4, -1, 0, 3, 4, 4, 7, 9 };
			QuickSort(array, 0, size - 1);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], sorted_array[i]);
			}
		}

		TEST_METHOD(Reverse_Quick) {
			const size_t size = 10;
			int array[size] = { 9, 7, 4, 4, 3, 0, -1, -4, -5, -10 };
			int sorted_array[size] = { -10, -5, -4, -1, 0, 3, 4, 4, 7, 9 };
			QuickSort(array, 0, size - 1);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], sorted_array[i]);
			}
		}

		TEST_METHOD(Sorted_Quick) {
			const size_t size = 10;
			int array[size] = { -10, -5, -4, -1, 0, 3, 4, 4, 7, 9 };
			int sorted_array[size] = { -10, -5, -4, -1, 0, 3, 4, 4, 7, 9 };
			QuickSort(array, 0, size - 1);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], sorted_array[i]);
			}
		}

		TEST_METHOD(Random_Count) {
			const size_t size = 10;
			int array[size] = { -4, -1, 7, 4, 9, 3, 4, -10, 0, -5 };
			int sorted_array[size] = { -10, -5, -4, -1, 0, 3, 4, 4, 7, 9 };
			CountSort(array, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], sorted_array[i]);
			}
		}

		TEST_METHOD(Reverse_Count) {
			const size_t size = 10;
			int array[size] = { 9, 7, 4, 4, 3, 0, -1, -4, -5, -10 };
			int sorted_array[size] = { -10, -5, -4, -1, 0, 3, 4, 4, 7, 9 };
			CountSort(array, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], sorted_array[i]);
			}
		}

		TEST_METHOD(Sorted_Count) {
			const size_t size = 10;
			int array[size] = { -10, -5, -4, -1, 0, 3, 4, 4, 7, 9 };
			int sorted_array[size] = { -10, -5, -4, -1, 0, 3, 4, 4, 7, 9 };
			CountSort(array, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], sorted_array[i]);
			}
		}

		TEST_METHOD(Random_Shell) {
			const size_t size = 10;
			int array[size] = { -4, -1, 7, 4, 9, 3, 4, -10, 0, -5 };
			int sorted_array[size] = { -10, -5, -4, -1, 0, 3, 4, 4, 7, 9 };
			ShellSort(array, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], sorted_array[i]);
			}
		}

		TEST_METHOD(Reverse_Shell) {
			const size_t size = 10;
			int array[size] = { 9, 7, 4, 4, 3, 0, -1, -4, -5, -10 };
			int sorted_array[size] = { -10, -5, -4, -1, 0, 3, 4, 4, 7, 9 };
			ShellSort(array, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], sorted_array[i]);
			}
		}

		TEST_METHOD(Sorted_Shell) {
			const size_t size = 10;
			int array[size] = { -10, -5, -4, -1, 0, 3, 4, 4, 7, 9 };
			int sorted_array[size] = { -10, -5, -4, -1, 0, 3, 4, 4, 7, 9 };
			ShellSort(array, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], sorted_array[i]);
			}
		}
	};
}
