#include "pch.h"
#include "CppUnitTest.h"
#include "..//lab09/graph.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest9
{
	TEST_CLASS(UnitTest9)
	{
	public:

		TEST_METHOD(TestDijkstraBestPath)
		{
			Graph g(6);
			g.addEdge(0, 1, 10);
			g.addEdge(1, 3, 4);
			g.addEdge(1, 4, 8);
			g.addEdge(3, 4, 1);
			g.addEdge(4, 5, 2);
			g.addEdge(2, 5, 11);

			Assert::AreEqual(28, g.dijkstra(0, 2));
			Assert::AreEqual(17, g.dijkstra(0, 5));
			Assert::AreEqual(14, g.dijkstra(0, 3));
			Assert::AreEqual(15, g.dijkstra(0, 4));

			Assert::AreEqual(5, g.dijkstra(1, 4));
			Assert::AreEqual(3, g.dijkstra(3, 5));
		}

		TEST_METHOD(TestDijkstraForLoop)
		{
			Graph g(6);
			g.addEdge(0, 1, 10);
			g.addEdge(1, 2, 8);
			g.addEdge(1, 3, 4);
			g.addEdge(1, 4, 8);
			g.addEdge(3, 4, 1);
			g.addEdge(4, 5, 2);
			g.addEdge(2, 5, 11);

			Assert::AreEqual(0, g.dijkstra(0, 0));
			Assert::AreEqual(0, g.dijkstra(3, 3));
			Assert::AreEqual(0, g.dijkstra(1, 1));
		}
	};
}
