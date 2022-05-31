#include "Algorithm.h"
#include "Dijkstra.h"
#include <iostream>

extern const std::vector<std::string> graph_data;
extern const std::vector<std::string> graph_data_dfs;
extern const std::vector<std::string> graph_data_connectivity;
extern const std::vector<std::string> graph_data_biconnectivity;
extern const std::vector<std::string> graph_data_dijkstra;

int main()
{
	GraphAlgo::graph g;

	g.add_edge(1, 2);
	g.add_edge(1, 4);
	g.add_edge(2, 4);
	g.add_edge(2, 5);
	g.add_edge(3, 4);
	g.add_edge(3, 6);
	g.add_edge(3, 12);
	g.add_edge(3, 13);
	g.add_edge(4, 6);
	g.add_edge(4, 7);
	g.add_edge(5, 7);
	g.add_edge(6, 11);
	g.add_edge(6, 12);
	g.add_edge(7, 10);
	g.add_edge(7, 11);
	g.add_edge(8, 10);
	g.add_edge(8, 16);
	g.add_edge(9, 10);
	g.add_edge(9, 11);
	g.add_edge(9, 15);
	g.add_edge(10, 16);
	g.add_edge(11, 14);
	g.add_edge(12, 13);
	g.add_edge(14, 15);
	g.add_edge(15, 16);


	std::cout << "Printing graph as adjacency-list:" << std::endl;
	g.print_neighborhood();
	std::cout << std::endl << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~ Dijkstra's Algorithm ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	std::cout << std::endl << std::endl;

	GraphAlgo::dijkstra dijk(g);

	dijk.set_edge_weight(1, 2, 1);
	dijk.set_edge_weight(1, 4, 5);
	dijk.set_edge_weight(2, 4, 3);
	dijk.set_edge_weight(2, 5, 2);
	dijk.set_edge_weight(3, 4, 4);
	dijk.set_edge_weight(3, 6, 2);
	dijk.set_edge_weight(3, 12, 3);
	dijk.set_edge_weight(3, 13, 1);
	dijk.set_edge_weight(4, 6, 6);
	dijk.set_edge_weight(4, 7, 3);
	dijk.set_edge_weight(5, 7, 1);
	dijk.set_edge_weight(6, 11, 5);
	dijk.set_edge_weight(6, 12, 1);
	dijk.set_edge_weight(7, 10, 2);
	dijk.set_edge_weight(7, 11, 9);
	dijk.set_edge_weight(8, 10, 1);
	dijk.set_edge_weight(8, 16, 1);
	dijk.set_edge_weight(9, 10, 3);
	dijk.set_edge_weight(9, 11, 4);
	dijk.set_edge_weight(9, 15, 2);
	dijk.set_edge_weight(10, 16, 3);
	dijk.set_edge_weight(11, 14, 1);
	dijk.set_edge_weight(12, 13, 2);
	dijk.set_edge_weight(14, 15, 1);
	dijk.set_edge_weight(15, 16, 2);

	dijk.shortest_paths_from(1);
	dijk.get_shortest_path_to(14);
	dijk.print_path();
	std::cout << std::endl;

	// another shortest path: from 1 to 9
	dijk.get_shortest_path_to(9);
	dijk.print_path();
	std::cout << std::endl;

	// another shortest path: from 13 to 8
	dijk.shortest_paths_from(13);
	dijk.get_shortest_path_to(8);
	dijk.print_path();

	std::cout << std::endl << std::endl;
}