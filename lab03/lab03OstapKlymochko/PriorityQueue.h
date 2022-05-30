#pragma once
#include <list>

using std::list;
class PriorityQueue
{

    list<std::pair<int, int>> queue;

public:
  void enqueue(const int& priority, const int& value);
  int dequeue();
  int size();
  int top();
  void clear();
  bool isEmpty();
};