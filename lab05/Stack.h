#pragma once
#include<iostream>
using namespace std;
#include "cmath"
char infix[150], postfix[150]; //variables to store records

class Stack
{
private:
    int used = 0; //top
    static const  int size = 150; //size of array
    char stack[size];
public:
    void Push(char symbol) //add symbol
    {
        if (used > 150)
        {
            throw "Stack overflow. Too many elements!\n";
        }
        else
        {
            stack[++used] = symbol;
        }
    }
    char Pop() //delete element of top
    {
        if (IsEmpty())
        {
            throw "Stack underflow. There are no elements in stack\n";
        }
        else return stack[used--];
    }
    bool IsEmpty() // check if stack is empty
    {
        if (used == 0)
            return true;
        else return false;
    }
    bool Empty_space(char symbol) // check if it is no spaces
    {
        if (symbol == ' ' || symbol == '\t')
            return true;
        else return false;
    }
    int priority(char symbol) // priority of operation
    {
        switch (symbol)
        {
            case '(':return 0;
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
            case '%':
                return 2;
            case '^': return 3;
            default:
                return -1;
        }
    }

    void Infix_to_Postfix() // converts infix note to postfix note
    {
        int inf, post = 0; //index of variables that store records
        char next;
        char symbol;
        for (inf = 0; inf < strlen(infix); ++inf) //strlen-length of infix
        {

            symbol = infix[inf] ;
            if (!Empty_space(symbol))
            {
                switch (symbol)
                {
                    case '(': Push(symbol); //add to stack
                        break;
                    case ')':
                        while ((next = Pop()) && next != '(') // remove from stack and put in variable next
                        {
                            postfix[post++] = next; // next put in postfix
                        }
                        break;
                    case '+':
                    case '-':
                    case '*':
                    case '/':
                    case '%':
                    case '^':
                        while (!IsEmpty() && priority(symbol) <= priority(stack[used])) //check if priority of operation
                        {																// less than privious
                            postfix[post++] = Pop(); //remove and put in postfix
                        }
                        Push(symbol);
                        break;
                    default:  // if symbol is number
                        postfix[post++] = symbol;
                }
            }

        }
        while (!IsEmpty())
        {
            postfix[post++] = Pop();
        }
        postfix[post] = '\0';
    }
    bool IsNumber(char symbol) // check if symbol  is number
    {

        return (symbol >= '0' && symbol <= '9' || symbol == '_');
    }
    int CountExpression() //count the expression in postfix
    {
        int a, b, i, temp_result, result; //a and b are numbers with them doing operation
        for (i = 0; i < strlen(postfix); i++)
        {
            if (IsNumber(postfix[i]))
            {
                Push(postfix[i] - '0'); //convert char number to int number and put it in stack
            }
            else
            {
                a = Pop(); //if it's not a number than we make the operation with
                b = Pop(); // last two operands in stack;
                switch (postfix[i])
                {
                    case '+':
                        temp_result = b + a;
                        break;
                    case '-':
                        temp_result = b - a;
                        break;
                    case '*':
                        temp_result = b * a;
                        break;
                    case '/':
                        temp_result = b / a;
                        break;
                    case '%':
                        temp_result = b % a;
                        break;
                    case '^':
                        temp_result = pow(b, a);
                        break;
                }
                Push(temp_result); //add to stack temp_result
            }
        }
        result = Pop(); // the finall result delete from stack and put in result
        return result;
    }
};
