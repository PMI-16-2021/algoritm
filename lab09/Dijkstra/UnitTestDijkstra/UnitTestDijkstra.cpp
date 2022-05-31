#include "pch.h"
#include "CppUnitTest.h"
#include "..//Dijkstra/graph.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestDijkstra
{
	TEST_CLASS(UnitTestDijkstra)
	{
	public:
		
		TEST_METHOD(TestFirst){
			Graph graph({ 'a', 'b', 'c', 'd', 'e', 'f' },
				{ {0, 4, 2, 0, 0, 0},
				{ 4, 0, 1, 5, 0, 0},
				{2, 1, 0, 8, 10, 0},
				{ 0, 5, 8, 0, 2, 6},
				{0, 0, 10, 2, 0, 3},
				{0, 0, 0, 6, 3, 0} });

			std::vector<int> result = graph.Dijkstra('a');
			std::vector<int> exp = { 0, 3, 2, 8, 10, 13 };
			for (int i = 0; i < result.size(); ++i)
			{
				Assert::AreEqual(exp[i], result[i]);
			}
		}
		TEST_METHOD(TestSecond) {
			Graph graph({ 'a', 'b', 'c', 'd', 'e', 'f' },
				{ {0, 7, 9, 0, 0, 14},
				{ 7, 0, 10, 15, 0, 0},
				{9, 10, 0, 11, 0, 2},
				{ 0, 15, 11, 0, 6, 0},
				{0, 0, 0, 6, 0, 9},
				{14, 0, 2, 0, 9, 0} });
			std::vector<int> result = graph.Dijkstra('a');
			std::vector<int> exp = { 0, 7, 9, 20, 20, 11 };
			for (int i = 0; i < result.size(); ++i)
			{
				Assert::AreEqual(exp[i], result[i]);
			}
		}
	};
}
