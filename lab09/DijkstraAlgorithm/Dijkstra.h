#pragma once
#include <limits> 
#include <map>
#include <set>
#include <list>
#include "Algorithm.h"

namespace GraphAlgo
{
	const double infinity = std::numeric_limits< double >::infinity();

	typedef std::set< std::pair<double, vertex> > vertex_queue;
	typedef std::map<vertex, double> vertex_distance;
	typedef std::map<vertex, vertex> vertex_previous;
	typedef std::map<edge, double> edge_weight;
	typedef std::list<vertex> vertex_path;

	class dijkstra
	{
	private:
		graph g_in;
		vertices m_vertices;
		edges m_edges;
		neighborhood m_neighborhood;

		vertex_path v_path;

		vertex_previous v_previous;
		vertex_distance v_distance;
		vertex_queue v_queue;
		edge_weight e_weight;

		void relaxation(const vertex&, const vertex&);
		void initialize(const vertex&);

	public:
		void print_path();

		vertex_path get_shortest_path_to(const vertex&);

		void set_edge_weight(const vertex&, const vertex&, double);
		void set_edge_weight(const edge&, double);

		double get_edge_weight(const vertex&, const vertex&);

		void shortest_paths_from(const vertex&);

		dijkstra(const graph&);
		~dijkstra();
	};
}; 