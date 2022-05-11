#include "set_of_stacks.h"
#include "test_functions.h"
using namespace std;

int main() {

    SetOfStacks<int> Stacks;

    Stacks.push(20);
    Stacks.push(1);
    Stacks.push(13);
    Stacks.push(320);
    Stacks.push(19);
    Stacks.push(66);
    Stacks.push(4);
    Stacks.push(177);
    Stacks.push(8);
    Stacks.push(27);
    Stacks.push(78);

    Stacks.pop();
    Stacks.popAt(1);

    Stacks.print();

    cout << "\n";
    resultPush<int>();
    resultPop<int>();
    resultEmpty<int>();
    resultSize<int>();
    resultIsEmpty<int>();

    return 0;
}
