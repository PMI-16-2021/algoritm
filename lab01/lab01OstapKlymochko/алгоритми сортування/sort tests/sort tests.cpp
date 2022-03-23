#include "pch.h"
#include "CppUnitTest.h"
#include"..//алгоритми сортування/funcs.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace sorttests
{
	TEST_CLASS(sorttests)
	{
	public:
		
		TEST_METHOD(BubbleTest)
		{
            const int size = 5;
            int data[] = { 4, 34, 8, 1, 3 };
            int result[] = { 1, 3, 4, 8, 34 };
            bubbleSort(data, size);
            for (int i = 0; i < size; ++i) {
                Assert::AreEqual(data[i], result[i]);
            }

            int reverse[] = { 34, 8, 4, 3, 1 };
            bubbleSort(reverse, size);
            for (int i = 0; i < size; ++i) {
                Assert::AreEqual(reverse[i], result[i]);
            }
		}
        TEST_METHOD(QuickTest)
        {
            const int size = 5;
            int data[] = { 4, 34, 8, 1, 3 };
            int result[] = { 1, 3, 4, 8, 34 };
            quickSort(data, size,0,size-1);
            for (int i = 0; i < size; ++i) {
                Assert::AreEqual(data[i], result[i]);
            }

            int reverse[] = { 34, 8, 4, 3, 1 };
            quickSort(reverse, size,0,size-1);
            for (int i = 0; i < size; ++i) {
                Assert::AreEqual(reverse[i], result[i]);
            }
        }
        TEST_METHOD(CountingTest)
        {
            const int size = 5;
            int data[] = { 4, 34, 8, 1, 3 };
            int result[] = { 1, 3, 4, 8, 34 };
            countingSort(data, size,1);
            for (int i = 0; i < size; ++i) {
                Assert::AreEqual(data[i], result[i]);
            }

            int reverse[] = { 34, 8, 4, 3, 1 };
            countingSort(reverse, size, 1);
            for (int i = 0; i < size; ++i) {
                Assert::AreEqual(reverse[i], result[i]);
            }
        }
        TEST_METHOD(ShellTest)
        {
            const int size = 5;
            int data[] = { 4, 34, 8, 1, 3 };
            int result[] = { 1, 3, 4, 8, 34 };
            shellSort(data, size);
            for (int i = 0; i < size; ++i) {
                Assert::AreEqual(data[i], result[i]);
            }

            int reverse[] = { 34, 8, 4, 3, 1 };
            shellSort(data, size);
            for (int i = 0; i < size; ++i) {
                Assert::AreEqual(reverse[i], result[i]);
            }
        }
	};
}
