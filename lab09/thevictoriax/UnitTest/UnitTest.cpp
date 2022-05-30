#include "pch.h"
#include "CppUnitTest.h"
#include "..\lab09\graph.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(one)
		{
			Graph graph({ 'a', 'b', 'c', 'd', 'e', 'f' },
				{ {1, 5, 7, 0, 0, 0},
				{ 3, 1, 2, 4, 0, 0},
				{5, 1, 0, 3, 7, 0},
				{ 2, 4, 0, 0, 1, 4},
				{1, 1, 0, 3, 0, 4},
				{0, 1, 0, 3, 7, 4} });

			std::vector<int> res = graph.algorithm('e');
			std::vector<int> check = { 1, 1, 8, 3, 0, 4 };
			for (int i = 0; i < res.size(); ++i)
			{
				Assert::IsTrue(check[i] == res[i]);
			}
		}
		TEST_METHOD(two)
		{
			Graph graph({ 'a', 'b', 'c', 'd', 'e', 'f' },
				{ {0, 1, 0, 3, 7, 4},
				{ 1, 1, 0, 3, 0, 4},
				{ 2, 4, 0, 0, 1, 4},
				{5, 1, 0, 3, 7, 0},
				{3, 1, 2, 4, 0, 0},
				{1, 5, 7, 0, 0, 0} });

			std::vector<int> res = graph.algorithm('c');
			std::vector<int> check = { 2, 2, 0, 5, 1, 4 };
			for (int i = 0; i < res.size(); ++i)
			{
				Assert::IsTrue(check[i] == res[i]);
			}
		}

		TEST_METHOD(three)
		{
			Graph graph({ 'a', 'b', 'c', 'd', 'e', 'f' },
				{ {0, 1, 0, 3, 7, 4},
				{ 1, 1, 0, 3, 0, 4},
				{ 2, 4, 0, 0, 1, 4},
				{5, 1, 0, 3, 7, 0},
				{3, 1, 2, 4, 0, 0},
				{1, 5, 7, 0, 0, 0} });

			std::vector<int> res = graph.algorithm('f');
			std::vector<int> check = { 1, 2, 7, 4, 8, 0 };
			for (int i = 0; i < res.size(); ++i)
			{
				Assert::IsTrue(check[i] == res[i]);
			}
		}
	};
}
