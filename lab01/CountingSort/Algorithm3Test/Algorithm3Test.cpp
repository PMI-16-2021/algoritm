#include "pch.h"
#include "CppUnitTest.h"
#include "..\\algorithm3.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Algorithm3Test
{
	TEST_CLASS(Algorithm3Test)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int arr[5] = { 3,8,4,5,9 };

			countSort(arr, 5);

			Assert::AreEqual(arr[3], 8);
			Assert::AreEqual(arr[2], 5);
		}

		TEST_METHOD(TestMethod2)
		{
			int arr[5] = { 3,8,4,5,9 };

			printArray(arr, 5);

			Assert::AreEqual(arr[3], 5);
			Assert::AreEqual(arr[2], 4);
		}

		TEST_METHOD(TestMethod3)
		{
			int arr[5] = { 3,8,4,5,9 };

			countSort(arr, 5);

			int brr[5] = { 3,4,5,8,9 };

			Assert::AreEqual(arr[3], brr[3]);
			Assert::AreEqual(arr[2], brr[2]);
		}
	};
}
