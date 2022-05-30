#include<iostream>
#include<time.h>
#include<cassert>
#include<iomanip>
using namespace std;
bool TestPush();
bool TestPop();
bool TestEmpty1();
bool TestEmpty2();
bool TestSize();
bool TestTop();
bool TestSwap();
struct STACK
{
    int num;
    STACK* next;
};
class Stack {
public:
    void push(int);
    void pop();
    bool is_empty();
    int size_Stack();
    void emplace();
    //void Print_Stack();
    STACK* head;
    int top();
    void Swap(Stack&);
    Stack();
    int size;
};
class SetOfStacks {
public:
    Stack stack_1;
    Stack stack_2;
    Stack stack_3;
    const int Limit = 9;
    void push(int);
    int popAt(int);
    bool audit(Stack);
};
int main() {
    srand(unsigned(time(0)));
    assert(TestPush());
    assert(TestPop());
    assert(TestEmpty1());
    cout << "\nTest passed successfully\n";
    assert(TestEmpty2());
    cout << "\nTest passed successfully\n";
    assert(TestSize());
    cout << "\nTest passed successfully\n";
    assert(TestTop());
    cout << "\nTest passed successfully\n";
    assert(TestSwap());
    cout << "\nTest passed successfully\n";
    SetOfStacks set1;
    for (int i = 0; i < 32; i++) set1.push(rand() % 9 + 1);
    cout << "\nStack1: ";
    for (int i = 0; i < 10; i++, cout << " ") cout << set1.popAt(1);
    cout << "\nStack2: ";
    for (int i = 0; i < 10; i++, cout << " ") cout << set1.popAt(2);
    cout << "\nStack3: ";
    for (int i = 0; i < 10; i++, cout << " ") cout << set1.popAt(3);
}
bool TestPush() {

    cout << "\nTest push\n";
    int arr[5] = { 1,2,3,4,5 };
    Stack st;
    for (int i = 0; i < 5; i++) st.push(arr[i]);
    cout << "Stack\tarray\n";
    for (int i = 4; i >= 0; i--) {
        cout << setw(2) << st.top() << "\t" << setw(2) << arr[i] << endl;
        if (st.top() != arr[i]) return false;
        st.pop();
    }
    cout << "\nTest passed successfully\n";
    return true;
}
bool TestPop() {
    cout << "\nTest pop\n";
    int* arr = new int[5]{ 1,2,3,4,5 };
    Stack st; 
    for (int i = 0; i < 5; i++) st.push(arr[i]);
    st.pop(); delete[] arr; arr = new int[4]{ 1,2,3,4 };
    cout << "Stack\tarray\n";
    for (int i = 3; i >= 0; i--) {
        cout << setw(2) << st.top() << "\t" << setw(2) << arr[i] << endl;
        if (st.top() != arr[i]) { delete[] arr; return false; }
        st.pop();
    }
    cout << "\nTest passed successfully\n";
    delete[] arr;
    return true;
}
bool TestEmpty1() {
    cout << "\nTest empty1\n";
    Stack st;
    return st.is_empty();
}
bool TestEmpty2() {
    cout << "\nTest empty2\n";
    Stack st; st.push(4);
    return (!st.is_empty());
}
bool TestSize() {
    cout << "\nTest size\n";
    int* arr = new int[5]{ 1,2,3,4,5 };
    Stack st;
    for (int i = 0; i < 5; i++) st.push(arr[i]);
    /*while (st.head) {
        cout << st.top() << " ";
        st.pop();
    }*/
    delete[] arr;
    return (st.size_Stack() == 5);
}
bool TestTop() {
    cout << "\nTest top\n";
    int arr[5] = { 1,2,3,4,5 };
    Stack st;
    for (int i = 0; i < 5; i++) st.push(arr[i]);
    return (st.top() == 5);
}
bool TestSwap() {
    cout << "\nTest swap\n";
    int arr[2] = { 1,2 };
    Stack st;
    for (int i = 0; i < 2; i++) st.push(arr[i]);
    Stack st1; st1.push(2); st1.push(1);
    st.Swap(st1);
    for (int i = 1; i >=0; i--) {
        if (st1.top() != arr[i]) return false;
        st.pop(); st1.pop();
    }
    return true;
}
void Stack::push(int number) {

    STACK* q = head;
    head = new STACK;
    /*head->number = new char[strlen(text) + 1];*/
    //size++;
    head->num = number;
    head->next = q;
}
void Stack::pop() {
    STACK* t = 0;
    t = head->next;
    delete[] head;
    head = t;
}
bool Stack::is_empty()
{
    if (!head) {
        puts("\nSTACK is Empty\n");
        return true;
    }
    return false;
}
int Stack::size_Stack()
{
    for (head; head; head = head->next) size++;
    //cout << "\n THE SIZE OF STACK: \n" << size << endl;
    return size;
}
void Stack::emplace() {
    int num = rand() % 9 + 1;
    push(num);
    puts("\nElement is created\n");
}
Stack::Stack() {
    head = nullptr;
    size = 0;
}
//void Stack::Print_Stack() {
//    puts("\nContent of the Stack\n");
//    if (is_empty()) cout << "\nSTACK is Empty\n";
//    STACK* p = head;
//    while (p) {
//        cout << p->num << "\n";
//        p = p->next;
//    }
//}
void Stack::Swap(Stack& Stek)
{
    STACK* t = Stek.head;
    Stek.head = this->head;
    this->head = t;
}
int Stack::top()
{
    return head->num;
}
bool  SetOfStacks::audit(Stack A) {
    if (A.size_Stack() > Limit) {
        return false;
    }
    return true;
}
int  SetOfStacks::popAt(int index) {
    int numb;
    switch (index)
    {
    case 1:   numb = stack_1.top(); stack_1.pop();
        return numb;
    case 2:   numb = stack_2.top(); stack_2.pop();
        return numb;
    case 3:   numb = stack_3.top(); stack_3.pop();
        return numb;
    }
    return 0;
}
void SetOfStacks::push(int number)
{
    if (audit(stack_1)) {
        stack_1.push(number);
    }
    else if (audit(stack_2)) {
        stack_2.push(number);
    }
    else if (audit(stack_3)) {
        stack_3.push(number);
    }
    else {
        puts("ALL STACK IS FULL");
    }
}