#include <iostream>
#include "stack.h"
#include "setOfStacks.h"
using namespace std;

int main() {
    cout << "Stack\n";
    Stack S;
    S.push(10);
    S.push(20);
    S.push(15);
    S.push(21);
    Stack B;
    for (size_t i = 0; i < 40; i += 4) {
        B.push(i);
    }
    S.print();
    B.print();
    S.emplace(8);
    B.pop();
    cout << "\n";
    S.print();
    B.print();
    S.swap(B);
    cout << "\n";
    S.print();
    B.print();

    cout << "\nSet of Stack\n";
    Stack* stack = new Stack();
    SetOfStacks setOfStacks(stack, 5);

    for (int i = 0; i < 20; ++i) {
        setOfStacks.push(i + 1);
    }
    setOfStacks.print();
    cout << "Number of stacks: " << setOfStacks.getNumber() << "\n\n";

    for (int i = 0; i < 3; ++i) {
        setOfStacks.pop();
    }
    setOfStacks.print();
    cout << "\n\n";

    setOfStacks.popAt(2);
    setOfStacks.print();

    system("pause");
    return 0;
}