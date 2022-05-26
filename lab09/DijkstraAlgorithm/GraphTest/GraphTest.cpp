#include "pch.h"
#include "CppUnitTest.h"
#include "..\\Algorithm.h"
#include "..\\Dijkstra.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GraphTest
{
	TEST_CLASS(GraphTest)
	{
	public:
		TEST_METHOD(TestConsructors)
		{
			GraphAlgo::graph graph;
			
			graph.add_edge(1, 2);
			graph.add_edge(1, 4);
			graph.add_edge(2, 4);
			graph.add_edge(2, 5);
			graph.add_edge(3, 4);

			GraphAlgo::graph graph1(graph);

			std::pair<int, int> edge1(1, 2);
			std::pair<int, int> edge2(1, 4);
			std::pair<int, int> edge3(2, 4);
			std::pair<int, int> edge4(2, 5);
			std::pair<int, int> edge5(3, 4);

			Assert::IsTrue(graph1.is_edge_in_graph(edge1));
			Assert::IsTrue(graph1.is_edge_in_graph(edge2));
			Assert::IsTrue(graph1.is_edge_in_graph(edge3));
			Assert::IsTrue(graph1.is_edge_in_graph(edge4));
			Assert::IsTrue(graph1.is_edge_in_graph(edge5));
		}

		TEST_METHOD(TestOperators)
		{
			GraphAlgo::graph graph;

			graph.add_edge(1, 2);
			graph.add_edge(1, 4);
			graph.add_edge(2, 4);
			graph.add_edge(2, 5);
			graph.add_edge(3, 4);

			GraphAlgo::graph graph1 = graph;

			std::pair<int, int> edge1(1, 2);
			std::pair<int, int> edge2(1, 4);
			std::pair<int, int> edge3(2, 4);
			std::pair<int, int> edge4(2, 5);
			std::pair<int, int> edge5(3, 4);

			Assert::IsTrue(graph1.is_edge_in_graph(edge1));
			Assert::IsTrue(graph1.is_edge_in_graph(edge2));
			Assert::IsTrue(graph1.is_edge_in_graph(edge3));
			Assert::IsTrue(graph1.is_edge_in_graph(edge4));
			Assert::IsTrue(graph1.is_edge_in_graph(edge5));
		}

		TEST_METHOD(TestAddEdge)
		{
			GraphAlgo::graph graph;

			graph.add_edge(1, 2);
			graph.add_edge(1, 4);
			graph.add_edge(2, 4);
			graph.add_edge(2, 5);
			graph.add_edge(3, 4);

		    std::pair<int, int> edge1(1, 2);
			std::pair<int, int> edge2(1, 4);
			std::pair<int, int> edge3(2, 4);
			std::pair<int, int> edge4(2, 5);
			std::pair<int, int> edge5(3, 4);

			Assert::IsTrue(graph.is_edge_in_graph(edge1));
			Assert::IsTrue(graph.is_edge_in_graph(edge2));
			Assert::IsTrue(graph.is_edge_in_graph(edge3));
			Assert::IsTrue(graph.is_edge_in_graph(edge4));
			Assert::IsTrue(graph.is_edge_in_graph(edge5));
		}

		TEST_METHOD(TestRemoveEdge)
		{
			GraphAlgo::graph graph;

			graph.add_edge(1, 2);
			graph.add_edge(1, 4);
			graph.add_edge(2, 4);
			graph.add_edge(2, 5);
			graph.add_edge(3, 4);

			std::pair<int, int> edge1(1, 2);
			std::pair<int, int> edge2(1, 4);
			std::pair<int, int> edge3(2, 4);
			std::pair<int, int> edge4(2, 5);
			std::pair<int, int> edge5(3, 4);

			graph.remove_edge(1, 2);
			graph.remove_edge(2, 5);
			graph.remove_edge(3, 4);

			Assert::IsFalse(graph.is_edge_in_graph(edge1));
			Assert::IsTrue(graph.is_edge_in_graph(edge2));
			Assert::IsTrue(graph.is_edge_in_graph(edge3));
			Assert::IsFalse(graph.is_edge_in_graph(edge4));
			Assert::IsFalse(graph.is_edge_in_graph(edge5));
		}

		TEST_METHOD(TestAddVertex)
		{
			GraphAlgo::graph graph;

			graph.add_vertex(1);
			graph.add_vertex(6);
			graph.add_vertex(9);
			graph.add_vertex(2);
			graph.add_vertex(3);

			Assert::IsTrue(graph.is_vertex_in_graph(1));
			Assert::IsTrue(graph.is_vertex_in_graph(6));
			Assert::IsTrue(graph.is_vertex_in_graph(9));
			Assert::IsTrue(graph.is_vertex_in_graph(3));
			Assert::IsTrue(graph.is_vertex_in_graph(2));
		}

		TEST_METHOD(TestRemoveVertex)
		{
			GraphAlgo::graph graph;

			graph.add_vertex(1);
			graph.add_vertex(6);
			graph.add_vertex(9);
			graph.add_vertex(2);
			graph.add_vertex(3);

			graph.remove_vertex(1);
			graph.remove_vertex(6);
			graph.remove_vertex(9);

			Assert::IsFalse(graph.is_vertex_in_graph(1));
			Assert::IsFalse(graph.is_vertex_in_graph(6));
			Assert::IsFalse(graph.is_vertex_in_graph(9));
			Assert::IsTrue(graph.is_vertex_in_graph(3));
			Assert::IsTrue(graph.is_vertex_in_graph(2));
		}
	};
}
