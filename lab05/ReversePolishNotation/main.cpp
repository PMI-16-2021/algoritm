#include <iostream>
#include "polish.h"
using namespace std;
int main() {
    string example = "((10-2)+(6*(7+4))*4^2)";
    cout << "Record: " << example << endl;
    cout <<"Reverse Polish notation: " << PolishRecord(example) << endl;
    cout <<"Result: " << Calculate(PolishRecord(example)) << endl;
    system("pause");
    return 0;
}