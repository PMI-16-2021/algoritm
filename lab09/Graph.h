#pragma once
#include<queue>
#include<iostream>
#include<vector>
#define infinity 100 //borders to distance
using namespace std;

class Graph
{
private:
    int size; //size of graph vertex
    vector<int> vertex;  //container to save vertex
    int** matrix_adjacent;// matrix of adjacent
public:
    Graph(vector<int>vertex, vector<vector<int>> edges); //constructor to create graph
    void print();//to output matrix
    int getSize(){return size;}// to get size of vertex
    int Deykstri(int start, int end); //function to find way between one vertex to another
    int operator()(int row, int col) const; // this is getter for value from graph
    bool isEdge(int i, int j);// method check if there is a path between two edges
};