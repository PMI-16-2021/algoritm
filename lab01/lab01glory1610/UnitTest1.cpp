#include "pch.h"
#include "CppUnitTest.h"
#include "..//Sort_/Sort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestBubbleSort)
		{
			const int n = 5;
			int random_array[n] = { 4, 23, 56, 0, 11 };
			int random_result[n] = { 0, 4, 11, 23, 56 };
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(random_array[i], random_result[i]);
			}
			int sorted_array[n] = { 0, 4, 11, 23, 56 };
			int sorted_result[n] = { 0, 4, 11, 23, 56 };
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(sorted_array[i], sorted_result[i]);
			}
			int reversed_array[n] = { 56, 23, 11, 4, 0 };
			int reversed_result[n] = { 0, 4, 11, 23, 56 };
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(reversed_array[i], reversed_result[i]);
			}

		}
		TEST_METHOD(TestQuickSort)
		{
			const int n = 5;
			int random_array[n] = { 4, 23, 56, 0, 11 };
			int random_result[n] = { 0, 4, 11, 23, 56 };
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(random_array[i], random_result[i]);
			}
			int sorted_array[n] = { 0, 4, 11, 23, 56 };
			int sorted_result[n] = { 0, 4, 11, 23, 56 };
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(sorted_array[i], sorted_result[i]);
			}
			int reversed_array[n] = { 56, 23, 11, 4, 0 };
			int reversed_result[n] = { 0, 4, 11, 23, 56 };
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(reversed_array[i], reversed_result[i]);
			}
		}
		TEST_METHOD(TestCountSort)
		{
			const int n = 5;
			int random_array[n] = { 4, 23, 56, 0, 11 };
			int random_result[n] = { 0, 4, 11, 23, 56 };
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(random_array[i], random_result[i]);
			}
			int sorted_array[n] = { 0, 4, 11, 23, 56 };
			int sorted_result[n] = { 0, 4, 11, 23, 56 };
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(sorted_array[i], sorted_result[i]);
			}
			int reversed_array[n] = { 56, 23, 11, 4, 0 };
			int reversed_result[n] = { 0, 4, 11, 23, 56 };
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(reversed_array[i], reversed_result[i]);
			}
		}
		TEST_METHOD(TestMergeSort)
		{
			const int n = 5;
			int random_array[n] = { 4, 23, 56, 0, 11 };
			int random_result[n] = { 0, 4, 11, 23, 56 };
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(random_array[i], random_result[i]);
			}
			int sorted_array[n] = { 0, 4, 11, 23, 56 };
			int sorted_result[n] = { 0, 4, 11, 23, 56 };
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(sorted_array[i], sorted_result[i]);
			}
			int reversed_array[n] = { 56, 23, 11, 4, 0 };
			int reversed_result[n] = { 0, 4, 11, 23, 56 };
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(reversed_array[i], reversed_result[i]);
			}
		}
	};
}
