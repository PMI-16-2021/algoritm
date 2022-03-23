#include "pch.h"
#include "CppUnitTest.h"
#include "..//Sort/sort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{
	TEST_CLASS(Test)
	{
	public:
		//BubbleSort 
		TEST_METHOD(RandomBubbleSort) {
			const size_t size = 5;
			int array[size] = { 2, 9, 1, 3, 6 };
			int sorted_array[size] = { 1, 2, 3, 6, 9 };
			BubbleSort(array, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], sorted_array[i]);
			}
		}
		TEST_METHOD(ReserveBubbleSort) {
			const size_t size = 5;
			int array[size] = { 9, 6, 3, 2, 1 };
			int sorted_array[size] = { 1, 2, 3, 6, 9 };
			BubbleSort(array, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], sorted_array[i]);
			}
		}
		TEST_METHOD(OrderedBubbleSort) {
			const size_t size = 5;
			int array[size] = { 1, 2, 3, 6, 9 };
			int sorted_array[size] = { 1, 2, 3, 6, 9 };
			BubbleSort(array, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], sorted_array[i]);
			}
		}
		//QuickSort
		TEST_METHOD(RandomQuickSort) {
			const size_t size = 5;
			int array[size] = { 2, 6, 1, 9, 3 };
			int sorted_array[size] = { 1, 2, 3, 6, 9 };
			QuickSort(array, 0, size - 1);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], sorted_array[i]);
			}
		}
		TEST_METHOD(ReserveQuickSort) {
			const size_t size = 5;
			int array[size] = { 9, 6, 3, 2, 1 };
			int sorted_array[size] = { 1, 2, 3, 6, 9 };
			QuickSort(array, 0, size - 1);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], sorted_array[i]);
			}
		}
		TEST_METHOD(OrderedQuickSort) {
			const size_t size = 5;
			int array[size] = { 2, 6, 1, 9, 3 };
			int sorted_array[size] = { 1, 2, 3, 6, 9 };
			QuickSort(array, 0, size - 1);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], sorted_array[i]);
			}
		}
		//CountingSort
		TEST_METHOD(RandomCountingSort) {
			const size_t size = 5;
			int array[size] = { 2, 3, 6, 3, 2 };
			int sorted_array[size] = { 2, 2, 3, 3, 6 };
			CountingSort(array, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], sorted_array[i]);
			}
		}
		TEST_METHOD(ReserveCountingSort) {
			const size_t size = 5;
			int array[size] = { 6, 3, 3, 2, 2 };
			int sorted_array[size] = { 2, 2, 3, 3, 6 };
			CountingSort(array, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], sorted_array[i]);
			}
		}
		TEST_METHOD(OrderedCountingSort) {
			const size_t size = 5;
			int array[size] = { 2, 2, 3, 3, 6 };
			int sorted_array[size] = { 2, 2, 3, 3, 6 };
			CountingSort(array, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], sorted_array[i]);
			}
		}
		//ShellSort
		TEST_METHOD(RandomShellSort) {
			const size_t size = 5;
			int array[size] = { 2, 6, 1, 9, 3 };
			int sorted_array[size] = { 1, 2, 3, 6, 9 };
			ShellSort(array, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], sorted_array[i]);
			}
		}
		TEST_METHOD(ReserveShellSort) {
			const size_t size = 5;
			int array[size] = { 9, 6, 3, 2, 1 };
			int sorted_array[size] = { 1, 2, 3, 6, 9 };
			ShellSort(array, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], sorted_array[i]);
			}
		}
		TEST_METHOD(OrderedShellSort) {
			const size_t size = 5;
			int array[size] = { 1, 2, 3, 6, 9 };
			int sorted_array[size] = { 1, 2, 3, 6, 9 };
			ShellSort(array, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], sorted_array[i]);
			}
		}

	};
}
