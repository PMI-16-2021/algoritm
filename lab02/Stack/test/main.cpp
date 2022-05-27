#include <gtest/gtest.h>
#include "SetOfStacks.h"

int main() {
    Stack *stack = new Stack();
    stack->push(1);
    stack->push(2);
    SetOfStacks setOfStacks(stack, 10);
    std::cout << "\n-------------------\n";
    //check push method
    //Stack1 (remember that according to stack description this stack will be the last stack in the set)
    setOfStacks.push(10);
    setOfStacks.push(9);
    setOfStacks.push(8);
    setOfStacks.push(7);
    setOfStacks.push(6);
    setOfStacks.push(5);
    setOfStacks.push(4);
    setOfStacks.push(3);
    //Stack2
    setOfStacks.push(10);
    setOfStacks.push(9);
    setOfStacks.push(8);
    setOfStacks.push(7);
    setOfStacks.push(6);
    setOfStacks.push(5);
    setOfStacks.push(4);
    setOfStacks.push(3);
    setOfStacks.push(2);
    setOfStacks.push(1);
    //Stack3
    setOfStacks.push(9);
    setOfStacks.push(8);
    setOfStacks.push(7);
    setOfStacks.push(6);
    setOfStacks.push(5);
    setOfStacks.push(4);
    setOfStacks.push(3);
    setOfStacks.push(3);
    setOfStacks.push(2);
    //check pop method
    setOfStacks.pop();
    setOfStacks.pop();
    setOfStacks.pop();
    setOfStacks.pop();
    //print Set Of Stacks
    setOfStacks.print();
    //check if
    std::cout << "Amount of stacks: " << setOfStacks.size() << '\n';
    //check method popAt with number of stack that does not exist
    setOfStacks.popAt(4);
    setOfStacks.print();
    //check method popAt with correct number
    setOfStacks.popAt(3);
    setOfStacks.print();

    //test how does Empty SetOfStacks constructor word
    SetOfStacks setOfStacks4;
    std::cout << "\nSet of Stacks size is: " << setOfStacks4.size() << '\n';
    setOfStacks4.push(3);
    setOfStacks4.push(4);
    setOfStacks4.print();

    return 0;
}