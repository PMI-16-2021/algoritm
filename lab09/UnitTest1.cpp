#include "pch.h"
#include "CppUnitTest.h"
#include "..\\dijkstra\dijkstraAlgorithm.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(AddEdgeTest) {
			Graph G(5);
			Assert::AreEqual(G.countEdges(), 0);
			G.addEdge(0, 1, 5);
			G.addEdge(0, 3, 10);
			Assert::AreEqual(G.countEdges(), 2);
			G.addEdge(1, 2, 7);
			G.addEdge(1, 3, 6);
			G.addEdge(3, 4, 2);
			Assert::AreEqual(G.countEdges(), 5);
		}
		TEST_METHOD(RemoveEdgeTest) {
			Graph G(5);
			Assert::AreEqual(G.countEdges(), 0);
			G.addEdge(0, 1, 5);
			G.addEdge(0, 2, 8);
			G.addEdge(0, 3, 10);
			G.addEdge(1, 2, 7);
			G.addEdge(1, 3, 6);
			G.addEdge(3, 4, 2);
			Assert::AreEqual(G.getCost(0, 2), 8);
			Assert::AreEqual(G.countEdges(), 6);
			G.removeEdge(1, 3);
			G.removeEdge(0, 2);
			Assert::AreEqual(G.getCost(0, 2), 0);
			Assert::AreEqual(G.countEdges(), 4);
		}
		TEST_METHOD(GetCostTest) {
			Graph G(5);
			G.addEdge(0, 1, 5);
			G.addEdge(0, 3, 10);
			G.addEdge(1, 2, 7);
			G.addEdge(1, 3, 6);
			G.addEdge(3, 4, 2);
			Assert::AreEqual(G.getCost(0, 3), 10);
			Assert::AreEqual(G.getCost(3, 0), 10);
		}
		TEST_METHOD(CountEdgesTest) {
			Graph G(5);
			Assert::AreEqual(G.countEdges(), 0);
			G.addEdge(0, 1, 5);
			G.addEdge(0, 3, 10);
			G.addEdge(1, 2, 7);
			G.addEdge(1, 3, 6);
			G.addEdge(3, 4, 2);
			Assert::AreEqual(G.countEdges(), 5);
		}
		TEST_METHOD(DijkstraTest) {
			Graph G(5);
			G.addEdge(0, 1, 5);
			G.addEdge(0, 3, 10);
			G.addEdge(1, 2, 7);
			G.addEdge(1, 3, 6);
			G.addEdge(3, 4, 2);
			int result = G.dijkstra(0, 4);
			Assert::AreEqual(result, 12);
		}
	};
}
