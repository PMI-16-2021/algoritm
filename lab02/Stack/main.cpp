#include "Stack.h"
#include "SetOfStacks.h"
#include <iostream>

int main()
{
    Stack st;
    st.push(3.);
    st.push(8.);
    st.push(1.);
    st.push(12.);
    st.push(5.);

    st.pop();
    std::cout << "size of stack: " << st.size() << '\n';
    std::cout << "top of stack: " << st.top() << '\n';
    double a = 6.;
    st.emplace(a);
    st.print();
   
    Stack st1;
    st1.push(3.);
    st1.push(2.);
    st1.push(2.);
    st1.push(4.);
    st1.push(11.);

    st.swap(st1);
    std::cout << "after swap content: " << '\n';
    st.print();

    SetOfStacks setOfStacks1(2, 10);
    setOfStacks1.push(4);
    setOfStacks1.push(3);
    setOfStacks1.pop();
    setOfStacks1.pop();
    setOfStacks1.pop();

    SetOfStacks S5(nullptr,5);
    if (S5.isSetEmpty()) std::cout << "Set is empty\n";

    Stack* st2 = new Stack();
    SetOfStacks setOfStacks2(st2, 10);
    SetOfStacks setOfStacks3(&st1, 22);
    std::cout << "Other set of stacks: " << '\n';
    setOfStacks3.print();
    std::cout << "Limit of nodes is: " << setOfStacks2.getMaxNodesLimit();

    return 0;
}