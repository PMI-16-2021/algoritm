#pragma once
class Str
{
private:
	int size;
	char* x = new char[256];
public:
	Str() { size = 0; }
	Str(char* x);
	Str operator+(Str& y);
	void print();
	int search(char s);
	int search(char* s);
	void in(char* s, int pos);
	void del(int pos, int size);
};
