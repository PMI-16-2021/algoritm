#include "pch.h"
#include "CppUnitTest.h"
#include "..//sort/sort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(bublleSortTest)
		{
			const int size = 5;
			int data[] = { 21, 4, 13, 8, 2 };
			int result[] = { 2, 4, 8, 13, 21 };
			int reverse[] = { 21, 13, 8, 4, 2 };

			bublleSort(data, size);
			for (int i = 0; i < size; ++i){
				Assert::AreEqual(data[i], result[i]);
			}

			bublleSort(reverse, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(reverse[i], result[i]);
			}
		}
		TEST_METHOD(quickSortTest)
		{
			const int size = 5;
			int data[] = { 21, 4, 13, 8, 2 };
			int result[] = { 2, 4, 8, 13, 21 };
			int reverse[] = { 21, 13, 8, 4, 2 };

			quickSort(data, 0, size - 1);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(data[i], result[i]);
			}

			quickSort(reverse, 0, size-1);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(reverse[i], result[i]);
			}
		}
		TEST_METHOD(shellSortTest)
		{
			const int size = 5;
			int data[] = { 21, 4, 13, 8, 2 };
			int result[] = { 2, 4, 8, 13, 21 };
			int reverse[] = { 21, 13, 8, 4, 2 };
			shellSort(data, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(data[i], result[i]);
			}

			shellSort(reverse, size);
			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(reverse[i], result[i]);
			}
		}
	};
}
