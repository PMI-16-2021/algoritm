
#include "Graph.h"

Graph::Graph(int size)
{
	amount = (size > 1) ? size : 3;
	matrix = new int*[amount];
	for (size_t i = 0; i < amount; i++)
	{
		matrix[i] = new int[amount];
	}
	for (size_t i = 0; i < amount; i++)
	{
		for (size_t j = 0; j < amount; j++)
		{
			matrix[i][j] = int();
		}
	}
}

Graph::~Graph()
{
	for (size_t i = 0; i < amount; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void Graph::add_edge(int v1, int v2, size_t weight)
{
	if (v1 < amount && v2 < amount && weight > 0)
	{
		matrix[v1][v2] = weight;
		matrix[v2][v1] = weight;
	}
}

void Graph::djskra(int start) const
{
	if (start >= amount)
	{
		throw std::invalid_argument("Invalid argument");
	}

	bool* visited = new bool[amount];
	int* dist = new int[amount];
	for (size_t i = 0; i < amount; i++)
	{
		dist[i] = INT_MAX;
		visited[i] = false;
	}
	dist[start] = 0;

	for (size_t i = 0; i < amount; i++)
	{
		int u;
		int min = INT_MAX;
		for (size_t k = 0; k < amount; k++)
		{
			if (!visited[k] && dist[k] <= min)
			{
				min = dist[k];
				u = k;
			}
		}
		visited[u] = true;

		for (size_t j = 0; j < amount; j++)
		{
			if ((!visited[j] && matrix[u][j]) && (dist[u] != INT_MAX) && (dist[u] + matrix[u][j] < dist[j]))
			{
				dist[j] = dist[u] + matrix[u][j];
			}
		}
	}
}
