#pragma once

class Graph
{
private:

    size_t amount;   //Кількість вершин (vertex)
    int** graph;  //Матриця суміжності графа
    int* dist;    //Дистанції між точками

public:
    Graph();  //Конструктор за замовчуванням
    Graph(size_t amount);    //Конструктор за параметром
    ~Graph(); //Деструктор
    void add(size_t vertex1, size_t vertex2, size_t weight);     //Добавляємо ребро в граф
    void remove(size_t vertex1, size_t vertex2);    //Видаляємо ребро
    void dijkstra(int start);
    size_t getDistance(size_t vertex) const;     //Дістаємо відстань
};