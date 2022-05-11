#include "stack.h"
#include <string>
#include <cmath>

bool isNum(char m_num)
{
	switch (m_num)
	{
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		return true;
	default:
		return false;
	}
}

bool isOperator(char m_operator)
{
	switch (m_operator)
	{
	case '+':
	case '-':
	case '*':
	case '/':
	case '^':
		return true;
	default:
		return false;
	}
}

int priority(char m_priority)
{
	switch (m_priority)
	{
	case '^':
		return 3;
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	default:
		return -1;
	}
}

std::string infixToPostfix(std::string infix)
{
	Stack<char> stack;
	std::string res;
	for (int i = 0; i < infix.length(); ++i)
	{
		char temp = infix[i];
		if (isNum(temp))
		{
			res += temp;
			if (!isNum(infix[i + 1]))
			{
				res += ' ';
			}
		}
		else if (temp == '(')
		{
			stack.push(temp);
		}
		else if (temp == ')')
		{
			while (stack.top() != '(')
			{
				res += stack.top();
				stack.pop();
				res += ' ';
			}
			stack.pop();
		}
		else
		{
			while (!stack.isEmpty() && priority(infix[i]) <= priority(stack.top()))
			{
				res += stack.pop();
				res += ' ';
			}
			stack.push(temp);
		}
	}
	while (!stack.isEmpty())
	{
		res += stack.pop();
	}
	return res;
}

double action(std::string postfix)
{
	double firstNum, secondNum, result;
	std::string temp;
	Stack<std::string> stack;
	for (int i = 0; i < postfix.length(); ++i)
	{
		while (postfix[i] == ' ')
		{
			++i;
		}
		if (isNum(postfix[i]))
		{
			while (isNum(postfix[i]))
			{
				temp += postfix[i];
				++i;
			}
			stack.push(temp.c_str());
			temp = "";
		}
		else if (isOperator(postfix[i]))
		{
			firstNum = std::stod(stack.pop());
			secondNum = std::stod(stack.pop());
			if (postfix[i] == '+')
			{
				result = firstNum + secondNum;
			}
			if (postfix[i] == '-')
			{
				result = secondNum - firstNum;
			}
			if (postfix[i] == '*')
			{
				result = firstNum * secondNum;
			}
			if (postfix[i] == '/')
			{
				if (firstNum == 0)
				{
					throw "Incorrect input";
				}
				result = secondNum / firstNum;
			}
			if (postfix[i] == '^')
			{
				result = pow(secondNum, firstNum);
			}
			stack.push(std::to_string(result));
		}
	}
	return std::stod(stack.pop());
}