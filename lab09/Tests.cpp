//
// Created by Sofia Demchuk on 30.05.2022.
//

#include "Tests.h"
bool TestOnConstructor()
{
    vector<int>vertex = { 1,2,3,4,5,6,7 };
    vector<vector<int>>edge = { {1,3,10}, {2,1,10}, {2,5,20}, {3,2,15}, {4,5,20}, {4,6,13},{3,7,2} };
    Graph graph(vertex, edge);
    assert(graph(0,2)==10);
    assert(graph(3,5)==13);
    return true;
}
bool TestAlg()
{
    vector<int>vertex = { 1,2,3,4,5,6,7 };
    vector<vector<int>>edge = { {1,3,10}, {2,1,10}, {2,5,20}, {3,2,15}, {4,5,20}, {4,6,13}, {3,7,2} };
    Graph graph(vertex, edge);
    assert(graph.Deykstri(1,3)==10);
    assert(graph.Deykstri(1,7)==12);
    assert(graph.Deykstri(3,5)==35);
    assert(graph.Deykstri(1,5)==45);
    return true;
}
bool isEdge()
{
    vector<int>vertex1 = { 1,2,3,4,5,6};
    vector<vector<int>> edge1 = { {1,3,10}, {2,1,10}, {2,5,20}, {3,2,15}, {4,5,20} };
    Graph graph1(vertex1, edge1);
    assert(graph1.isEdge(1,3)==true);
    assert(graph1.isEdge(1,6)==false);
    return true;
}

void Test1()
{
    assert(TestOnConstructor()==true);
    cout<<"Test on constructor is PASSED!\n";
}
void Test2()
{
    assert(TestAlg()==true);
    cout<<"Test on Deykstri algoritm is PASSED!\n";
}
void Test3()
{
    assert(isEdge()==true);
    cout<<"Test on isEdge() is PASSED!\n";
}