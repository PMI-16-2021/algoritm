#pragma once

class Graph
{
private:

    size_t amount;   //ʳ������ ������ (vertex)
    int** graph;  //������� �������� �����
    int* dist;    //��������� �� �������

public:
    Graph();  //����������� �� �������������
    Graph(size_t amount);    //����������� �� ����������
    ~Graph(); //����������
    void add(size_t vertex1, size_t vertex2, size_t weight);     //���������� ����� � ����
    void remove(size_t vertex1, size_t vertex2);    //��������� �����
    void dijkstra(int start);
    size_t getDistance(size_t vertex) const;     //ĳ����� �������
};