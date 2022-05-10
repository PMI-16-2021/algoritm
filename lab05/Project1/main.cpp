#include "Stack.h"
#include <string>
#include "polishRecord.h"
using std::cout;
using std::string;
using std::cin;
typedef string::const_iterator symb;

int main()
{
	string infix_string = "5 - ( 2 ^ 4 + 3.5 ) * ( 1.0 - 4.2 )";
	try
	{
		cout << Calculate(PolishRecord(infix_string));
	}
	catch (const BadBracketBalance& a)
	{
		a.report();
	}
	
	
	
	
	
	system("pause");
	return 0;
}