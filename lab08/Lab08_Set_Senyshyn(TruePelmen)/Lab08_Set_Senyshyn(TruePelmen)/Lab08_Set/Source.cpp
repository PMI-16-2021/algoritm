#include<iostream>
#include"Set.h"

using namespace std;

int main()
{
	Set S;
	S.Add(3);
	S.Add(7);
	S.Add(2);
	S.print();

	Set S1;
	S1.Add(3);
	S1.Add(1);
	S1.Add(6);
	S1.print();

	Set D = S-S1;
	D.print();
	
	Set I = S*S1;
	I.print();

	Set Sym = S+S1;
	Sym.print();

	Set U = S%S1;
	U.print();
	


	system("pause");
	return 0;
}