#include "Graph.h"

Graph::Graph(vector<int> vertex, vector<vector<int>> edges) {
    this->vertex = vertex;
    size = vertex.size();
    matrix_adjacent = new int* [size];// we create 2 dimension-matrix
    for (int i = 0; i < size; ++i)
    {
        matrix_adjacent[i] = new int[size];
    }
    for (int i = 1; i <= size; ++i)
    {
        for (int j = 1; j <= size; ++j)
        {
            matrix_adjacent[i - 1][j - 1] = 0;
            for (int k = 0; k < edges.size(); ++k)
            {
                if (edges[k][0] == i && edges[k][1] == j)
                {
                    matrix_adjacent[i - 1][j - 1] = edges[k][2];
                    break;
                }
            }
        }
    }
}

int Graph::Deykstri(int start, int end)
    {
        --start; --end;
        vector<int> distance(size, infinity);
        distance[start] = 0; //null the start
        priority_queue<pair<int, int>> q;
        q.push(make_pair(0, start));
        while (!q.empty())
        {
            int len = q.top().first;
            int v = q.top().second;
            q.pop();
            if (len > distance[v]) continue;
            for (int i = 0; i < size; ++i)
            {
                int to = i;
                int lenght = matrix_adjacent[v][i];
                if (matrix_adjacent[v][to] != 0 && distance[to] > distance[v] + lenght && lenght >= 0)
                {
                    distance[to] = distance[v] + lenght;
                    q.push(make_pair(distance[to], to));
                }
            }
        }
        if (distance[end] == infinity)//there is no path
        {
            cout << "The path from " << start + 1 << " to " << end + 1 << " does not exist!" << endl;
            return infinity;
        }
        else
        {
            cout << "Distance from " << start + 1 << " to " << end + 1 << ": " << distance[end] << endl;
            return distance[end];
        }
}

int Graph::operator()(int row, int col) const
{
        return matrix_adjacent[row][col];// kile getter
}

void Graph::print()
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            cout << matrix_adjacent[i][j] << '\t';
        }
        cout << endl;
    }
}

bool Graph::isEdge(int i ,int j) // method check if there is a path between two edges
{
    if (i >= 0 && i < vertex.size() && j >= 0 && j < vertex.size())
    {
        return true;
    } else
    {
        std::cout << "Invalid vertex number.\n";
        return false;
    }
}
