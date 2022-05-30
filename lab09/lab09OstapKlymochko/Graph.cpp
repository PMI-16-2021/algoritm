#include <climits>
#include<stdexcept>
#include"Graph.h"
using namespace std;

    
    Graph::Graph() = default;

    Graph::Graph(size_t amount)
    :amount(amount)
    {
        dist = new int[amount];
        graph = new int* [amount];
        for (int i = 0; i < amount; i++)
        {
            graph[i] = new int[amount];
            for (int j = 0; j < amount; j++)
            {
                graph[i][j] = 0;
            }
        }
    }

    
    Graph::~Graph() 
    {
        for (int i = 0; i < amount; ++i)
        {
            delete[] graph[i];
        }
        delete[] graph;
        delete[] dist;
    }

    void Graph::add(size_t vertex1, size_t vertex2, size_t weight)
    {
        //���� �� �����, �������� �� ������� � ������� ��� ����������,�� ������ �������
        if (vertex1 == vertex2 || vertex1 >= amount || vertex2 >= amount || graph[vertex1][vertex2] != 0)
        {
            throw invalid_argument("Invalid argument");
        }

        graph[vertex1][vertex2] = weight;
        graph[vertex2][vertex1] = weight;
    }

    void Graph::remove(size_t vertex1, size_t vertex2)
    {
        //���� �� �����, �������� �� �������,�� ������ �������
        if (vertex1 == vertex2 || vertex1 >= amount || vertex2 >= amount)
        {
            throw invalid_argument("Invalid argument");
        }

        graph[vertex1][vertex2] = 0;
        graph[vertex2][vertex1] = 0;
    }

    void Graph::dijkstra(int start)
    {
        if (start >= amount)
        {
            throw invalid_argument("Invalid argument");
        }

        auto* visited = new bool[amount]; //���� true, ���� ������� i-�� �������� � ����������� ���� ���
                                         //����������� ���� �� start (��������� �������) �� i-��� ����������
        for (int i = 0; i < amount; i++)
        {
            dist[i] = INT_MAX;
            visited[i] = false;
        }

        // ³������ �� ��������� ������� ������� 0
        dist[start] = 0;
        // ����������� ���� �� ����� �������
        for (int count = 0; count < amount - 1; count++)
        {

            int u;
            // �������� �������� ������� �� �������
            int min = INT_MAX;
            for (int i = 0; i < amount; i++)
            {
                if (!visited[i] && dist[i] <= min)
                {
                    min = dist[i];
                    u = i;
                }
            }
            // ������� ���� �� �������
            visited[u] = true;
            // ��������� ������ �����
            for (int v = 0; v < amount; v++)
            {
                // ��������� ��������� v-���, ����� ���� �� � visited, � ����� �
                // u �� v, � �������� ���� ����� �� start �� v ����� u �������
                // ����� ��������� �������� dist [v]
                if ((!visited[v] && graph[u][v]) && (dist[u] != INT_MAX) && (dist[u] + graph[u][v] < dist[v]))
                {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    size_t Graph::getDistance(size_t vertex) const 
    {
        if (vertex >= amount) {
            throw invalid_argument("Invalid argument");
        }
        if (dist == nullptr) {
            throw invalid_argument("invalid argument");
        }
        return dist[vertex];
    }

