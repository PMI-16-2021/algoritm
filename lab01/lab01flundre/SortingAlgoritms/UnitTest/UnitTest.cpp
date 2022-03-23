#include "pch.h"
#include "CppUnitTest.h"
#include "..//SortingAlgoritms/sorts.h"
#include "..//SortingAlgoritms/sorts.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		TEST_METHOD(BubbleSortTest1)
		{
			const int n = 10;
			int test_array[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			BubbleSort(test_array, n);
			Assert::AreEqual(test_array[0], 1);
		}

		TEST_METHOD(BubbleSortTest2)
		{
			const int n = 10;
			int test_array[n] = { 10, 9, 8, 7, 6, 5, 5, 3, 2, 1 };
			BubbleSort(test_array, n);
			Assert::AreEqual(test_array[0], 1);
		}

		TEST_METHOD(BubbleSortTest3)
		{
			const int n = 10;
			int test_array[n] = { 4, 2, 1, 6, 5, 9, 7, 8, 3, 10 };
			BubbleSort(test_array, n);
			Assert::AreEqual(test_array[0], 1);
		}

		TEST_METHOD(QuickSortTest1)
		{
			const int n = 10;
			int test_array[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			QuickSort(test_array, 0, 9);
			Assert::AreEqual(test_array[0], 1);
		}

		TEST_METHOD(QuickSortTest2)
		{
			const int n = 10;
			int test_array[n] = { 10, 9, 8, 7, 6, 5, 5, 3, 2, 1 };
			QuickSort(test_array, 0, 9);
			Assert::AreEqual(test_array[0], 1);
		}

		TEST_METHOD(QuickSortTest3)
		{
			const int n = 10;
			int test_array[n] = { 4, 2, 1, 6, 5, 9, 7, 8, 3, 10 };
			QuickSort(test_array, 0, 9);
			Assert::AreEqual(test_array[0], 1);
		}

		TEST_METHOD(CountingSortTest1)
		{
			const int n = 10;
			int test_array[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			CountingSort(test_array, 10);
			Assert::AreEqual(test_array[0], 1);
		}

		TEST_METHOD(CountingSortTest2)
		{
			const int n = 10;
			int test_array[n] = { 10, 9, 8, 7, 6, 5, 5, 3, 2, 1 };
			CountingSort(test_array, 10);
			Assert::AreEqual(test_array[0], 1);
		}

		TEST_METHOD(CountingSortTest3)
		{
			const int n = 10;
			int test_array[n] = { 4, 2, 1, 6, 5, 9, 7, 8, 3, 10 };
			CountingSort(test_array, 10);
			Assert::AreEqual(test_array[0], 1);
		}

		TEST_METHOD(ShellSortTest1)
		{
			const int n = 10;
			int test_array[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			ShellSort(test_array, 10);
			Assert::AreEqual(test_array[0], 1);
		}

		TEST_METHOD(ShellSortTest2)
		{
			const int n = 10;
			int test_array[n] = { 10, 9, 8, 7, 6, 5, 5, 3, 2, 1 };
			ShellSort(test_array, 10);
			Assert::AreEqual(test_array[0], 1);
		}

		TEST_METHOD(ShellSortTest3)
		{
			const int n = 10;
			int test_array[n] = { 4, 2, 1, 6, 5, 9, 7, 8, 3, 10 };
			ShellSort(test_array, 10);
			Assert::AreEqual(test_array[0], 1);
		}
		

	};
}
