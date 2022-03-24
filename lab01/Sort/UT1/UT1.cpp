#include "pch.h"
#include "CppUnitTest.h"
#include "..//Sort/sort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UT1
{
	TEST_CLASS(UT1)
	{
	public:
		
		TEST_METHOD(TestBubbleSort1)
		{
			const int Size = 10;
			int Arr[Size] = { 2, 8, 5, 1, 20, 6, 4, 15, 9, 7 };
			int Sorted[Size] = { 1, 2, 4, 5, 6, 7, 8, 9, 15, 20 };
			int Reverse[Size] = { 20, 15, 9, 8, 7, 6, 5, 4, 2, 1};
			//Assert::AreEqual(Arr[4], 20);

			BublleSort(Arr, Size);
			//Assert::AreEqual(Arr[7], 9);
			for (int i = 0; i < Size; ++i) {
				Assert::AreEqual(Arr[i], Sorted[i]);
			}
			
			ReverseSortArray(Arr, Size);
			//Assert::AreEqual(Arr[9], 1);
			for (int i = 0; i < Size; ++i) {
				Assert::AreEqual(Arr[i], Reverse[i]);
			}
		}


		TEST_METHOD(TestQuickSort) {
			const int Size = 10;
			int Arr[Size] = { 2, 8, 5, 1, 20, 6, 4, 15, 9, 7 };
			int Sorted[Size] = { 1, 2, 4, 5, 6, 7, 8, 9, 15, 20 };
			int Reverse[Size] = { 20, 15, 9, 8, 7, 6, 5, 4, 2, 1};
			//Assert::AreEqual(Arr[4], 20);

			QuickSort(Arr, 0, Size - 1);
			//Assert::AreEqual(Arr[7], 9);
			for (int i = 0; i < Size; ++i) {
				Assert::AreEqual(Arr[i], Sorted[i]);
			}

			ReverseSortArray(Arr, Size);
			//Assert::AreEqual(Arr[9], 1);
			for (int i = 0; i < Size; ++i) {
				Assert::AreEqual(Arr[i], Reverse[i]);
			}
		}

		TEST_METHOD(TestShellSort) {
			const int Size = 10;
			int Arr[Size] = { 2, 8, 5, 1, 20, 6, 4, 15, 9, 7 };
			int Sorted[Size] = { 1, 2, 4, 5, 6, 7, 8, 9, 15, 20 };
			int Reverse[Size] = { 20, 15, 9, 8, 7, 6, 5, 4, 2, 1};
			//Assert::AreEqual(Arr[4], 20);

			ShellSort(Arr, Size);
			//Assert::AreEqual(Arr[7], 9);
			for (int i = 0; i < Size; ++i) {
				Assert::AreEqual(Arr[i], Sorted[i]);
			}

			ReverseSortArray(Arr, Size);
			//Assert::AreEqual(Arr[9], 1);
			for (int i = 0; i < Size; ++i) {
				Assert::AreEqual(Arr[i], Reverse[i]);
			}
		}

		TEST_METHOD(TestRadixSort) {
			const int Size = 11;
			int Arr[Size] = { 2, 8, 5, 1, 20, 6, 10, 4, 15, 9, 7 };
			int Sorted[Size] = { 1, 2, 4, 5, 6, 7, 8, 9, 10, 15, 20 };
			int Reverse[Size] = { 20, 15, 10, 9, 8, 7, 6, 5, 4, 2, 1};
			//Assert::AreEqual(Arr[4], 20);

			RadixSort(Arr, Size);
			//Assert::AreEqual(Arr[7], 9);
			for (int i = 0; i < Size; ++i) {
				Assert::AreEqual(Arr[i], Sorted[i]);
			}

			ReverseSortArray(Arr, Size);
			//Assert::AreEqual(Arr[9], 1);
			for (int i = 0; i < Size; ++i) {
				Assert::AreEqual(Arr[i], Reverse[i]);
			}
		}
	};
}
