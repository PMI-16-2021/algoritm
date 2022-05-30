#include <iostream>
#include "Stack.h"
#include "polish.h"

using namespace std;

int main() {

    string exp1 = "5+5";
    cout << getReversedPolishNotation(exp1) << '\n';
    cout << calculateReversedPolishNotation(getReversedPolishNotation(exp1)) << "\n";

	system("pause");
	return 0;
}