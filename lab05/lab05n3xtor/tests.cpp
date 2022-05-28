#include "tests.h"
#include "funcs.h"
using namespace std;

void BracketsTest()
{
    string expression = "5^3-((35+25)+10/5))";
    if (CheckBrackets(expression) == false)
    {
        cout << "Brackets test passed\n";
    }
    else
    {
        cout << "Brackets test failed\n";
    }
}

void PolishRecordTest()
{
    string expression = "5^3-((35+25)+10/5)";
    string result = "5_3_^35_25_+10_5_/+-";
    if (PolishRecord(expression) == result)
    {
        cout << "Polish record test passed\n";
    }
    else
    {
        cout << "Polish record test failed\n";
    }
}

void CalculateTest()
{
    string expression = "5^3-(35+25)+10/5";
    if (Calculate(PolishRecord(expression)) == 67)
    {
        cout << "Calculate test passed\n";
    }
    else
    {
        cout << "Calculate test failed\n";
    }
}