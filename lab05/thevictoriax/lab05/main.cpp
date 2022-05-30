#include "stack.h"
#include "polish.h"
#include <string>
using namespace std;

int main() 
{
	string sample;
	cout << "Enter sample: "; cin >> sample;
	cout << "Reverse polish notation: " << reversion(sample) << '\n';
	cout << "Result: " << calculation(reversion(sample));
	
	return 0;
}