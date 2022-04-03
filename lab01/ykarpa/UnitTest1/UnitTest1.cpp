#include "pch.h"
#include "CppUnitTest.h"
#include "..//лр1/functions.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1 {
	TEST_CLASS(UnitTest1) {
	public:
		TEST_METHOD(TestBubbleSort) {
			const size_t size = 6;
			int array[] = { 5, 1, 2, 8, 14, 9 };
			int reverseArray[] = { 14, 9, 8, 5, 2, 1 };
			int sortedArray[] = { 1, 2, 5, 8, 9, 14 };
			int result[] = { 1, 2, 5, 8, 9, 14 };

			bubbleSort(array, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], result[i]);
			}

			bubbleSort(reverseArray, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(reverseArray[i], result[i]);
			}

			bubbleSort(sortedArray, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(sortedArray[i], result[i]);
			}
		}
		TEST_METHOD(TestQuickSort) {
			const size_t size = 6;
			int array[] = { 5, 1, 2, 8, 14, 9 };
			int reverseArray[] = { 14, 9, 8, 5, 2, 1 };
			int sortedArray[] = { 1, 2, 5, 8, 9, 14 };
			int result[] = { 1, 2, 5, 8, 9, 14 };

			quickSort(array, 0, size - 1);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], result[i]);
			}

			quickSort(reverseArray, 0, size - 1);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(reverseArray[i], result[i]);
			}

			quickSort(sortedArray, 0, size - 1);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(sortedArray[i], result[i]);
			}
		}
		TEST_METHOD(TestCountSort) {
			const int size = 6;
			int array[] = { 5, 1, 2, 8, 14, 9 };
			int reverseArray[] = { 14, 9, 8, 5, 2, 1 };
			int sortedArray[] = { 1, 2, 5, 8, 9, 14 };
			int result[] = { 1, 2, 5, 8, 9, 14 };

			countSort(array, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], result[i]);
			}

			countSort(reverseArray, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(reverseArray[i], result[i]);
			}

			countSort(sortedArray, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(sortedArray[i], result[i]);
			}
		}
		TEST_METHOD(TestShellSort) {
			const int size = 6;
			int array[] = { 5, 1, 2, 8, 14, 9 };
			int reverseArray[] = { 14, 9, 8, 5, 2, 1 };
			int sortedArray[] = { 1, 2, 5, 8, 9, 14 };
			int result[] = { 1, 2, 5, 8, 9, 14 };

			shellSort(array, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(array[i], result[i]);
			}

			shellSort(reverseArray, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(reverseArray[i], result[i]);
			}

			shellSort(sortedArray, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(sortedArray[i], result[i]);
			}
		}
	};
}