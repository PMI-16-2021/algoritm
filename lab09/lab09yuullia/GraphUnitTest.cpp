#include "pch.h"
#include "CppUnitTest.h"
#include "..//Project9/graph.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GraphUnitTest
{
	TEST_CLASS(GraphUnitTest)
	{
	public:
		
		TEST_METHOD(GetCountTest)
		{
			Graph G(3);
			Assert::AreEqual(G.getCount(), 0);
			G.addEdge(0, 1, 1);
			G.addEdge(0, 2, 2);
			G.addEdge(1, 2, 3);
			Assert::AreEqual(G.getCount(), 3);
		}
		
		TEST_METHOD(AddEdgeTest)
		{
			Graph G(5);
			Assert::AreEqual(G.getCount(), 0);
			G.addEdge(0, 1, 1);
			G.addEdge(0, 2, 2);
			G.addEdge(1, 3, 3);
			Assert::AreEqual(G.getCount(), 3);
			G.addEdge(1, 4, 4);
			G.addEdge(3, 4, 5);
			Assert::AreEqual(G.getCount(), 5);
		}
		
		TEST_METHOD(RemoveEdgeTest)
		{
			Graph G(5);
			Assert::AreEqual(G.getCount(), 0);
			G.addEdge(0, 1, 1);
			G.addEdge(0, 2, 2);
			G.addEdge(1, 3, 3);
			G.addEdge(1, 4, 4);
			G.addEdge(3, 4, 5);
			Assert::AreEqual(G.getCount(), 5);
			G.removeEdge(0, 1);
			Assert::AreEqual(G.getCount(), 4);
			G.removeEdge(0, 2);
			Assert::AreEqual(G.getCount(), 3);
		}
		
		TEST_METHOD(DijkstraTest)
		{
			Graph G(4);
			G.addEdge(0, 1, 1);
			G.addEdge(0, 2, 2);
			G.addEdge(1, 2, 3);
			G.addEdge(1, 3, 4);
			Assert::AreEqual(G.dijkstra(0, 3), 5);
			Assert::AreEqual(G.dijkstra(1, 2), 3);
		}
	};
}
