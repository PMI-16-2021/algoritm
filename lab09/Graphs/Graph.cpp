#include "Graph.h"

//default Graph constructor
Graph::Graph()
{
	amount = 1;                          
	matrix = SparceMatrix<unsigned>(amount, amount);
	djskra_res = new int[amount];
	for (size_t i = 0; i < amount; i++)
	{
		djskra_res[i] = INT_MAX;        //don't know shortest distances
	}
}

//param
Graph::Graph(int size)
{
	amount = (size > 1) ? size : 1;
	matrix = SparceMatrix<unsigned>(amount, amount);
	djskra_res = new int[amount];
	for (size_t i = 0; i < amount; i++)
	{
		djskra_res[i] = INT_MAX;       //don't know shortest distances
	}
}

//deletes Sparce Matrix
//adn djskra_res
Graph::~Graph()
{
	delete[] djskra_res;
}

//add ORIENTED edge
void Graph::add_edge(int v1, int v2, size_t weight)
{
	if (v1 < amount && v2 < amount && weight > 0) //if valid data
	{
		matrix.set(v1, v2, weight);               //set to Sparce Matrix
	}
}

//returns number of Vertices 
int Graph::getVertex() const
{
	return amount; 
}

//main Djskra algorithm
void Graph::djskra(int start) const
{
	if (start >= amount)
	{
		throw std::invalid_argument("Invalid argument");
	}

	bool* visited = new bool[amount];    //label bool-array
	for (size_t i = 0; i < amount; i++) 
	{
		djskra_res[i] = INT_MAX;         //unknown distances
		visited[i] = false;              //all are not visited
	}
	djskra_res[start] = 0;               //distance to this vertice is 0

	for (size_t i = 0; i < amount; i++)
	{
		int temp_vertice;
		int min = INT_MAX;
		for (size_t k = 0; k < amount; k++)
		{
			if (!visited[k] && djskra_res[k] <= min) //if not visited and min dist is lower
			{
				min = djskra_res[k];                 //remember distance
				temp_vertice = k;                    //remember vertice
			}
		}
		visited[temp_vertice] = true;                //we visited this vertice!

		for (size_t j = 0; j < amount; j++)
		{
			if ((!visited[j] && matrix[temp_vertice][j] != 0)                              //if not visited yet and edge exists
				&& (djskra_res[temp_vertice] + matrix[temp_vertice][j] < djskra_res[j]))   //and dist to temp + edge to j is less than written is result arr
			{
				djskra_res[j] = djskra_res[temp_vertice] + matrix[temp_vertice][j];        //update distance (decrease it)
			}
		}
	}
}

//print wieght matrix of Graph
void Graph::print_matrix() const
{
	std::cout << "Weights matrix for Graph: \n";
	matrix.print();
}

//print results of djskra alg work
void Graph::print_djskra() const
{
	std::cout << "==================================\n";
	std::cout << "Djskra results: \n";
	for (size_t i = 0; i < amount; i++)
	{
		std::cout << "Vertex: |" << i << "| shortest distance: ";
		std::cout.width(2);
		std::cout << djskra_res[i] << '\n';
	}
	std::cout << "==================================\n";
}

int* Graph::get_djskra_results() const
{
	int* copy = new int[amount];           //copy array
	for (size_t i = 0; i < amount; i++) 
	{
		copy[i] = djskra_res[i];
	}
	return copy;                           //return copy
}
