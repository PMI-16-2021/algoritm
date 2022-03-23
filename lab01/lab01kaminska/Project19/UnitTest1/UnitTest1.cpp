#include "pch.h"
#include "CppUnitTest.h"
#include "..\Project19\sort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestBubbleSort){
			const int size = 6;
			int array[size] = { 6,2,7,1,9,4 };
			Assert::AreEqual(array[0], 6);
			Assert::AreEqual(array[2], 7);

			Assert::AreEqual(getMax(array, size), 9);

			reverseArray(array, size);
			Assert::AreEqual(array[0], 4);
			Assert::AreEqual(array[2], 1);

			bubbleSort(array, size);
			Assert::AreEqual(array[0], 1);
			Assert::AreEqual(array[1], 2);
			Assert::AreEqual(array[2], 4);

			reverseArray(array, size);
			Assert::AreEqual(array[0], 9);
			Assert::AreEqual(array[1], 7);

			swap(&array[0], &array[1]);
			Assert::AreEqual(array[0], 7);
			Assert::AreEqual(array[1], 9);
		}

		TEST_METHOD(TestQuickSort) {
			const int size = 6;
			int array[size] = { 6,2,7,1,9,4 };
			Assert::AreEqual(array[0], 6);
			Assert::AreEqual(array[2], 7);

			Assert::AreEqual(getMax(array, size), 9);

			reverseArray(array, size);
			Assert::AreEqual(array[0], 4);
			Assert::AreEqual(array[2], 1);

			quickSort(array, 0, size - 1);
			Assert::AreEqual(array[0], 1);
			Assert::AreEqual(array[1], 2);
			Assert::AreEqual(array[2], 4);

			reverseArray(array, size);
			Assert::AreEqual(array[0], 9);
			Assert::AreEqual(array[1], 7);

			swap(&array[0], &array[1]);
			Assert::AreEqual(array[0], 7);
			Assert::AreEqual(array[1], 9);
		}

		TEST_METHOD(TestCountSort) {
			const int size = 6;
			int array[size] = { 6,2,7,1,9,4 };
			Assert::AreEqual(array[0], 6);
			Assert::AreEqual(array[2], 7);

			Assert::AreEqual(getMax(array, size), 9);

			reverseArray(array, size);
			Assert::AreEqual(array[0], 4);
			Assert::AreEqual(array[2], 1);

			countSort(array, size);
			Assert::AreEqual(array[0], 1);
			Assert::AreEqual(array[1], 2);
			Assert::AreEqual(array[2], 4);

			reverseArray(array, size);
			Assert::AreEqual(array[0], 9);
			Assert::AreEqual(array[1], 7);

			swap(&array[0], &array[1]);
			Assert::AreEqual(array[0], 7);
			Assert::AreEqual(array[1], 9);
		}

		TEST_METHOD(TestShellSort) {
			const int size = 6;
			int array[size] = { 6,2,7,1,9,4 };
			Assert::AreEqual(array[0], 6);
			Assert::AreEqual(array[2], 7);

			Assert::AreEqual(getMax(array, size), 9);

			reverseArray(array, size);
			Assert::AreEqual(array[0], 4);
			Assert::AreEqual(array[2], 1);

			shellSort(array, size);
			Assert::AreEqual(array[0], 1);
			Assert::AreEqual(array[1], 2);
			Assert::AreEqual(array[2], 4);

			reverseArray(array, size);
			Assert::AreEqual(array[0], 9);
			Assert::AreEqual(array[1], 7);

			swap(&array[0], &array[1]);
			Assert::AreEqual(array[0], 7);
			Assert::AreEqual(array[1], 9);
		}
	};
}
