#include "pch.h"
#include "CppUnitTest.h"
#include "..//DijkstraAlgorithm/graph.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DijkstraAlgorithmTest {

	TEST_CLASS(DijkstraAlgorithmTest) {

	public:
		TEST_METHOD(GetCountVertexTest) {
			Graph G;
			Assert::AreEqual(G.GetCountVertex(), 0);
			Graph G1(3);
			Assert::AreEqual(G1.GetCountVertex(), 3);
		}
		TEST_METHOD(IsEmptyTest) {
			Graph G;
			Assert::IsTrue(G.IsEmpty());
			Graph G1(9);
			Assert::AreEqual(G1.GetCountVertex(), 9);
		}
		TEST_METHOD(GetCostTest) {
			Graph G(6);
			G.AddEdge(0, 1, 7);
			G.AddEdge(0, 2, 9);
			G.AddEdge(0, 5, 14);
			G.AddEdge(1, 2, 10);
			G.AddEdge(1, 3, 15);
			G.AddEdge(2, 5, 2);
			G.AddEdge(2, 3, 11);
			G.AddEdge(3, 4, 6);
			G.AddEdge(4, 5, 9);
			Assert::AreEqual(G.GetCost(0, 2), 9);
			Assert::AreEqual(G.GetCost(2, 0), 9);
		}
		TEST_METHOD(GetCountEdgesTest) {
			Graph G(6);
			Assert::AreEqual(G.GetCountEdge(), 0);
			G.AddEdge(0, 1, 7);
			G.AddEdge(0, 2, 9);
			G.AddEdge(0, 5, 14);
			G.AddEdge(1, 2, 10);
			G.AddEdge(1, 3, 15);
			G.AddEdge(2, 5, 2);
			G.AddEdge(2, 3, 11);
			G.AddEdge(3, 4, 6);
			G.AddEdge(4, 5, 9);
			Assert::AreEqual(G.GetCountEdge(), 9);
		}
		TEST_METHOD(GetDegreeVertexTest) {
			Graph G(6);
			G.AddEdge(0, 1, 7);
			G.AddEdge(0, 2, 9);
			G.AddEdge(0, 5, 14);
			G.AddEdge(1, 2, 10);
			G.AddEdge(1, 3, 15);
			G.AddEdge(2, 5, 2);
			G.AddEdge(2, 3, 11);
			G.AddEdge(3, 4, 6);
			G.AddEdge(4, 5, 9);
			Assert::AreEqual(G.GetDegreeVertex(0), 3);
			Assert::AreEqual(G.GetDegreeVertex(1), 3);
			Assert::AreEqual(G.GetDegreeVertex(3), 3);
		}
		TEST_METHOD(FindEdgesTest) {
			Graph G(6);
			G.AddEdge(0, 1, 7);
			G.AddEdge(0, 2, 9);
			G.AddEdge(0, 5, 14);
			G.AddEdge(1, 2, 10);
			G.AddEdge(1, 3, 15);
			G.AddEdge(2, 5, 2);
			G.AddEdge(2, 3, 11);
			G.AddEdge(3, 4, 6);
			G.AddEdge(4, 5, 9);
			Assert::IsTrue(G.FindEdge(1, 3));
			Assert::IsTrue(G.FindEdge(3, 1));
			Assert::IsFalse(G.FindEdge(3, 5));
		}
		TEST_METHOD(AddEdgeTest) {
			Graph G(6);
			Assert::IsFalse(G.FindEdge(3, 2));
			G.AddEdge(0, 1, 7);
			G.AddEdge(0, 2, 9);
			G.AddEdge(0, 5, 14);
			G.AddEdge(1, 2, 10);
			G.AddEdge(1, 3, 15);
			G.AddEdge(2, 5, 2);
			G.AddEdge(2, 3, 11);
			G.AddEdge(3, 4, 6);
			G.AddEdge(4, 5, 9);
			Assert::IsTrue(G.FindEdge(3, 2));
			Assert::IsTrue(G.FindEdge(2, 3));
			Assert::AreEqual(G.GetCost(3, 2), 11);
		}
		TEST_METHOD(RemoveEdgeTest) {
			Graph G(6);
			G.AddEdge(0, 1, 7);
			G.AddEdge(0, 2, 9);
			G.AddEdge(0, 5, 14);
			G.AddEdge(1, 2, 10);
			G.AddEdge(1, 3, 15);
			G.AddEdge(2, 5, 2);
			G.AddEdge(2, 3, 11);
			G.AddEdge(3, 4, 6);
			G.AddEdge(4, 5, 9);
			Assert::IsTrue(G.FindEdge(0, 5));
			G.RemoveEdge(0, 5);
			Assert::IsFalse(G.FindEdge(0, 5));
			Assert::IsFalse(G.FindEdge(5, 0));
		}
		TEST_METHOD(DijkstraTest) {
			Graph G(6);
			G.AddEdge(0, 1, 7);
			G.AddEdge(0, 2, 9);
			G.AddEdge(0, 5, 14);
			G.AddEdge(1, 2, 10);
			G.AddEdge(1, 3, 15);
			G.AddEdge(2, 5, 2);
			G.AddEdge(2, 3, 11);
			G.AddEdge(3, 4, 6);
			G.AddEdge(4, 5, 9);
			G.Dijkstra(0);
			const int n = 5;
			int* p = G.GetPrev();
			int* d = G.GetDist();
			int dist[n] = { 7, 9, 20, 20, 11 };
			int prev[n] = { 0, 0, 2, 5, 2 };
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(p[i + 1], prev[i]);
				Assert::AreEqual(d[i + 1], dist[i]);
			}
		}
	};
}
