#include "pch.h"
#include "CppUnitTest.h"
#include"Functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	const size_t n = 10;
	int array[] = { 23,11,5,70,12,3,9,81,37,6 };
	int reversedArray[] = { 81,70,37,23,12,11,9,6,5,3 };
	int result[] = { 3,5,6,9,11,12,23,37,70,81 };
	TEST_CLASS(UnitTest1)
	{
	public:
		
		
		TEST_METHOD(TestQuickSort)
		{
			
			quickSort(array, 0, n - 1);
			for (int i = 0; i < n; ++i)
			{
				Assert::AreEqual(array[i], result[i]);
			}
			quickSort(reversedArray, 0, n - 1);
			for (int i = 0; i < n; ++i)
			{
				Assert::AreEqual(reversedArray[i],result[i]);
			}
		}
		
		TEST_METHOD(TestShellSort)
		{
			
			shellSort(array, n);
			for (int i = 0; i < n; ++i)
			{
				Assert::AreEqual(array[i], result[i]);
			}
			shellSort(array, n);
			for (int i = 0; i < n; ++i)
			{
				Assert::AreEqual(reversedArray[i], result[i]);
			}
		
		}
		
		TEST_METHOD(TestMergeSort)
		{
			
			mergeSort(array, 0, n - 1);
			for (int i = 0; i < n; ++i)
			{
				Assert::AreEqual(array[i], result[i]);
			}
			mergeSort(reversedArray, 0,n-1);
			for (int i = 0; i < n; ++i)
			{
				Assert::AreEqual(reversedArray[i], result[i]);
			}

		}
		TEST_METHOD(TestInsertionSort)
		{
			
			insertionSort(array,n);
			for (int i = 0; i < n; ++i)
			{
				Assert::AreEqual(array[i], result[i]);
			}
			insertionSort(reversedArray, n);
			for (int i = 0; i < n; ++i)
			{
				Assert::AreEqual(reversedArray[i], result[i]);
			}

		}
	};
}
