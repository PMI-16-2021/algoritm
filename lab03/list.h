#include <iostream>
#pragma once
using namespace std;
template <typename T>
struct Node
{
    T data;
    Node<T> * next;
    Node(T value);
    Node(T value,Node<T>* _next );

};

template<typename T>
Node<T>::Node(T value) : data(value), next(nullptr){}

template<typename T>
Node<T>::Node(T value, Node<T> *_next) : data(value), next(_next){}

template <typename T>
class List
{
private:
    Node<T> * top;
    Node<T>* end;
public:
    List();
    List(Node <T> * _top,Node<T> * _end);
    void push_front( T elem); // add a value from the top
    void push_back(T elem);// add a value from the end
    void pop(int index);//delete a value by index
    void print(); //print our list
    bool isEmpty();//check if list is empty
    void clear();//clear all list
    void delTop();//delete top node
    int getSize()const;//check the size of list
    Node<T>* getTop(){return top;} // pointer to top
    Node<T>* getEnd(){return end;}//pointer to tail
    void insert(int index,const T& value );//insert a value by index
    T popFront();//delete from front
    T getData(){return top->data;}//get top value

};

template<typename T>
List<T>::List() : top(nullptr), end(nullptr){}

template<typename T>
List<T>::List(Node<T> *_top, Node<T> * _end): top(_top) , end(_end){}

template<typename T>
void List<T>::push_front(T elem)
{
    Node<T>* newNode = new Node<T>(elem,top);

    // Assign to head
    if (top== nullptr)
    {
        end = newNode;


    }
    top=newNode;
    newNode= nullptr;
}

template<typename T>
void List<T>::print()
{
    Node<T>* temp = top;

    // Check for empty list.
    if (top== nullptr)
    {
        cout<<"is emtpy";
        return;
    }

    // Traverse the list.
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
        cout<<"\n";
    }

}

template<typename T>
bool List<T>::isEmpty()
{
    return(top== nullptr&& end== nullptr);
}

template<typename T>
void List<T>::pop(int index)
{
    Node<T> *temp1 = top;
    Node<T> *temp2 = nullptr;
    int lenght = 0;

    if (isEmpty())
    {
        cout<<"is empty";
        return;
    }

    while (temp1 != nullptr)
    {
        temp1 = temp1->next;
        lenght++;
    }
    if (lenght < index)
    {
      throw "Index out of range";
        return;
    }

    temp1 = top;

    // Deleting the head.
    if (index == 0)
    {

        // Update head
        top = top->next;
        delete temp1;
        return;
    }
    while (index-- > 0)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    temp2->next = temp1->next;
    delete temp1;
}

template<typename T>
void List<T>::clear()
{
    while(!isEmpty())
    {
       popFront();
    }
}

template<typename T>
void List<T>::push_back(T elem)
{
    Node<T>*temp= new Node<T>(elem);
    if (top== nullptr)
    {
       top= end = temp;
        temp= nullptr;
        return;
    }
    end->next = temp;
    end = temp;
}

template<typename T>
void List<T>::delTop()
{
     Node<T>* temp=top;
     top=top->next;
     delete temp;
     temp= nullptr;
}

template<typename T>
int List<T>::getSize() const
{
    int counter = 0;
    Node<T>* temp = top;
    while(temp != nullptr)
    {
        counter++;
        temp = temp->next;
    }
    return counter;
}

template<typename T>
void List<T>::insert(int index,const T& value)
{
    if(index<0)
    {
        throw "Bad index";
    }
    if(index>getSize()-1)
    {
        push_back(value);
        return;
    }
    if(index == 0 && !isEmpty())
    {
        push_front(value);
        return;
    }
    else if(isEmpty())
    {
        push_back(value);
        return;
    }
    Node<T>* ptr=new Node<T>(value);
    Node<T>* temp=top;
    while(index > 1 && temp != end)
    {
        temp=temp->next;
        --index;
    }
    Node<T> *curr =temp;// like link
    temp=temp->next;
    curr-> next=ptr;
    ptr->next=temp;
    curr=nullptr;
    temp=nullptr;
    ptr=nullptr;
}

template<typename T>
T List<T>::popFront()
{
    Node<T>* temp = top->next;
    T t_val = top->data;
    if(getSize() == 1)
    {
        end = temp;
    }
    delete top;
    top = temp;
    return t_val;
}

