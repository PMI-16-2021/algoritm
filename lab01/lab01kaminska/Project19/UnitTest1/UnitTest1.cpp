#include "pch.h"
#include "CppUnitTest.h"
#include "..\Project19\sort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestGetMax){
			const int size = 6;
			int array[size] = { 6,2,7,1,9,4 };

			Assert::AreEqual(getMax(array, size), 9);
		}

		TEST_METHOD(TestSwap) {
			const int size = 6;
			int array[size] = { 6,2,7,1,9,4 };

			swap(&array[0], &array[1]);
			Assert::AreEqual(array[0], 2);
			Assert::AreEqual(array[1], 6);
		}

		TEST_METHOD(TestBubbleSort) {
			const int size = 6;
			int array[size] = { 6,2,7,1,9,4 };
			int reversedArray[size] = { 4,9,1,7,2,6 };
			int sortedArray[size] = { 1,2,4,6,7,9 };
			int reversedSortedArray[size] = { 9,7,6,4,2,1 };

			reverseArray(array, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], reversedArray[i]);
			}

			bubbleSort(array, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], sortedArray[i]);
			}

			reverseArray(array, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], reversedSortedArray[i]);
			}
		}

		TEST_METHOD(TestQuickSort) {
			const int size = 6;
			int array[size] = { 6,2,7,1,9,4 };
			int reversedArray[size] = { 4,9,1,7,2,6 };
			int sortedArray[size] = { 1,2,4,6,7,9 };
			int reversedSortedArray[size] = { 9,7,6,4,2,1 };

			reverseArray(array, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], reversedArray[i]);
			}

			quickSort(array, 0, size - 1);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], sortedArray[i]);
			}

			reverseArray(array, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], reversedSortedArray[i]);
			}
		}

		TEST_METHOD(TestCountSort) {
			const int size = 6;
			int array[size] = { 6,2,7,1,9,4 };
			int reversedArray[size] = { 4,9,1,7,2,6 };
			int sortedArray[size] = { 1,2,4,6,7,9 };
			int reversedSortedArray[size] = { 9,7,6,4,2,1 };

			reverseArray(array, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], reversedArray[i]);
			}

			countSort(array, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], sortedArray[i]);
			}

			reverseArray(array, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], reversedSortedArray[i]);
			}
		}

		TEST_METHOD(TestShellSort) {
			const int size = 6;
			int array[size] = { 6,2,7,1,9,4 };
			int reversedArray[size] = { 4,9,1,7,2,6 };
			int sortedArray[size] = { 1,2,4,6,7,9 };
			int reversedSortedArray[size] = { 9,7,6,4,2,1 };

			reverseArray(array, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], reversedArray[i]);
			}

			shellSort(array, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], sortedArray[i]);
			}

			reverseArray(array, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], reversedSortedArray[i]);
			}
		}
	};
}
