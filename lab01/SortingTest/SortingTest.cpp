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
			int arr[size] = { 48, 73, 10, -5, 14, 106, 43, 40, 0, 60 };

			InsertSort(arr, size);

			Assert::AreEqual(-5, arr[0]);
			Assert::AreEqual(0, arr[1]);
			Assert::AreEqual(106, arr[9]);
		}

		TEST_METHOD(Reverse_Array_Testing_insertSort)
		{
			const int size = 10;
			int arr_forward[size] = { 48, 73, 10, -5, 14, 106, 43, 40, 0, 60 };
			int arr_reverse[size] = {106, 73, 60, 48, 43, 40, 14, 10, 0, -5 };
			InsertSort(arr_forward, size);
			InsertSort(arr_reverse, size);
			for (int i = 0; i < size; ++i) Assert::AreEqual(arr_forward[i], arr_reverse[i]);
		}


		TEST_METHOD(Exceptions_Classes_Check_insertSort)
		{
			const int size = 10;
			int fake_size = -3;
			int arr[size] = { 7, 9, 1, 4, 8, 3, 0, 5, 6, 2 };
			
			//BadSize test
			try
			{
				InsertSort(arr, fake_size);
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
				InsertSort(fake_arr, size);
				Assert::Fail(); // if func doesn't throw exception => FAIL!
			}
			catch (const BadPointer&) {}
		}

		////////////////////QUICKSORT
		TEST_METHOD(Random_array_testing_Quicksort)
		{
			const int size = 10;
			int arr[size] = { 48, 73, 10, -5, 14, 106, 43, 40, 0, 60 };

			QuickSort(arr, 0, size);

			Assert::AreEqual(-5, arr[0]);
			Assert::AreEqual(0, arr[1]);
			Assert::AreEqual(106, arr[9]);
			
		}

		TEST_METHOD(Reverse_Array_Testing_Quicksort)
		{
			const int size = 10;
			int arr_forward[size] = { 48, 73, 10, -5, 14, 106, 43, 40, 0, 60 };
			int arr_reverse[size] = { 106, 73, 60, 48, 43, 40, 14, 10, 0, -5 };
			QuickSort(arr_forward, 0, size);
			QuickSort(arr_reverse, 0, size);
			for (int i = 0; i < size; ++i) Assert::AreEqual(arr_forward[i], arr_reverse[i]);
			
			
		}
		
		TEST_METHOD(Exceptions_Classes_Check_Quicksort)
		{
			const int size = 10;
			int fake_index = -3;
			int arr[size] = { 7, 9, 1, 4, 8, 3, 0, 5, 6, 2 };

			//BadSize test
			try
			{
				QuickSort(arr, fake_index, size);
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
				QuickSort(fake_arr, 0, size);
				Assert::Fail(); // if func doesn't throw exception => FAIL!
			}
			catch (const BadPointer&) {}
		}
	    ///////////////////ShellSorting
		TEST_METHOD(Random_array_testing_Shellsorting)
		{
			const int size = 10;
			int arr[size] = { 48, 73, 10, -5, 14, 106, 43, 40, 0, 60 };

			
			ShellSorting(arr, size);

			Assert::AreEqual(-5, arr[0]);
			Assert::AreEqual(0, arr[1]);
			Assert::AreEqual(106, arr[9]);

		}

		TEST_METHOD(REverse_array_testing_ShellSorting)
		{
			const int size = 10;
			int arr_forward[size] = { 48, 73, 10, -5, 14, 106, 43, 40, 0, 60 };
			int arr_reverse[size] = { 106, 73, 60, 48, 43, 40, 14, 10, 0, -5 };
			ShellSorting(arr_forward, size);
			ShellSorting(arr_reverse, size);
			for (int i = 0; i < size; ++i) Assert::AreEqual(arr_forward[i], arr_reverse[i]);

		}

		TEST_METHOD(ExceptionClasses_Check_ShellSorting)
		{
		
			const int size = 10;
			int bad_size = -3;
			int arr[size] = { 7, 9, 1, 4, 8, 3, 0, 5, 6, 2 };

			//BadSize test
			try
			{
				ShellSorting(arr, bad_size);
				Assert::Fail(); // if func doesn't throw exception => FAIL!
			}
			catch (const BadSize& A)
			{
				Assert::AreEqual(-3, A.returnField()); // chech if Exception class catches incorrect argument to .report()
			}
			// BadPointer test
			int* fake_arr = nullptr;
			try
			{
				ShellSorting(fake_arr, size);
				Assert::Fail(); // if func doesn't throw exception => FAIL!
			}
			catch (const BadPointer&) {}
		}

		////////////////////////CountSorting
		TEST_METHOD(Random_array_testing_CountSorting)
		{
			const int size = 10;
			int arr[size] = { 48, 73, 10, -5, 14, 106, 43, 40, 0, 60 };

			CountSorting(arr, size);

			Assert::AreEqual(-5, arr[0]);
			Assert::AreEqual(0, arr[1]);
			Assert::AreEqual(106, arr[9]);
		}

		TEST_METHOD(Reverse_Array_Testing_CountSorting)
		{
			const int size = 10;
			int arr_forward[size] = { 48, 73, 10, -5, 14, 106, 43, 40, 0, 60 };
			int arr_reverse[size] = { 106, 73, 60, 48, 43, 40, 14, 10, 0, -5 };
			CountSorting(arr_forward, size);
			CountSorting(arr_reverse, size);
			for (int i = 0; i < size; ++i) Assert::AreEqual(arr_forward[i], arr_reverse[i]);
		}

		TEST_METHOD(Exceptions_Classes_Check_CountSorting)
		{
			const int size = 10;
			int fake_size = -3;
			int arr[size] = { 7, 9, 1, 4, 8, 3, 0, 5, 6, 2 };

			//BadSize test
			try
			{
				CountSorting(arr, fake_size);
				Assert::Fail(); // if func doesn't throw exception => FAIL!
			}
			catch (const BadSize& A)
			{
				Assert::AreEqual(A.returnField(), -3); // chech if Exception class catches incorrect argument to .report()
			}

			// BadPointer test
			int* fake_arr = nullptr;
			try
			{
				CountSorting(fake_arr, size);
				Assert::Fail(); // if func doesn't throw exception => FAIL!
			}
			catch (const BadPointer&) {}
		}
	};



}
