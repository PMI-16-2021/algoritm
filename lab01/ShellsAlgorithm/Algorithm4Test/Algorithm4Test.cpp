#include "pch.h"
#include "CppUnitTest.h"
#include "..\\algorithm4.h"
#include "..\\SortingAlgorithm\algorithm1.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Algorithm4Test
{
	TEST_CLASS(Algorithm4Test)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int arr[5] = { 3,7,13,2,1 };

			shellSort(arr, 5);

			Assert::AreEqual(arr[4], 13);
			Assert::AreEqual(arr[3], 7);
		}

		TEST_METHOD(TestMethod2)
		{
			int arr[5] = { -3,-7,-13,-2,-1 };

			shellSort(arr, 5);

			int brr[5] = { -13,-7,-3,-2,-1 };

			Assert::AreEqual(arr[2],brr[0]);
			Assert::AreEqual(arr[3],brr[3]);
		}

		TEST_METHOD(TestMethod3)
		{
			int arr[5] = { 3,7,13,2,1 };

			shellSort(arr, 5);

			int brr[5] = { 1,2,3,7,13 };

			Assert::AreEqual(arr[4], brr[4]);
			Assert::AreEqual(arr[3], brr[3]);
		}
	};
}
