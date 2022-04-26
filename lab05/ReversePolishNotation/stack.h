#ifndef CMAKETESTSETUP_STACK_H
#define CMAKETESTSETUP_STACK_H
#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

class Stack
{
private:
    char* stack;
    int quantity;
public:
    Stack() { stack = nullptr; quantity = 0; }
    Stack(const Stack& S);
    Stack operator=(const Stack& S);
    int size() { return quantity; }
    char push(char new_element);
    char pop();
    bool isEmpty();
    char top();
    void print();
    ~Stack() { if (quantity > 0) delete[] stack; }
};

bool emptySpace(char symbol);
string infixToPostfix(string infix);
int priority(char symbol);
bool isNum(char symbol);
int action(string postfix);
#endif //CMAKETESTSETUP_STACK_H
