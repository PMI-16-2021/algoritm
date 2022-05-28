#include <iostream>
#include "funcs.h"
#include "tests.h"
using namespace std;

int main()
{
    cout << "Enter expression: ";
    string expression;
    cin >> expression;
    cout << "Reverse polish record: " << PolishRecord(expression) << '\n';
    cout << "Answer: " << Calculate(PolishRecord(expression)) << "\n\n";

    BracketsTest();
    PolishRecordTest();
    CalculateTest();

    system("pause>>void");
    return 0;
}