#include "pch.h"
#include "CppUnitTest.h"
#include"..\dz1\sort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestSortBobl)
		{
			const int size = 4;
			int invertedArr[size] = {4,3,2,1};
			sortBubl(invertedArr, size);
			for(int i=1;i<=size;++i)
			{
				Assert::AreEqual(invertedArr[i], i);
			}
			int sortedArr[size] = {1,2,3,4};

			sortBubl(sortedArr, size);
			for (int i = 1; i <= size; ++i)
			{
				Assert::AreEqual(sortedArr[i], i);
			}
			int Arr[size] = {2,3,1,4};
			sortBubl(Arr, size);
			for (int i = 1; i <= size; ++i)
			{
				Assert::AreEqual(Arr[i], i);
			}

		}


		TEST_METHOD(TestQuickSort)
		{
			const int size = 4;
			int invertedArr[size] = { 4,3,2,1 };
			quickSort(invertedArr,0,size);
			for (int i = 1; i <= size; ++i)
			{
				Assert::AreEqual(invertedArr[i], i);
			}
			int sortedArr[size] = { 1,2,3,4 };

			quickSort(sortedArr,0, size);
			for (int i = 1; i <= size; ++i)
			{
				Assert::AreEqual(sortedArr[i], i);
			}
			int Arr[size] = { 2,3,1,4 };
			quickSort(Arr,0, size);
			for (int i = 1; i <= size; ++i)
			{
				Assert::AreEqual(Arr[i], i);
			}

		}


		TEST_METHOD(TestCountSort)
		{
			const int size = 4;
			int invertedArr[size] = {4,3,2,1 };
			int arr[size] = { 1,2,3,4 };
			countSort(invertedArr,  size,size+1);
			for (int i = 0; i < size; ++i)
			{
				Assert::AreEqual(invertedArr[i], arr[i]);
			}
			int sortedArr[size] = { 1,2,3,4 };

			countSort(sortedArr,  size,size+1);
			for (int i = 0; i < size; ++i)
			{
				Assert::AreEqual(sortedArr[i], arr[i]);
			}
			int Arr[size] = { 2,3,1,4 };
			countSort(Arr,  size,size+1);
			for (int i = 0; i < size; ++i)
			{
				Assert::AreEqual(Arr[i], arr[i]);
			}

		}


		TEST_METHOD(TestSortShell)
		{
			const int size = 4;
			int invertedArr[size] = {4,3,2,1 };
			int arr[size] = { 1,2,3,4 };
			sortShell(invertedArr, size);
			for (int i = 0; i < size; ++i)
			{
				Assert::AreEqual(invertedArr[i], arr[i]);
			}
			int sortedArr[size] = { 1,2,3,4 };

			sortShell(sortedArr, size);
			for (int i = 0; i < size; ++i)
			{
				Assert::AreEqual(sortedArr[i], arr[i]);
			}
			int Arr[size] = { 3,1,4,2 };

			sortShell(Arr, size);
			for (int i = 0; i < size; ++i)
			{
				Assert::AreEqual(Arr[i], arr[i]);
			}

		}

	};
}
