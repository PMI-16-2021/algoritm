#include "polishRecord.h"
#include "Stack.h"
typedef string::const_iterator symb; //symb == string::const_iterator
               

string PolishRecord(string str)
{
	if (!balanceStr(str))                          //check whether brackets are well-balanced
	{
		throw BadBracketBalance(str);              //exception 
	}
	str += ' ';                                    //add SPACE to keep iterator in range
	Stack<string> st;                              //stack for operands
	string return_str = "";                        //return variable
	for (symb i = str.begin(); i < str.end(); ++i) //overall loop
	{
		string temp = "";                          //to separate each number  
		for (symb f = i; *f != ' '; ++f)           //while *iter != ' '
		{
			temp += *f;                            //add 
			i += f - i;                            //to mantain order
		}
		if (IsOperation(temp))                     //if operation 
		{
			while (!st.empty() && GetPriority(temp) <= GetPriority(st.top()))  
			{	                          
				return_str += st.pop();  //add to return variable operand 
				return_str += '_';       //and separator
			}
			st.push(temp);               //push operation to stack 
		}
		else if ((temp >= "0" && temp <= "9") || temp.length() > 1) //if number length > 1 
		{                                                           //stands for >= 10
			return_str += temp;                                     //add number to array
			return_str += '_';                                      //separator
		}
		else       //if parenthesis
		{
			if (temp == "(")    //if left one
			{
				st.push(temp);  //add to stack
			}
			else if (temp == ")")  //if right 
			{
				while (true)
				{
					if (st.top() == "(") // if top == left one 
					{
						st.pop();        // popit from stack
						break;           // break
					}
					return_str += st.pop(); // else: add resulr from stack 
					return_str += '_';      // and add separator
				}
			}
		}	
	}

	while (!st.empty())      //if any left in stack => pop them to result
	{
		return_str += st.pop();
		return_str += '_';
	}
	return return_str;   //return result
}

//returns priority based on operator
//not switch because it doesn't support string
size_t GetPriority(string a)
{
	if (a == "^")
	{
		return 3;
	}
	else if (a == "*" || a == "/")
	{
		return 2;
	}
	else if (a == "+" || a == "-")
	{
		return 1;
	}
	else if (a == "(")
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

//define whether operator
bool IsOperation(const string a)
{
	return (a == "*"  || a == "+" || a == "-" || a == "^" || a == "/");
}

//calculate infix string
double Calculate(string revPolish)
{
	double result, a, b, temp_res; // eturn and 2 temp values
	Stack<string> st;              //stack of strings
	for (size_t i = 0; i < revPolish.length(); ++i)
	{
		string temp = "";    // to get string to first separator
		while (true)         // breaks inside
		{
			if (revPolish[i] == '_')  //if separator - break
			{
				break;
			}
			else                      //if not - operand OR operation
			{
				temp += revPolish[i]; // add to string
				++i;                  //increment looper
			}
		}
	
		if (!IsOperation(temp)) // number 
		{
			st.push(temp);      //add to stack
		}
		else                   // operation
		{
			try                     //safe unwrap in case of bad notation
			{
				a = stod(st.pop()); //get two numbers from stack
				b = stod(st.pop()); //stod: string to double
			}
			catch (const char* A)
			{
				std::cerr << A;    //report if exception
			}
			if (temp == "*")       //define operation
			{
				temp_res = b * a;  //carry out calculation
			}
			else if (temp == "/")
			{
				temp_res = b / a;
			}
			else if (temp == "+")
			{
				temp_res = a + b;
			}
			else if (temp == "-")
			{
				temp_res = b - a;
			}
			else if (temp == "^")
			{
				temp_res = pow(b, a);
			}
			st.push(to_string(temp_res)); //convert to string
		}                                 //push back to stack
	}
	result = stod(st.pop()); //if end of loop 
	return result;           //return result
}

//check brackets balance
bool balanceStr(const string b)
{
	int oCount = 0;     //open 
	int clCount = 0;    //close
	for (unsigned i = 0; i < b.length(); ++i)
	{
		if (b[i] == '(') ++oCount; //++open
		if (b[i] == ')')           //++close
		{
			++clCount;             //if close > open = > false
			if (clCount > oCount) return false; 
		}
	}
	return (oCount == clCount);   //also check general equality
}