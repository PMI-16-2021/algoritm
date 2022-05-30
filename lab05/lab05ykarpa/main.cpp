#include <iostream>
#include "polishNotation.h"
using namespace std;

int main() {
    cout << convert_to_reversed_polish_notation("(2+3)^(3-2)+1") << "\n";
    cout << reversed_polish_notation(convert_to_reversed_polish_notation("(2+3)^(3-2)+1")) << "\n";

    system("pause");
    return 0;
}