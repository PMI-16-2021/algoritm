
#include "Stack.h"

Node::Node(int NodeValue, Node *Nodeptr)  : value(NodeValue) , ptr(Nodeptr){}

Stack::Stack():head(nullptr)
{


}

Stack::Stack(int value)
{
    head = new Node(value, nullptr);
    ++size;
    next= nullptr;
}

int Stack::push(int value)
{
    Node* next  = new Node(value,head);
    head=next;
    ++size;
}

bool Stack::isEmpty() const
{
    return (head == nullptr);
}


void Stack::delTop()
{
    if(isEmpty()) return;

    Node* temp=head;
    head =head->ptr;
    delete temp;
    --size;
}
void Stack::print() const
{
    Node* temp;
    if (head == nullptr)
    {
        throw "\nStack is empty\n";

    }
    else
    {
        temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->value << "\n";
            temp = temp->ptr;
        }
    }


}

int Stack::pop()
{
    int retValue = -1;
    if(!isEmpty())
    {
        retValue = head->value;
        delTop();
    }
    --size;
    return retValue;
}

int Stack::getSize() {
    int size_ = 0;
    Node* temp= head;

    if (temp->ptr == nullptr)
    {
        return 0;
    }
    else
    {
        while (temp != nullptr)
        {
            ++size_;
            temp = temp->ptr;
        }
    }
    return size_;
}
void Stack::swap(Stack& stack)
{
    Node* temp=this->head;
    this->head=stack.head;
    stack.head=temp;
}

void Stack::emplace(int &value)
{
    if (isEmpty())
    {
       throw  "Stack is empty;";

    }
    else
    {
        Node* val = new Node(value, nullptr);
        val->ptr = head;
        head = val;
        head->value = value;
    }
}

int Stack::topValue()
{
    return head->value;
}




