#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab01/algos.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortingTest
{
	TEST_CLASS(SORTINGS_TESTS) 
	{
	public:
		
		///////////////////////INSERT SORT
		
		TEST_METHOD(Random_array_testing_insertSort)
		{
			const int size = 10;
			int arr[size] = { 7, 9, 1, 4, 8, 3, 0, 5, 6, 2  };

			insertSort(arr, size);

			for (int i = 0; i < size; ++i) Assert::AreEqual(i, arr[i]);
		}

		TEST_METHOD(Reverse_Array_Testing_insertSort)
		{
			const int size = 10;
			int arr[size] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
			insertSort(arr, size);
			for (int i = 0; i < size; ++i) Assert::AreEqual(i, arr[i]);
		}


		TEST_METHOD(Exceptions_Classes_Check_insertSort)
		{
			const int size = 10;
			int fake_size = -3;
			int arr[size] = { 7, 9, 1, 4, 8, 3, 0, 5, 6, 2 };
			
			//BadSize test
			try
			{
				insertSort(arr, fake_size);
				Assert::Fail(); // if func doesn't throw exception => FAIL!
			}
			catch (const BadSize& A) 
			{
				Assert::AreEqual(A.returnField(),-3 ); // chech if Exception class catches incorrect argument to .report()
			}

			// BadPointer test
			int* fake_arr = nullptr;
			try
			{
				insertSort(fake_arr, size);
				Assert::Fail(); // if func doesn't throw exception => FAIL!
			}
			catch (const BadPointer&) {}
		}

		/////////////////QUICKSORT
		TEST_METHOD(Random_array_testing_Quicksort)
		{
			const int size = 10;
			int arr[size] = { 7, 9, 1, 4, 8, 3, 0, 5, 6, 2 };

			QuickSort(arr, 0, size - 1);

			for (int i = 0; i < size; ++i) Assert::AreEqual(i, arr[i]);
		}

		TEST_METHOD(Reverse_Array_Testing_Quicksort)
		{
			const int size = 10;
			int arr[size] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
			QuickSort(arr, 0, size - 1);
			for (int i = 0; i < size; ++i) Assert::AreEqual(i, arr[i]);
		}


		TEST_METHOD(Exceptions_Classes_Check_Quicksort)
		{
			const int size = 10;
			int fake_index = -3;
			int arr[size] = { 7, 9, 1, 4, 8, 3, 0, 5, 6, 2 };

			//BadSize test
			try
			{
				QuickSort(arr, fake_index, size - 1);
				Assert::Fail(); // if func doesn't throw exception => FAIL!
			}
			catch (const BadIndex& A)
			{
				Assert::AreEqual(A.returnField(), -3); // chech if Exception class catches incorrect argument to .report()
			}

			// BadPointer test
			int* fake_arr = nullptr;
			try
			{
				QuickSort(fake_arr, 0, size - 1);
				Assert::Fail(); // if func doesn't throw exception => FAIL!
			}
			catch (const BadPointer&) {}

		}



		
	};



}
