#include "pch.h"
#include "CppUnitTest.h"
#include "..\\SortingAlgorithm\algorithm1.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Algorithm1Test
{
	TEST_CLASS(Algorithm1Test)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int arr[2] = { 2,3 };

			swap(&arr[0], &arr[1]);

			Assert::AreEqual(arr[0], 3);
			Assert::AreEqual(arr[1], 2);
		}

		TEST_METHOD(TestMethod2)
		{
			int arr[5] = { 2,1,3,8,6};

			bubbleSort(arr, 5);
			Assert::AreEqual(arr[3], 6);
			Assert::AreEqual(arr[1], 2);
			Assert::AreEqual(arr[2], 3);
			Assert::AreEqual(arr[0], 1);
			Assert::AreEqual(arr[4], 8);
		}

		TEST_METHOD(TestMethod3)
		{
			int arr[5] = { -2,-1,-3,-8,-6 };

			bubbleSort(arr, 5);

			Assert::AreEqual(arr[1], -6);
			Assert::AreEqual(arr[2], -3);
			Assert::AreEqual(arr[0], -8);
			Assert::AreEqual(arr[4], -1);
			Assert::AreEqual(arr[3], -2);
		}
	};
}
