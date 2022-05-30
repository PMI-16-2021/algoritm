#include "pch.h"
#include "CppUnitTest.h"
#include "..//лр9/graph.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest {
	TEST_CLASS(GraphTest) {
	public:
		TEST_METHOD(setVertexGetWeightTest) {
			Graph gr(9);
			gr.setVertex(0, 1, 4);
			gr.setVertex(3, 7, 7);
			gr.setVertex(6, 7, 4);
			Assert::AreEqual(gr.getWeight(0, 1), 4);
			Assert::AreEqual(gr.getWeight(3, 7), 7);
			Assert::AreEqual(gr.getWeight(6, 7), 4);
		}
		TEST_METHOD(graphConstructorDefaultTest) {
			Graph gr;
			Assert::AreEqual(gr.getNumberOfVertexes(), 5);
			Assert::AreNotEqual(gr.getNumberOfVertexes(), 2);
		}
		TEST_METHOD(graphConstructorTest) {
			Graph gr(7);
			Assert::AreEqual(gr.getNumberOfVertexes(), 7);
			Assert::AreNotEqual(gr.getNumberOfVertexes(), 2);
		}
		TEST_METHOD(areAdjacentTest) {
			Graph gr(8);
			gr.setVertex(0, 1, 4);
			gr.setVertex(0, 4, 3);
			gr.setVertex(1, 4, 2);
			gr.setVertex(1, 2, 5);
			gr.setVertex(2, 4, 3);
			Assert::IsTrue(gr.areAdjacent(1, 4));
			Assert::IsFalse(gr.areAdjacent(1, 3));
			Assert::IsTrue(gr.areAdjacent(2, 4));
		}
		TEST_METHOD(dijkstraTest) {
			Graph gr(8);
			gr.setVertex(0, 1, 4);
			gr.setVertex(0, 4, 3);
			gr.setVertex(1, 4, 2);
			gr.setVertex(1, 2, 5);
			gr.setVertex(2, 4, 3);
			gr.setVertex(4, 5, 6);
			gr.setVertex(2, 5, 1);
			gr.setVertex(2, 3, 5);
			gr.setVertex(5, 6, 5);
			gr.setVertex(3, 6, 2);
			gr.setVertex(3, 7, 7);
			gr.setVertex(6, 7, 4);
			Assert::AreEqual(gr.dijkstra(0)[2], 6);
			Assert::AreEqual(gr.dijkstra(0)[3], 11);
			Assert::AreEqual(gr.dijkstra(0)[4], 3);
			Assert::AreEqual(gr.dijkstra(0)[5], 7);
			Assert::AreEqual(gr.dijkstra(0)[6], 12);
			Assert::AreEqual(gr.dijkstra(0)[7], 16);
		}
	};
}