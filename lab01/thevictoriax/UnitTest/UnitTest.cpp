#include "pch.h"
#include "CppUnitTest.h"
#include "..//lab01/sorting.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(BubbleSortTest)
		{
			
			const int size = 5;
			int data[] = { 7, 4, 11, 5, 17 };
			Assert::AreEqual(data[3], 5);

			BubbleSort(data, size);
			Assert::AreEqual(data[1], 5);

			ReverseArray(data, size);
			Assert::AreEqual(data[0], 17);
			
		}

		TEST_METHOD(QuickSortTest)
		{

			const int size = 5;
			int data[] = { 7, 4, 11, 5, 17 };
			Assert::AreEqual(data[3], 5);

			QuickSort(data, 0, size - 1);
			Assert::AreEqual(data[1], 5);

			ReverseArray(data, size);
			Assert::AreEqual(data[0], 17);

		}

		TEST_METHOD(ShellSortTest)
		{

			const int size = 5;
			int data[] = { 7, 4, 11, 5, 17 };
			Assert::AreEqual(data[3], 5);

			ShellSort(data, size);
			Assert::AreEqual(data[1], 5);

			ReverseArray(data, size);
			Assert::AreEqual(data[0], 17);

		}

		TEST_METHOD(RadixSortTest)
		{

			const int size = 5;
			int data[] = { 7, 4, 11, 5, 17 };
			Assert::AreEqual(data[3], 5);

			RadixSort(data, size);
			Assert::AreEqual(data[1], 5);

			ReverseArray(data, size);
			Assert::AreEqual(data[0], 17);

		}
	};
}
