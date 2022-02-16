#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab01/algos.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortingTest
{
	TEST_CLASS(SortingTest)
	{
	public:
		
		TEST_METHOD(insertSort_ifCorrect)
		{
			const int size = 10;
			int arr[size] = { 7, 9, 1, 4, 8, 3, 0, 5, 6, 2  };

			insertSort(arr, size);

			Assert::AreEqual(0, arr[0]); 
			Assert::AreEqual(1, arr[1]);
			Assert::AreEqual(2, arr[2]);
			Assert::AreEqual(3, arr[3]);
			Assert::AreEqual(4, arr[4]);
			Assert::AreEqual(5, arr[5]);
			Assert::AreEqual(6, arr[6]);
			Assert::AreEqual(7, arr[7]);
			Assert::AreEqual(8, arr[8]);
			Assert::AreEqual(9, arr[9]);
		}

		TEST_METHOD(BadSize_Test)
		{
			int size = -3;
			int* arr = new int[size];
			try
			{
				insertSort(arr, size);
			}
			catch (const BadSize& A)
			{
				Assert::AreEqual(-3, A.returnField());
				
			}
			
			
			
			
			

		}
	};
}
