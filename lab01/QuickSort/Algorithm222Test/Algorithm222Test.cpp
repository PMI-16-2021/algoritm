#include "pch.h"
#include "CppUnitTest.h"
#include "..\\algorithm2.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Algorithm2Test
{
	TEST_CLASS(Algorithm2Test)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int arr[5] = { 1,4,7,1,-3 };

			swap(&arr[3], &arr[4]);

			Assert::AreEqual(arr[3], -3);
			Assert::AreEqual(arr[4], 1);
		}

		TEST_METHOD(TestMethod2)
		{
			int arr[5] = { 1,4,7,1,3 };

			quickSort(arr, 1, 4);

			Assert::AreEqual(arr[3], 4);
			Assert::AreEqual(arr[4], 7);
		}

		TEST_METHOD(TestMethod3)
		{
			int arr[5] = { -1,-4,-7,-5,-6 };

			quickSort(arr, 1,4);

			Assert::AreEqual(arr[2], -6);
		}
	};
}