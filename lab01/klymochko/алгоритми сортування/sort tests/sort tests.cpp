#include "pch.h"
#include "CppUnitTest.h"
#include"..//алгоритми сортування/funcs.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace sorttests
{
    const int size = 5;
    int arr[] = { 4, 34, 8, 1, 3 };
    int result[] = { 1, 3, 4, 8, 34 };
    int reverseArr[] = { 34, 8, 4, 3, 1 };
	TEST_CLASS(sorttests)
	{
	public:
		
		TEST_METHOD(BubbleTest)
		{
           
            bubbleSort(arr, size);
            for (int i = 0; i < size; ++i) {
                Assert::AreEqual(arr[i], result[i]);
            }

           
            bubbleSort(reverseArr, size);
            for (int i = 0; i < size; ++i) {
                Assert::AreEqual(reverseArr[i], result[i]);
            }
		}
        TEST_METHOD(QuickTest)
        {
            
            quickSort(arr, size,0,size-1);
            for (int i = 0; i < size; ++i) {
                Assert::AreEqual(arr[i], result[i]);
            }

           
            quickSort(reverseArr, size,0,size-1);
            for (int i = 0; i < size; ++i) {
                Assert::AreEqual(reverseArr[i], result[i]);
            }
        }
        TEST_METHOD(CountingTest)
        {
           
            countingSort(arr, size,1);
            for (int i = 0; i < size; ++i) {
                Assert::AreEqual(arr[i], result[i]);
            }

            
            countingSort(reverseArr, size, 1);
            for (int i = 0; i < size; ++i) {
                Assert::AreEqual(reverseArr[i], result[i]);
            }
        }
        TEST_METHOD(ShellTest)
        {
           
            shellSort(arr, size);
            for (int i = 0; i < size; ++i) {
                Assert::AreEqual(arr[i], result[i]);
            }

            
            shellSort(arr, size);
            for (int i = 0; i < size; ++i) {
                Assert::AreEqual(reverseArr[i], result[i]);
            }
        }
	};
}
