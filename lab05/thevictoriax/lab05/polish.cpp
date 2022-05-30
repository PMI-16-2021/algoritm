#include "polish.h"
#include "Stack.h"
#include <string>
#include <cmath>
using namespace std;

bool operators(const char& op)
{
	switch (op)
	{
	case '+':
	case '-':
	case '/':
	case '*':
	case '^':
		return true;
	default:
		return false;
	}
}

bool numbers(const char& num)
{
	switch (num)
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

int priority(const char& prior)
{
	switch (prior)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '^':
		return 3;
	default:
		return -1;
	}
}

std::string reversion(std::string sample)
{
	std::string result;
	Stack<char> stk;
	for (size_t i = 0; i < sample.length(); ++i) 
	{
		char num = sample[i];
		if (numbers(num)) 
		{
			result += num;
			if (!numbers(sample[i + 1])) 
			{
				result += ' ';
			}
		}
		else if (num == '(') 
		{
			stk.push(num);
		}
		else if (num == ')') 
		{
			while (stk.peek() != '(')
			{
				result += stk.pop();
				result += ' ';
			}
			stk.pop();
		}
		else 
		{
			while (!stk.isEmpty() && priority(sample[i]) <= priority(stk.peek())) 
			{
				result += stk.pop();
				result += ' ';
			}	
			stk.push(num);
		}
	}
	
	while (!stk.isEmpty())
	{
		result += stk.pop();
	}
	return result;
}

double calculation(std::string sample)
{
	Stack<std::string> stk;
	double result = 0;
	double x = 0;
	double y = 0;
	std::string tok = "";
	
	for (size_t i = 0; i < sample.length(); ++i)
	{
		while (sample[i] == ' ')
		{
			++i;
		}
		if (numbers(sample[i]))
		{
			while (numbers(sample[i]))
			{
				tok += sample[i];
				++i;
			}
			stk.push(tok.c_str());
			tok = "";
		}
		else if (operators(sample[i]))
		{
			x = stod(stk.pop());
			y = stod(stk.pop());
			if (sample[i] == '+')
			{
				result = (x + y);
			}
			if (sample[i] == '-')
			{
				result = y - x;
			}
			if (sample[i] == '*')
			{
				result = (x * y);
			}
			if (sample[i] == '/')
			{
				if (x == 0) {
					throw "You can't divide by zero";
				}
				result = (y / x);
			}
			if (sample[i] == '^')
			{
				result = pow(y, x);
			}
			stk.push(std::to_string(result));
		}
		else 
		{
			cout << "-----Incorrect value-----\n";
			break;
		}
	}
	return stod(stk.pop());
}