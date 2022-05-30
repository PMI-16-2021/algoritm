#include <list>
#include<string>
#include"PriorityQueue.h"
using namespace std;



    void PriorityQueue::enqueue(const int& priority, const int& value)
    {
        for (auto it = queue.begin(); it != queue.end(); it++)
        {
            if (it->first > priority)
            {
                queue.insert(it, pair<int, int>(priority, value));
                return;
            }
        }
        queue.emplace_back(pair<int, int>(priority, value));
    }

    int PriorityQueue::dequeue()
    {
        int result = queue.front().second;
        queue.erase(queue.begin());
        return result;
    }

    int PriorityQueue::size()
    {
        return queue.size();
    }

    int PriorityQueue::top()
    {
        return queue.front().second;
    }

    void PriorityQueue::clear()
    {
        queue.clear();
    }

    bool PriorityQueue::isEmpty()
    {
        return queue.empty();
    }
