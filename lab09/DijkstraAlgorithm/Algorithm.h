#pragma once
#include <vector>
#include <map>
#include <utility> 

namespace GraphAlgo
{

	typedef int vertex;
	typedef std::vector<int> vertices;
	typedef std::pair<int, int> edge;
	typedef std::vector<edge> edges;
	typedef std::map<vertex, vertices> neighborhood;

	class graph
	{
	private:
		edges m_edges;
		vertices m_vertices;
		neighborhood m_neighborhood;

	public:
		void print_neighborhood() const;

		void remove_vertex(vertex);
		void remove_edge(vertex, vertex);

		bool is_vertex_in_graph(const vertex&) const;
		bool is_edge_in_graph(const edge&) const;
		bool is_edge_in_graph(const vertex&, const vertex&) const;

		neighborhood get_neighborhood() const;
		vertices get_neighbors(const vertex&);
		edges get_edges() const;
		vertices get_vertices() const;

		void add_neighborhood(const neighborhood&);
		void add_vertices(const vertices&);
		void add_vertex(const vertex&);
		void add_edges(const edges&);
		void add_edge(const vertex&, const vertex&);
		void add_edge(const edge&);

		graph(const neighborhood&);
		graph(const graph&);
		graph();
		~graph();
		graph& operator=(const graph&);
	};
}; 