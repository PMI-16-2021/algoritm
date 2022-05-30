#include <iostream>
#include "polish.h"




int main()
{
	std::string expression = "(4-2)^((-3) + 5) * (tg4)+1";
	std::string rpolish_expression = rpolish(expression);
	std::cout << rpolish_expression << std::endl;
	std::cout << rpolish_calculate(rpolish_expression);


	system("pause");
	return 0;
}