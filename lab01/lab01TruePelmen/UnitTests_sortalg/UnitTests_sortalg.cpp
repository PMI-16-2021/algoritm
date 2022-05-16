#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab01/sortalg.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestssortalg
{
	TEST_CLASS(UnitTestssortalg)
	{
	public:
		TEST_METHOD(BubbleSortRandomArr)
		{
			const int size = 10;
			int arr[size] = { 3, 5, 1, 7, 2, 9, 4, 6, 8, 3 };
			int correct[size] = { 1, 2, 3, 3, 4, 5, 6, 7, 8, 9 };
			//int reversed[size] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
			BubbleSort(arr, size);
			for (int i = 0; i < size; ++i)
			{
				Assert::AreEqual(arr[i], correct[i]);
			}
		};
		TEST_METHOD(QuickSortRandomArr)
		{
			const int size = 10;
			int arr[size] = { 3, 5, 1, 7, 2, 9, 4, 6, 8, 3 };
			int correct[size] = { 1, 2, 3, 3, 4, 5, 6, 7, 8, 9 };
			//int reversed[size] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
			QuickSort(arr, 0, size - 1);
			for (int i = 0; i < size; ++i)
			{
				Assert::AreEqual(arr[i], correct[i]);
			}
		}
		TEST_METHOD(ShellSortRandomArr)
		{
			const int size = 10;
			int arr[size] = { 3, 5, 1, 7, 2, 9, 4, 6, 8, 3 };
			int correct[size] = { 1, 2, 3, 3, 4, 5, 6, 7, 8, 9 };
			//int reversed[size] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
			ShellSort(arr, size);
			for (int i = 0; i < size; ++i)
			{
				Assert::AreEqual(arr[i], correct[i]);
			};
		}
		TEST_METHOD(CountSortRandomArr)
		{
			const int size = 10;
			int arr[size] = { 3, 5, 1, 7, 2, 9, 4, 6, 8, 3 };
			int correct[size] = { 1, 2, 3, 3, 4, 5, 6, 7, 8, 9 };
			//int reversed[size] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
			CountSort(arr, size);
			for (int i = 0; i < size; ++i)
			{
				Assert::AreEqual(arr[i], correct[i]);
			}
		}
	};
}