#include "pch.h"
#include "CppUnitTest.h"
#include "..//Sorting/function.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SortingUnitTest
{
	TEST_CLASS(SortingUnitTest)
	{
	public:
		
		TEST_METHOD(Bubble_TestSorted)
		{
			int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			const int n = sizeof a / sizeof a[0];
			int result[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			BubbleS(a, n);
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(result[i], a[i]);
			}
		}

		TEST_METHOD(Bubble_TestTenValues)
		{
			int a[] = { 1, 6, 4, 3, 0, 5, 9, 8, 7, 2 };
			const int n = sizeof a / sizeof a[0];
			int result[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			BubbleS(a, n);
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(result[i], a[i]);
			}
		}

		TEST_METHOD(Bubble_TestReversed)
		{
			int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
			const int n = sizeof a / sizeof a[0];
			int result[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			BubbleS(a, n);
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(result[i], a[i]);
			}
		}


		TEST_METHOD(Quick_TestSorted)
		{
			int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			const int n = sizeof a / sizeof a[0];
			int result[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			QuickS(a, 0, n-1);
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(result[i], a[i]);
			}
		}

		TEST_METHOD(Quick_TestTenValues)
		{
			int a[] = { 1, 6, 4, 3, 0, 5, 9, 8, 7, 2 };
			const int n = sizeof a / sizeof a[0];
			int result[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			QuickS(a, 0, n-1);
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(result[i], a[i]);
			}
		}

		TEST_METHOD(Quick_TestReversed)
		{
			int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
			const int n = sizeof a / sizeof a[0];
			int result[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			QuickS(a, 0, n-1);
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(result[i], a[i]);
			}
		}


		TEST_METHOD(Count_TestSorted)
		{
			int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			const int n = sizeof a / sizeof a[0];
			int result[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			CountS(a, n);
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(result[i], a[i]);
			}
		}

		TEST_METHOD(Count_TestTenValues)
		{
			int a[] = { 1, 6, 4, 3, 0, 5, 9, 8, 7, 2 };
			const int n = sizeof a / sizeof a[0];
			int result[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			CountS(a, n);
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(result[i], a[i]);
			}
		}

		TEST_METHOD(Count_TestReversed)
		{
			int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
			const int n = sizeof a / sizeof a[0];
			int result[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			CountS(a, n);
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(result[i], a[i]);
			}
		}


		TEST_METHOD(Shell_TestSorted)
		{
			int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			const int n = sizeof a / sizeof a[0];
			int result[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			ShellS(a, n);
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(result[i], a[i]);
			}
		}

		TEST_METHOD(Shell_TestTenValues)
		{
			int a[] = { 1, 6, 4, 3, 0, 5, 9, 8, 7, 2 };
			const int n = sizeof a / sizeof a[0];
			int result[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			ShellS(a, n);
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(result[i], a[i]);
			}
		}

		TEST_METHOD(Shell_TestReversed)
		{
			int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
			const int n = sizeof a / sizeof a[0];
			int result[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			ShellS(a, n);
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(result[i], a[i]);
			}
		}

		
	};
}
