#pragma once
#include "List.h"


template<typename T, template<typename T> class Holder = Pair>
class PriorityQueue
{
private:
	List<Holder, T> object;

public:

	PriorityQueue(): object(List<Holder, T>()){}
	~PriorityQueue(){}

	void enQueue(T elem, int prior)
	{

	}

};


