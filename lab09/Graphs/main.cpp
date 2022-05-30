#include "Graph.h"
using std::cin;
using std::cout;

int main()
{
	Graph A(6);

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
	A.print_matrix();
	A.get_djskra_results();

	A.djskra(0);
	A.print_djskra();

	



	system("pause");
	return 0;
}