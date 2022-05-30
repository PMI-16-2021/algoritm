#pragma once
#include <iostream>
#include "Matrix.h"

//Oriented graph class
class Graph
{
private:
	size_t amount;                     //number of vertices          
	SparceMatrix<unsigned> matrix;          //Sparce matrix for vertices
	int* djskra_res;                   //array for djkstra results
public:
	Graph();                           //default Graph: no edges
	Graph(int size);                   //graph of *size* vertices
	~Graph();                          
	int getVertex() const;
	void add_edge(int v1, int v2, size_t weight); //add oriented edge: from *v1* to *v2* with *weight* 
	void djskra(int start) const;                 //djskra algorithm: fills *djskra_res* array 
	                                              //in format index: vertice, value - shortest distance 
	void print_matrix() const;                    //print weights Sparce matrix
	int* get_djskra_results() const;              //returns copy of djskra_res
	void print_djskra() const;                    //print result of djskra algorithm
};

