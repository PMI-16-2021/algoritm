#include "pch.h"
#include "CppUnitTest.h"
#include "../Graphs/Graph.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GraphsTest
{
	TEST_CLASS(GraphsTest)
	{
	public:
		
		TEST_METHOD(Graph_One)
		{
			const int n = 6;
			Graph A(n);
			A.add_edge(0, 1, 4);
			A.add_edge(0, 2, 2);
			A.add_edge(2, 1, 1);
			A.add_edge(1, 3, 5);
			A.add_edge(2, 4, 10);
			A.add_edge(2, 3, 8);
			A.add_edge(3, 4, 2);
			A.add_edge(4, 5, 3);
			A.add_edge(3, 5, 6);
			A.djskra(0);
			int* result = A.get_djskra_results();
			int expected[n] = {0, 3, 2, 8, 10, 13};
			for (size_t i = 0; i < A.getVertex(); i++)
			{
				Assert::AreEqual(expected[i], result[i]);
			}
		}

		TEST_METHOD(Graph_Two)
		{
			const int n = 4;
			Graph A(n);
			A.add_edge(0, 1, 5);
			A.add_edge(0, 2, 9);
			A.add_edge(1, 2, 3);
			A.add_edge(2, 3, 1);
			A.add_edge(1, 3, 2);
			A.djskra(0);
			int* result = A.get_djskra_results();
			int expected[n] = { 0, 5, 8, 7};
			for (size_t i = 0; i < A.getVertex(); i++)
			{
				Assert::AreEqual(expected[i], result[i]);
			}
		}

		TEST_METHOD(Graph_Three)
		{
			const int n = 6;
			Graph A(n);
			A.add_edge(0, 1, 2);
			A.add_edge(1, 4, 4);
			A.add_edge(1, 2, 6);
			A.add_edge(1, 3, 1);
			A.add_edge(3, 4, 2);
			A.add_edge(3, 5, 2);
			A.add_edge(5, 2, 2);
			int* before_algorithm = A.get_djskra_results();
			for (size_t i = 0; i < A.getVertex(); i++)
			{
				Assert::AreEqual(INT_MAX, before_algorithm[i]);
			}
			A.djskra(0);
			int* result = A.get_djskra_results();
			int expected[n] = { 0, 2, 7, 3, 5, 5 };
			for (size_t i = 0; i < A.getVertex(); i++)
			{
				Assert::AreEqual(expected[i], result[i]);
			}
		}
	};
}
