#include <cstdlib>
#include <iostream>
#include <vector>
#include "markov.h"
using namespace std;

int main() {
	rules_for_bin_to_dec r1;
	rules_for_multiply r2;
	my_rules r3;

	String k1 = "101";
	String k2 = "||*||";
	String k3 = "acbbca";

	cout << k1.for_bin_to_dec(r1) << "\n";
	cout << k2.for_multiply(r2) << "\n";
	cout << k3.for_my_rules(r3) << "\n";

	String k5 = "acb";
	String k6 = "f";

	cout << "k5 length is: " << k5.leng() << "\n";
	cout << "k3.Find(k5): " << k3.Find(k5) << "\n";
	k3.Replace(k5, k6);

	String str = "0123456789";
	String str1 = "78";
	String str2 = "";

	str.Replace(str1, str2);
	cout << str << endl;

	system("pause");
	return 0;
}